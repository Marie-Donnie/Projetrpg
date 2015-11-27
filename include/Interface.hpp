//include guard
#ifndef INTERFACE_HPP
#define INTERFACE_HPP

class PNJ;
class Jeu;

//included dependencies
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "Observer.hpp"
#include "Etat.hpp"
#include "Etats.hpp"
#include "Personnage.hpp"
#include "Case.hpp"

using namespace std;

 class Interface : public Observer{
private:
  Etat* _etatCourant;
   Personnage& _perso;
   Case* _case;

public:
   static ABase abase;
   static AAide aaide;
   static AStats astats;
   static AEquipement aequi;
   static ACorps acorps;
   static AInventaireSplit ainvs;
   static AInventaire ainv;
   static AArmes aarmes;
   static AArmures aarmures;
   static AObjets aobjets;
   static ADialogues adial;
   static AInventairep ainvp;

   Interface(Personnage& perso);

  Interface(const Interface& lautre);
  Interface& operator=(const Interface& lautre);

   void updateEtat();

   //Getter
   Etat* getEtatCourant();
   Personnage& getPerso();
   Case* getCase();

   //Setter
   void setEtat(Etat* etat);
   void setCase(Case* c);

   //Méthodes de l'observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  void traiter(Membre& m, int pv);
  void passer(Membre& m);
  void personnageMort();
  void pnjMort(PNJ& p);

  //Méthodes state
  void affichage();
  void retour();
  void inputchiffre(int chiffre);
  void interaction(Case& c);
  void aide();
   void inventaire();
 };


#endif //INTERFACE_HPP
