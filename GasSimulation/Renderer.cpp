#include "Renderer.h"

Renderer::Renderer(int width, int heigth) {
    window.create(sf::VideoMode(width, heigth), "SFML works!");
}

void Renderer::update(double dt_time) {
    for (auto& molecule : gas) {
        molecule.update(dt_time);
    }
}

void Renderer::checkCollisions() {
    for (int i = 0; i < gas.size(); i++) {
        for (int j = i + 1; j < gas.size(); j++) {
            auto& fir_mol = gas[i];
            auto& sec_mol = gas[j];

            sf::Vector2f c_mol1 = sf::Vector2f(
                fir_mol.getPos().x + fir_mol.getRadius(),
                fir_mol.getPos().y + fir_mol.getRadius());

            sf::Vector2f c_mol2 = sf::Vector2f(
                sec_mol.getPos().x + sec_mol.getRadius(),
                sec_mol.getPos().y + sec_mol.getRadius());


            double catet1 = std::abs(c_mol2.x - c_mol1.x);
            double catet2 = std::abs(c_mol2.y - c_mol1.y);
            if ((std::sqrt(catet1 * catet1 + catet2 * catet2)) < 
                (fir_mol.getRadius() + sec_mol.getRadius())) {
                std::cout << "collision occured" << std::endl;
            }
        }
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
        checkCollisions();
        clock.restart();

        // render
        window.clear();
        for (auto& molecule : gas) {
            window.draw(molecule.getShape());
        }
        window.display();
    }
}
