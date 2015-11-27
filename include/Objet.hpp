  /**
   * @name  Constructeur complet
   * @brief Créé un objet avec son nom et sa description
   * @param nom le nom de l'objet
   * @param des sa description
   * @return Un objet
   */

  /**
   * @name  afficher
   * @brief Affiche l'objet
   */

  /**
   * @name  utiliser
   * @brief Utilise l'objet sur un personnage
   * @param p la référence vers le personnage
   */

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

};

#endif //OBJET_HPP
