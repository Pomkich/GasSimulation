#include "Renderer.h"

Renderer::Renderer(int width, int heigth) {
    window.create(sf::VideoMode(width, heigth), "SFML works!");
}

void Renderer::update() {
    for (auto& molecule : gas) {
        molecule.update();
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
        update();

        // render
        window.clear();
        for (auto& molecule : gas) {
            window.draw(molecule.getShape());
        }
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(64));
    }
}
