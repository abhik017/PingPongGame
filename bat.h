#pragma once
#include <SFML/Graphics.hpp>
class bat
{
public:
	bat(float xi,float yi);
	sf::Vector2f position;
	float currentposx();
	float currentposy();
	sf::RectangleShape getShape();
	void MoveRight();
	void MoveLeft();
	void update();
	
private:
	sf::RectangleShape rect;
};
