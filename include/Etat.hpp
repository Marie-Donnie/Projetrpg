//include guard
#ifndef ETAT_HPP
#define ETAT_HPP

class Interface;
class Case;
class Membre;

//included dependencies
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "Observer.hpp"


using namespace std;


class Etat : public Observer{
protected:
  Interface* interface;
public:
  virtual void affichage();
  virtual void retour();
  virtual void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
  void inventaire();

  void setInterface(Interface* inter);

     //Méthodes de l'observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  void traiter(Membre& m, int pv);
  void passer(Membre& m);
  void personnageMort();
  void pnjMort(PNJ& p);
};

#endif //ETAT_HPP
