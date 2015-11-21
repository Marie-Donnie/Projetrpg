/**
 * @file  Inventaire.hpp
 * @Author Marie Delavergne, Robin Wibaux
 * @date   November, 2015
 * @brief  Définit la classe Inventaire
 *
 *
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
  Armure prendreArmure(int loca);
  Arme prendreArme(int loca);
  Objet prendreObjet(int loca);
  void utiliserObjet(Personnage& p, int loca);
  void afficher();
};

#endif //INVENTAIRE_HPP
