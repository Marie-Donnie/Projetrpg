#include "Etat.hpp"
#include "Interface.hpp"
#include "Case.hpp"
#include "Membre.hpp"


/*------------Etat------------*/
void Etat::affichage(){}
void Etat::retour(){}
void Etat::inputchiffre(int chiffre){}
void Etat::interaction(Case& c){}
void Etat::aide(){
  interface->setEtat(&interface->aaide);
  interface->affichage();
}
void Etat::inventaire(){
  interface->setEtat(&interface->ainvp);
  interface->affichage();
}

/*------------Setters------------*/
void Etat::setInterface(Interface* inter){
  interface = inter;
}

/*------------Observer------------*/
Observer* Etat::getSuiv(){return suiv;}
void Etat::setSuiv(Observer* o){suiv = o;}
void Etat::traiter(Membre& m, int pv){
  interface->setEtat(&interface->abase);
  interface->affichage();
  cout << "Le zombie a attaqué votre " << m.getNom() << " !" << endl;
}
void Etat::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, 0);
  else cout << "Etat n'a pas de suivant" << endl;
}
void Etat::personnageMort(){
  cout << "Vous êtes mort ! Dieu a gagné !" << endl;
}
void Etat::pnjMort(PNJ& p){
  cout << "Le zombie est mort !" << endl;
}
