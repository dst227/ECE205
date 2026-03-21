#include <iostream>
using namespace std;

//take as input a degree of difficulty and 7 judges' scores (store in array)
//note: scores are between 0 and 10 
//highest and lowest scores are thrown out and the remaining scores are added together
//the sum is multiplied by the degree of difficulty, which ranges from 1.2 to 3.8
//diver's score then calculated by multiplying final number by 0.6

//global variable
double degree; //degree of difficulty

//function declarations
void get_degree();
void fill_array(double a[]);
void sort_array(double a[]);
double get_sum(double a[]);

int main(){

    //magic formula to get two decimals of precision in output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //define the scores array that will be used to hold the 7 judge's scores
    double scores[7]; 

    //get the degree of difficulty
    get_degree();

    //fill the array with input from the users
    fill_array(scores);

    //sort the array
    sort_array(scores);

    //now it's sorted, the correct sum can be found
    double sum = get_sum(scores);

    //then, the sum can be multiplied by the degree of difficulty and then by 0.6 to determine the score
    double score = sum * degree * 0.6;

    cout<<"The score for the diver is: "<<score<<endl;

    return 0;
}
void get_degree(){

    cout<<"Choose a degree of difficulty for the diver. It should be a number between 1.2 and 3.8"<<endl;
    cin>>degree; //make the degree variable the input

    //check if the degree variable is valid
    while(degree < 1.2 || degree > 3.8){

        cout<<"Error: enter a valid degree of difficulty between 1.2 and 3.8"<<endl;
        cin>>degree;

    }
}
void fill_array(double a[]){

    //prompt user
    cout<<"Enter 7 scores from the judges. Make sure it is a number between 0 and 10."<<endl;

    //get input from the user -- use a for loop for simplicity
    for(int i = 0; i < 7; i++){
    
        //prompt user again
        cout<<"Enter a score:"<<endl;
        //make the score the indice of the array
        cin>>a[i];

        //make sure it's a valid number between 0 and 10
        while(a[i] < 0 || a[i] > 10){
            cout<<"Error: enter a valid number between 0 and 10"<<endl;
            cin>>a[i];
        }
    }
}
void sort_array(double a[]){

    //I'll do a selection sort the way I learned in cse7 instead because I think it's easier 
    //than the way we learned in class

    //define the minimum value
    int min;

    for(int i = 0; i < 7 - 1; i++){
        
        //make the minimum value = i
        min = i;

        //go through the  
        for(int j = i + 1; j < 7; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }

        //swap the values
        double temp = a[i];
        a[i] = a[min];
        a[min] = temp;

    }

}
double get_sum(double a[]){

    //get the sum from the sorted array (exclude the min and the max values)
    //this means I'll exclude the highest and lowest indices

    //define the value to be returned
    double sum = 0;

    for(int i = 1; i < 6; i++){
        sum += a[i];
    }

    return sum;
}