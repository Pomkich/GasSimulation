#pragma once
#include <SFML/Graphics.hpp>


class Molecule {
private:
	sf::CircleShape shape;
	sf::Vector2f velocity;	// value - pixels in second

public:
	Molecule();
	Molecule(int p_x, int p_y, int radius, double vel_x, double vel_y);

	void update(double& dt_time);
	void setVelocity(sf::Vector2f vel);
	sf::CircleShape& getShape();
	void setPos(sf::Vector2f pos);
	sf::Vector2f getPos();
	sf::Vector2f getVelocity();
	float getRadius();
};