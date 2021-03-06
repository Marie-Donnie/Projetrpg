#include "Etats.hpp"
#include "Interface.hpp"
#include "Membre.hpp"
#include "Case.hpp"

/*------------ABase------------*/

ABase::ABase() {}
void ABase::affichage(){
  cout << "\x1B[2J" ;
  cout << "Vos points de vie : " << interface->getPerso().getStats().getHP() << "/" << interface->getPerso().getCorps().getPvMax() << endl;
  interface->getPerso().getEquipement().afficher();
  cout << "Votre force : " << interface->getPerso().getStats().getForce() << endl;
  cout << "Votre agilité : " << interface->getPerso().getStats().getAgi() << endl;
  cout << "Votre capacité de combat : " <<interface->getPerso().getStats().getCc() << endl;
  cout << "1 : Corps | 2 : Equipement | 3 : Stats | F : Soin" << endl;
  cout << "E : Interagir | I : Inventaire | R : Retour | H : Aide" << endl;
}
void ABase::retour(){
interface->setEtat(&interface->abase);
  interface->affichage();}
void ABase::inputchiffre(int chiffre){
  switch(chiffre){
  case 1:{//Corps
    interface->setEtat(&interface->acorps);
    interface->affichage();
    break;
  }
  case 2:{//Equipement
    interface->setEtat(&interface->aequi);
    interface->affichage();
    break;
  }
  case 3:{//Stats
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
  cout << "Programmation : Robin Wibaux et Marie Delavergne" << endl;
  cout << "Art : Marie Delavergne" << endl;
  cout << "Musique : Florent Marchand de Kerchove de Denterghem" << endl;
  cout << "Scénario : Logan Carpantier" << endl;
  cout << "R : Retour | H : Aide" << endl;
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
  cout << "R : Retour | H : Aide" << endl;
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
  cout << "R : Retour | H : Aide" << endl;
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
  cout << "R : Retour | H : Aide" << endl;
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
  cout << "1 : Armures | 2 : Armes | 3 : Objets | R : Retour | H : Aide" << endl;
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
  cout << "1 : Armures | 2 : Armes | 3 : Objets | R : Retour | H : Aide" << endl;
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
  cout << "R : Retour | H : Aide" << endl;
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
  cout << "R : Retour | H : Aide" << endl;
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
  cout << "R : Retour | H : Aide" << endl;
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
  switch(_nombre){
  case 0:{//intro
  cout << "\x1b[34m";
  cout << "Vous : \"Wow... ma tête... Où suis-je ? Un sanatorium ?\"" << endl;
  cout << "\x1b[31m";
  cout << "Inconnu : \"Salut.\"" << endl;
  cout << "\x1b[34m";
  cout << "Vous : \"Qui-êtes vous ? Vous n’avez pas l’air d’un moine...\"" << endl;
  cout << "\x1b[31m";
  cout << "Inconnu, riant : \"Non. Je suis quelqu’un qui a besoin de ton aide.\"" << endl;
  cout << "\x1b[34m";
    cout << "1 : \"Mon aide pour quoi ?\"" << endl;
    cout << "2 : \"Pourquoi moi ?\"" << endl;
  cout << "\x1b[39;49m";
    break;
      }
  case 1 :{//explications
  cout << "\x1b[31m";
      cout << "Inconnu : \"La peste, là, qui ravage l’Europe... C’est pas bon pour mon commerce. Je sais bien que c’est une punition divine, mais il a un peu déconné, Dieu, là. " << endl;
      cout << "Entre la peste qui tue les gens et le fait que ça les ramène en mort-vivant pour bouffer d’autres gens... Il va pas rester grand monde. " << endl;
      cout << "Je sais, je sais vous l’avez cherché, comme pour Sodome et Gomorrhe, comme pour la tour de Babel, tout ça, mais le vieux il  déconne, là, on va se retrouver comme après le déluge avec plus personne avec qui marchander, s’il continue !" <<endl;
      cout << "Alors j’ai besoin de quelqu’un... Ben pour éliminer les sources de peste, ce genre de trucs.\" " << endl;
  cout << "\x1b[34m";
      cout<< "1 : \"Vous vous rendez compte que je suis pas un chevalier ?\"" << endl;
      cout << "2 : \"D’accord. Vous me donnez quoi en échange ?\" " << endl;
      cout << "3 : \"D’accord, je vais sauver le monde.\"" << endl;
  cout << "\x1b[39;49m";
      break;
    }
  case 2 :{//pourquoi moi ?
  cout << "\x1b[31m";
    cout << "Inconnu : \"Et alors ? Noé il était pas capitaine de bateau ! Et puis, les chevaliers... A part leur armure, ils sont pas meilleurs que les autres !\"" << endl;
  cout << "\x1b[34m";
      cout << "1 : \"D’accord. Vous me donnez quoi en échange ?\" " << endl;
      cout << "2 : \"D’accord, je vais sauver le monde. \" " << endl;
      cout << "3 : \"Euh...\"" << endl;
  cout << "\x1b[39;49m";
      break;
  }
  case 3 :{//d'accord
  cout << "\x1b[31m";
    cout << "Inconnu, riant à nouveau : \"Là, tu me plais. Je peux te donner deux ou trois trucs qui pourront bien t’aider. D’accord ?\""<<endl;;
  cout << "\x1b[34m";
      cout << "1 : \"Non, en fait, rien à foutre, salut !\"" << endl;
    cout << "2 : \"Non, je suis un guerrier, je vais me démerder !\"" << endl;
    cout << "3 : \"Euh... ouais ?\"" << endl;
  cout << "\x1b[39;49m";
    break;
  }
  case 4 :{//merveilleux
  cout << "\x1b[31m";
    cout << "Inconnu : \"Merveilleux. D’abord : tiens, faut que je mette ma main sur ton épaule, là. Voilà.\" Une lueur brunâtre enveloppe sa main et votre épaule. \"Maintenant, si tu te concentres, tu vas pouvoir... Oh tiens, je te montre !\" L'inconnu sort une machette et coupe votre bras " << endl;
  cout << "\x1b[34m";
    cout << "Vous : \"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH !\"" << endl;
  cout << "\x1b[31m";
    cout << "Inconnu : \"Bon, j'y suis allé un peu fort. Mais vas-y, concentre-toi sur ta douleur. Voilà, comme ça. Tu vois ? Ca repousse ! Bon... Là, c'était cadeau. Je t'avoue que la prochaine fois, ça aura un coût. Mais passons à plus important. Je vais te laisser te démerder. Mais y a une surprise pour toi dans l'armoire là-bas, au nord. Je suis sûr que tu t'orientes trèès bien. Ah et... n'essaie pas de prendre les draps, ils n'servent à rien !\""<<endl;
  cout << "\x1b[34m";
      cout << "1 : Quitter l'inconnu." << endl;
  cout << "\x1b[39;49m";
    break;
  }
  case 5:{//snif
  cout << "\x1b[31m";
    cout << "Inconnu : \" Quoi ? T'as besoin de moi finalement ?\" " <<endl;
  cout << "\x1b[34m";
    cout << "1 : \" Un peu...\" " << endl;
    cout << "2 : \" NON ! \" " << endl;
  cout << "\x1b[39;49m";
    break;
  }
  case 6:{//musique de Koyaanisqatsi
  cout << "\x1b[31m";
    cout << "Inconnu : \"Je te surveille un peu.\" " << endl;
  cout << "\x1b[34m";
    cout << "1 : Quitter l'inconnu." << endl;
  cout << "\x1b[39;49m";
    break;
  }
  cout << "R : Retour | H : Aide" << endl;
  cout << "\x1b[39;49m";
  }
}
void ADialogues::retour(){
  interface->setEtat(&interface->abase);
  interface->affichage();
}
void ADialogues::inputchiffre(int chiffre){
  switch(_nombre){
  case 0:{//intro
    switch(chiffre){
    case 0:
      _nombre = 0; //on revient au début
      break;
    case 1 ://input 1
      _nombre = 1; //on passe dans le case 1 d'affichage
      break;
    case 2:
      _nombre = 2; //on passe dans le case 2 d'affichage
      break;
    }
    break;
  }//fin intro
  case 1:{//Explications
    switch(chiffre){
    case 1://input 1
      _nombre =2;
      break;
    case 2://d'accord
    case 3://d'accord
      _nombre = 3;
      break;
    case 0:
      _nombre = 0; //on revient au début
      break;
    }
    break;
  }//fin explication
  case 2:{//pourquoi moi ?
    switch(chiffre){
    case 0:
      _nombre =0;
      break;
    case 1://d'accord
    case 2://d'accord
    case 3://euh
      _nombre = 3;
      break;
    }
    break;
  }//fin pourquoi moi
  case 3:{//d'accord
    switch(chiffre){
    case 0:
      _nombre = 0;
      break;
    case 1://fu
    case 2://nop
      _nombre = 5;
      retour();
  cout << "\x1b[31m";
      cout << "Inconnu : \"Ah ok, salut ! Et bonne chance !\" " << endl;
  cout << "\x1b[39;49m";
      break;
    case 3: _nombre=4;
      break;
    }
    break;
  }//fin d'accord
  case 4:{//merveilleux
    switch(chiffre){
    case 0:
      _nombre = 0; //on revient au début
      break;
    case 1:
      _nombre =6;
      retour();
      break;
    }
    break;
  }
  case 5:{//snif
    switch(chiffre){
    case 0:
      _nombre = 0; //on revient au début
      break;
    case 1://oui je suis une mite en pullover
      _nombre = 4;
      break;
    case 2://nonononon
      retour();
  cout << "\x1b[31m";
      cout << "L'inconnu s'en souviendra." << endl;
  cout << "\x1b[39;49m";
      break;
    }
    break;
  }
  case 6:{//musique de Koyaanisqatsi
    switch(chiffre){
    case 0:
      _nombre = 0; //on revient au début
      break;
    case 1:
      retour();
      break;
    }
    break;
  }
  }//fin switch
  affichage();
}
