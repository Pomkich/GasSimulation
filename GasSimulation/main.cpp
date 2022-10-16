#include "Renderer.h"
#include <thread>

int main()
{
    Molecule mol1(400, 200, 10, 50, 0);
    //Molecule mol2(300, 200, 10, 50, -50);
    Molecule mol3(500, 300, 10, 0, -50);

    Renderer rend(800, 600);
    rend.addMolecule(mol1);
    //rend.addMolecule(mol2);
    rend.addMolecule(mol3);

    rend.run();

    return 0;
}