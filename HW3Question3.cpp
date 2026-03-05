#include <iostream>

using namespace std;

int find_min(int start, int end);
int main(){

    //define variables to be found from the user
    int start_time, end_time;

    //get the start time from the user
    cout<<"I will find the minutes between two numbers. What is your start time in military notation (0000 - 2359)?"<<endl;
    cin>>start_time;
    
    //make sure the number is valid so it doesn't break the function
    while(start_time < 0 || start_time > 2359){
        cout<<"No, I said to enter a number between 0000 and 2359!"<<endl;
        cin>>start_time;
    }

    //get the end time from the user
    cout<<"Ok, now what is the end time?"<<endl;
    cin>>end_time;

    //make sure the number is valid so it doesn't break the function
    while(end_time < 0 || end_time > 2359){
        cout<<"No, I said to enter a number between 0000 and 2359!"<<endl;
        cin>>end_time;
    }

    //call the function and store it as a variable
    int min = find_min(start_time, end_time);

    cout<<endl;
    cout<<"The difference in minutes is: "<<min<<" minutes."<<endl;
    cout<<endl;

    return 0;
}
int find_min(int start, int end){
    //variable definitions 
    int start_min, start_hour, end_min, end_hour;

    int min = 0; //value to be returned

    //check if the end time is the following day
    if(end < start){
        //add 24 hours to the end time to account for this 
        end += 2400;
    }
    
    //get values for the start hour, start minutes, end hour, end minutes 
    start_hour = start / 100;
    start_min = start % 100;
    end_hour = end / 100;
    end_min = end % 100;

        
    //update min
    min += 60*(end_hour - start_hour) + (end_min - start_min);

    return min;
}
