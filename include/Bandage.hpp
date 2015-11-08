#include <string>
#include <iostream>
#include "Objet.hpp"

#ifndef BANDAGE_HPP
#define BANDAGE_HPP

using namespace std;

class Bandage : public Objet{
private:
  string _nom;
  string _description;

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
