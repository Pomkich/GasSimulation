#include "Renderer.h"
#include <thread>
#include <ctime>
#include "Constants.h"

int main()
{
    srand(time(NULL));
    Renderer rend(screen_width, screen_heigth);
    int prev_x = wall_size + 10;
    int prev_y = wall_size + 10;
    int prev_rad = 0;
    // many magic variables but i dont care
    for (int i = 0; i < molecules_size / 10; i++) {
        int vel_x = rand() % max_velocity;
        int vel_y = rand() % max_velocity;
        for (int j = 0; j < 10; j++) {
            //int distance = prev_rad * 2 + 30;
            int radius = rand() % 10 + 5;
            int p_x = prev_x + 50;
            int p_y = prev_y;
            Molecule mol(p_x, p_y, radius, vel_x, vel_y);
            rend.addMolecule(mol);
            prev_x = p_x;
            prev_rad = radius;
        }
        prev_x = wall_size + 10;
        prev_y = prev_y + 50;
    }
    std::cout << "A button - add molecule" << std::endl;
    std::cout << "D button - delete last added molecule" << std::endl;

    rend.run();

    return 0;
}