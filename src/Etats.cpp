#include "Etats.hpp"
#include "Interface.hpp"
#include "Membre.hpp"
#include "Case.hpp"

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


/*------------AInventaireSplit------------*/
AInventaireSplit::AInventaireSplit() {}
void AInventaireSplit::affichage(){
  cout << "\x1B[2J" ;
  cout << "*------------------Inventaire perso------------------*" << endl;
  interface->getPerso().getInventaire().afficherC();
  cout << "*------------------Fin Inventaire perso------------------*" << endl;
  cout << "*------------------Loots------------------*" << endl;
  interface->getCase()->getInventaireAdress()->afficherC();
  cout << "*------------------Fin Loots------------------*" << endl;
  cout << "1 : Inventaire perso | 2 : Loots" << endl;
}
void AInventaireSplit::retour(){
  interface->setEtat(&interface->abase);
  interface->affichage();
}
void AInventaireSplit::inputchiffre(int chiffre){
  switch(chiffre){
  case 1:{
    interface->setEtat(&interface->ainvp);
    interface->affichage();
    break;
  }
  case 2:{
    interface->setEtat(&interface->ainv);
    interface->affichage();
    break;
  }
  }
}
// void AInventaireSplit::setCase(Case& c){
//   _c = c;
// }


/*------------AInventaire------------*/
AInventaire::AInventaire() {}
void AInventaire::affichage(){
  cout << "\x1B[2J" ;
  interface->getCase()->getInventaireAdress()->afficher();
  cout << "1 : Armures | 2 : Armes | 3 : Objets" << endl;
}
void AInventaire::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AInventaire::inputchiffre(int chiffre){
  switch(chiffre){
  case 1:{
    interface->setEtat(&interface->aarmures);
    interface->affichage();
    break;
  }
  case 2:{
    interface->setEtat(&interface->aarmes);
    interface->affichage();
    break;
  }
  case 3:{
    interface->setEtat(&interface->aobjets);
    interface->affichage();
    break;
  }
  }
}
// void AInventaire::setCase(Case& c){
//   _c = c;
// }


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
