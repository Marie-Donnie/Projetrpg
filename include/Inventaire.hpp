/**
 * @file  Inventaire.hpp
 * @Author Marie Delavergne, Robin Wibaux
 * @date   November, 2015
 * @brief  Définit la classe Inventaire
 */


  /**
   * @name  Constructeur complet
   * @brief Créé un inventaire prenant les paramètres donnés.
   * @param armures une référence vers le vecteur d'Armure qu'on veut affecter
   * @param armes une référence vers le vecteur d'Arme qu'on veut affecter
   * @param objets une référence vers le vecteur boost (polymorphique)
   * d'Objets qu'on veut affecter
   * @return Un inventaire déterminé
   */

  /**
   * @name  Constructeur spécial
   * @brief Créé un inventaire prenant une chaîne de caractère qui
   * détermine la façon de construire l'inventaire
   * @param nom le nom de la case qui contient l'inventaire
   * d'Objets qu'on veut affecter
   * @return Un inventaire déterminé
   * Pour l'armoire, on créé un inventaire aléatoire qui peut contenir
   * 1 à 2 armes/armures
   * Pour le lit, un inventaire qui contient un drap
   * Pour l'armoire spé, l'inventaire qui pourra être utile au début
   * pour le personnage
   */

  /**
   * @name  trouverObjet
   * @brief Permet de trouver un objet par son nom
   * @param nom le nom en question
   * @return Un entier qui peut servir pour la localisation
   */

  /**
   * @name  estVide
   * @brief Vérifie si un inventaire est vide ou non
   * @return un booléen : 1 s'il est vide, 0 sinon
   */

  /**
   * @name    prendreArmure
   * @brief   Retourne une copie de l'armure à l'indice loca, et
   * supprime l'armure à l'indice loca.
   *
   * Ici, on est obligés de retourner une copie de l'armure, et non pas
   * une référence, car erase détruit aussi l'élément, et ne le supprime
   * pas seulement du vector.
   * @param  loca l'index de l'élément qu'on veut récupérer
   * @return Une copie de l'élément qu'on veut récupérer
   */

  /**
   * @name    prendreArme
   * @brief   Retourne une copie de l'arme à l'indice loca, et
   * supprime l'arme à l'indice loca.
   * Mêmes raisons que pour prendre Armure
   * @param  loca l'index de l'élément qu'on veut récupérer
   * @return Une copie de l'élément qu'on veut récupérer
   */

  /**
   * @name    prendreObjet
   * @brief   Retourne une copie de l'objet à l'indice loca, et
   * supprime l'objet à l'indice loca.
   * Voir prendreArmure
   * @param  loca l'index de l'élément qu'on veut récupérer
   * @return Une copie de l'élément qu'on veut récupérer
   */

  /**
   * @name    afficher
   * @brief   Permet d'afficher en détails l'inventaire
   */

  /**
   * @name    afficherC
   * @brief   Permet d'afficher l'inventaire, uniquement par les noms
   */

  /**
   * @name    afficherArmures
   * @brief   Permet d'afficher en détails les armures de l'inventaire
   */

  /**
   * @name    afficherArmes
   * @brief   Permet d'afficher en détails les armes de l'inventaire
   */

  /**
   * @name    afficherObjets
   * @brief   Permet d'afficher en détails les objets de l'inventaire
   */

//include guard
#ifndef INVENTAIRE_HPP
#define INVENTAIRE_HPP

//included dependencies
#include <string>
#include <vector>
#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>
#include "Armure.hpp"
#include "Arme.hpp"
#include "Objet.hpp"


using namespace std;

class Inventaire {
private :
  vector<Armure> _armures;
  vector<Arme> _armes;
  boost::ptr_vector<Objet> _objets;

public :
  //Constructeur
  Inventaire();
  Inventaire(vector<Armure>& armures, vector<Arme>& armes, boost::ptr_vector<Objet>& objets);
  Inventaire(string nom);
  //Getters
  vector<Armure>& getArmures();
  Armure& getArmure(int loca);
  vector<Arme>& getArmes();
  Arme& getArme(int loca);
boost::ptr_vector<Objet>& getObjets();
  Objet& getObjet(int loca);
  int trouverObjet(string nom);
  //Setters
  void setArmures(vector<Armure>& armures);
  void setArmure(Armure& armure, int loca);
  void setArmes(vector<Arme>& armes);
  void setArme(Arme& arme, int loca);
void setObjets(boost::ptr_vector<Objet>& objets);
  void ajouterArmure(Armure& armure);
  void retirerArmure(int loca);
  void ajouterArme(Arme& arme);
  void retirerArme(int loca);
  void ajouterObjet(Objet* objet);
  void retirerObjet(int loca);
  void ajouter(Armure& armure);
  void ajouter(Arme& arme);
  void ajouter(Objet* objet);

  //Autres méthodes
  bool estVide();
  Armure prendreArmure(int loca);
  Arme prendreArme(int loca);
  Objet prendreObjet(int loca);
  void utiliserObjet(Personnage& p, int loca);
  void afficher();
  void afficherC();
  void afficherArmures();
  void afficherArmes();
  void afficherObjets();
};

#endif //INVENTAIRE_HPP
