#include <iostream>
using namespace std;

//function definitions
void display_board(char a[3][3]);
void get_val(int& val, int& player, char a[3][3]);
bool check_winner(char a[3][3]);
int main(){

    //create board array
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    //define the player (will be XORed to switch each time)
    int player = 0; //1 == X and 0 == 'O'

    display_board(board);

    //get user input for the location on where to put the X or O
    int num;

    //boolean value for while loop
    bool status = false;

    //integer value to end the loop if there is no winner
    int i = 0;

    while(!status && i < 9){
        //update the player value using XOR
        player ^= 1;
        get_val(num, player, board);
        status = check_winner(board);
        i++;
    }

    if(i == 9){
        cout<<"No winner!"<<endl;
    }
    //else, display the winner
    else if(player == 1){
        cout<<"The winner is 'X'!"<<endl;
    }
    else{
        cout<<"The winner is 'O'!"<<endl;
    }

    return 0;
}
void display_board(char a[3][3]){

    //statements for readability
    cout<<"Current board:"<<endl;
    cout<<endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<a[i][j]<<"   ";
        }
        //make a new line
        cout<<endl;
    }

}
void get_val(int& val, int& player, char a[3][3]){

    cout<<"Enter a value where you would like to go"<<endl;
    cin>>val;

    //check if the entered value is in range
    while(val < 1 || val > 9){
        cout<<"Error: value not in range"<<endl;
        cin>>val;
    }

    //check if the value is valid
    //get variables to check the array
    int i = (val - 1) / 3;
    int j = (val - 1) % 3;

    while(a[i][j] == 'X' || a[i][j] == 'O'){
        cout<<"Error: value is already chosen"<<endl;
        cin>>val;

        i = (val - 1) / 3;
        j = (val - 1) % 3;

    }

    //update the board:
    if(player == 1){
        a[i][j] = 'X';
    }
    else{
        a[i][j] = 'O';
    }

    //display the board again:
    display_board(a);

}
bool check_winner(char a[3][3]){

    //bool value to be returned:
    bool status;

    //check diagonals, row, and column
    //row and column first:
    if(a[0][0] == a[1][0] && a[1][0] == a[2][0]){
        status = true;
    }
    else if(a[0][1] == a[1][1] && a[1][1] == a[2][1]){
        status = true;
    }
    else if(a[0][2] == a[1][2] && a[1][2] == a[2][2]){
        status = true;
    }
    else if(a[0][0] == a[0][1] && a[0][1] == a[0][2]){
        status = true;
    }
    else if(a[1][0] == a[1][1] && a[1][1] == a[1][2]){
        status = true;
    }
    else if(a[2][0] == a[2][1] && a[2][1] == a[2][2]){
        status = true;
    }
    //then, check the diagonals:
    else if(a[0][0] == a[1][1] && a[1][1] == a[2][2]){
        status = true;
    }
    else if(a[0][2] == a[1][1] && a[1][1] == a[2][0]){
        status = true;
    }
    //else, return false
    else{
        status = false;
    }
    return status;
}