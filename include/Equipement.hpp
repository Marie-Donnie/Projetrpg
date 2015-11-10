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

  //Autres méthodes
  Armure changerArmure(Armure& a, int loca);
  Armure changerArmure(Armure& a);
  Arme changerArme(Arme& a);

  void afficher();
};

#endif //EQUIPEMENT_HPP
