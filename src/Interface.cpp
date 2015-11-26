#include "Interface.hpp"

Interface::Interface(Personnage& perso) : _perso(perso){
  _etatCourant= NULL;
    suiv = NULL;
 }

Etat* Interface::getEtatCourant(){return _etatCourant;}

void Interface::setEtat(Etat* etat){_etatCourant = etat;}


Observer* Interface::getSuiv(){return suiv;}
void Interface::setSuiv(Observer* o){suiv = o;}
void Interface::traiter(Membre& m, int pv){
  cout << "lol" << endl;
}
void Interface::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, 0);
  else cout << "Personnage n'a pas de suivant" << endl;
}
void Interface::personnageMort(){}
void Interface::pnjMort(){}





void Interface::affichage(){
  _etatCourant->affichage();
}
void Interface::retour(){
  _etatCourant->retour();
}
void Interface::inputchiffre(int chiffre){
  _etatCourant->inputchiffre(chiffre);
}
void Interface::interaction(int laquelle){
  _etatCourant->interaction(laquelle);
}
void Interface::aide(){
  _etatCourant->aide();
}
