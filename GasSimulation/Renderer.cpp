#include "Renderer.h"

Renderer::Renderer(int width, int heigth) {
    window.create(sf::VideoMode(width, heigth), "SFML works!");
    // adding walls with setting size
    walls.push_back(sf::RectangleShape(sf::Vector2f(wall_size, screen_heigth)));
    walls.push_back(sf::RectangleShape(sf::Vector2f(screen_width, wall_size)));
    walls.push_back(sf::RectangleShape(sf::Vector2f(wall_size, screen_heigth)));
    walls.push_back(sf::RectangleShape(sf::Vector2f(screen_width, screen_heigth)));

    // setup position of walls
    walls[(int)side::left].setPosition(sf::Vector2f(0, 0));
    walls[(int)side::up].setPosition(sf::Vector2f(0, 0));
    walls[(int)side::rigth].setPosition(sf::Vector2f(screen_width - wall_size, 0));
    walls[(int)side::bottom].setPosition(sf::Vector2f(0, screen_heigth - wall_size));

    // setup color
    for (auto& wall : walls)
        wall.setFillColor(sf::Color::Red);
}

void Renderer::update(double dt_time) {
    for (auto& molecule : gas) {
        molecule.update(dt_time);
    }
}

void Renderer::checkCollisions() {
    // check collisions with walls
    for (auto& molecule : gas) {
        if (molecule.getPos().x < walls[(int)side::left].getSize().x || 
            ((molecule.getPos().x + molecule.getRadius() * 2) > walls[(int)side::rigth].getPosition().x)) {
            molecule.setVelocity(   // just reflect from wall in opposite direction
                sf::Vector2f(-molecule.getVelocity().x, molecule.getVelocity().y)
            );
        }
        else if (molecule.getPos().y < walls[(int)side::up].getSize().y || 
            ((molecule.getPos().y + molecule.getRadius() * 2) > walls[(int)side::bottom].getPosition().y)) {
            molecule.setVelocity(
                sf::Vector2f(molecule.getVelocity().x, -molecule.getVelocity().y)
            );
        }
    }

    // check collisions between molecules
    for (int i = 0; i < gas.size(); i++) {
        for (int j = i + 1; j < gas.size(); j++) {
            auto& fir_mol = gas[i];
            auto& sec_mol = gas[j];

            // center of molecule
            sf::Vector2f c_mol1 = sf::Vector2f(
                fir_mol.getPos().x + fir_mol.getRadius(),
                fir_mol.getPos().y + fir_mol.getRadius()
            );

            sf::Vector2f c_mol2 = sf::Vector2f(
                sec_mol.getPos().x + sec_mol.getRadius(),
                sec_mol.getPos().y + sec_mol.getRadius()
            );


            double catet1 = std::abs(c_mol2.x - c_mol1.x);
            double catet2 = std::abs(c_mol2.y - c_mol1.y);
            if ((std::sqrt(catet1 * catet1 + catet2 * catet2)) < 
                (fir_mol.getRadius() + sec_mol.getRadius())) {
                resolveCollision(fir_mol, sec_mol);
            }
        }
    }
}

void Renderer::resolveCollision(Molecule& mol1, Molecule& mol2) {
    sf::Vector2f mol1_vel = mol1.getVelocity();
    sf::Vector2f mol2_vel = mol2.getVelocity();
    auto mass_mol1 = mol1.getRadius();
    auto mass_mol2 = mol2.getRadius();

    sf::Vector2f new_vel_m1 = sf::Vector2f(
        ((mass_mol1 - mass_mol2) * mol1_vel.x + 2 * mass_mol2 * mol2_vel.x) / (mass_mol1 + mass_mol2),  // x axis
        ((mass_mol1 - mass_mol2) * mol1_vel.y + 2 * mass_mol2 * mol2_vel.y) / (mass_mol1 + mass_mol2)   // y axis
    );

    sf::Vector2f new_vel_m2 = sf::Vector2f(
        ((mass_mol2 - mass_mol1) * mol2_vel.x + 2 * mass_mol1 * mol1_vel.x) / (mass_mol1 + mass_mol2),  // x axis
        ((mass_mol2 - mass_mol1) * mol2_vel.y + 2 * mass_mol1 * mol1_vel.y) / (mass_mol1 + mass_mol2)   // y axis
    );

    mol1.setVelocity(new_vel_m1);
    mol2.setVelocity(new_vel_m2);

    // setup new color
    sf::Color col(rand() % 255, rand() % 255, rand() % 255, 255);
    mol1.setColor(col);
    mol2.setColor(col);
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
        for (auto& wall : walls) {
            window.draw(wall);
        }
        window.display();
    }
}
