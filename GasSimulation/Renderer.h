#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include "Molecule.h"
#include "Constants.h"
#include <iostream>

class Renderer {
private:
	sf::RenderWindow window;
	std::vector<Molecule> gas;	// first moved by mouse
	std::vector<sf::RectangleShape> walls;
	sf::Clock clock;
	
	void update(double dt_time);
	void checkCollisions();
	void resolveCollision(Molecule& mol1, Molecule& mol2);
public:
	Renderer(int width, int heigth);
	void addMolecule(Molecule new_mol);
	void run();
};