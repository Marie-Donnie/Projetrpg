#include "Etats.hpp"
#include "Interface.hpp"

/*------------ABase------------*/

ABase::ABase(Interface& interface) : _interface(interface) {}
void ABase::affichage(){}
void ABase::retour(){}
void ABase::inputchiffre(int chiffre){}
void ABase::interaction(int laquelle){}
void ABase::aide(){}
void ABase::traiter(Membre& m, int pv){}


/*------------AAide------------*/
AAide::AAide(Interface& interface) : _interface(interface) {}
void AAide::affichage(){}
void AAide::retour(){}
void AAide::inputchiffre(int chiffre){}
void AAide::interaction(int laquelle){}
void AAide::aide(){}
void AAide::traiter(Membre& m, int pv){}

/*------------AStats------------*/
AStats::AStats(Interface& interface) : _interface(interface) {}
void AStats::affichage(){}
void AStats::retour(){}
void AStats::inputchiffre(int chiffre){}
void AStats::interaction(int laquelle){}
void AStats::aide(){}
void AStats::traiter(Membre& m, int pv){}

/*------------AEquipement------------*/
AEquipement::AEquipement(Interface& interface) : _interface(interface) {}
void AEquipement::affichage(){}
void AEquipement::retour(){}
void AEquipement::inputchiffre(int chiffre){}
void AEquipement::interaction(int laquelle){}
void AEquipement::aide(){}
void AEquipement::traiter(Membre& m, int pv){}



/*------------ACorps------------*/
ACorps::ACorps(Interface& interface) : _interface(interface) {}
void ACorps::affichage(){}
void ACorps::retour(){}
void ACorps::inputchiffre(int chiffre){}
void ACorps::interaction(int laquelle){}
void ACorps::aide(){}
void ACorps::traiter(Membre& m, int pv){}

/*------------AInventaireSplit------------*/
AInventaireSplit::AInventaireSplit(Interface& interface) : _interface(interface) {}
void AInventaireSplit::affichage(){}
void AInventaireSplit::retour(){}
void AInventaireSplit::inputchiffre(int chiffre){}
void AInventaireSplit::interaction(int laquelle){}
void AInventaireSplit::aide(){}
void AInventaireSplit::traiter(Membre& m, int pv){}


/*------------AInventaire------------*/
AInventaire::AInventaire(Interface& interface) : _interface(interface) {}
void AInventaire::affichage(){}
void AInventaire::retour(){}
void AInventaire::inputchiffre(int chiffre){}
void AInventaire::interaction(int laquelle){}
void AInventaire::aide(){}
void AInventaire::traiter(Membre& m, int pv){}


/*------------AArmures------------*/

AArmures::AArmures(Interface& interface) : _interface(interface) {}
void AArmures::affichage(){}
void AArmures::retour(){}
void AArmures::inputchiffre(int chiffre){}
void AArmures::interaction(int laquelle){}
void AArmures::aide(){}
void AArmures::traiter(Membre& m, int pv){}


/*------------AArmes------------*/

AArmes::AArmes(Interface& interface) : _interface(interface) {}
void AArmes::affichage(){}
void AArmes::retour(){}
void AArmes::inputchiffre(int chiffre){}
void AArmes::interaction(int laquelle){}
void AArmes::aide(){}
void AArmes::traiter(Membre& m, int pv){}


/*------------AObjets------------*/

AObjets::AObjets(Interface& interface) : _interface(interface) {}
void AObjets::affichage(){}
void AObjets::retour(){}
void AObjets::inputchiffre(int chiffre){}
void AObjets::interaction(int laquelle){}
void AObjets::aide(){}
void AObjets::traiter(Membre& m, int pv){}

/*------------ADialogues------------*/

ADialogues::ADialogues(Interface& interface) : _interface(interface) {}
void ADialogues::affichage(){}
void ADialogues::retour(){}
void ADialogues::inputchiffre(int chiffre){}
void ADialogues::interaction(int laquelle){}
void ADialogues::aide(){}
void ADialogues::traiter(Membre& m, int pv){}
