#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Shape {
protected:
 double radius;
public:
 Shape(double r = 0) {
 radius = r;
 }
};
class Circle : public Shape {
private:
 double area;
public:
 Circle(double r = 0) : Shape(r), area(0) {}
 void calculateArea() {
 area = M_PI * radius * radius;
 }
 void displayArea() const {
 cout << "Circle with radius " << radius << " has area: " << area << endl;
 }
};
int main() {
 int n;
 cout << "Enter the number of circles: ";
 cin >> n;
 cout << "\n=== STL Approach (using vector) ===" << endl;
  vector<Circle> circlesVector;
 for (int i = 0; i < n; ++i) {
 double r;
 cout << "Enter radius for circle " << i + 1 << ": ";
 cin >> r;
 Circle c(r);
 c.calculateArea();
 circlesVector.push_back(c);
 }
cout << "\nDisplaying areas using vector:" << endl;
 for (const auto& circle : circlesVector) {
 circle.displayArea();
 }
 cout << "\n=== Non-STL Approach (using array) ===" << endl;
 Circle* circlesArray = new Circle[n];
for (int i = 0; i < n; ++i) {
 double r;
 cout << "Enter radius for circle " << i + 1 << ": ";
 cin >> r;
 circlesArray[i] = Circle(r);
 circlesArray[i].calculateArea();
 }
 cout << "\nDisplaying areas using array:" << endl;
 for (int i = 0; i < n; ++i) {
 circlesArray[i].displayArea();
 }
delete[] circlesArray;
cout<<"24CE037_Yashvi";
 return 0;
}

