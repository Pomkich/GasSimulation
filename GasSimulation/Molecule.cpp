#include "Molecule.h"

Molecule::Molecule() {
	shape.setRadius(5);
	shape.setPosition(0, 0);
	velocity.x = 0;
	velocity.y = 0;
}

Molecule::Molecule(int p_x, int p_y, int radius, double vel_x, double vel_y) {
	shape.setRadius(radius);
	shape.setPosition(p_x, p_y);
	velocity.x = vel_x;
	velocity.y = vel_y;
}

void Molecule::update() {
	shape.setPosition(
		shape.getPosition().x + velocity.x,
		shape.getPosition().x + velocity.y);
}

void Molecule::setVelocity(sf::Vector2f vel) {
	velocity = vel;
}

sf::CircleShape& Molecule::getShape() {
	return shape;
}