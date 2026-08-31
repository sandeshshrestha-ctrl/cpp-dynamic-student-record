#include <iostream>
using namespace std;
class Time
{
private:
    short hours, minutes, seconds;

public:
    Time()
    {
        cout << "default constructor is made" << endl;
    }
    Time(short hours, short minutes, short seconds) : hours(hours), minutes(minutes), seconds(seconds)
    {
        cout << "value is set using the parameterized constructor" << endl;
    }
    Time operator++()
    {
        ++this->seconds;
        this->minutes += this->seconds / 60;
        this->seconds %= 60;
        this->hours += this->minutes / 60;
        this->minutes %= 60;
        return *this;
    }
    Time operator++(int)
    {
        Time temp(hours, minutes, seconds);

        ++this->seconds;
        this->minutes += this->seconds / 60;
        this->seconds %= 60;
        this->hours += this->minutes / 60;
        this->minutes %= 60;
        return (temp);
    }
    void display()
    {
        cout << this->hours << ":" << this->minutes << ":" << this->seconds << endl;
    }
};
int main()
{

    Time t1(2, 59, 59);
    cout << "the original time is:" << endl;
    t1.display();

    Time t2 = ++t1;
    cout << "after the pre-increament , the time is:" << endl;
    t2.display();
    Time t3(2, 59, 59);
    cout << "the original time is:" << endl;
    t3.display();

    Time t4 = t3++;
    cout << "after the post increament:" << endl;
    t4.display();
    cout << "the original time is now:" << endl;
    t3.display();
    return (0);
}