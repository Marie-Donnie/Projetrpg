/**
 * @file Personnage.hpp
 * @author Marie Delavergne, Robin Wibaux
 * @date October, 2015
 * @brief Définition de la classe de personnage
 **/

  /**
   * @name  Constructeur complet
   * @brief Créé un personnage prenant les paramètres donnés.
   * @param nom le nom qu'on veut donner au personnage
   * @param sexe le sexe du personnage (0 pour homme et 1 pour femme)
   * @param age l'âge du personnage
   * @param taille sa taille (type 1.50, pour 1 mètre et 50 centimètres)
   * @param poids son poids (type 50.3)
   * @param niveau son niveau
   * @param stats les stats qu'on veut lui donner
   * @param corps le corps du personnage
   * @param inventaire l'inventaire qu'il aura
   * @param equipement l'équipement qu'il porte
   * @param texture la texture qu'on va lui appliquer
   * @return Un personnage tout prêt !
   */

  /**
   * @name  Constructeur partiel
   * @brief Créé un personnage prenant les paramètres donnés, ce
   * constructeur n'est actuellement pas utilisé
   * @param nom le nom qu'on veut donner au personnage
   * @param sexe le sexe du personnage (0 pour homme et 1 pour femme)
   * @param age l'âge du personnage
   * @param taille sa taille (type 1.50, pour 1 mètre et 50 centimètres)
   * @param poids son poids (type 50.3)
   * @param niveau son niveau
   * @return Un personnage tout prêt !
   */

  /**
   * @name  Constructeur partiel
   * @brief Créé un personnage prenant les paramètres donnés, des
   * valeurs par défaut (la texture, le bool deuxmains, ...) et des
   * valeurs aléatoires (age, poids, ...)
   * @param nom le nom qu'on veut donner au personnage
   * @param sexe le sexe du personnage (0 pour homme et 1 pour femme)
   * @return Un personnage tout prêt !
   */

  /**
   * @name  Constructeur par défaut
   * @brief Créé un personnage avec des valeurs aléatoires, sert
   * principalement pour les tests
   * @return Un personnage tout prêt !
   */

  /**
   * @name  personnageMort()
   * @brief Envoie à son suivant dans la chaîne d'observer le fait que
   * le personnage est mort
   */

  /**
   * @name  afficher
   * @brief Affichage par défaut du personnage, sert
   * principalement pour les tests
   */

  /**
   * @name  défendre
   * @brief Calculs des attaques faites par le pnj attaquant
   * @param attaquant la référence du pnj qui attaque
   */

  /**
   * @name  attaquer
   * @brief Lance la fonction défendre du pnj attaqué
   * @param defendant la référence vers le pnj attaqué
   */

  /**
   * @name  soin
   * @brief Lance le soin() du corps du personnage et fixe le nombre
   * de points de vie des stats
   */

  /**
   * @name  bandage
   * @brief Lance le bandage() du corps du personnage et fixe le nombre
   * de points de vie des stats
   */




//include guard
#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

//forward declarations
class PNJ;

//included dependencies
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Stat.hpp"
#include "Corps.hpp"
#include "Equipement.hpp"
#include "Inventaire.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Observer.hpp"
#include "Entite.hpp"

using namespace std;

class Personnage : public Observer, public Entite {
private :
  string _nom;
  int _sexe;
  int _age;
  double _taille;
  double _poids;
  int _niveau;
  Stat _stats;
  Corps _corps;
  Inventaire _inventaire;
  Equipement _equipement;
  bool _deuxmains;

public :
  //Constructeurs
  Personnage(string nom, int sexe, int age, double taille, double poids, int niveau, Stat stats, Corps corps, Inventaire inventaire, Equipement equipement, string texture);
  Personnage(string nom, int sexe, int age, double taille, double poids, int niveau);
  Personnage(string nom, int sexe);
  Personnage();

  //Recopie
  Personnage(const Personnage& lautre);
  //Assignement
  Personnage& operator=(const Personnage& lautre);

  //Getters
  string getNom();
  int getSexe();
  int getAge();
  double getTaille();
  double getPoids();
  int getNiveau();
  Stat& getStats();
  Corps& getCorps();
  Inventaire& getInventaire();
  Equipement& getEquipement();

  //Setters
  void setAge(int age);
  void setTaille(double taille);
  void setPoids(double poids);
  void setNiveau(int niveau);
  void levelUp();

  //Methodes de l'Observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  void traiter(Membre& m, int pv);
  void passer(Membre& m);
  void personnageMort();

  //Autres méthodes
  void afficher();
  void defendre(PNJ& attaquant);
  void attaquer(PNJ& defendant);
  void soin();
  void bandage();

  void action(sf::Time turnTime);
};

#endif //PERSONNAGE_HPP
