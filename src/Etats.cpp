#include "Etats.hpp"
#include "Interface.hpp"

/*------------ABase------------*/

ABase::ABase() {}
void ABase::affichage(){
  cout << "\x1B[2J" ;
  cout << interface->getPerso().getStats().getHP() << endl;
}
void ABase::retour(){}
void ABase::inputchiffre(int chiffre){}
void ABase::interaction(Case& c){}
void ABase::aide(){}
void ABase::traiter(Membre& m, int pv){
    affichage();
}


/*------------AAide------------*/
AAide::AAide() {}
void AAide::affichage(){
  cout << "\x1B[2J" ;
}
void AAide::retour(){}
void AAide::inputchiffre(int chiffre){}
void AAide::interaction(Case& c){}
void AAide::aide(){}

/*------------AStats------------*/
AStats::AStats() {}
void AStats::affichage(){
  cout << "\x1B[2J" ;
}
void AStats::retour(){}
void AStats::inputchiffre(int chiffre){}
void AStats::interaction(Case& c){}

/*------------AEquipement------------*/
AEquipement::AEquipement() {}
void AEquipement::affichage(){
  cout << "\x1B[2J" ;
}
void AEquipement::retour(){}
void AEquipement::inputchiffre(int chiffre){}
void AEquipement::interaction(Case& c){}

/*------------ACorps------------*/
ACorps::ACorps() {}
void ACorps::affichage(){
  cout << "\x1B[2J" ;
}
void ACorps::retour(){}
void ACorps::inputchiffre(int chiffre){}
void ACorps::interaction(Case& c){}

/*------------AInventaireSplit------------*/
AInventaireSplit::AInventaireSplit() {}
void AInventaireSplit::affichage(){
  cout << "\x1B[2J" ;
}
void AInventaireSplit::retour(){}
void AInventaireSplit::inputchiffre(int chiffre){}
void AInventaireSplit::interaction(Case& c){}

/*------------AInventaire------------*/
AInventaire::AInventaire() {}
void AInventaire::affichage(){
  cout << "\x1B[2J" ;
}
void AInventaire::retour(){}
void AInventaire::inputchiffre(int chiffre){}
void AInventaire::interaction(Case& c){}

/*------------AArmures------------*/

AArmures::AArmures() {}
void AArmures::affichage(){
  cout << "\x1B[2J" ;
}
void AArmures::retour(){}
void AArmures::inputchiffre(int chiffre){}
void AArmures::interaction(Case& c){}


/*------------AArmes------------*/

AArmes::AArmes() {}
void AArmes::affichage(){
  cout << "\x1B[2J" ;
}
void AArmes::retour(){}
void AArmes::inputchiffre(int chiffre){}
void AArmes::interaction(Case& c){}


/*------------AObjets------------*/

AObjets::AObjets() {}
void AObjets::affichage(){
  cout << "\x1B[2J" ;
}
void AObjets::retour(){}
void AObjets::inputchiffre(int chiffre){}
void AObjets::interaction(Case& c){}

/*------------ADialogues------------*/

ADialogues::ADialogues() {}
void ADialogues::affichage(){
  cout << "\x1B[2J" ;
}
void ADialogues::retour(){}
void ADialogues::inputchiffre(int chiffre){}
void ADialogues::interaction(Case& c){}

/*------------AInventairep------------*/
AInventairep::AInventairep() {}
void AInventairep::affichage(){
  cout << "\x1B[2J" ;
}
void AInventairep::retour(){}
void AInventairep::inputchiffre(int chiffre){}
void AInventairep::interaction(Case& c){}
