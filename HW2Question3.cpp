#include <iostream>

using namespace std;

double hat_size(double weight, double height);
double jacket_size(double height, double weight, double age);
double waist_size(double weight, double age);
int main(){

    double height, weight, age, hat, jacket, waist; //initializing variables including hat size, jacket size, and waist size

    //get values for some of the variables
    cout<<"What is your height in inches?"<<endl;
    cin>>height;
    cout<<"What is your weight in pounds?"<<endl;
    cin>>weight;
    cout<<"What is your age in years?"<<endl;
    cin>>age;

    //get values for the rest of the variables
    hat = hat_size(weight, height);
    jacket = jacket_size(height, weight, age);
    waist = waist_size(weight, age);

    cout<<"Your hat size is: "<<hat<<endl;
    cout<<"Your jacket size is: "<<jacket<<endl;
    cout<<"Your waist size is: "<<waist<<endl;

    return 0;
}
double hat_size(double weight, double height){

    double size = 2.9 * weight / height;

    return size;
}
double jacket_size(double height, double weight, double age){

    double size = height * weight / 288;

    //adds 1/8 of an inch for each 10 years over 30 years of age
    if(age > 30){
        if(age >= 40){
            size += 1.0/8;
        }
        if(age >= 50){
            size += 1.0/8;
        }
        if(age >= 60){
            size += 1.0/8;
        }
        if(age >= 70){
            size += 1.0/8;
        }
        if(age >= 80){
            size += 1.0/8;
        }
        if(age >= 90){
            size += 1.0/8;
        }
        if(age >= 100){
            size += 1.0/8;
        }
        if(age >= 110){
            size += 1.0/8;
        }
        if(age >= 120){
            size += 1.0/8;
        }
        if(age >= 130){
            size += 1.0/8;
        }
        //note this stops at 130 because I don't think humans live longer than that
    }
    return size;
}

double waist_size(double weight, double age){

    double size = weight / 5.7;

    //add 1/10 of an inch for each 2 years over the age of 28
    if(age > 28){
        //for loop to start at age = 28 and end at the user's actual age, adding 1/10th of an inch each iteration
        for(int i = 28; i < age; i += 2){
            size += 0.1;
        }
    }

    return size;
}

