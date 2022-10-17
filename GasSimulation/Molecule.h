#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Molecule {
private:
	sf::CircleShape shape;
	sf::Vector2f velocity;	// value - pixels in second
	sf::RectangleShape move_vector;

public:
	Molecule();
	Molecule(int p_x, int p_y, int radius, double vel_x, double vel_y);

	void update(double& dt_time);
	void updateMoveVector();
	void setVelocity(sf::Vector2f vel);
	void setPos(sf::Vector2f pos);
	void setColor(sf::Color col);

	sf::CircleShape& getShape();
	sf::RectangleShape& getMoveVector();
	sf::Vector2f getPos();
	sf::Vector2f getVelocity();
	float getRadius();
};