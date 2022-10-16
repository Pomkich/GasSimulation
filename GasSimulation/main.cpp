#include "Renderer.h"
#include <thread>
#include <ctime>
#include "Constants.h"

int main()
{
    srand(time(NULL));
    Renderer rend(screen_width, screen_heigth);
    for (int i = 0; i < molecules_size; i++) {
        int vel_x = rand() % max_velocity;
        int vel_y = rand() % max_velocity;
        Molecule mol1(
            (rand() % (int)(screen_width * 0.80)) + (int)(screen_width * 0.15), 
            (rand() % (int)(screen_heigth * 0.80)) + (int)(screen_heigth * 0.15), 
            10, vel_x, vel_y);
        rend.addMolecule(mol1);
    }

    rend.run();

    return 0;
}