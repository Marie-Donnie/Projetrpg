#include "Membre.hpp"
#include <iostream>


using namespace std;

//Constructeur
Membre::Membre(int pv, string nom, vector<Membre> sousm){
  _pv = pv;
  _nom = nom;
  _sousMembre = sousm;
}

Membre::Membre(int pv, string nom){
  _pv = pv;
  _nom = nom;
  _sousMembre = vector<Membre>();
}

Membre::Membre(){
  _pv = 0;
  _nom = "Membre bidon";
  _sousMembre = vector<Membre>();
}

//Setters
void Membre::setPv(int pv){
  _pv = pv;
}
void Membre::setNom(string nom){_nom = nom;}
void Membre::changerPv(int pv){
  _pv -= pv;
}
void Membre::changerMembre(Membre& m, int loca){
  _sousMembre[loca] = m;
}

//Getters
int Membre::getPv(){return _pv;}
string Membre::getNom(){return _nom;}
vector<Membre>& Membre::getMembres(){return _sousMembre;}
Membre& Membre::getMembre(int loca){return _sousMembre.at(loca);}
