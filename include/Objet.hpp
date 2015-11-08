#include <string>
#include <iostream>
#include "Personnage.hpp"

#ifndef OBJET_HPP
#define OBJET_HPP

using namespace std;

class Objet {
private :
  string _nom;
  string _description;

public:
  //Constructeurs
  Objet(string nom, string des);
  //Getters
  virtual string getNom();
  virtual string getDescription();
  //Setters
  virtual void setNom(string nom);
  virtual void setDescription(string des);
  //Autres méthodes
  virtual void afficher();
  virtual void utiliser(Personnage p);

};

#endif //OBJET_HPP
