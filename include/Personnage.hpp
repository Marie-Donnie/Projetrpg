#include <string>
#include <iostream>
#include <stdlib.h>
#include "Stat.hpp"
#include "Corps.hpp"
#include "Equipement.hpp"


#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

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
  //  Inventaire inventaire;
  Equipement _equipement;


public :
  //Constructeurs
  Personnage(string nom, int sexe, int age, double taille, double poids, int niveau, Stat stats, Corps corps, Equipement equipement);
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
