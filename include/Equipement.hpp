#include <string>
#include <vector>
#include <iostream>
#include "Armure.hpp"

#ifndef EQUIPEMENT_HPP
#define EQUIPEMENT_HPP

using namespace std;

class Equipement{
private:
  vector<Armure> _armures;
  // Arme _arme;

public:
  Equipement();
  Equipement(string suff);
  Equipement(vector<Armure>& armor);
  //Getters
  vector<Armure>& getArmures();
  Armure& getArmure(int loca);
  //void getArme();

  //Setters
  //void ajouterArmure();
  void changerArmure(Armure& a, int loca);

  //Autres méthodes
  void afficher();
};

#endif //EQUIPEMENT_HPP
