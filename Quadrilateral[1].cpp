//Name: Lauren Gregory
//Assignment: Lab10Out
//Description: ....
#include <iostream>
#include "Quadrilateral.h"
#include "graph1.h"
#include <cmath>

Quadrilateral::Quadrilateral()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);
}

Quadrilateral::Quadrilateral(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->d.setPoint(d.getX(), d.getY());
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}

void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
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

	//Set x for point d
	if (d.getX() < 0)
		this->d.setPoint(0, d.getY());
	else if (d.getX() > 639)
		this->d.setPoint(639, d.getY());
	else
		this->d.setPoint(d.getX(), d.getY());
	//Set y for point d
	if (d.getY() < 0)
		this->d.setPoint(this->d.getX(), 0);
	else if (d.getY() > 399)
		this->d.setPoint(this->d.getX(), 399);
	else
		this->d.setPoint(this->d.getX(), d.getY());
}

double Quadrilateral::getPerimeter()
{
	double perimeter = 0;

	perimeter = sqrt(pow((b.getX() - a.getX()), 2) + pow((b.getY() - a.getY()), 2));
	perimeter+= sqrt(pow((c.getX() - b.getX()), 2) + pow((c.getY() - b.getY()), 2));
	perimeter+= sqrt(pow((c.getX() - d.getX()), 2) + pow((c.getY() - d.getY()), 2));
	perimeter+= sqrt(pow((d.getX() - a.getX()), 2) + pow((d.getY() - a.getY()), 2));

	return perimeter;
}

void Quadrilateral::print()
{
	gout << setPos(0, 400) << ::setColor(0, 255, 0) << "-------------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << ::setColor(0, 255, 0) << "Shape Info Follows For: Quadrilateral" << endg;
	gout << setPos(200, 420) << ::setColor(0, 255, 0) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << ::setColor(0, 255, 0) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << ::setColor(0, 255, 0) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << ::setColor(0, 255, 0) << "Point d: (" << d.getX() << "," << d.getY() << ")" << endg;
	gout << setPos(200, 480) << ::setColor(0, 255, 0) << "Perimeter: " << Quadrilateral::getPerimeter() << endg;
}

void Quadrilateral::draw()
{
	int obj_no[4] = {};
	obj_no[0] = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 1);
	obj_no[1] = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 1);
	obj_no[2] = drawLine(c.getX(), c.getY(), d.getX(), d.getY(), 1);
	obj_no[3] = drawLine(d.getX(), d.getY(), a.getX(), a.getY(), 1);
	for (int i = 0; i < 4; i++)
	{
		::setColor(obj_no[i], color.getRed(), color.getGreen(), color.getBlue());
	}
}
