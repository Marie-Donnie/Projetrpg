#include "Membre.hpp"
#include "Corps.hpp"
#include <iostream>


using namespace std;

/*-----Constructeur par défaut-----*/
Corps::Corps(){
  //Jambe Gauche
  Membre orteil0G = Membre(2, 2, "Quintus gauche", this);
  Membre orteil1G = Membre(2, 2, "Quartus gauche", this);
  Membre orteil2G = Membre(2, 2, "Tertius gauche", this);
  Membre orteil3G = Membre(2, 2, "Secundus gauche", this);
  Membre orteil4G = Membre(2, 2, "Hallux gauche", this);
  vector<Membre> pG;
  pG.push_back(orteil0G);
  pG.push_back(orteil1G);
  pG.push_back(orteil2G);
  pG.push_back(orteil3G);
  pG.push_back(orteil4G);
  Membre piedG = Membre(4, 4, "Pied gauche", pG, this);
  Membre genouG = Membre(4, 4, "Genou gauche", this);
  Membre cuisseG = Membre(4, 4, "Cuisse gauche", this);
  vector<Membre>jG;
  jG.push_back(piedG);
  jG.push_back(genouG);
  jG.push_back(cuisseG);
  Membre jambeG = Membre(10, 10, "Jambe gauche", jG, this);
  //Fin Jambe Gauche

  //Jambe Droite
  Membre orteil0D = Membre(2, 2, "Quintus droit", this);
  Membre orteil1D = Membre(2, 2, "Quartus droit", this);
  Membre orteil2D = Membre(2, 2, "Tertius droit", this);
  Membre orteil3D = Membre(2, 2, "Secundus droit", this);
  Membre orteil4D = Membre(2, 2, "Hallux droit", this);
  vector<Membre> pD;
  pD.push_back(orteil0D);
  pD.push_back(orteil1D);
  pD.push_back(orteil2D);
  pD.push_back(orteil3D);
  pD.push_back(orteil4D);
  Membre piedD = Membre(4, 4, "Pied droit", pD, this);
  Membre genouD = Membre(4, 4, "Genou droit", this);
  Membre cuisseD = Membre(4, 4, "Cuisse droite", this);
  vector<Membre>jD;
  jD.push_back(piedD);
  jD.push_back(genouD);
  jD.push_back(cuisseD);
  Membre jambeD = Membre(10, 10, "Jambe droite", jD, this);
  //Fin Jambe Droite

  //Bras Gauche
  Membre doigt0G = Membre(2, 2, "Auriculaire gauche", this);
  Membre doigt1G = Membre(2, 2, "Annulaire gauche", this);
  Membre doigt2G = Membre(2, 2, "Majeur gauche", this);
  Membre doigt3G = Membre(2, 2, "Index gauche", this);
  Membre doigt4G = Membre(2, 2, "Pouce gauche", this);
  vector<Membre> mG;
  mG.push_back(doigt0G);
  mG.push_back(doigt1G);
  mG.push_back(doigt2G);
  mG.push_back(doigt3G);
  mG.push_back(doigt4G);
  Membre mainG = Membre(4, 4, "Main gauche", mG, this);
  Membre coudeG = Membre(4, 4, "Coude gauche", this);
  Membre epauleG = Membre(4, 4, "Epaule gauche", this);
  vector<Membre>bG;
  bG.push_back(mainG);
  bG.push_back(coudeG);
  bG.push_back(epauleG);
  Membre brasG = Membre(10, 10, "Bras gauche", bG, this);
  //Fin Bras Gauche

  //Bras Droit
  Membre doigt0D = Membre(2, 2, "Auriculaire droit", this);
  Membre doigt1D = Membre(2, 2, "Annulaire droit", this);
  Membre doigt2D = Membre(2, 2, "Majeur droit", this);
  Membre doigt3D = Membre(2, 2, "Index droit", this);
  Membre doigt4D = Membre(2, 2, "Pouce droit", this);
  vector<Membre> mD;
  mD.push_back(doigt0D);
  mD.push_back(doigt1D);
  mD.push_back(doigt2D);
  mD.push_back(doigt3D);
  mD.push_back(doigt4D);
  Membre mainD = Membre(4, 4, "Main droite", mD, this);
  Membre coudeD = Membre(4, 4, "Coude droite", this);
  Membre epauleD = Membre(4, 4, "Epaule droite", this);
  vector<Membre>bD;
  bD.push_back(mainD);
  bD.push_back(coudeD);
  bD.push_back(epauleD);
  Membre brasD = Membre(10, 10, "Bras droit", bD, this);
  //Fin Bras Droit

  //Torse
  Membre coeur = Membre(3, 3, "Coeur", this);
  Membre poumonG = Membre(2, 2, "Poumon gauche", this);
  Membre poumonD = Membre(2, 2, "Poumon droit", this);
  Membre foie = Membre(2, 2, "Foie", this);
  Membre estomac = Membre(2, 2, "Estomac", this);
  Membre reinG = Membre(2, 2, "Rein gauche", this);
  Membre reinD = Membre(2, 2, "Rein droit", this);
  vector<Membre> leTorse;
  leTorse.push_back(coeur);
  leTorse.push_back(poumonG);
  leTorse.push_back(poumonD);
  leTorse.push_back(foie);
  leTorse.push_back(estomac);
  leTorse.push_back(reinG);
  leTorse.push_back(reinD);
  Membre torse = Membre(10, 10, "Torse", leTorse, this);
  //Fin Torse

  //Tête
  Membre joueG = Membre(2, 2, "Joue Gauche", this);
  Membre joueD = Membre(2, 2, "Joue Droite", this);
  Membre oreilleG = Membre(2, 2, "Oreille Gauche", this);
  Membre oreilleD = Membre(2, 2, "Oreille Droite", this);
  Membre oeilG = Membre(2, 2, "Oeil Gauche", this);
  Membre oeilD = Membre(2, 2, "Oeil Droit", this);
  Membre front = Membre(2, 2, "Front", this);
  vector<Membre> laTete;
  laTete.push_back(joueG);
  laTete.push_back(joueD);
  laTete.push_back(oreilleG);
  laTete.push_back(oreilleD);
  laTete.push_back(oeilG);
  laTete.push_back(oeilD);
  laTete.push_back(front);
  Membre tete = Membre(10, 10, "Tête", laTete, this);
  //Fin Tête

  _corps.push_back(jambeG);
  _corps.push_back(jambeD);
  _corps.push_back(brasG);
  _corps.push_back(brasD);
  _corps.push_back(torse);
  _corps.push_back(tete);

  suiv = NULL;
}
/*-----Fin du constructeur par défaut-----*/


/*-----Getters-----*/
vector<Membre>& Corps::getLMembres(){return _corps;}

int Corps::getPv(){
  int pv = 0;
  //On parcourt le corps
  for (int i=0; i < _corps.size(); ++i){
    //On récupère la référence vers chaque membre
    Membre& m = _corps.at(i);
    //On ajoute ses pvs
    pv += m.getPv();
    //On récupère ses sous-membres
    for (int j=0; j < m.getMembres().size(); ++j){
      Membre& sm = m.getMembres().at(j);
      //dont on ajoute les pvs
      pv += sm.getPv();
      if (i < 4 && j == 0) {
        //et à nouveau si on a affaire à une jambe ou un bras
        for (int k=0; k<sm.getMembres().size(); ++k){
          Membre& ssm = sm.getMembres().at(k);
          pv += ssm.getPv();
        }
      }
    }
  }
  return pv;
}//fin getPv()

int Corps::getPvMax(){
  int pvmax = 0;
  //On parcourt le corps
  for (int i=0; i < _corps.size(); ++i){
    //On récupère la référence vers chaque membre
    Membre& m = _corps.at(i);
    //On ajoute ses pvs
    pvmax += m.getPvMax();
    //On récupère ses sous-membres
    for (int j=0; j < m.getMembres().size(); ++j){
      Membre& sm = m.getMembres().at(j);
      //dont on ajoute les pvs
      pvmax += sm.getPvMax();
      if (i < 4 && j == 0) {
        //et à nouveau si on a affaire à une jambe ou un bras
        for (int k=0; k<sm.getMembres().size(); ++k){
          Membre& ssm = sm.getMembres().at(k);
          pvmax += ssm.getPvMax();
        }
      }
    }
  }
  return pvmax;
}//fin getPvMax()

/*--------Setters--------*/
void Corps::changerMembre(Membre m, int loca){
  _corps.at(loca) = m;
}

/*-----Méthodes de l'observer-----*/
Observer* Corps::getSuiv(){return suiv;}
void Corps::setSuiv(Observer* o){suiv = o;}
void Corps::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, m.getPv());
}
void Corps::traiter(Membre& m, int pv){
  //si le membre n'est plus là et a des sous-membres, on met tous les
  //sous-membres à 0
  if (pv == 0 && !m.getMembres().empty()){
    for (int i=0; i < m.getMembres().size(); ++i){
      Membre& sm = m.getMembres().at(i);
      sm.setPv(0);
      if (!sm.getMembres().empty()) {
        for (int j=0; j<sm.getMembres().size(); ++j){
          sm.getMembres().at(j).setPv(0);
        }
      }
    }
  }
  passer(m);
}
void Corps::updateObs(){
  for (int i=0; i < _corps.size(); ++i){
    Membre& m = _corps.at(i);
    m.setObs(this);
    for (int j=0; j < m.getMembres().size(); ++j){
      Membre& sm = m.getMembres().at(j);
      sm.setObs(this);
      if (i < 4 && j == 0) {
        for (int k=0; k<sm.getMembres().size(); ++k){
          Membre& ssm = sm.getMembres().at(k);
          ssm.setObs(this);
        }
      }
    }
  }
}// fin updateObs()


/*--------Autres méthodes--------*/
void Corps::soin(int membre){
  Membre& m = _corps.at(membre);
  //Le soin rend tous les pv
  m.setPv(m.getPvMax());
  for (int j=0; j < m.getMembres().size(); ++j){
    Membre& sm = m.getMembres().at(j);
    sm.setPv(sm.getPvMax());
    if (membre < 4 && j == 0) {
      for (int k=0; k<sm.getMembres().size(); ++k){
        Membre& ssm = sm.getMembres().at(k);
        ssm.setPv(ssm.getPvMax());
      }
    }
  }
}//fin soin(int membre)


void Corps::bandage(int membre, int niveau){
  Membre& m = _corps.at(membre);
  int add = m.getPv() + niveau;
  //Si les pvs actuels plus le soin sont inférieurs aux points de vie
  //maximum, on applique le soin, sinon on remet seulement le membre à
  //ses points de vie maximum
  if (add < m.getPvMax()){
    m.setPv(add);
  }
  else {m.setPv(m.getPvMax());}
  for (int j=0; j < m.getMembres().size(); ++j){
    Membre& sm = m.getMembres().at(j);
    add = sm.getPv() + niveau;
    if (add < sm.getPvMax()){
      sm.setPv(add);
    }
    else {sm.setPv(sm.getPvMax());}
    if (membre < 4 && j == 0) {
      for (int k=0; k<sm.getMembres().size(); ++k){
        Membre& ssm = sm.getMembres().at(k);
        add = ssm.getPv() + niveau;
        if (add < ssm.getPvMax()){
          ssm.setPv(add);
        }
        else {ssm.setPv(ssm.getPvMax());}
      }
    }
  }
}//fin bandage(int membre, int niveau)


void Corps::afficher(){
  cout << "-----------------Corps-----------------" << endl;
  for (int i=0; i < _corps.size(); ++i){
    Membre& m = _corps.at(i);
    cout << m.getNom() << " : "<< m.getPv() << endl ;
    for (int j=0; j < m.getMembres().size(); ++j){
      Membre& sm = m.getMembres().at(j);
      cout << "\t" << sm.getNom() << " : "<< sm.getPv() << endl;
      if (i < 4 && j == 0) {
        for (int k=0; k<sm.getMembres().size(); ++k){
          Membre& ssm = sm.getMembres().at(k);
          cout << "\t\t" <<ssm.getNom() << " : "<< ssm.getPv() << endl;
        }
      }
    }
  }
  cout << "-----------------Fin Corps-----------------" << endl;
}// fin afficher()
