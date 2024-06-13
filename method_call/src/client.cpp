#include <condition_variable>
#include <iostream>
#include <thread>
#include <vsomeip/vsomeip.hpp>
#define SERVICE_ID 0x00001
#define INSTANCE_ID 0x00001
#define METHOD_ID 0x0002
std::shared_ptr<vsomeip::application> app;
std::mutex mutex;
std::condition_variable condition;

void run() {
  std::cout << "run\n";
  std::unique_lock<std::mutex> lock(mutex);
  condition.wait(lock);

  std::shared_ptr<vsomeip::message> request;
  request = vsomeip::runtime::get()->create_request();
  request->set_service(SERVICE_ID);
  request->set_instance(INSTANCE_ID);
  request->set_method(METHOD_ID);

  std::shared_ptr<vsomeip::payload> payload =
      vsomeip::runtime::get()->create_payload();
  std::vector<vsomeip::byte_t> payload_data;

  std::string text = "Hello from client \n";
  payload_data.insert(payload_data.end(), text.begin(), text.end());
  payload->set_data(payload_data);
  request->set_payload(payload);
  app->send(request);
  std::cout << "Request sent\n";
}
void on_message(const std::shared_ptr<vsomeip::message>& _request) {
  std::shared_ptr<vsomeip::payload> respond_payload = _request->get_payload();
  vsomeip::length_t length = _request->get_length();

  const vsomeip::byte_t* request_payload_data = respond_payload->get_data();

  std::cout << "Server respond: \n";

  for (vsomeip::length_t i = 0; i < length; i++) {
    std::cout << static_cast<char>(*(request_payload_data + i));
  }
  std::cout << "\n";
}

void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance,
                     bool is_available) {
  if (is_available) {
    std::cout << "service " << _service << " instance " << _instance
              << " is available \n";

  } else {
    std::cout << "service " << _service << " instance " << _instance
              << " is NOT  available\n";
  }
  condition.notify_one();
}

int main() {
  app = vsomeip::runtime::get()->create_application("Hello_2");
  app->init();

  app->register_availability_handler(SERVICE_ID, INSTANCE_ID, on_availability);
  app->request_service(SERVICE_ID, INSTANCE_ID);
  app->register_message_handler(SERVICE_ID, INSTANCE_ID, METHOD_ID, on_message);
  std::thread sender(run);
  app->start();
}
