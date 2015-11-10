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
  _armures.push_back(Armure("Jambieres"));
  _armures.push_back(Armure("Plastron"));
  _armures.push_back(Armure("Heaume"));
  _arme = Arme("Mains nues");
}

/*-----Constructeur par nom-----*/
Equipement::Equipement(string suff){
  _armures.push_back(Armure("Jambieres", suff));
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


/*-----Autres méthodes-----*/
Armure Equipement::changerArmure(Armure& a, int loca){
  Armure temp = _armures.at(loca);
  _armures.at(loca) = a;
  return temp;
}

Armure Equipement::changerArmure(Armure& a){
  if (a.getPiece().compare("Jambieres")==0){
    Armure temp = _armures.at(0);
    _armures.at(0) = a;
    return temp;}
  else if (a.getPiece().compare("Plastron")==0){
    Armure temp = _armures.at(1);
    _armures.at(1) = a;
    return temp;}
  else {
    Armure temp = _armures.at(2);
    _armures.at(2) = a;
    return temp;
  }
}

Arme Equipement::changerArme(Arme& a){
  Arme temp = _arme;
  _arme = a;
  return temp;
}

void Equipement::afficher(){
  cout << "*------------------Equipement------------------*" << endl;
  cout << "*------------------Armures------------------*" << endl;
  for (int i = 0; i < _armures.size(); ++i){
    _armures.at(i).afficher();
  }
  cout << "*------------------Arme------------------*" << endl;
  _arme.afficher();
}
