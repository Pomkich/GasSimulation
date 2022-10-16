#pragma once
#include <SFML/Graphics.hpp>


class Molecule {
private:
	sf::CircleShape shape;
	sf::Vector2f velocity;

public:
	Molecule();
	Molecule(int p_x, int p_y, int radius, double vel_x, double vel_y);

	void update();
	void setVelocity(sf::Vector2f vel);
	sf::CircleShape& getShape();
};