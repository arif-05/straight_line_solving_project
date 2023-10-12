#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<string>
#include <sstream>
#include <cmath>
using namespace std;


class line
{
    public:
    double v1,v2,v3;
};

struct line2 {
    double a, b, c;
};

double determin(double a, double b, double c, double d)
{
    return a*d-b*c;
}

bool concurrent(const line2& l1, const line2& l2, const line2& l3) {
    // Check if the determinant of the coefficients matrix is zero
    double determinant = l1.a * (l2.b * l3.c - l2.c * l3.b)
                       - l1.b * (l2.a * l3.c - l2.c * l3.a)
                       + l1.c * (l2.a * l3.b - l2.b * l3.a);

    return determinant == 0;
}


int menu(){
  system("cls");
    int op;

    cout << "        *****  OPTIONS  *****  " <<endl<<endl;
    cout << " 1. Cheak the quation either parallal to X-Y axis " << endl;
    cout << " 2. Slope of an straight line " << endl;
    cout << " 3. Intercept of X-Y axis " << endl;
    cout << " 4. Equation passing through the intersetion of two line " << endl;
    cout << " 5. Perpendicular distance of straight line" << endl;
    cout << " 6. Concurrency cheaking of three straight line " << endl;
    cout << " 7. Area of triangle formed by three lines" << endl;
    cout << " 8. Lines parallel " << endl;
    cout << " 9. Polar straight line " << endl;
    cout << " 0. Enter 0 to exit "<<endl;

    cout<<" Enter your option : ";
    
    cin >> op;
    
    // Clear the newline character from the input buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    return op;
}


int equation(){

  string eqn;
    
    
    cout << "Enter the equation (e.g., y = b or x = a): ";
    getline(cin, eqn);
    
    
    if (eqn.length() < 5) {
        cerr << "Invalid equation format. Please use 'y = constant' or 'x = constant' format." << endl;
        cout<<"Enter any key for options...";
        getch();
        return 1;
    }
    string lhs = eqn.substr(0, 2);
    string rhs = eqn.substr(4);
    
    // Check if it's parallel to x-axis or y-axis
    if (lhs == "y " && rhs != "") {
        cout << "The equation represents a line parallel to the x-axis." << endl;
    } else if (lhs == "x " && rhs != "") {
        cout << "The equation represents a line parallel to the y-axis." << endl;
    } else {
        cerr << "Invalid equation format. Please use 'y = constant' or 'x = constant' format." << endl;
        return 1;
    }
    system("pause");
};


int distance(){
 
    string equation;
    cout << "Enter a linear equation in the form ax + by + c = 0: ";
    getline(cin, equation);

    // Parse the equation to extract coefficients
    double a, b, c;
    istringstream equationStream(equation);

    // Extract coefficients from the equation
    equationStream >> a;
    char x; 
    equationStream >> x; 
    equationStream >> b;
    char y;
    equationStream >> y; 
    equationStream >> c;

    if (equationStream.fail() || equationStream.eof()) {
        cerr << "Invalid input format. Please enter a valid linear equation." << endl;
        return 1;
    }

    if (x != 'x' || y != 'y') {
        cerr << "Invalid variable. Please use 'x' and 'y' as variables in the equation." << endl;
        return 1;
    }

    // Check if the equation is of the form "ax + by + c = 0"
    if (equationStream.peek() != '=' || equationStream.get() != '=' || equationStream.peek() != '0') {
        cerr << "Invalid equation format. Please use the form 'ax + by + c = 0'." << endl;
        return 1;
    }
    
   
    cout << "Coefficient 'a' is: " << a << endl;
    cout << "Coefficient 'b' is: " << b << endl;
    cout << "Coefficient 'c' is: " << c << endl;

   
    double x0, y0;
    cout << "Enter the coordinates of the point (x0, y0): ";
    cin >> x0 >> y0;

    
    double distance = fabs(a * x0 + b * y0 + c) / sqrt(a * a + b * b);

    cout << "Distance from the point to the line is: " << distance <<" unit"<< endl;
    system("pause");
    return 0;
};


int concurrency(){

 line2 l1, l2, l3;
    string equation;

    cout << "Enter the equation for Line 1 (e.g., ax+by+c=0): ";
    getline(cin, equation);

    istringstream equationStream1(equation);
    equationStream1 >> l1.a;
    char x1;
    equationStream1 >> x1;
    equationStream1 >> l1.b;
    char y1;
    equationStream1 >> y1;
    equationStream1 >> l1.c;

    if (equationStream1.fail() || equationStream1.eof() || x1 != 'x' || y1 != 'y') {
        cerr << "Invalid input format for Line 1. Please enter a valid equation in the form ax + by + c = 0." << endl;
        return 1;
    }

    cout << "Enter the equation for Line 2 (e.g., ax+by+c=0): ";
    getline(cin, equation);

    istringstream equationStream2(equation);
    equationStream2 >> l2.a;
    char x2;
    equationStream2 >> x2;
    equationStream2 >> l2.b;
    char y2;
    equationStream2 >> y2;
    equationStream2 >> l2.c;

    if (equationStream2.fail() || equationStream2.eof() || x2 != 'x' || y2 != 'y') {
        cerr << "Invalid input format for Line 2. Please enter a valid equation in the form ax+by+c=0." << endl;
        return 1;
    }

    cout << "Enter the equation for Line 3 (e.g., ax+by+c=0): ";
    getline(cin, equation);

    istringstream equationStream3(equation);
    equationStream3 >> l3.a;
    char x3;
    equationStream3 >> x3;
    equationStream3 >> l3.b;
    char y3;
    equationStream3 >> y3;
    equationStream3 >> l3.c;

    if (equationStream3.fail() || equationStream3.eof() || x3 != 'x' || y3 != 'y') {
        cerr << "Invalid input format for Line 3. Please enter a valid equation in the form ax + by + c = 0." << endl;
        return 1;
    }

    if (concurrent(l1, l2, l3))
        cout << "The lines are concurrent" << endl;
    else
        cout << "The lines are not concurrent" << endl;

    system("pause");
    return 0;
};

int slope(){

string equation;
    double a, b, c;
    cout << "Enter the equation of the straight line (ax+by+c=0): ";
    getline(cin, equation);

    istringstream equationStream(equation);

    equationStream >> a;
    equationStream.ignore();  
    equationStream >> b;
    equationStream.ignore();  
    equationStream >> c;

    double slope = -a / b;
    cout << "The slope of the line is: " << slope << endl;
    system("pause");


};


void intercept(){
    string equation;
    double a, b, c;

    
    cout << "Enter the equation of the straight line (ax+by+c=0): ";
    getline(cin, equation);
    istringstream equationStream(equation);



    equationStream >> a;
    equationStream.ignore();  
    equationStream >> b;
    equationStream.ignore();  
    equationStream >> c;

    double m = -c/a;
    double n = -c/b;


    // Display the result
    cout<<"The intercept of X axis is = ("<<m<<",0)"<<endl;
    cout<<"The intercept of Y axis is = (0,"<<n<<")"<<endl;
    system("pause");


};

struct Line {
    double a, b, c;
};

struct Point {
    double x, y;
};

// Function to calculate the intersection point of two lines
Point calculateIntersection(const Line& line1, const Line& line2) {
    Point intersection;
    double determinant = line1.a * line2.b - line2.a * line1.b;

    if (determinant == 0) {
        cerr << "Lines are parallel. No intersection." << endl;
        exit(1);
    }

    intersection.x = (line2.c * line1.b - line1.c * line2.b) / determinant;
    intersection.y = (line1.c * line2.a - line2.c * line1.a) / determinant;

    return intersection;
}

// Function to calculate the distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void area(){

    Line lines[3];
    Point intersectionPoints[3];

    
    for (int i = 0; i < 3; ++i) {
        int c = i+1;
        cout << "Enter coefficients for line (a b c)" << (i+1) << ": ";
        cin >> lines[i].a >> lines[i].b >> lines[i].c;
    }

   
    for (int i = 0; i < 3; ++i) {
        int nextIndex = (i + 1) % 3;  
        intersectionPoints[i] = calculateIntersection(lines[i], lines[nextIndex]);
    }

   
    double sideLengths[3];
    for (int i = 0; i < 3; ++i) {
        int nextIndex = (i + 1) % 3;  
        sideLengths[i] = calculateDistance(intersectionPoints[i], intersectionPoints[nextIndex]);
    }

   
    double s = (sideLengths[0] + sideLengths[1] + sideLengths[2]) / 2;
    double area = sqrt(s * (s - sideLengths[0]) * (s - sideLengths[1]) * (s - sideLengths[2]));

    cout << "The area of the triangle formed by the three lines is: " << area << endl;
    system("pause");

};

void paralism(){

    Line line1, line2;

    
    cout << "Enter coefficients for the first line (a1 b1 c1): ";
    cin >> line1.a >> line1.b >> line1.c;

    cout << "Enter coefficients for the second line (a2 b2 c2): ";
    cin >> line2.a >> line2.b >> line2.c;

    
    if (line1.a * line2.b == line2.a * line1.b) {
        cout << "The two lines are parallel." << endl;
    } else {
        cout << "The two lines are not parallel." << endl;
    }
    system("pause");
   
};


void twoline(){

    Line line1, line2;
    Point intersection;

   
    cout << "Enter coefficients for the first line (a1 b1 c1): ";
    cin >> line1.a >> line1.b >> line1.c;

    
    cout << "Enter coefficients for the second line (a2 b2 c2): ";
    cin >> line2.a >> line2.b >> line2.c;

    // Calculate the intersection point of the two lines
    double determinant = line1.a * line2.b - line2.a * line1.b;

    if (determinant == 0) {
        cerr << "The two lines are parallel and do not intersect." << endl;
    
    }else{
    intersection.x = (line2.c * line1.b - line1.c * line2.b) / determinant;
    intersection.y = (line1.c * line2.a - line2.c * line1.a) / determinant;

    double slope = -line1.a / line1.b;  

    cout << "The intersection point is : (" << intersection.x << ", " << intersection.y << ")"<<endl;
    cout <<"The equation is : "<<"y = " << slope << "x + " << (intersection.y - slope * intersection.x) << endl;
    }

    system("pause");
};

struct PolarPoint {
    double r, theta;
};

struct CartesianPoint {
    double x, y;
};


void polar(){

    PolarPoint polar1, polar2;
    CartesianPoint cartesian1, cartesian2;

    cout << "Enter the first polar coordinates (r1, theta1): ";
    cin >> polar1.r >> polar1.theta;
    cout << "Enter the second polar coordinates (r2, theta2): ";
    cin >> polar2.r >> polar2.theta;
    cartesian1.x = polar1.r * cos(polar1.theta);
    cartesian1.y = polar1.r * sin(polar1.theta);

    cartesian2.x = polar2.r * cos(polar2.theta);
    cartesian2.y = polar2.r * sin(polar2.theta);
    double m = (cartesian2.y - cartesian1.y) / (cartesian2.x - cartesian1.x);

    
    double x1 = cartesian1.x;
    double y1 = cartesian1.y;

    double a = m;
    double b = -1;
    double c = y1 - m * x1;

    // Output the equation of the line in Cartesian form
    cout << "The equation of the line passing through the given points in Cartesian form is:" << endl;
    cout << a << "x + " << b << "y + " << c << " = 0" << endl;
    system("pause");

};

int main(){
    int op;
    
    for(;;){
      int a;
      op = menu();
      if(op==0)break;
      switch (op)
      {
      case 1 : equation();break;
      case 2 : slope();break;
      case 3 : intercept();break;
      case 4 : twoline();break;
      case 5 : distance();break;
      case 6 : concurrency();break;
      case 7 : area();break;
      case 8 : paralism();break;
      case 9 : polar();break;
      }

    }
    return 0;
}