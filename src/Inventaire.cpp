#include "Inventaire.hpp"

using namespace std;

/*-----Constructeur par défaut-----*/
Inventaire::Inventaire(){}

/*-----Constructeur complet-----*/
Inventaire::Inventaire(vector<Armure>& armures, vector<Arme>& armes, boost::ptr_vector<Objet>& objets){
  _armures = armures;
  _armes = armes;
  _objets = objets;
}

/*-----Getters-----*/
vector<Armure>& Inventaire::getArmures(){return _armures;}
Armure& Inventaire::getArmure(int loca){return _armures.at(loca);}
vector<Arme>& Inventaire::getArmes(){return _armes;}
Arme& Inventaire::getArme(int loca){return _armes.at(loca);}
boost::ptr_vector<Objet>& Inventaire::getObjets(){return _objets;}
Objet& Inventaire::getObjet(int loca){return _objets.at(loca);}
int Inventaire::trouverObjet(string nom){
  int i=0;
  while (i<_objets.size() && ((_objets.at(i).getNom()).compare(nom) != 0)){
    ++i;
  }
  if ((_objets.at(i).getNom()).compare(nom) == 0){
    return i;
  }
  else return -1;
}


/*-----Setters-----*/
void Inventaire::setArmures(vector<Armure>& armures){_armures = armures;}
void Inventaire::setArmure(Armure& armure, int loca){_armures.at(loca) = armure;}
void Inventaire::setArmes(vector<Arme>& armes){_armes = armes;}
void Inventaire::setArme(Arme& arme, int loca){_armes.at(loca) = arme;}
void Inventaire::setObjets(boost::ptr_vector<Objet>& objets){_objets = objets;}
void Inventaire::ajouterArmure(Armure& armure){_armures.push_back(armure);}
void Inventaire::retirerArmure(int loca){_armures.erase(_armures.begin() + loca);}
void Inventaire::ajouterArme(Arme& arme){_armes.push_back(arme);}
void Inventaire::retirerArme(int loca){_armes.erase(_armes.begin() + loca);}
void Inventaire::ajouterObjet(Objet* objet){_objets.push_back(objet);}
void Inventaire::retirerObjet(int loca){_objets.erase(_objets.begin() + loca);}
void Inventaire::ajouter(Armure& armure){_armures.push_back(armure);}
void Inventaire::ajouter(Arme& arme){_armes.push_back(arme);}
void Inventaire::ajouter(Objet* objet){_objets.push_back(objet);}


/*-----Autres méthodes-----*/


Armure Inventaire::prendreArmure(int loca){
  Armure arm = _armures.at(loca);
  _armures.erase(_armures.begin() + loca);
  return arm;
}

Arme Inventaire::prendreArme(int loca){
  Arme arm = _armes.at(loca);
  _armes.erase(_armes.begin() + loca);
  return arm;
}

Objet Inventaire::prendreObjet(int loca){
  Objet obj = _objets.at(loca);
  _objets.erase(_objets.begin() + loca);
  return obj;
}

void Inventaire::utiliserObjet(Personnage& p, int loca){
   _objets.at(loca).utiliser(p);
   _objets.erase(_objets.begin() + loca);
}

void Inventaire::utiliserObjet(Personnage& p, int membre, int loca){
   _objets.at(loca).utiliser(p, membre);
   _objets.erase(_objets.begin() + loca);
}



void Inventaire::afficher(){
  cout << "*------------------Inventaire------------------*" << endl;
  cout << "*------------------Armures------------------*" << endl;
  for (int i = 0; i < _armures.size(); ++i){
    _armures.at(i).afficher();
  }
  cout << "*------------------Armes------------------*" << endl;
  for (int i = 0; i < _armes.size(); ++i){
    _armes.at(i).afficher();
  }
  cout << "*------------------Objets------------------*" << endl;
  for (int i = 0; i < _objets.size(); ++i){
    _objets.at(i).afficher();
  }
}
