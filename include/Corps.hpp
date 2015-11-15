//include guard
#ifndef CORPS_HPP
#define CORPS_HPP

//forward declared dependencies
class Membre;

//included dependencies
#include <string>
#include <vector>
#include "Observer.hpp"

using namespace std;

class Corps : public Observer{
private:
  vector<Membre> _corps;

public:
  Corps();

  //Getters
  vector<Membre>& getLMembres();
  int getPv();
  int getPvMax();

  //Setters
  void changerMembre(Membre m, int loca);

  //Méthodes de l'observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  void passer(Membre& m);
  void traiter(Membre& m);

  //Autres méthodes
  void soin(int membre);
  void afficher();


};

#endif // CORPS_HPP
