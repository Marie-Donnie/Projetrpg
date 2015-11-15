#include "Drap.hpp"
#include "Personnage.hpp"
#include "Bandage.hpp"

using namespace std;

/*-----Constructeur-----*/
Drap::Drap(){
  _nom = "Drap";
  _description = "Un drap en lin. Déchirez pour créer des bandages.";
}

/*-----Constructeur-----*/
Drap::Drap(string nom, string des): Objet(nom, des){}


/*-----Getters-----*/
string Drap::getNom(){return _nom;}
string Drap::getDescription(){return _description;}

/*-----Setters-----*/
void Drap::setNom(string nom){_nom = nom;}
void Drap::setDescription(string des){_description = des;}


/*-----Autres méthodes-----*/
void Drap::afficher(){
  cout << "Nom : " << _nom << endl;
  cout << "Description : " << _description << endl;
}

void Drap::utiliser(Personnage& p){
  p.getInventaire().ajouterObjet(new Bandage());
  p.getInventaire().ajouterObjet(new Bandage());
  p.getInventaire().ajouterObjet(new Bandage());
 }
