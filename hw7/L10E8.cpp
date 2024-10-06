//Christian Aruba
//cma3939
//TACC ID: slopan_karn93
#include<iostream>
#include<cmath>
#include<sstream>
#include<string>
using std::atan;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Point {

 private:
 float x,y;

 public:

  //constructor to quickly make objects
 Point(float in_x,float
 in_y) {
 x = in_x; y = in_y; };

  //return the distance of a point to the origin
   float distance_to_origin() {

     return sqrt( x*x + y*y );



 };

  //creating a method to return the angle of a point
  float angle(){
        return (atan(y/x))*(180.0/3.1415);

  };

  //creating a method that computes the distance btw p1 and another point
  float distance(Point q) {
    auto dx = x-q.x, dy = y-q.y;

    return sqrt(dx*dx + dy*dy);

  };

  //create a point halfway between 2 other points
  Point halfway(Point q){
    Point half((q.x-x)/2.0,(q.y-y)/2.0);
      return half;

  }

  //scale an object with a overloaded operator (replaces te scale function)
  //input a float that the point's x and y coordinates will be multiplied by
  Point operator*(float f){
    //return the scaled point
    return Point(x*f,y*f);

  }

  //adds two points together (replaces the add function)
  //overload star operator to return a point when multipling two point objects
  Point operator+(Point q){
    //*this gets the member value of the object using the method
    Point sumPoint((*this).x+q.x,(*this).y+q.y);
    //return the sum point
    return sumPoint;

  }
  
  //return a point as a string
  string as_string(){
    stringstream ss;
    ss<<"("<<x<<","<<y<<")";
    return ss.str();
  };
  
 };


int main(){
 Point p1(1.0,1.0);
 //p1 as a string
 string p1Str = p1.as_string();
 //print out point 2 as a string
 cout<<"Point 1 : "<<p1Str<<'\n';

 Point p2(3.9,1.8);
 //point 2 as a string
string p2Str = p2.as_string();
//print out point 2 as a string
 cout<<"Point 2: "<<p2Str<<'\n'; 

 //angle of point 1 on a graph using .angle() method
 float pAngle = p1.angle();

 //use the .distance_to_origin() method to get and print out p1's distance to the origin
 float d =
 p1.distance_to_origin();
 cout << "Point one's distance from the origin: "<<d<<'\n';

 //distance between p1 and p2
 float dist = p1.distance(p2);
 cout<<"Distance between two points: "<<dist<<endl;

 //point between p1 and p2
 Point h = p1.halfway(p2);

 //point h as a string

 string hStr = h.as_string();
 






 cout<<"The point halfway between those points: "<<hStr<<'\n';

 

 //make a point that's the product of another point and a float using your overloaded '*' operator
 Point p3 = p1*(2.0);

 //render p3 as a string
 string p3Str = p3.as_string();
 
 cout<<"Point 3, point 1 multiplied by 2: "<<p3Str<<'\n';
 
 //make a point that's the sum of other points using your overloaded '+" operator
 Point p4 = p1+p2;

 //render it as a string
 string p4Str = p4.as_string();

 cout<<"Point 4, the sum of points 1 and 2: "<<p4Str<<endl;

 
}
