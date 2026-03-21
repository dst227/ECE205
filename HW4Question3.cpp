#include <iostream>
using namespace std;

//function definitons
void fill_array(char a[][4]);
void print_array(char a[][4]);
void get_input(int& num, char& let);
void check_seat(char a[][4], int num, char let);
int main(){

    //create the seat array
    char seats[10][4]; // 10 rows by 4 column array of chars

    fill_array(seats);

    //then, print the array to the console
    print_array(seats);

    //prompt the user for the desired seat
    int seat_num;
    char letter;

    get_input(seat_num, letter);

    //check if the seat number and letter are valid
    check_seat(seats, seat_num, letter);

    //see if the user wants to keep adding seats 
    char resp = 'y';
    cout<<"Do you want to keep adding seats? Enter y for yes and n for no."<<endl;
    cin>>resp;

    //function until the user says to stop
    while(resp != 'n' && resp != 'N'){
        get_input(seat_num, letter);
        check_seat(seats, seat_num, letter);
        cout<<"Do you want to keep adding seats? Enter y for yes and n for no."<<endl;
        cin>>resp;
    }

    return 0;
}
void fill_array(char a[][4]){

    //fill the array with 
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 4; j++){
            //need an 'X' at 1B, 3D, and 5A
            if((i == 0 && j == 1)||(i == 2 && j == 3)||(i == 4 && j == 0)){
                a[i][j] = 'X';
            }
            //else, assign values based on j
            else{

                switch (j){
                    case 0:
                        a[i][j] = 'A';
                        break;
                    case 1:
                        a[i][j] = 'B';
                        break;
                    case 2:
                        a[i][j] = 'C';
                        break;
                    case 3:
                        a[i][j] = 'D';
                        break;
                }

            }

        }
    }

}
void print_array(char a[][4]){

    //just cycle through the array with for loops and print what's inside
    for(int i = 0; i < 10; i++){
        
        cout<<i + 1<<"      ";

        for(int j = 0; j < 4; j++){
            cout<<a[i][j]<<" ";
        }

        //get a new line
        cout<<endl;
    }

}
void get_input(int& num, char& let){

    cout<<"Enter a seat letter followed by the desired seat number"<<endl;
    cin>>let;
    
    while(let != 'A' && let != 'B' && let != 'C' && let != 'D'){
        cout<<"Error: enter a valid seat letter (A, B, C, or D)"<<endl;
        cin>>let;
    }

    cout<<"Now enter the seat number."<<endl;
    cin>>num;

    while(num > 10 || num < 1){
        cout<<"Error: enter a valid seat number (1-10)"<<endl;
        cin>>num;
    }

}
void check_seat(char a[][4], int num, char let){

    //first step: convert the num value to work with arrays
    num -= 1; 

    //second step: convert the char to a number
    int temp;
    switch (let){
        case 'A':
            temp = 0;
            break;
        case 'B':
            temp = 1;
            break;
        case 'C':
            temp = 2;
            break;
        case 'D':
            temp = 3;
            break;  
    }

    //check the array:
    while(a[num][temp] == 'X'){
        cout<<"That seat is taken! Try again."<<endl;
        
        get_input(num, let);

        num -= 1;

        switch (let){
        case 'A':
            temp = 0;
            break;
        case 'B':
            temp = 1;
            break;
        case 'C':
            temp = 2;
            break;
        case 'D':
            temp = 3;
            break;  
        }

        
    }
    //update the seat to ensure it doesn't get selected again
    a[num][temp] = 'X';
    cout<<"That seat is available! You're booked!"<<endl;
    //display the array
    print_array(a);

}