//
//  main.cpp
//  w05-25-notification
//
//  Created by Sergey Gordeev on 05.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include "notification.hpp"
void SendSms(const std::string& number, const std::string& message) {
  std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
  std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

/*
 Реализуйте здесь классы INotifier, SmsNotifier, EmailNotifier
 */

void Notify(INotifier& notifier, const std::string& message) {
  notifier.Notify(message);
}


int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
}
