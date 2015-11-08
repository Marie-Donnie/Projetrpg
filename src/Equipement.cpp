/**
 * @file Equipement.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe d'équipement du personnage
 **/


#include "Equipement.hpp"


using namespace std;

/*-----Constructeur par défaut-----*/
Equipement::Equipement(){
  _armures.push_back(Armure("Jambières"));
  _armures.push_back(Armure("Plastron"));
  _armures.push_back(Armure("Heaume"));
  _arme = Arme("Mains nues");
}

/*-----Constructeur par nom-----*/
Equipement::Equipement(string suff){
  _armures.push_back(Armure("Jambières", suff));
  _armures.push_back(Armure("Plastron", suff));
  _armures.push_back(Armure("Heaume", suff));
  _arme = Arme("Mains nues");
}

/*-----Constructeur complet-----*/
Equipement::Equipement(vector<Armure>& armures, Arme& arme){
  _armures = armures;
  _arme = arme;
}

/*-----Getters-----*/
vector<Armure>& Equipement::getArmures(){
  return _armures;
}

Armure& Equipement::getArmure(int loca){
  return _armures.at(loca);
}

Arme& Equipement::getArme(){
  return _arme;
}

/*-----Setters-----*/
void Equipement::changerArmure(Armure& a, int loca){
  _armures.at(loca) = a;
}

void Equipement::changerArme(Arme& a){
  _arme = a;
}

/*-----Autres méthodes-----*/
void Equipement::afficher(){
  cout << "*------------------Equipement------------------*" << endl;
  cout << "*------------------Armures------------------*" << endl;
  for (int i = 0; i < _armures.size(); ++i){
    _armures.at(i).afficher();
  }
  cout << "*------------------Arme------------------*" << endl;
  _arme.afficher();
}
