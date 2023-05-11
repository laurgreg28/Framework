//Name: Lauren Gregory
//Assignment: Lab10Out
//Description: ....

#include "Circle.h"
#include <cmath>
#include "graph1.h"
#include <iostream>

const double Circle::PI = 3.1415926;

Circle::Circle()
{
	radius = 0;
	center.setPoint(0, 0);
}

Circle::Circle(GenPoint center, int radius, Color c)
{
	this->center.setPoint(center.getX(), center.getY());
	this->radius = radius;
	color.setColor(c.getRed(), c.getGreen(), c.getBlue());
}

void Circle::setCenter(GenPoint center)
{
	this->center.setPoint(center.getX(), center.getY());
}

void Circle::setRadius(int radius)
{
	this->radius = radius;
}

double Circle::getPerimeter()
{
	double perimeter = 0.0;

	perimeter = 2 * PI * radius;

	return perimeter;
}

double Circle::getArea()
{
	double area = 0.0;

	area = PI * pow(radius, 2);

	return area;
}

void Circle::print()
{
	gout << setPos(0, 400) << ::setColor(0, 255, 0) << "-------------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << ::setColor(0, 255, 0) << "Shape Info Follows For: Circle" << endg;
	gout << setPos(200, 420) << ::setColor(0, 255, 0) << "Center Point: (" << center.getX() << "," << center.getY() << ")" << endg;
	gout << setPos(200, 435) << ::setColor(0, 255, 0) << "Radius: " << radius << endg;
	gout << setPos(200, 450) << ::setColor(0, 255, 0) << "Perimeter: " << Circle::getPerimeter() << " Area: " << Circle::getArea() << endg;
}
void Circle::draw()
{
	int obj_no = drawCircle(radius, center.getX(), center.getY());
	::setColor(obj_no, color.getRed(), color.getGreen(), color.getBlue());
}
