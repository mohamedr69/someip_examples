#include <condition_variable>
#include <iostream>
#include <thread>
#include <vsomeip/vsomeip.hpp>

#define SERVICE_ID 0x00001
#define INSTANCE_ID 0x00001
#define EVENT_ID 0x8778

std::shared_ptr<vsomeip::application> app;
std::mutex mutex;
std::condition_variable condition;
void run() {
  std::cout << "IN \n";
  std::unique_lock<std::mutex> its_lock(mutex);
  condition.wait(its_lock);

  std::set<vsomeip::eventgroup_t> its_groups;
  its_groups.insert(EVENT_ID);
  app->request_event(SERVICE_ID, INSTANCE_ID, EVENT_ID, its_groups);
  app->subscribe(SERVICE_ID, INSTANCE_ID, EVENT_ID);
  std::cout << "subscrbed\n";
}

void on_message(const std::shared_ptr<vsomeip::message>& _response) {
  std::shared_ptr<vsomeip::payload> respond_payload = _response->get_payload();
  vsomeip::length_t length = respond_payload->get_length();

  const vsomeip::byte_t* request_payload_data = respond_payload->get_data();

  std::cout << "Server respond: \n";

  for (vsomeip::length_t i = 0; i < length; i++) {
    std::cout << static_cast<int>(*(request_payload_data + i));
  }
  std::cout << "\n data recieved \n";
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
  app = vsomeip::runtime::get()->create_application("Hello");
  app->init();
  app->register_availability_handler(SERVICE_ID, INSTANCE_ID, on_availability);
  app->request_service(SERVICE_ID, INSTANCE_ID);

  app->register_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE,
                                vsomeip::ANY_METHOD, on_message);

  std::thread sender(run);
  app->start();
  sender.join();
}