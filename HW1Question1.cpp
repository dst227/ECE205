#include <iostream>
#include <string>
using namespace std;


int main(){
    //magic formula
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    //variables
    int time; //input, in seconds
    int seconds;
    int minutes;
    float real_minutes; //for the decimal
    int hour;
    float real_hour; //for the decimal

    cout<<endl;
    cout<<"Give a length of time of your choosing in seconds (enter an integer for the number of seconds)"<<endl;
    cin>>time;
    cout<<endl;

    hour = time / 3600; //truncated hours
    minutes = (time % 3600) / 60;
    seconds = (time % 3600) % 60;

    //outputting the hours, minutes and seconds
    cout<<"Hours: "<<hour<<endl;
    cout<<"Minutes: "<<minutes<<endl;
    cout<<"Seconds: "<<seconds<<endl;
    cout<<endl;

    //making the real hours and the real minutes
    real_hour = time / 3600.0;
    real_minutes = time / 60.0;

    //displaying the real hours and the real minutes
    cout<<"The real amount of hours is "<<real_hour<<endl;
    cout<<"The real amount of minutes is "<<real_minutes<<endl;
    cout<<endl;

    return 0;
}