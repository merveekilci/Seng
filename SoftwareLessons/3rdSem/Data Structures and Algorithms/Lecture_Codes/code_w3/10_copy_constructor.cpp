#include<iostream>
using namespace std;
class Point
{
private:
	int x, y;
public:
	Point(int x1, int y1) { 
		x = x1; y = y1; 
	}
	
	// Copy constructor
	Point(const Point &p1) {
		x = p1.x; y = p1.y; 
	}
	void setX(int x) { this->x=x; }
	void setY(int y){ this->y=y; }
	int getX() { return x; }
	int getY() { return y; }
	
};
int main()
{
	Point p1(10, 15); //Constructor
	Point p2 = p1; // Copy constructor
	Point p3(p2);
	cout << "p1.getX() = " << p1.getX() << ", p1.getY() = " <<p1.getY()<<endl;
    cout << "p2.getX() = " << p2.getX() << ", p2.getY() = " <<p2.getY()<<endl;
    cout << "p3.getX() = " << p3.getX() << ", p3.getY() = " <<p3.getY()<<endl;
    cout<<"p1.setX(20);p1.setY(30);"<<endl;
	p1.setX(20);p1.setY(30);
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY()<<endl;
	cout << "p2.x = " << p2.getX() << ", p2.y = " <<p2.getY()<<endl;
	cout<<endl;	
return 0;
}
