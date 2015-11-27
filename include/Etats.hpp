//include guard
#ifndef ETATS_HPP
#define ETATS_HPP

class Interface;
class Membre;

//included dependencies
#include <string>
#include <stdio.h>
#include <iostream>				//cin cout
#include <vector>
#include "Observer.hpp"
#include "Etat.hpp"
#include "Personnage.hpp"

using namespace std;



class ABase : public Etat{
public:
ABase();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
  void traiter(Membre& m, int pv);
};

class AAide : public Etat{
public:
AAide();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class AStats : public Etat{
public:
AStats();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class AEquipement : public Etat{
public:
AEquipement();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class ACorps : public Etat{
public:
ACorps();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class AInventaireSplit : public Etat{
public:
AInventaireSplit();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class AInventaire : public Etat{
public:
AInventaire();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class AArmures : public Etat{
public:
AArmures();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class AArmes : public Etat{
public:
AArmes();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class AObjets : public Etat{
public:
AObjets();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class ADialogues : public Etat{
public:
ADialogues();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

class AInventairep : public Etat{
public:
AInventairep();
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
};

#endif //ETATS_HPP
