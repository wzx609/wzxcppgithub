#include<iostream>
using namespace std;
int main()
{
    enum Weekday{SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
    enum Weekday wd;
    wd = SUNDAY;
    cout<<(int)wd<<endl;
    return 0;
}
