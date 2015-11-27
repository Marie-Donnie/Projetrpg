#include "Etats.hpp"
#include "Interface.hpp"
#include "Membre.hpp"

/*------------ABase------------*/

ABase::ABase() {}
void ABase::affichage(){
  cout << "\x1B[2J" ;
  cout << "Vos points de vie : " << interface->getPerso().getStats().getHP() << endl;
  interface->getPerso().getEquipement().afficher();
  cout << "Votre force : " << interface->getPerso().getStats().getForce() << endl;
  cout << "Votre agilité : " << interface->getPerso().getStats().getAgi() << endl;
  cout << "Votre capacité de combat : " <<interface->getPerso().getStats().getCc() << endl;
  cout << "1 : Corps | 2 : Equipement | 3 : Stats" << endl;
  cout << "E : Interagir | I : Inventaire | H : Aide" << endl;
}
void ABase::retour(){}
void ABase::inputchiffre(int chiffre){}
void ABase::interaction(Case& c){}
void ABase::traiter(Membre& m, int pv){
    affichage();
    cout << "Le zombie a attaqué votre " << m.getNom() << " !" << endl;
}


/*------------AAide------------*/
AAide::AAide() {}
void AAide::affichage(){
  cout << "\x1B[2J" ;
  cout << "Conseil : N'attaquez pas les zombies à mains nues !" << endl;
}
void AAide::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AAide::inputchiffre(int chiffre){}
void AAide::interaction(Case& c){}

/*------------AStats------------*/
AStats::AStats() {}
void AStats::affichage(){
  cout << "\x1B[2J" ;
}
void AStats::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AStats::inputchiffre(int chiffre){}
void AStats::interaction(Case& c){}

/*------------AEquipement------------*/
AEquipement::AEquipement() {}
void AEquipement::affichage(){
  cout << "\x1B[2J" ;
}
void AEquipement::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AEquipement::inputchiffre(int chiffre){}
void AEquipement::interaction(Case& c){}

/*------------ACorps------------*/
ACorps::ACorps() {}
void ACorps::affichage(){
  cout << "\x1B[2J" ;
}
void ACorps::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void ACorps::inputchiffre(int chiffre){}
void ACorps::interaction(Case& c){}

/*------------AInventaireSplit------------*/
AInventaireSplit::AInventaireSplit() {}
void AInventaireSplit::affichage(){
  cout << "\x1B[2J" ;
}
void AInventaireSplit::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AInventaireSplit::inputchiffre(int chiffre){}
void AInventaireSplit::interaction(Case& c){}

/*------------AInventaire------------*/
AInventaire::AInventaire() {}
void AInventaire::affichage(){
  cout << "\x1B[2J" ;
}
void AInventaire::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AInventaire::inputchiffre(int chiffre){}
void AInventaire::interaction(Case& c){}

/*------------AArmures------------*/

AArmures::AArmures() {}
void AArmures::affichage(){
  cout << "\x1B[2J" ;
}
void AArmures::retour(){
interface->setEtat(&interface->ainvs);
  interface->affichage();
}
void AArmures::inputchiffre(int chiffre){}
void AArmures::interaction(Case& c){}


/*------------AArmes------------*/

AArmes::AArmes() {}
void AArmes::affichage(){
  cout << "\x1B[2J" ;
}
void AArmes::retour(){
interface->setEtat(&interface->ainvs);
  interface->affichage();
}
void AArmes::inputchiffre(int chiffre){}
void AArmes::interaction(Case& c){}


/*------------AObjets------------*/

AObjets::AObjets() {}
void AObjets::affichage(){
  cout << "\x1B[2J" ;
}
void AObjets::retour(){
interface->setEtat(&interface->ainvs);
  interface->affichage();
}
void AObjets::inputchiffre(int chiffre){}
void AObjets::interaction(Case& c){}

/*------------ADialogues------------*/

ADialogues::ADialogues() {}
void ADialogues::affichage(){
  cout << "\x1B[2J" ;
}
void ADialogues::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void ADialogues::inputchiffre(int chiffre){}
void ADialogues::interaction(Case& c){}

/*------------AInventairep------------*/
AInventairep::AInventairep() {}
void AInventairep::affichage(){
  cout << "\x1B[2J" ;
  cout << "1 : Armures | 2 : Armes | 3 : Objets" << endl;
}
void AInventairep::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AInventairep::inputchiffre(int chiffre){}
void AInventairep::interaction(Case& c){}
