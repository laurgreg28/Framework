//Name: Lauren Gregory
//Assignment: Lab10Out
//Description: ....

#include "Triangle.h"
#include <cmath>
#include "graph1.h"
#include <iostream>

Triangle::Triangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}

Triangle::Triangle(GenPoint a, GenPoint b, GenPoint c, Color color)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}

void Triangle::setPoints(GenPoint a, GenPoint b, GenPoint c)
{
	//Set x for point a
	if (a.getX() < 0)
		this->a.setPoint(0, a.getY());
	else if (a.getX() > 639)
		this->a.setPoint(639, a.getY());
	else
		this->a.setPoint(a.getX(), a.getY());
	//Set y for point a
	if (a.getY() < 0)
		this->a.setPoint(this->a.getX(), 0);
	else if (a.getY() > 399)
		this->a.setPoint(this->a.getX(), 399);
	else
		this->a.setPoint(this->a.getX(), a.getY());


	//Set x for point b
	if (b.getX() < 0)
		this->b.setPoint(0, b.getY());
	else if (b.getX() > 639)
		this->b.setPoint(639, b.getY());
	else
		this->b.setPoint(b.getX(), b.getY());
	//Set y for point b
	if (b.getY() < 0)
		this->b.setPoint(this->b.getX(), 0);
	else if (b.getY() > 399)
		this->b.setPoint(this->b.getX(), 399);
	else
		this->b.setPoint(this->b.getX(), b.getY());

	//Set x for point c
	if (c.getX() < 0)
		this->c.setPoint(0, c.getY());
	else if (c.getX() > 639)
		this->c.setPoint(639, c.getY());
	else
		this->c.setPoint(c.getX(), c.getY());
	//Set y for point c
	if (c.getY() < 0)
		this->c.setPoint(this->c.getX(), 0);
	else if (c.getY() > 399)
		this->c.setPoint(this->c.getX(), 399);
	else
		this->c.setPoint(this->c.getX(), c.getY());
}

double Triangle::getArea()
{
	double area = 0.0;
	double side1 = sqrt(pow((b.getX() - a.getX()), 2) + pow((b.getY() - a.getY()), 2));
	double side2 = sqrt(pow((c.getX() - b.getX()), 2) + pow((c.getY() - b.getY()), 2));
	double side3 = sqrt(pow((c.getX() - a.getX()), 2) + pow((c.getY() - a.getY()), 2));

	double s = (side1 + side2 + side3) / 2.0;

	area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

	return area;
}

double Triangle::getPerimeter()
{
	double perimeter = 0.0;

	perimeter = sqrt(pow((b.getX() - a.getX()), 2) + pow((b.getY() - a.getY()), 2));
	perimeter += sqrt(pow((c.getX() - b.getX()), 2) + pow((c.getY() - b.getY()), 2));
	perimeter += sqrt(pow((c.getX() - a.getX()), 2) + pow((c.getY() - a.getY()), 2));

	return perimeter;
}

void Triangle::print()
{
	gout << setPos(0, 400) << ::setColor(0, 255, 0) << "-------------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << ::setColor(0, 255, 0) << "Shape Info Follows For: Triangle" << endg;
	gout << setPos(200, 420) << ::setColor(0, 255, 0) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << ::setColor(0, 255, 0) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << ::setColor(0, 255, 0) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << ::setColor(0, 255, 0) << "Perimeter: " << Triangle::getPerimeter() << " Area: " << Triangle::getArea() << endg;
}

void Triangle::draw()
{
	int obj_no[3] = {};
	obj_no[0] = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 1);
	obj_no[1] = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 1);
	obj_no[2] = drawLine(c.getX(), c.getY(), a.getX(), a.getY(), 1);
	for (int i = 0; i < 3; i++)
	{
		::setColor(obj_no[i], color.getRed(), color.getGreen(), color.getBlue());
	}
}
