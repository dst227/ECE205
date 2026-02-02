#include <iostream>
using namespace std;

int main(){
    //magic formula
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    float rate = 36.75; //hourly rate paid to employee
    float overtime = 1.5 * rate; //hourly overtime rate

    //taxes
    float social = 0.06; //6% social security tax
    float fed = 0.15; //15% federal income tax
    float state = 0.04; //4% state income
    float local = 0.01; //1% for local tax
    int uniondues = 20; //$20 in union dues

    int dependents;
    float hours;

    cout<<endl;
    cout<<"How many hours did you work this week?"<<endl;
    cin>>hours;
    cout<<endl;

    cout<<"How many dependents do you have?"<<endl;
    cin>>dependents;
    cout<<endl;

    float grossPay;
    
    //accounting for overtime...
    if(hours > 40){
        float overtimeHours = hours - 40;
        grossPay = rate * 40 + overtimeHours * overtime;
    }
    else{
        grossPay = hours * rate; //calculation for the gross pay
    }

    //calculation for net take home pay in one long line: 
    float takeHome = grossPay - (grossPay * social) - (grossPay * fed) - (grossPay * state) - (grossPay * local) - uniondues;

    //if 2 or more dependents, $40 more deducted for health insurance
    if(dependents > 1){
        takeHome = takeHome - 40;
    }

    //printing everything out
    cout<<"Your gross pay is $"<<grossPay<<endl;
    cout<<endl;
    //printing out withholding info; the calculations are done in the print statements
    cout<<"Your withholding amounts:"<<endl;
    cout<<"Social Security: $"<<grossPay * social<<endl;
    cout<<"Federal Income: $"<<grossPay * fed<<endl;
    cout<<"State Income: $"<<grossPay * state<<endl;
    cout<<"Bethlehem Local Tax: $"<<grossPay * local<<endl;
    cout<<"Union dues: $"<<uniondues<<endl;
    //if 2 or more dependents, there's another due
    if(dependents > 1){
        cout<<"Health Insurance: $40"<<endl;
    }
    
    cout<<endl;
    cout<<"Your final take home check is $"<<takeHome<<endl;

    return 0;
}