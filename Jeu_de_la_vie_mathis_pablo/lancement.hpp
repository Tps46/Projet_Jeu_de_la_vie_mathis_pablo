#ifndef LANCEMENT_HPP
#define LANCEMENT_HPP

#include <iostream>
#include <cstdlib>

class lancement {
public:
    void leLancement();
    lancement();

private:
    int nombre_iteration;
    void lancementGraphique(int duree_iteration);
    void lancementConsole();
    void lancementTest_unitaire();
    void menu();
   
};

#endif