//include guard
#ifndef BANDAGE_HPP
#define BANDAGE_HPP

//included dependencies
#include <string>
#include <iostream>
#include "Objet.hpp"

using namespace std;

class Bandage : public Objet{

public:
  //Constructeurs
  Bandage(string nom, string des);
  Bandage();
  //Getters
  string getNom();
  string getDescription();
  //Setters
  void setNom(string nom);
  void setDescription(string des);
  //Autres méthodes
  void afficher();
  void utiliser(Personnage& p);

};

#endif //BANDAGE_HPP
