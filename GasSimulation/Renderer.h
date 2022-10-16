#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include "Molecule.h"

class Renderer {
private:
	sf::RenderWindow window;
	std::vector<Molecule> gas;
	
	void update();
public:
	Renderer(int width, int heigth);
	void addMolecule(Molecule new_mol);
	void run();
};