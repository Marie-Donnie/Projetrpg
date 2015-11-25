//include guard
#ifndef ETAT_HPP
#define ETAT_HPP

class Interface;

//included dependencies
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "Observer.hpp"


using namespace std;


class Etat : public Observer{
public:
  virtual void affichage();
  virtual void retour();
  virtual void inputchiffre(int chiffre);
  virtual void interaction(int laquelle);
  virtual void aide();
};

#endif //ETAT_HPP
