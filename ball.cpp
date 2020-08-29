#include "ball.h"
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<SFML/Graphics.hpp>

ball::ball(float xi, float yi)
{
	position.x = xi;
	position.y = yi;
	circ.setRadius(10.00f);
	circ.setPosition(position);
	circ.setFillColor(sf::Color::Black);
}
sf::CircleShape ball::getshape()
{
	return circ;
}
void ball::reboundsides()
{
	xvel = -xvel;
}
void ball::reboundbatortop()
{
	yvel = -yvel;
}
float ball::currentposx()
{
	return position.x;
}
float ball::currentposy()
{
	return position.y;
}
void ball::speed()
{
	if (xvel >= 0)xvel += 0.2f;
	else xvel -= 0.2f;
	if (yvel >= 0)yvel += 0.2f;
	else yvel -= 0.2f;
}
void ball::speeds()
{
	if (xvel >= 0)xvel -= 0.2f;
	else xvel += 0.2f;
	if (yvel >= 0)yvel -= 0.2f;
	else yvel += 0.2f;
}
void ball::update()
{
	position.x += xvel;
	position.y += yvel;
	circ.setPosition(position);
}