#include "Interface.hpp"
#include "PNJ.hpp"
#include "Case.hpp"


/*--------Constructeur--------*/
Interface::Interface(Personnage& perso) : _perso(perso){
  _etatCourant= NULL;
    suiv = NULL;
    updateEtat();
 }

Interface::Interface(const Interface& lautre)
  : _etatCourant(lautre._etatCourant),
    _perso(lautre._perso)
{
  updateEtat();
}

Interface& Interface::operator=(const Interface& lautre){
  _etatCourant=(lautre._etatCourant);
  _perso=(lautre._perso);
  updateEtat();
   return *this;
}

ABase Interface::abase = ABase();
AAide Interface::aaide = AAide();
AStats Interface::astats = AStats();
AEquipement Interface::aequi = AEquipement();
ACorps Interface::acorps = ACorps();
AInventaireSplit Interface::ainvs = AInventaireSplit();
AInventaire Interface::ainv = AInventaire();
AArmes Interface::aarmes = AArmes();
AArmures Interface::aarmures = AArmures();
AObjets Interface::aobjets = AObjets();
ADialogues Interface::adial = ADialogues();
AInventairep Interface::ainvp = AInventairep();

void Interface::updateEtat(){
  abase.setInterface(this);
  aaide.setInterface(this);
  astats.setInterface(this);
  aequi.setInterface(this);
  acorps.setInterface(this);
  ainvs.setInterface(this);
  ainv.setInterface(this);
  aarmes.setInterface(this);
  aarmures.setInterface(this);
  aobjets.setInterface(this);
  adial.setInterface(this);
  ainvp.setInterface(this);
}



/*--------Getters--------*/
Etat* Interface::getEtatCourant(){return _etatCourant;}
Personnage& Interface::getPerso(){return _perso;}
Case* Interface::getCase(){return _case;}


/*--------Setters--------*/
void Interface::setEtat(Etat* etat){_etatCourant = etat;}
void Interface::setCase(Case* c){_case = c;}

/*--------Methodes de l'Observer--------*/
Observer* Interface::getSuiv(){return suiv;}
void Interface::setSuiv(Observer* o){suiv = o;}
void Interface::traiter(Membre& m, int pv){
  //cout << "Interface a passé le membre" << endl;
  passer(m);
}
void Interface::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, 0);
  else cout << "Personnage n'a pas de suivant" << endl;
}
void Interface::personnageMort(){
    abase.personnageMort();
}
void Interface::pnjMort(PNJ& p){
    abase.pnjMort(p);
}


/*--------Methodes du State--------*/
void Interface::affichage(){
  _etatCourant->affichage();
}
void Interface::retour(){
  _etatCourant->retour();
}
void Interface::inputchiffre(int chiffre){
  _etatCourant->inputchiffre(chiffre);
}
void Interface::interaction(Case& c){
  Case* ca = &c;
  setCase(ca);
  _etatCourant->interaction(c);
}
void Interface::aide(){
  _etatCourant->aide();
}
void Interface::inventaire(){
  _etatCourant->inventaire();
}
