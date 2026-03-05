#include <iostream>

using namespace std;

void input(int& hour, int& min);
void output(char time, int hour, int min);
void conversion(char& time, int& hour);
bool check_min(int min);
int main(){

    //define the hour and minute integers
    int hour, min; 

    //char to tell if it is AM or PM and char to tell when to stop the loop
    char time, stop = 'y';

    while(stop == 'Y' || stop == 'y'){

        //get values for hour and minute from input function
        input(hour, min);


        //if the hour is greater than 13, it has to be converted
        if(hour > 12){
            conversion(time, hour); //converts the hour and gives the char as 'P'
            output(time, hour, min);
        }
        //special case for if it is 12 pm
        else if (hour == 12){
            time = 'P';
            output(time, hour, min);
            
        }
        //special case for if it is 12 am
        else if(hour == 0){
            time = 'A';
            hour += 12; //make hour 12 am
            output(time, hour, min);
        }
        //else, the char has to be 'A' and print out a different statement
        else{
            time = 'A';
            output(time, hour, min);            
        }

        //prompt the user to keep on going
        cout<<"Would you want to keep going? Enter y for yes or n for no"<<endl;
        cin>>stop;

    }



    return 0;
}
void input(int& hour, int& min){

    //get the hour and minute as input
    cout<<"You will enter the time. What is the hour?"<<endl;
    cin>>hour;
    cout<<"What is the minute? Please enter an integer under 60."<<endl;
    cin>>min;

}
void conversion(char& time, int& hour){

    //call by reference so both the hour and the time can change
    hour -= 12;
    time = 'P';

}
void output(char time, int hour, int min){
    
    if(hour == 12 || hour == 10 || hour == 11){
        if(check_min(min)){
            cout<<"The time is "<<hour<<":0"<<min<<" "<<time<<"M"<<endl;
        }
        else{
            cout<<"The time is "<<hour<<":"<<min<<" "<<time<<"M"<<endl;
        }
    }
    else{
        if(check_min(min)){
            cout<<"The time is 0"<<hour<<":0"<<min<<" "<<time<<"M"<<endl;
        }
        else{
            cout<<"The time is 0"<<hour<<":"<<min<<" "<<time<<"M"<<endl;
        }
    }


}
//function to check if the amount of minutes is under 10 for formatting issues
bool check_min(int min){
    if(min < 10){
        return true;
    }
    else{
        return false;
    }
}