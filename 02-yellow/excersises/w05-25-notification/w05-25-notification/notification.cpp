//
//  notification.cpp
//  w05-25-notification
//
//  Created by Sergey Gordeev on 05.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "notification.hpp"


void SmsNotifier::Notify(const std::string& message){
    SendSms(number, message);
};

void EmailNotifier::Notify(const std::string& message){
    SendEmail( email,  message);
};
