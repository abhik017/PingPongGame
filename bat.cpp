#include "bat.h"
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<SFML/Graphics.hpp>

bat::bat(float xi, float yi)
{
	position.x = xi;
	position.y = yi;
	rect.setSize(sf::Vector2f(150.00, 20.00));
	rect.setPosition(position);
	rect.setFillColor(sf::Color::Black);
}

sf::RectangleShape bat::getShape()
{
	return rect;
}

void bat::update()
{
	rect.setPosition(position);
}
float bat::currentposx()
{
	return position.x;
}
float bat::currentposy()
{
	return position.y;
}
void bat::MoveRight()
{
	position.x += 15.0;
}
void bat::MoveLeft()
{
	position.x -= 15.0;
}
