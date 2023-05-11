//Name: Lauren Gregory
//Assignment: Lab10Out
//Description: ....

#include "Shape.h"

Shape::Shape()
{
	color.setColor(0, 0, 0);
}

void Shape::setColor(Color color)
{
	this->color = color;
}

Color Shape::getColor()
{
	return color;
}
