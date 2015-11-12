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
   * @return Un personnage tout prêt !
   */


#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Stat.hpp"
#include "Corps.hpp"
#include "Equipement.hpp"
#include "Inventaire.hpp"

using namespace std;

class Personnage {
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


public :
  //Constructeurs
  Personnage(string nom, int sexe, int age, double taille, double poids, int niveau, Stat stats, Corps corps, Inventaire inventaire, Equipement equipement);
  Personnage(string nom, int sexe, int age, double taille, double poids, int niveau);
  Personnage();
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
  //Autres méthodes
  void afficher();
  void defendre(Personnage& attaquant);
  void attaquer(Personnage& defendant);
};

#endif //PERSONNAGE_HPP
