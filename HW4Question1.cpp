#include <iostream>
using namespace std;

//want to take a list of integers from the user and calculate a histogram from it
//first ask user for the array size, then ask for each number and make sure it's non-negative
//assume bins are size 10 (0-9, etc.)
//output a list of bins and number of values that fall into each one

//list global variable
int nums[1000]; //defines the number array and initializes it using an arbitrary value (1000)
int array_size; //variable to determine the amount of the array that will be initialized with meaning

//function definitions
void get_input();
void fill_array(int a[]);
int find_max(int a[]);
void display(int a[], int bins, int array_size);

int main(){

    int hist[1000]; //histogram array to output later

    //get the input from the user using the get_input function
    get_input();

    //fill up the array using the function fill_array
    fill_array(nums);

    //find the maximum number in the array to make determine the number of bins in the histogram
    int max = find_max(nums);

    //get the amount of bins needed for the histogram:
    int num_bins = (max / 10) + 1; //this makes sure that even if the maximum value is less than 10, the number of bins isn't zero

    //determine how many numbers are in each bin and display to the console
    display(nums, num_bins, array_size);

    return 0;
}
void get_input(){
    cout<<"What size would you like the histogram to be? Enter a nonzero positive integer less than 1000"<<endl;
    cin>>array_size;

    //make sure the size is nonzero and positive and less than 1000
    while(array_size <= 0 || array_size > 1000){
        cout<<"Error, try again."<<endl;
        cin>>array_size;
    }

}
void fill_array(int a[]){

    cout<<"It's time to fill the array!"<<endl;

    //make temporary variable to use to fill the array
    int temp;

    for(int i = 0; i < array_size; i++){
        //ask for input, then give it to the array
        cout<<"Enter a positive number:"<<endl;
        cin>>temp;

        //make sure the number is non-negative
        while(temp < 0){
            cout<<"No, I said to enter a positive integer. Try again."<<endl;
            cin>>temp;
        }

        a[i] = temp;

    }
    
}
int find_max(int a[]){
    
    //create max variable to be returned and initialize it to the first value 
    int max = a[0];

    //use linear search to find the maximum value in the array 
    //note: I learned this in my cse7 class

    for(int i = 1; i < array_size; i++){
        
        if(a[i] > max){
            max = a[i];
        }

    }

    return max;

}
void display(int a[], int bins, int array_size){

    //define temporary variable for displaying
    int temp;

    //use a for-loop system to loop over the numbers array to determine how many numbers are in each bin
    for(int i = 0; i < bins; i++){
        //set temp variable to zero at first
        temp = 0;

        //nested for loop to go through the array each time, again doing a linear search
        for(int j = 0; j < array_size; j++){
            //logic to get the right amount of numbers in each bin
            if((a[j] < ((i + 1) * 10)) && (a[j] >= (i * 10))){
                temp++;
            }
        }
        //display everything
        cout<<"Bin "<< i+1 <<", number of values: "<<temp<<endl;
    
    }


}