#include "Interface.hpp"

Interface::Interface(){
  // _ABase= new ABase(*this);
  // _AAide= new AAide(*this);
  // _AStats= new AStats(*this);
  // _AEquipement= new AEquipement(*this);
  // _ACorps= new ACorps(*this);
  // _AInventaireSplit= new AInventaireSplit(*this);
  // _AInventaire= new AInventaire(*this);
  // _AArmures= new AArmures(*this);
  // _AArmes= new AArmes(*this);
  // _AObjets= new AObjets(*this);
  // _ADialogues= new ADialogues(*this);
  _etatCourant= NULL;
    suiv = NULL;
 }

Etat* Interface::getEtatCourant(){return _etatCourant;}
// Etat* Interface::getEtatABase(){return _ABase;}
// Etat* Interface::getEtatAAide(){return _AAide;}
// Etat* Interface::getEtatAStats(){return _AStats;}
// Etat* Interface::getEtatAEquipement(){return _AEquipement;}
// Etat* Interface::getEtatACorps(){return _ACorps;}
// Etat* Interface::getEtatAInventaireSplit(){return _AInventaireSplit;}
// Etat* Interface::getEtatAInventaire(){return _AInventaire;}
// Etat* Interface::getEtatAArmures(){return _AArmures;}
// Etat* Interface::getEtatAArmes(){return _AArmes;}
// Etat* Interface::getEtatAObjets(){return _AObjets;}
// Etat* Interface::getEtatADialogues(){return _ADialogues;}

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
