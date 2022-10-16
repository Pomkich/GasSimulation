#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include "Molecule.h"
#include <iostream>

class Renderer {
private:
	sf::RenderWindow window;
	std::vector<Molecule> gas;
	sf::Clock clock;
	
	void update(double dt_time);
	void checkCollisions();
	//void resolveCollision();
public:
	Renderer(int width, int heigth);
	void addMolecule(Molecule new_mol);
	void run();
};