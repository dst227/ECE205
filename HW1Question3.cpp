#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main(){
    //magic formula
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    float rate = 1.5 / 100; //interest rate is 1.5% per month
    int monthly = 50; //monthly payments of $50 
    float interest; //value used in the while loop 
    int month = 1; //number of months

    float balance = 1000.0; //cost of the stereo system
    float principal; //value used in the while loop

    //defining and initializing total amounts so they can be used in the while loop 
    float tot_interest = 0.0;
    float tot_paid = 0.0;

    //title
    cout<<right<<setw(8)<<"Month #"<<right<<setw(12)<<"Interest"<<right<<setw(12)<<"Principal"<<right<<setw(12)<<"Balance"<<right<<setw(16)<<"Total Interest"<<right<<setw(12)<<"Total Paid"<<endl;

    while(balance > 0){

        interest = rate * balance; //finds the amount of interest you owe
        principal = monthly - interest; //the amount of money you can actually use towards the payment (after accounting for interest)

        
        tot_interest += interest;
        
        //gets the total amount of money paid
        if(balance < monthly){
            tot_paid += balance + interest; 
        }
        else{
            tot_paid += monthly; 

        }

        //monthly payments pay the interest first and then whatever is left pays the remaining debt
        balance -= principal;

        //makes sure there is no negative balance
        if(balance < 0){
            balance = 0.0;
        }

        cout<<right<<setw(8)<<month<<right<<setw(7)<<"$"<<setw(5)<<interest<<right<<setw(7)<<"$"<<setw(4)<<principal<<right<<setw(6)<<"$"<<setw(6)<<balance<<right<<setw(10)<<"$"<<setw(6)<<tot_interest<<right<<setw(5)<<"$"<<setw(7)<<tot_paid<<endl;


        month++; //increment the month after each iteration
        
    }


   

    //cout<<right<<setw(7)<<fixed<<month<<"\t"<<right<<setw(7)<<fixed<<"$"<<interest<<"\t"<<principal<<"\t"<<balance<<"\t"<<tot_interest<<"\t"<<tot_paid<<endl;

    

    return(0);
}