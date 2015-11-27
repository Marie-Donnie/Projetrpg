#include "Membre.hpp"
#include "Observer.hpp"
#include "PNJ.hpp"

using namespace std;

//Traiter est une "pure virtual method"
void Observer::traiter(Membre& m, int pv){}

void Observer::passer(Membre& m){
}

void Observer::personnageMort(){}
void Observer::pnjMort(PNJ& p){}
