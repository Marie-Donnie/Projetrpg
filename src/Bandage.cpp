#include "Bandage.hpp"
#include "Personnage.hpp"

using namespace std;

/*-----Constructeur-----*/
Bandage::Bandage(){
  _nom = "Bandage";
  _description = "Un bandage en lin. Utilisez sur les plaies.";
}

/*-----Constructeur-----*/
Bandage::Bandage(string nom, string des): Objet(nom, des){}


/*-----Getters-----*/
string Bandage::getNom(){return _nom;}
string Bandage::getDescription(){return _description;}

/*-----Setters-----*/
void Bandage::setNom(string nom){_nom = nom;}
void Bandage::setDescription(string des){_description = des;}


/*-----Autres méthodes-----*/
void Bandage::afficher(){
  cout << "Nom : " << _nom << endl;
  cout << "Description : " << _description << endl;
}

void Bandage::utiliser(Personnage& p){
  p.bandage();
}
