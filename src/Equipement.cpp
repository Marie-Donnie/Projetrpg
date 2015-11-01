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
}

/*-----Constructeur par nom-----*/
Equipement::Equipement(string suff){
  _armures.push_back(Armure("Jambières", suff));
  _armures.push_back(Armure("Plastron", suff));
  _armures.push_back(Armure("Heaume", suff));
}

/*-----Constructeur complet-----*/
Equipement::Equipement(vector<Armure>& armor){
  _armures = armor;
}

/*-----Getters-----*/
vector<Armure>& Equipement::getArmures(){
  return _armures;
}

Armure& Equipement::getArmure(int loca){
  return _armures.at(loca);
}

/*-----Setters-----*/
void Equipement::changerArmure(Armure& a, int loca){
  _armures.at(loca) = a;
}


/*-----Autres méthodes-----*/
void Equipement::afficher(){
  cout << "*------------------Equipement------------------*" << endl;
  for (int i = 0; i < _armures.size(); ++i){
    _armures.at(i).afficher();
  }
}
