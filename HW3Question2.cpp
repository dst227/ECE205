#include <iostream>
#include <cmath>
using namespace std;

void find_area(int a, int b, int c, double& area, double& perim);
int main(){

    //initialize the variables for the sides of the triangle
    int a, b, c;
    //initialze the variables for the area and the perimeter
    double area, perim;

    //get user input for the sides
    cout<<"Enter in the sides of a triangle, one at a time!"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;

    //compute the area and the perimeter
    find_area(a, b, c, area, perim);

    cout<<"The perimeter of the triangle is: "<<perim<<" [units]"<<" and the area is: "<<area<<" [units squared]"<<endl;

    return 0;
}
void find_area(int a, int b, int c, double& area, double& perim){

    //check if it's a valid triangle: if a + b > c, if a + c > b, if b + c > a, it can make a triangle
    //if it is a valid triangle, compute the area and the perimeter
    if(a + b > c && a + c > b && b + c > a){
        //calculate the perimeter
        perim = a + b + c;
        
        //calculate the semi-perimeter
        double s = perim / 2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));

    }
    //if it is not a valid triangle, print error and give zeros for the values
    else{
        cout<<"Error: not a valid triangle!"<<endl;
        area = 0;
        perim = 0;
    }

}
