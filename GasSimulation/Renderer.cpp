#include "Renderer.h"

Renderer::Renderer(int width, int heigth) {
    window.create(sf::VideoMode(width, heigth), "SFML works!");
}

void Renderer::update(double dt_time) {
    for (auto& molecule : gas) {
        molecule.update(dt_time);
    }
}

void Renderer::addMolecule(Molecule new_mol) {
    gas.push_back(new_mol);
}

void Renderer::run() {
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // updating simulation
        update(clock.getElapsedTime().asSeconds());
        clock.restart();

        // render
        window.clear();
        for (auto& molecule : gas) {
            window.draw(molecule.getShape());
        }
        window.display();
    }
}
