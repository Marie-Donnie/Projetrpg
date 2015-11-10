#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Personnage.hpp"
#include "Armure.hpp"
#include "Stat.hpp"
#include "Corps.hpp"
#include "Equipement.hpp"
#include "Arme.hpp"
#include "Inventaire.hpp"

using namespace std;

int main(){
  /* initialize random seed: */
  srand (time(NULL));

  /* Personnage mario = Personnage("Mario", 0, 42, 1.45, 90.2, 6);
  mario.afficher();
  Personnage luigi = Personnage();
  luigi.afficher();*/
  Stat bowserstat = Stat(20,20,2,2,4,1,0,0,90,90);
  Corps bowserbody = Corps();
  Equipement bowserstuff = Equipement();
  Personnage bowser = Personnage("Bowser", 0, 250, 3.55, 680.0, 100, bowserstat, bowserbody, bowserstuff);/*
  cout << "Mario :" << endl;
  mario.getCorps().afficher();
  cout << "Luigi :" << endl;
  luigi.getCorps().afficher();
  cout << "Bowser :" << endl;
  bowser.getCorps().afficher();*/
  bowser.getEquipement().afficher();
  /*mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);*/
  //bowser.getEquipement().afficher();
  /* bowser.getCorps().afficher();*/
  Arme arme1 = Arme(0,2);
  //arme1.afficher();
  Arme arme2 = Arme(0,1);
  //arme2.afficher();
  Arme arme3 = Arme(1,2);
  //arme3.afficher();
  Arme arme4 = Arme(1,1);
  //arme4.afficher();
  Arme arme5 = Arme(2,2);
  //arme5.afficher();
  Arme arme6 = Arme(2,1);
  //arme6.afficher();

  Armure arm = Armure("arm", "Jambieres", "Plaque", 20, 3, 2, 3, 25.3);
  //arm.afficher();
  Armure lolol = Armure();
  //lolol.afficher();
  Armure lilol = Armure();
  //lilol.afficher();
  Armure lalol = Armure();
  //lalol.afficher();
  Armure lulol = Armure();
  //lulol.afficher();*/
  Inventaire inv = Inventaire();
  inv.ajouter(arme1);
  inv.ajouter(arme2);
  inv.ajouter(arme3);
  inv.ajouter(arme4);
  inv.ajouter(arme5);
  inv.ajouter(arme6);
  inv.ajouter(arm);
  inv.ajouter(lolol);
  inv.ajouter(lilol);
  inv.ajouter(lalol);
  inv.ajouter(lulol);
  inv.afficher();
  Armure temp = inv.prendreArmure(3);
  temp.afficher();
  Armure test = bowserstuff.changerArmure(temp);
  inv.ajouter(test);
  bowserstuff.afficher();
  inv.afficher();
}
