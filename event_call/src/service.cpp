#include <chrono>
#include <iostream>
#include <thread>
#include <vsomeip/vsomeip.hpp>
#define SERVICE_ID 0x0001
#define INSTANCE_ID 0x0001
#define METHOD_ID 0x0001
#define EVENT_ID 0x8778

std::shared_ptr<vsomeip::application> app;
std::shared_ptr<vsomeip::payload> payload;

void run() {
  /*std::vector<vsomeip::byte_t> payload_data;
  std::string text = "Hello from server Events\n";
  payload = vsomeip::runtime::get()->create_payload();
  payload->set_data(payload_data);*/
  const vsomeip::byte_t its_data[] = {0x10};
  payload = vsomeip::runtime::get()->create_payload();
  payload->set_data(its_data, sizeof(its_data));

  while (true) {
    app->notify(SERVICE_ID, INSTANCE_ID, EVENT_ID, payload);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void on_message(const std::shared_ptr<vsomeip::message>& _request) {
  std::cout << "\nhello\n";
  std::shared_ptr<vsomeip::payload> request_payload = _request->get_payload();
  vsomeip::length_t length = request_payload->get_length();
  const vsomeip::byte_t* request_payload_data = request_payload->get_data();
  std::cout << "Client request: \n";

  for (vsomeip::length_t i = 0; i < length; i++) {
    std::cout << static_cast<char>(*(request_payload_data + i));
  }
  std::cout << "\n";

  std::shared_ptr<vsomeip::message> respond;
  respond = vsomeip::runtime::get()->create_response(_request);
  request_payload = vsomeip::runtime::get()->create_payload();

  std::vector<vsomeip::byte_t> payload_data;
  std::string text = "Hello from server \n";

  payload_data.insert(payload_data.end(), text.begin(), text.end());
  request_payload->set_data(payload_data);
  respond->set_payload(request_payload);
  app->send(respond);
  std::cout << "Request sent \n";
}

int main() {
  app = vsomeip::runtime::get()->create_application();
  app->init();

  std::set<vsomeip::eventgroup_t> its_groups;
  its_groups.insert(EVENT_ID);

  // app->register_message_handler(SERVICE_ID, INSTANCE_ID, METHOD_ID ,
  // on_message);
  app->offer_event(SERVICE_ID, INSTANCE_ID, EVENT_ID, its_groups);
  app->register_message_handler(SERVICE_ID, INSTANCE_ID, METHOD_ID, on_message);
  app->offer_service(SERVICE_ID, INSTANCE_ID);

  std::thread sender(run);
  app->start();
  sender.join();
}