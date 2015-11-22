//include guard
#ifndef ETAT_HPP
#define ETAT_HPP


//included dependencies
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "Observer.hpp"
#include "Interface.hpp"

using namespace std;

class Etat : public Observer{
public:
  virtual void affichage();
  virtual void retour();
  virtual void inputchiffre(int chiffre);
  virtual void interaction(int laquelle);
  virtual void aide();
};

class ABase : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class AAide : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class AStats : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class AEquipement : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class ACorps : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class AInventaireSplit : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class AInventaire : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class AArmures : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class AArmes : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class AObjets : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};

class ADialogues : public Etat{
private:
  Interface interface;
public:
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
};
