#pragma once
#include <SFML/Graphics.hpp>

class ball {
	public:
		ball(float xi, float yi);
		sf::Vector2f position;
		sf::CircleShape getshape();
		void reboundsides();
		void reboundbatortop();
		void update();
		float currentposx();
		float currentposy();
		float xvel = 0.6f;
		float yvel = 0.6f;
		void speed();
		void speeds();
	private:
		sf::CircleShape circ;
		

		
};