#include <iostream>
#include <cmath>

using namespace std;

const double G = 6.673E-8; //declare G as a constant

double calculate_force(double m1, double m2, double d);
int main(){

    double m1, m2, d; //masses in units kg and distance in units cm
    char response = 'y'; //char to see if the user wants to repeat the code

    //magic formula to output 2 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //repeat the code as many times as the user wants

    while(response == 'y'||response == 'Y'){

        cout<<endl;
        cout<<"Enter in values for the masses in kg."<<endl;
        cin>>m1;
        cin>>m2;
        cout<<"Enter in a value for the distance between the masses in cm"<<endl;
        cin>>d;

        cout<<"The force between the two masses is: "<<calculate_force(m1, m2, d)<<" dynes"<<endl;

        cout<<endl;
        cout<<"Would you like to enter another response? Enter 'y' or 'n'"<<endl;
        cin>>response;

    }

    return 0;
}

double calculate_force(double m1, double m2, double d){
    
    //convert kg to g
    double m1_real = m1 * 1000;
    double m2_real = m2 * 1000;


    double val = (G*m1_real*m2_real) / pow(d, 2); 

    return val;

}