#include <iostream>
#include "Membre.hpp"
#include "Observer.hpp"

using namespace std;

//Constructeur
Membre::Membre(int pv, int pvmax, string nom, vector<Membre> sousm, Observer* o){
  _pv = pv;
  _pvmax = pvmax;
  _nom = nom;
  _sousMembre = sousm;
  _corps = o;
}

Membre::Membre(int pv, int pvmax, string nom, Observer* o){
  _pv = pv;
  _pvmax = pvmax;
  _nom = nom;
  _sousMembre = vector<Membre>();
  _corps = o;
}

Membre::Membre(int pv, int pvmax, string nom){
  _pv = pv;
  _pvmax = pvmax;
  _nom = nom;
  _sousMembre = vector<Membre>();
  _corps = NULL;
}

Membre::Membre(){
  _pv = 0;
  _pvmax = 0;
  _nom = "Membre bidon";
  _sousMembre = vector<Membre>();
  _corps = NULL;
}

  /*-----Getters-----*/
int Membre::getPv(){return _pv;}
int Membre::getPvMax(){return _pvmax;}
string Membre::getNom(){return _nom;}
vector<Membre>& Membre::getMembres(){return _sousMembre;}
Membre& Membre::getMembre(int loca){return _sousMembre.at(loca);}

  /*-----Setters-----*/
void Membre::setPv(int pv){_pv = pv;}
void Membre::setPvMax(int pv){_pvmax = pv;}
void Membre::setNom(string nom){_nom = nom;}
void Membre::setObs(Observer* o){_corps = o;}
void Membre::changerPv(int pv){
  int coup = _pv - pv;
  if (coup > 0){
    _pv -= pv;
  }
  else _pv = 0;
}
void Membre::changerMembre(Membre& m, int loca){_sousMembre[loca] = m;}


void Membre::checkPv(){
  if (_corps)
  _corps->traiter(*this, _pv);
  else
    cout << "Le membre n'est pas dans un corps" << endl;
}
