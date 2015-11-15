#include "Objet.hpp"


using namespace std;


/*-----Constructeur-----*/
Objet::Objet(string nom, string des){
  _nom = nom;
  _description = des;
}
Objet::Objet(){}


/*-----Getters-----*/
string Objet::getNom(){return _nom;}
string Objet::getDescription(){return _description;}

/*-----Setters-----*/
void Objet::setNom(string nom){_nom = nom;}
void Objet::setDescription(string des){_description = des;}


/*-----Autres méthodes-----*/
void Objet::afficher(){
  cout << "Nom : " << _nom << endl;
  cout << "Description : " << _description << endl;
}

void Objet::utiliser(Personnage& p){}
void Objet::utiliser(Personnage& p, int membre){}
