#include "Molecule.h"

Molecule::Molecule() {
	shape.setRadius(5);
	shape.setPosition(0, 0);
	velocity.x = 0;
	velocity.y = 0;
}

Molecule::Molecule(int p_x, int p_y, int radius, double vel_x, double vel_y) {
	shape.setFillColor(sf::Color::Green);
	shape.setRadius(radius);
	shape.setPosition(p_x, p_y);
	velocity.x = vel_x;
	velocity.y = vel_y;
}

void Molecule::update(double& dt_time) {
	shape.setPosition(
		shape.getPosition().x + (velocity.x * dt_time),
		shape.getPosition().y + (velocity.y * dt_time));
}

void Molecule::setVelocity(sf::Vector2f vel) {
	velocity = vel;
}

void Molecule::setPos(sf::Vector2f pos) {
	shape.setPosition(pos);
}

void Molecule::setColor(sf::Color col) {
	shape.setFillColor(col);
}

sf::CircleShape& Molecule::getShape() {
	return shape;
}

sf::Vector2f Molecule::getPos() {
	return shape.getPosition();
}

sf::Vector2f Molecule::getVelocity() {
	return velocity;
}

float Molecule::getRadius() {
	return shape.getRadius();
}