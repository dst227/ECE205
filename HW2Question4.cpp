#include <iostream>
#include <cstdlib>
#include <ctime> //time library used for the random seeds
using namespace std;

int choose_num();
int repeating_num(int num1, int num2);
int main(){

    //creates a seed for the random number
    srand(time(0)); 

    //variables for the finalists
    int num1, num2, num3, num4;

    num1 = choose_num();
    
    //choose value for num2
    num2 = choose_num();
    num2 = repeating_num(num1, num2); //repeating function checks if num1 == num2 

    //choose value for num3
    num3 = choose_num();
    num3 = repeating_num(num1, num3);
    num3 = repeating_num(num2, num3);
    
    //choose value for num4
    num4 = choose_num();
    num4 = repeating_num(num1, num4);
    num4 = repeating_num(num2, num4);
    num4 = repeating_num(num3, num4);

    //print out the values to the console
    cout<<"The lucky winning finalists are: "<<num1<<", "<<num2<<", "<<num3<<", "<<num4<<endl;

    return 0;
}
int choose_num(){

    int num = rand() % 25 + 1; //returns a random integer between 1 and 25

    return num;
}
int repeating_num(int num1, int num2){

    //while loop to make sure num 2 doesn't equal num 1
    while(num1 == num2){
        num2 = choose_num();
    }

    return num2;
}