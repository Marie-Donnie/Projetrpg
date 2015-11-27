  /**
   * @name  utiliser
   * @brief Ajoute trois bandages à l'inventaire du personnage passé
   * en paramère, en déchirant le drap
   * @param p le personnage à qui on veut ajouter des bandages
   */

  /**
   * @name  afficher
   * @brief Affiche le nom et la description de l'objet
   */


//include guard
#ifndef DRAP_HPP
#define DRAP_HPP

//included dependencies
#include <string>
#include <iostream>
#include "Objet.hpp"

using namespace std;

class Drap : public Objet{

public:
  //Constructeurs
  Drap(string nom, string des);
  Drap();
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

#endif //DRAP_HPP
