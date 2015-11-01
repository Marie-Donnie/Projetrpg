#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Personnage.hpp"
#include "Armure.hpp"
#include "Stat.hpp"
#include "Corps.hpp"
#include "Equipement.hpp"

using namespace std;

int main(){
  /* initialize random seed: */
  srand (time(NULL));

  Personnage mario = Personnage("Mario", 0, 42, 1.45, 90.2, 6);
  mario.afficher();
  Personnage luigi = Personnage();
  luigi.afficher();
  Stat bowserstat = Stat(20,20,2,2,4,1,0,0,90,90);
  Corps bowserbody = Corps();
  Equipement bowserstuff = Equipement();
  Personnage bowser = Personnage("Bowser", 0, 250, 3.55, 680.0, 100, bowserstat, bowserbody, bowserstuff);
  cout << "Mario :" << endl;
  mario.getCorps().afficher();
  cout << "Luigi :" << endl;
  luigi.getCorps().afficher();
  cout << "Bowser :" << endl;
  bowser.getCorps().afficher();
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  mario.attaquer(bowser);
  bowser.getEquipement().afficher();
  //bowser.getCorps().afficher();

  /*Armure arm = Armure("arm", 20, "Plaque", 3, 2, 25.3, couv);
  arm.afficher();
  Armure lolol = Armure();
  lolol.afficher();
  Armure lilol = Armure();
  lilol.afficher();
  Armure lalol = Armure();
  lalol.afficher();
  Armure lulol = Armure();
  lulol.afficher();*/
}
