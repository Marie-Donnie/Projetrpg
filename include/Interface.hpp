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
#include "Etats.hpp"
#include "Personnage.hpp"


using namespace std;

 class Interface : public Observer{
private:
  Etat* _etatCourant;
   Personnage& _perso;

public:
  Interface(Personnage& perso);
  //Getter
  Etat* getEtatCourant();

  //Setter
  void setEtat(Etat* etat);

   //Méthodes de l'observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  void traiter(Membre& m, int pv);
  void passer(Membre& m);
  void personnageMort();
   void pnjMort();

  //Méthodes state
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(int laquelle);
  void aide();
 };


#endif //INTERFACE_HPP
