#include "Arme.hpp"

using namespace std;


Arme::Arme(string nom, int type, int mains, double vitesse, int dmgmin, int dmgmax, int penetration, bool contondant){
  _nom = nom;
  _type = type;
  _mains = mains;
  _vitesse = vitesse;
  _dmgmin = dmgmin;
  _dmgmax = dmgmax;
  _penetration = penetration;
  _contondant = contondant;
}

Arme::Arme(int type, int mains){
  _type = type;
  _mains = mains;
  if (type==0){
    _nom = "Epée à "+ _mains + "main" + ((_mains==1)?"s":"");
    _vitesse = rand() %3;
  }
  if (type==1){
    _nom = "Masse à "+ _mains + "main" + ((_mains==1)?"s":"");
  }
  else if (_mains==1){
    _nom = "Dague";

  }
  else {
    _nom = "Hallebarde";
  }
}

Arme::Arme(){
  _nom =
    }
