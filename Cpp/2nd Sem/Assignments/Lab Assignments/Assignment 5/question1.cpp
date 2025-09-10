#include <iostream>
/// As we have studied in class that interface is simply a contract and
/// any class inheriting/implementing this must have to implement
/// the notify() method.....
/// 'I' prefix is just a naming convention here to show its interface....

using namespace std;

class INotification
{
public:
    virtual void notify() = 0;
};
/// NotificationModule is like the notification system on your phone
/// it doesnt care what type of notification it is.....
class NotificationModule
{
public:
    virtual void showNotification(INotification *notification)
    {
        notification->notify();
    }
};
/// these are different notification types
/// they all follow the INotification contract so they must have
/// to implement the notify() method....
class SMSNotification : public INotification
{
public:
    void notify() 
    {
        cout << "SMS Notification Popup on screen!\n";
    }
};
class CallNotification : public INotification
{
public:
    void notify()
    {
        cout << "Call Notification Popup on screen!\n";
    }
};
class WhatsAppNotification : public INotification
{
public:
    void notify()
    {
        cout << "WhatsApp related Notification Popup on screen!\n";
    }
};

class LMSNotification:public INotification{

public:
    void notify(){// this is the function added by Intisar Ahmad 16880
        cout<<"This is an LMS notification"<<endl;
    }

};
int main()
{
    /// make different types of notification objects......
    INotification *sms = new SMSNotification();
    INotification *whatsapp = new WhatsAppNotification();
    INotification *call = new CallNotification();
    INotification *lms = new LMSNotification();
    /// pass those notification objects to our NotificationModule
    /// system so it can react according to notification objects.......
    NotificationModule module;
    module.showNotification(sms);
    module.showNotification(whatsapp);
    module.showNotification(call);
    module.showNotification(lms);
    return 0;
}
