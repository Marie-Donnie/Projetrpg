//include guard
#ifndef INTERFACE_HPP
#define INTERFACE_HPP


//included dependencies
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "Jeu.hpp"
#include "Observer.hpp"
#include "Etat.hpp"

using namespace std;

 class Interface : public Observer{
private:
  Etat* _etatCourant;
  Etat* _ABase;
  Etat* _AAide;
  Etat* _AStats;
  Etat* _AEquipement;
  Etat* _ACorps;
  Etat* _AInventaireSplit;
  Etat* _AInventaire;
  Etat* _AArmures;
  Etat* _AArmes;
  Etat* _AObjets;
  Etat* _ADialogues;
public:
  Interface();
  //Getter
  Etat* getEtatCourant();
  Etat* getEtatABase();
  Etat* getEtatAAide();
  Etat* getEtatAStats();
  Etat* getEtatAEquipement();
  Etat* getEtatACorps();
  Etat* getEtatAInventaireSplit();
  Etat* getEtatAInventaire();
  Etat* getEtatAArmures();
  Etat* getEtatAArmes();
  Etat* getEtatAObjets();
  Etat* getEtatADialogues();
  //Setter
  void setEtat(Etat* etat);
  //Méthodes state
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
 };


#endif //INTERFACE_HPP
