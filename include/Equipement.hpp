#include <string>
#include <vector>
#include <iostream>
#include "Armure.hpp"
#include "Arme.hpp"

#ifndef EQUIPEMENT_HPP
#define EQUIPEMENT_HPP

using namespace std;

class Equipement{
private:
  vector<Armure> _armures;
  Arme _arme;

public:
  Equipement();
  Equipement(string suff);
  Equipement(vector<Armure>& armures, Arme& arme);
  //Getters
  vector<Armure>& getArmures();
  Armure& getArmure(int loca);
  Arme& getArme();

  //Setters
  void changerArmure(Armure& a, int loca);
  void changerArme(Arme& a);

  //Autres méthodes
  void afficher();
};

#endif //EQUIPEMENT_HPP
