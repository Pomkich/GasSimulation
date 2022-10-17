#include "Molecule.h"

Molecule::Molecule() {
	shape.setRadius(5);
	shape.setPosition(0, 0);
	velocity.x = 0;
	velocity.y = 0;

	move_vector.setPosition(
		shape.getPosition().x + shape.getRadius(),
		shape.getPosition().y + shape.getRadius()
	);
	move_vector.setSize(sf::Vector2f(50, 1));
}

Molecule::Molecule(int p_x, int p_y, int radius, double vel_x, double vel_y) {
	shape.setFillColor(sf::Color::Green);
	shape.setRadius(radius);
	shape.setPosition(p_x, p_y);
	velocity.x = vel_x;
	velocity.y = vel_y;
	move_vector.setFillColor(sf::Color::Red);
	move_vector.setPosition(
		shape.getPosition().x + shape.getRadius(), 
		shape.getPosition().y + shape.getRadius()
	);
	move_vector.setSize(sf::Vector2f(50, 1));

	const int pi = 3.14;
	sf::Vector2f base_vector(1, 0);
	int angle = std::acos(
		(velocity.x * base_vector.x) /
		(base_vector.x * std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y)))
		* 180 / pi;
	if (velocity.y < 0) {
		move_vector.setRotation(-angle);
	}
	else move_vector.setRotation(angle);
}

void Molecule::update(double& dt_time) {
	shape.setPosition(
		shape.getPosition().x + (velocity.x * dt_time),
		shape.getPosition().y + (velocity.y * dt_time)
	);

	move_vector.setPosition(
		shape.getPosition().x + shape.getRadius(),
		shape.getPosition().y + shape.getRadius()
	);
}

void Molecule::updateMoveVector() {
	const int pi = 3.14;
	sf::Vector2f base_vector(1, 0);
	int angle = std::acos(
		(velocity.x * base_vector.x) / 
		(base_vector.x * std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y)))
		* 180 / pi;
	if (velocity.y < 0) {
		move_vector.setRotation(-angle);
	}
	else move_vector.setRotation(angle);
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

sf::RectangleShape& Molecule::getMoveVector() {
	return move_vector;
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