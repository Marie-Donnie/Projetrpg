//include guard
#ifndef ETATS_HPP
#define ETATS_HPP

class Interface;

//included dependencies
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "Observer.hpp"
#include "Etat.hpp"
#include "Personnage.hpp"

using namespace std;



class ABase : public Etat{
private:
Interface& _interface;
public:
ABase(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class AAide : public Etat{
private:
Interface& _interface;
public:
AAide(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class AStats : public Etat{
private:
Interface& _interface;
public:
AStats(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class AEquipement : public Etat{
private:
Interface& _interface;
public:
AEquipement(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class ACorps : public Etat{
private:
Interface& _interface;
public:
ACorps(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class AInventaireSplit : public Etat{
private:
Interface& _interface;
public:
AInventaireSplit(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class AInventaire : public Etat{
private:
Interface& _interface;
public:
AInventaire(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class AArmures : public Etat{
private:
Interface& _interface;
public:
AArmures(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class AArmes : public Etat{
private:
Interface& _interface;
public:
AArmes(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class AObjets : public Etat{
private:
Interface& _interface;
public:
AObjets(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

class ADialogues : public Etat{
private:
Interface& _interface;
public:
ADialogues(Interface& interface);
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
void traiter(Membre& m, int pv);
};

#endif //ETATS_HPP
