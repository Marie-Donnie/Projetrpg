#ifndef OBJET_HPP
#define OBJET_HPP

#include <string>
#include <iostream>

class Personnage;

using namespace std;

class Objet {
protected :
  string _nom;
  string _description;

public:
  //Constructeurs
  Objet(string nom, string des);
  Objet();
  //Getters
  virtual string getNom();
  virtual string getDescription();
  //Setters
  virtual void setNom(string nom);
  virtual void setDescription(string des);
  //Autres méthodes
  virtual void afficher();
  virtual void utiliser(Personnage& p);

};

#endif //OBJET_HPP
