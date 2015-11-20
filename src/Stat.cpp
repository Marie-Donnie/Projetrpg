#include "Stat.hpp"
#include <iostream>

using namespace std;


/*-----Constructeur par défaut-----*/
Stat::Stat(){
  _hitPoint = 177;
  _mana = 10;
  _endu = 1;
  _intel = 1;
  _force = 1;
  _agi = 1;
  _esprit = 1;
  _resiPeste = 1;
  _capCombat = 80;
  _capTir = 80;
  _vitesse = 2;
}

/*-----Constructeur complet-----*/
Stat::Stat(int hp, int mana, int endu, int intel, int force, int agi, int esprit, int rP, int cc, int ct, int vitesse){
  _hitPoint = hp;
  _mana = mana;
  _endu = endu;
  _intel = intel;
  _force = force;
  _agi = agi;
  _esprit = esprit;
  _resiPeste = rP;
  _capCombat = cc;
  _capTir = ct;
  _vitesse = vitesse;
}

/*-----Getters-----*/
int Stat::getHP(){return _hitPoint;}
int Stat::getMana(){return _mana;}
int Stat::getIntel(){return _intel;}
int Stat::getEndu(){return _endu;}
int Stat::getForce(){return _force;}
int Stat::getAgi(){return _agi;}
int Stat::getEsprit(){return _esprit;}
int Stat::getRP(){return _resiPeste;}
int Stat::getCc(){return _capCombat;}
int Stat::getCt(){return _capTir;}
int Stat::getVitesse(){return _vitesse;}

/*-----Setters-----*/
void Stat::setHP(int hp){_hitPoint = hp;}
void Stat::setMana(int mana){_mana = mana;}
void Stat::setEndu(int endu){_endu = endu;}
void Stat::setIntel(int intel){_intel = intel;}
void Stat::setForce(int force){_force = force;}
void Stat::setAgi(int agi){_agi = agi;}
void Stat::setEsprit(int esprit){_esprit = esprit;}
void Stat::setRP(int rP){_resiPeste = rP;}
void Stat::setCc(int cc){_capCombat = cc;}
void Stat::baisserCc(){_capCombat -= 20;}
void Stat::monterCc(){_capCombat += 20;}
void Stat::setCt(int ct){_capTir = ct;}
void Stat::baisserVitesse(){--_vitesse;}
void Stat::monterVitesse(){++_vitesse;}


void Stat::afficher(){
  cout << "Points de vie : " << _hitPoint << endl;
  cout << "Points de mana : " << _mana  << endl;
  cout << "Endurance : " << _endu  << endl;
  cout << "Intelligence : "<< _intel  << endl;
  cout << "Force : "<< _force  << endl;
  cout << "Agilité : "<< _agi << endl;
  cout << "Esprit : "<< _esprit  << endl;
  cout << "Résistance à la peste : " << _resiPeste << endl;
  cout << "Capacité de combat : " << _capCombat << endl;
  cout << "Capacité de tir : " << _capTir  << endl;
  cout << "Vitesse : " << _vitesse << endl;
}
