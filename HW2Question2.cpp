#include <iostream>
#include <cmath>
#include <fstream> //file stream to read files

using namespace std;

double find_avg(int n1, int n2, int n3, int n4, int n5);
double find_var(int n1, int n2, int n3, int n4, int n5, double avg);
int main(){
    
    //magic formula to output 2
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);


    ifstream in; //equivalent to cin
    ofstream out; //equivalent to cout

    //magic formula to output to text file 2
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);

    int n1, n2, n3, n4, n5;

    //read data from text file

    in.open("scores.txt"); //this is assuming the text file is in the same directory as this cpp file
    //assigning values to variables
    in>>n1;
    in>>n2;
    in>>n3;
    in>>n4;
    in>>n5;


    //get the average
    double avg = find_avg(n1, n2, n3, n4, n5);
    //note the variance is calculated using 1/5 instead of 1/4 because of the provided document
    double variance = find_var(n1, n2, n3, n4, n5, avg); //finds the variance
    double std_dev = pow(variance, 0.5);

    //write data in text file
    out.open("output.txt"); //same thing: assumes text file is in the same directory
    out<<avg<<endl;
    out<<std_dev<<endl;



    //display data in console
    cout<<"The mean is: "<<avg<<endl;
    cout<<"The standard deviation is: "<<std_dev<<endl;

    in.close();
    out.close();

    return 0;
}
double find_avg(int n1, int n2, int n3, int n4, int n5){
    
    double avg = (n1 + n2 + n3 + n4 + n5)/5.0;

    return avg;
}
double find_var(int n1, int n2, int n3, int n4, int n5, double avg){

    double var = 0.2 * (pow(n1 - avg, 2) +  pow(n2 - avg, 2) + pow(n3 - avg, 2) + pow(n4 - avg, 2) + pow(n5 - avg, 2));

    return var;

}

