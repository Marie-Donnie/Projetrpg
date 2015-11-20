#include "Membre.hpp"
#include "Observer.hpp"

using namespace std;

//Traiter est une pure virtual method
void Observer::traiter(Membre& m, int pv){}


void Observer::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, m.getPv());
}
