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
  cout << "1 : Corps | 2 : Equipement | 3 : Stats | F : Soin" << endl;
  cout << "E : Interagir | I : Inventaire | R : Retour | H : Aide" << endl;
}
void ABase::retour(){}
void ABase::inputchiffre(int chiffre){
  switch(chiffre){
  case 1:{
    interface->setEtat(&interface->acorps);
    interface->affichage();
    break;
  }
  case 2:{
    interface->setEtat(&interface->aequi);
    interface->affichage();
    break;
  }
  case 3:{
    interface->setEtat(&interface->astats);
    interface->affichage();
    break;
  }
  }
}
void ABase::traiter(Membre& m, int pv){
    affichage();
    cout << "Le zombie a attaqué votre " << m.getNom() << " !" << endl;
}

/*------------AAide------------*/
AAide::AAide() {}
void AAide::affichage(){
  cout << "\x1B[2J" ;
  cout << "Conseil : N'attaquez pas les zombies à mains nues !" << endl;
  cout << "R : Retour" << endl;
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
  interface->getPerso().getStats().afficher();
}
void AStats::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AStats::inputchiffre(int chiffre){}


/*------------AEquipement------------*/
AEquipement::AEquipement() {}
void AEquipement::affichage(){
  cout << "\x1B[2J";
  interface->getPerso().getEquipement().afficherC();
  cout << "R : Retour" << endl;
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
  interface->getPerso().getCorps().afficher();
  cout << "R : Retour" << endl;
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
  cout << "\x1b[34m";
  cout << "*------------------Inventaire perso------------------*" << endl;
  cout << "\x1b[39;49m";
  interface->getPerso().getInventaire().afficherC();
  cout << "\x1b[34m";
  cout << "*------------------Fin Inventaire perso------------------*" << endl;
  cout << "\x1b[39;49m";
  cout << "\x1b[31m";
  cout << "*------------------Loots------------------*" << endl;
  cout << "\x1b[39;49m";
  interface->getCase()->getInventaireAdress()->afficherC();
  cout << "\x1b[31m";
  cout << "*------------------Fin Loots------------------*" << endl;
  cout << "\x1b[39;49m";
  cout << "1 : Inventaire perso | 2 : Loots | R : Retour" << endl;
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


/*------------AInventaire------------*/
AInventaire::AInventaire() {}
void AInventaire::affichage(){
  cout << "\x1B[2J" ;
  interface->getCase()->getInventaireAdress()->afficher();
  cout << "1 : Armures | 2 : Armes | 3 : Objets | R : Retour" << endl;
  interface->setQuoi(1);
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

/*------------AInventairep------------*/
AInventairep::AInventairep() {}
void AInventairep::affichage(){
  cout << "\x1B[2J" ;
  interface->getPerso().getInventaire().afficher();
  cout << "1 : Armures | 2 : Armes | 3 : Objets | R : Retour" << endl;
  interface->setQuoi(0);
}
void AInventairep::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void AInventairep::inputchiffre(int chiffre){
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


/*------------AArmures------------*/

AArmures::AArmures() {}
void AArmures::affichage(){
  cout << "\x1B[2J" ;
  if (interface->getQuoi() ==0){
    interface->getPerso().getInventaire().afficherArmures();
    cout << "1 : Equiper armure 1 | 2 : Equiper armure 2..." << endl;
  }
  else if (interface->getQuoi() == 1){
    interface->getCase()->getInventaire().afficherArmures();
    cout << "1 : Récupérer armure 1 | 2 : Récupérer armure 2..." << endl;
  }
  cout << "R : Retour" << endl;
}
void AArmures::retour(){
interface->setEtat(&interface->ainvs);
  interface->affichage();
}
void AArmures::inputchiffre(int chiffre){
  if (interface->getQuoi() ==0){
    if ((chiffre-1)< interface->getPerso().getInventaire().getArmures().size()){
    Armure a = interface->getPerso().getInventaire().prendreArmure(chiffre-1);
    Armure b = interface->getPerso().getEquipement().changerArmure(a);
    interface->getPerso().getInventaire().ajouterArmure(b);
  affichage();
    cout << "L'armure a bien été équipée" << endl;
    }
    else cout << "Il n'existe pas d'armure numéro " << chiffre << endl;
  }
  else if (interface->getQuoi() == 1){
    if ((chiffre-1)< interface->getCase()->getInventaire().getArmures().size()){
    Armure a = interface->getCase()->getInventaire().prendreArmure(chiffre-1);
    interface->getPerso().getInventaire().ajouterArmure(a);
  affichage();
    cout << "L'armure a bien été récupérée" << endl;
    }
    else cout << "Il n'existe pas d'armure numéro " << chiffre << endl;
  }
}



/*------------AArmes------------*/

AArmes::AArmes() {}
void AArmes::affichage(){
  cout << "\x1B[2J" ;
  if (interface->getQuoi() ==0){
    interface->getPerso().getInventaire().afficherArmes();
    cout << "1 : Equiper arme 1 | 2 : Equiper arme 2..." << endl;
  }
  else if (interface->getQuoi() == 1){
    interface->getCase()->getInventaire().afficherArmes();
    cout << "1 : Récupérer arme 1 | 2 : Récupérer arme 2..." << endl;
  }
  cout << "R : Retour" << endl;
}
void AArmes::retour(){
interface->setEtat(&interface->ainvs);
  interface->affichage();
}
void AArmes::inputchiffre(int chiffre){
  if (interface->getQuoi() ==0){
    if ((chiffre-1)< interface->getPerso().getInventaire().getArmes().size()){
    Arme a = interface->getPerso().getInventaire().prendreArme(chiffre-1);
    Arme b = interface->getPerso().getEquipement().changerArme(a);
    interface->getPerso().getInventaire().ajouterArme(b);
    affichage();
    cout << "L'arme a bien été équipée" << endl;
    }
    else cout << "Il n'existe pas d'arme numéro " << chiffre << endl;
  }
  else if (interface->getQuoi() == 1){
    if ((chiffre-1)< interface->getCase()->getInventaire().getArmes().size()){
    Arme a = interface->getCase()->getInventaire().prendreArme(chiffre-1);
    interface->getPerso().getInventaire().ajouterArme(a);
    affichage();
    cout << "L'arme a bien été récupérée" << endl;
    }
    else cout << "Il n'existe pas d'arme numéro " << chiffre << endl;
  }

}



/*------------AObjets------------*/

AObjets::AObjets() {}
void AObjets::affichage(){
  cout << "\x1B[2J" ;
  if (interface->getQuoi() ==0){
    interface->getPerso().getInventaire().afficherObjets();
    cout << "1 : Utiliser objet 1 | 2 : Utiliser objet 2..." << endl;
  }
  else if (interface->getQuoi() == 1){
    interface->getCase()->getInventaire().afficherObjets();
    cout << "1 : Récupérer objet 1 | 2 : Récupérer objet 2..." << endl;
  }
  cout << "R : Retour" << endl;
}
void AObjets::retour(){
interface->setEtat(&interface->ainvs);
  interface->affichage();
}
void AObjets::inputchiffre(int chiffre){
  if (interface->getQuoi() ==0){
    if ((chiffre-1)< interface->getPerso().getInventaire().getObjets().size()){
      interface->getPerso().getInventaire().utiliserObjet(interface->getPerso(), chiffre-1);
  affichage();
    cout << "L'objet a bien été utilisé" << endl;
    }
    else cout << "Il n'existe pas d'objet numéro " << chiffre << endl;
  }
  else if (interface->getQuoi() == 1){
    if ((chiffre-1)< interface->getCase()->getInventaire().getArmes().size()){
    Objet o = interface->getCase()->getInventaire().prendreObjet(chiffre-1);
    interface->getPerso().getInventaire().ajouterObjet(&o);
  affichage();
    cout << "L'objet a bien été récupéré" << endl;
    }
    else cout << "Il n'existe pas d'objet numéro " << chiffre << endl;
  }
}

/*------------ADialogues------------*/

ADialogues::ADialogues() {_nombre = 0;}
void ADialogues::affichage(){
  cout << "\x1B[2J" ;
  cout << "Vous : Wow... ma tête... Où suis-je ? Un sanatorium ?" << endl;
  cout << "Inconnu : Salut." << endl;
  cout << "Vous : Qui-êtes vous ? Vous n’avez pas l’air d’un moine..." << endl;
  cout << "Inconnu, riant : Non. Je suis quelqu’un qui a besoin de ton aide." << endl;
  cout << "R : Retour" << endl;
}
void ADialogues::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();
}
void ADialogues::inputchiffre(int chiffre){  cout << chiffre << endl;
}
