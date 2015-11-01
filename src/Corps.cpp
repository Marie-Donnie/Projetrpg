#include "Corps.hpp"
#include <iostream>


using namespace std;

/*-----Constructeur par défaut-----*/
Corps::Corps(){
  //Jambe Gauche
  Membre orteil0G = Membre(2, "Quintus gauche");
  Membre orteil1G = Membre(2, "Quartus gauche");
  Membre orteil2G = Membre(2, "Tertius gauche");
  Membre orteil3G = Membre(2, "Secundus gauche");
  Membre orteil4G = Membre(2, "Hallux gauche");
  vector<Membre> pG;
  pG.push_back(orteil0G);
  pG.push_back(orteil1G);
  pG.push_back(orteil2G);
  pG.push_back(orteil3G);
  pG.push_back(orteil4G);
  Membre piedG = Membre(4, "Pied gauche", pG);
  Membre genouG = Membre(4, "Genou gauche");
  Membre cuisseG = Membre(4, "Cuisse gauche");
  vector<Membre>jG;
  jG.push_back(piedG);
  jG.push_back(genouG);
  jG.push_back(cuisseG);
  Membre jambeG = Membre(10, "Jambe gauche", jG);
  //Fin Jambe Gauche

  //Jambe Droite
  Membre orteil0D = Membre(2, "Quintus droit");
  Membre orteil1D = Membre(2, "Quartus droit");
  Membre orteil2D = Membre(2, "Tertius droit");
  Membre orteil3D = Membre(2, "Secundus droit");
  Membre orteil4D = Membre(2, "Hallux droit");
  vector<Membre> pD;
  pD.push_back(orteil0D);
  pD.push_back(orteil1D);
  pD.push_back(orteil2D);
  pD.push_back(orteil3D);
  pD.push_back(orteil4D);
  Membre piedD = Membre(4, "Pied droit", pD);
  Membre genouD = Membre(4, "Genou droit");
  Membre cuisseD = Membre(4, "Cuisse droite");
  vector<Membre>jD;
  jD.push_back(piedD);
  jD.push_back(genouD);
  jD.push_back(cuisseD);
  Membre jambeD = Membre(10, "Jambe droite", jD);
  //Fin Jambe Droite

  //Bras Gauche
  Membre doigt0G = Membre(2, "Auriculaire gauche");
  Membre doigt1G = Membre(2, "Annulaire gauche");
  Membre doigt2G = Membre(2, "Majeur gauche");
  Membre doigt3G = Membre(2, "Index gauche");
  Membre doigt4G = Membre(2, "Pouce gauche");
  vector<Membre> mG;
  mG.push_back(doigt0G);
  mG.push_back(doigt1G);
  mG.push_back(doigt2G);
  mG.push_back(doigt3G);
  mG.push_back(doigt4G);
  Membre mainG = Membre(4, "Main gauche", mG);
  Membre coudeG = Membre(4, "Coude gauche");
  Membre epauleG = Membre(4, "Epaule gauche");
  vector<Membre>bG;
  bG.push_back(mainG);
  bG.push_back(coudeG);
  bG.push_back(epauleG);
  Membre brasG = Membre(10, "Bras gauche", bG);
  //Fin Bras Gauche

  //Bras Droit
  Membre doigt0D = Membre(2, "Auriculaire droite");
  Membre doigt1D = Membre(2, "Annulaire droite");
  Membre doigt2D = Membre(2, "Majeur droite");
  Membre doigt3D = Membre(2, "Index droite");
  Membre doigt4D = Membre(2, "Pouce droite");
  vector<Membre> mD;
  mD.push_back(doigt0D);
  mD.push_back(doigt1D);
  mD.push_back(doigt2D);
  mD.push_back(doigt3D);
  mD.push_back(doigt4D);
  Membre mainD = Membre(4, "Main droite", mD);
  Membre coudeD = Membre(4, "Coude droite");
  Membre epauleD = Membre(4, "Epaule droite");
  vector<Membre>bD;
  bD.push_back(mainD);
  bD.push_back(coudeD);
  bD.push_back(epauleD);
  Membre brasD = Membre(10, "Bras droit", bD);
  //Fin Bras Droit

  //Torse
  Membre coeur = Membre(3, "Coeur");
  Membre poumonG = Membre(2, "Poumon gauche");
  Membre poumonD = Membre(2, "Poumon droit");
  Membre foie = Membre(2, "Foie");
  Membre estomac = Membre(2, "Estomac");
  Membre reinG = Membre(2, "Rein gauche");
  Membre reinD = Membre(2, "Rein droit");
  vector<Membre> leTorse;
  leTorse.push_back(coeur);
  leTorse.push_back(poumonG);
  leTorse.push_back(poumonD);
  leTorse.push_back(foie);
  leTorse.push_back(estomac);
  leTorse.push_back(reinG);
  leTorse.push_back(reinD);
  Membre torse = Membre(10, "Torse", leTorse);
  //Fin Torse

  //Tête
  Membre joueG = Membre(2, "Joue Gauche");
  Membre joueD = Membre(2, "Joue Droite");
  Membre oreilleG = Membre(2, "Oreille Gauche");
  Membre oreilleD = Membre(2, "Oreille Droite");
  Membre oeilG = Membre(2, "Oeil Gauche");
  Membre oeilD = Membre(2, "Oeil Droit");
  Membre front = Membre(2, "Front");
  vector<Membre> laTete;
  laTete.push_back(joueG);
  laTete.push_back(joueD);
  laTete.push_back(oreilleG);
  laTete.push_back(oreilleD);
  laTete.push_back(oeilG);
  laTete.push_back(oeilD);
  laTete.push_back(front);
  Membre tete = Membre(10, "Tête", laTete);
  //Fin Tête

  _corps.push_back(jambeG);
  _corps.push_back(jambeD);
  _corps.push_back(brasG);
  _corps.push_back(brasD);
  _corps.push_back(torse);
  _corps.push_back(tete);

}
/*-----Fin du constructeur par défaut-----*/


/*-----Getters-----*/
vector<Membre>& Corps::getLMembres(){return _corps;}


/*-----Setters-----*/
void Corps::changerMembre(Membre m, int loca){
  _corps.at(loca) = m;
}


/*-----Autre méthodes-----*/

/*Afficher()*/
void Corps::afficher(){
  //cout << &_corps;
  cout << "-----------------Corps-----------------" << endl;
  for (int i=0; i < _corps.size(); ++i){
    Membre& m = _corps.at(i);
    //cout << &m;
    cout << m.getNom() << " : "<< m.getPv() << endl ;
    for (int j=0; j < m.getMembres().size(); ++j){
      Membre& sm = m.getMembres().at(j);
      //cout << &sm;
      cout << "\t" << sm.getNom() << " : "<< sm.getPv() << endl;
      if (i < 4 && j == 0) {
        for (int k=0; k<sm.getMembres().size(); ++k){
          Membre& ssm = sm.getMembres().at(k);
          //cout << &ssm;
          cout << "\t\t" <<ssm.getNom() << " : "<< ssm.getPv() << endl;
        }
      }
    }
  }
  cout << "-----------------Fin Corps-----------------" << endl;
}
/*Fin de Afficher()*/
