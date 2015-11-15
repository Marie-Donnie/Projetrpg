//include guard
#ifndef OBJET_HPP
#define OBJET_HPP

// forward declared dependencies
class Personnage;

//included dependencies
#include <string>
#include <iostream>

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
  virtual void utiliser(Personnage& p, int membre);

};

#endif //OBJET_HPP
