#include<iostream>
#include"bat.h"
#include"ball.h"
#include<math.h>
#include<vector>
#include<algorithm>
#include<SFML/Graphics.hpp>
int main()
{
	int life = 3;
	int score = 0;
	while (life)
	{
 		sf::RenderWindow Window(sf::VideoMode(1366,768), "Ping Pong", sf::Style::Close);
		bat Bat(1366/2, 700);
		ball Ball(1366/2 + 65, 700-20/*0,0*/);
		score -= 10;
		sf::Text LIFE;
		LIFE.setString("LIVES: " + std::to_string(life));
		sf::Font font;
		font.loadFromFile("Dustfine.otf");
		LIFE.setFont(font);
		LIFE.setCharacterSize(50);
		sf::Text SCORE;
		SCORE.setFont(font);
		SCORE.setCharacterSize(50);
		LIFE.setPosition(20, 100);
		SCORE.setPosition(400, 100);
		sf::Text Warning;
		Warning.setFont(font);
		Warning.setCharacterSize(40);
		Warning.setPosition(300, 40);
		Warning.setFillColor(sf::Color::Black);
		Warning.setString("Press F OR S to adjust ball speed--Press ESC to Exit!");
		while (Window.isOpen())
		{
			sf::Event Event;
			while (Window.pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					life = 0;
					Window.close();
				}
				if (Event.type == sf::Event::KeyPressed)
				{
					if (Event.key.code == sf::Keyboard::Right)
					{
						if (Bat.currentposx() < 1366 - 150)
							Bat.MoveRight();
					}
					if (Event.key.code == sf::Keyboard::Left)
					{
						if (Bat.currentposx() > 0)
							Bat.MoveLeft();
					}
					if (Event.key.code == sf::Keyboard::Escape)
					{
						life = 0;
						Window.close();
					}
					if (Event.key.code == sf::Keyboard::F)
					{
						Ball.speed();
					}
					if (Event.key.code == sf::Keyboard::S)
					{
						Ball.speeds();
					}
				}
			}


			if (Ball.currentposx() - 20 >= Bat.currentposx()-10 && Ball.currentposx() <= Bat.currentposx() + 150 + 10 && Ball.currentposy() + 20 >= 700 && Ball.currentposy() + 20 <= 700.2)
			{
				score += 10;
				Ball.reboundbatortop();
				SCORE.setString("SCORE: " + std::to_string(score));
			}
			if (Ball.currentposy() <= 0)
			{
				Ball.reboundbatortop();
			}
			if (Ball.currentposx() <= 0)
			{
				Ball.reboundsides();
			}
			if (Ball.currentposx() >= 1366-20)
			{
				Ball.reboundsides();
			}
			if (Ball.currentposy() + 20 > 720.2)
			{
				life--;
				Window.close();
			}

			Window.display();
			Window.clear(sf::Color::Cyan);
			Window.draw(Bat.getShape());
			Window.draw(Ball.getshape());
			Window.draw(LIFE);
			Window.draw(SCORE);
			Window.draw(Warning);
			Bat.update();
			Ball.update();
		}

	}
	return 0;
}