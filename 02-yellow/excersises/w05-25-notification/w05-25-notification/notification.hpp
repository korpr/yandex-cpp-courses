//
//  notification.hpp
//  w05-25-notification
//
//  Created by Sergey Gordeev on 05.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef notification_hpp
#define notification_hpp

#include <string>
void SendSms(const std::string& number, const std::string& message);
void SendEmail(const std::string& email, const std::string& message);
class INotifier{
public:
    virtual void Notify(const std::string& message) = 0;
};


class SmsNotifier : public INotifier{
public:
    SmsNotifier(const std::string aNumber):number(aNumber){}
    virtual void Notify(const std::string& message);
private:
    std::string number;
};


class EmailNotifier : public INotifier{
public:
    EmailNotifier(const std::string aEmail):email(aEmail){}
    virtual void Notify(const std::string& message);
    
private:
    std::string email;
};
#endif /* notification_hpp */
