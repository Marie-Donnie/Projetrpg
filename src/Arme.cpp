#include "Arme.hpp"


using namespace std;

/*-----Constructeur complet-----*/
Arme::Arme(string nom, int type, int mains, int portee, double vitesse, int dmgmin, int dmgmax, int penetration, bool contondant){
  _nom = nom;
  _type = type;
  _mains = mains;
  _portee = portee;
  _vitesse = vitesse;
  _dmgmin = dmgmin;
  _dmgmax = dmgmax;
  _penetration = penetration;
  _contondant = contondant;
}

/*-----Constructeur partiel-----*/
Arme::Arme(int type, int mains){
  _type = type;
  _mains = mains;
  _portee = _mains;
  if (_type==0){
    _nom = ((_mains==1)?"Epée à une main":"Epée à deux mains");
    _vitesse = _mains + (rand() %5 + 6)/10.0;
    _dmgmin = ((_mains==1)?1:3) + rand() % 3;
    _dmgmax = ((_mains==1)?3:5) + rand() % 2;
    _penetration = _mains;
    _contondant = false;
  }
  else if (_type==1){
    _nom = ((_mains==1)?"Masse à une main":"Masse à deux mains");
    _vitesse = 1 + _mains + (rand() %5 + 6)/10.0;
    _dmgmin = ((_mains==1)?2:4) + rand() % 3;
    _dmgmax = ((_mains==1)?4:6) + rand() % 2;
    _penetration = 0;
    _contondant = true;
  }
  else {
    if (_mains==1){
      _nom = "Dague";
      _vitesse = (rand() %5 + 7)/10.0;
      _dmgmin = 1 + rand()%2;
      _dmgmax = 2 + rand()%2;
      _penetration = 0;
      _contondant = false;

    }
    else {
      _nom = "Hallebarde";
      _vitesse = 2 + (rand() %5 + 6)/10.0;
      _dmgmin = 3 + rand()%2;;
      _dmgmax = 4 + rand()%2;;
      _penetration = 3;
      _contondant = false;
    }
  }
}

/*-----Constructeur partiel-----*/
Arme::Arme(string nom){
  _nom = nom;
  _type = 5;
  _mains = 0;
  _portee = 1;
  _vitesse = 1;
  _dmgmin = 0;
  _dmgmax = 0;
  _penetration = 0;
  _contondant = true;
}

/*-----Constructeur par défaut-----*/
Arme::Arme(){
  _nom = "lol";
  _type = 1;
  _mains = 1;
  _portee = _mains;
  _vitesse = 2.2;
  _dmgmin = 3;
  _dmgmax = 4;
  _penetration = 2;
  _contondant = true;
}


/*-----Getters-----*/
string Arme::getNom(){return _nom;}
int Arme::getType(){return _type;}
int Arme::getMains(){return _mains;}
int Arme::getPortee(){return _portee;}
double Arme::getVitesse(){return _vitesse;}
int Arme::getDmgmin(){return _dmgmin;}
int Arme::getDmgmax(){return _dmgmax;}
int Arme::getPene(){return _penetration;}
bool Arme::getContondance(){return _contondant;}

/*-----Setters-----*/
void Arme::setNom(string nom){_nom = nom;}
void Arme::setType(int type){_type = type;}
void Arme::setMains(int mains){_mains = mains;}
void Arme::setPortee(int portee){_portee = portee;}
void Arme::setVitesse(double vitesse){_vitesse = vitesse;}
void Arme::setDmgmin(int dmgmin){_dmgmin = dmgmin;}
void Arme::setDmgmax(int dmgmax){_dmgmax = dmgmax;}
void Arme::setPene(int penetration){_penetration = penetration;}
void Arme::setContondance(bool contondance){_contondant = contondance;}


/*-----Autres méthodes-----*/
void Arme::afficher(){
  cout << "Nom : " << _nom << endl;
  cout << "Portée : " << _portee << endl;
  cout << "Vitesse : " << _vitesse << endl;
  cout << "Dommages minimum->maximum : " << _dmgmin << "->" << _dmgmax << endl;
  cout << "Indice de pénétration : " << _penetration << endl;
  cout << "Capacité d'assomer : " << (_contondant?"oui":"non") << endl;
  cout << "Dommages moyens : " << (((_dmgmax + _dmgmin)/2.0)/_vitesse) << endl;
}
