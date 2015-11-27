#include "Inventaire.hpp"
#include "Drap.hpp"

using namespace std;

/*-----Constructeur par défaut-----*/
Inventaire::Inventaire(){}

/*-----Constructeur complet-----*/
Inventaire::Inventaire(vector<Armure>& armures, vector<Arme>& armes, boost::ptr_vector<Objet>& objets){
  _armures = armures;
  _armes = armes;
  _objets = objets;
}

/*-----Constructeur spécial-----*/
Inventaire::Inventaire(string nom){
  //si c'est une armoire, on crée un inventaire aléatoire
  if (nom.compare("Armoire")==0){
    int chance = rand() %2;
    //si 1 on crée un "objet"
    if (chance){
      int type = rand()%2;
      //si 1 c'est une arme, 0 une armure
      if (type){
        Arme a = Arme();
        _armes.push_back(a);
      }
      else {
        Armure a = Armure();
        _armures.push_back(a);
      }
      //on teste si on recommence une fois
      int gigachance = rand()% 100 +1;
      //mais il faut une réussite critique
      if (gigachance > 97){
        int type = rand()%2;
        if (type){
          Arme a = Arme();
          _armes.push_back(a);
        }
        else {
          Armure a = Armure();
          _armures.push_back(a);
        }
      }
    }
  }//fin de l'inventaire aléatoire
  //si c'est un lit, on met un drap dans son inventaire
  else if (nom.compare("Lit")==0){
    Drap* drap = new Drap();
    _objets.push_back(drap);
  }
  //sinon si c'est l'armoire unique, on ajoute les objets spéciaux
  else if (nom.compare("Armoire spe")==0){
    _armes.push_back(Arme("Hallebarde du héros", 2, 2, 2, 2.5, 4, 5, 3, false));
    _armures.push_back(Armure("Heaume en acier incassable ou presque", "Heaume", "plaque", 1000, 6, 2, 3, 5.0));
  }
}//Fin des inventaires spéciaux

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

bool Inventaire::estVide(){
  bool vide = (_armures.empty() && _armes.empty() && _objets.empty());
  return vide;
}

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
  cout << "*------------------Fin Inventaire------------------*" << endl;
}

void Inventaire::afficherC(){
  cout << "*------------------Armures------------------*" << endl;
  for (int i = 0; i < _armures.size(); ++i){
    cout << _armures.at(i).getNom() << endl;
  }
  cout << "*------------------Armes------------------*" << endl;
  for (int i = 0; i < _armes.size(); ++i){
    cout << _armes.at(i).getNom()<< endl;
  }
  cout << "*------------------Objets------------------*" << endl;
  for (int i = 0; i < _objets.size(); ++i){
    cout << _objets.at(i).getNom()<<endl;
  }
}

void Inventaire::afficherArmures(){
  cout << "*------------------Armures------------------*" << endl;
  if (!_armures.empty()){
    for (Armure& a : _armures){
      a.afficher();
    }
  }
  else cout << "Pas d'armures dans l'inventaire" << endl;
}

void Inventaire::afficherArmes(){
  cout << "*------------------Armes------------------*" << endl;
  if (!_armes.empty()){
    for (Arme& a : _armes){
      a.afficher();
    }
  }
  else cout << "Pas d'armes dans l'inventaire" << endl;
}

void Inventaire::afficherObjets(){
  cout << "*------------------Objets------------------*" << endl;
  if (!_objets.empty()){
    for (int i = 0; i < _objets.size(); ++i){
      _objets.at(i).afficher();
    }
  }
  else cout << "Pas d'objets dans l'inventaire" << endl;
}
