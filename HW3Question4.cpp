#include <iostream> 
using namespace std;


void convert(int pounds, int oz, int& kilo, int& gram);
void input(int& pounds, int& oz);
void go_again(char& stop);
int main(){

    //define variables
    int pounds, oz, gram; 
    int kilo;
    char stop = 'y'; //char to tell when to stop

    while(stop == 'y' || stop == 'Y'){

        //get the input from the user
        input(pounds, oz);

        convert(pounds, oz, kilo, gram);

        cout<<pounds<<"lb "<<oz<<"oz = "<<kilo<<"kg "<<gram<<"g"<<endl;

        //see if the user wants to go again
        go_again(stop);

    }

    return 0;
}
void input(int& pounds, int& oz){

    //get user input for pounds and ounces
    cout<<"Input pounds and ounces and I will convert them to kilograms and grams."<<endl;
    cout<<"How many pounds do you want?"<<endl;
    cin>>pounds;
    cout<<"How many ounces do you want?"<<endl;
    cin>>oz;

}
void convert(int pounds, int oz, int& kilo, int& gram){

    //there are 2.2046 pounds in 1000g, 1000g in 1kg
    //also, 16 oz in 1 pound -> 1 ounce = 28.3498g (1000 / 2.2046 / 16)

    //first, convert pounds to ounces
    oz += 16 * pounds;

    //then, convert ounces to grams
    //static cast because I'm using all integer values here
    gram = static_cast<int>(oz * 28.3498); //note: static cast isn't actually needed here, i included it just to make sure

    //account for kilos
    kilo = gram / 1000;

    //then, subtract the kilos from the grams to make it even

    gram -= kilo * 1000;


}
void go_again(char& stop){

    cout<<endl;
    cout<<"Would you want to go again? Enter 'y' or 'Y' to keep going and anything else to stop"<<endl;
    cin>>stop;

}