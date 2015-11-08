#include "Bandage.hpp"


using namespace std;

/*-----Constructeur-----*/
Bandage::Bandage(){
  _nom = "Bandage";
  _description = "Un bandage en lin. Utilisez sur les plaies."
}

/*-----Constructeur-----*/
Bandage::Bandage(string nom, string des){
  _nom = nom;
  _description = des;
}


/*-----Getters-----*/
string getNom(){return _nom;}
string getDescription(){return _description;}

/*-----Setters-----*/
void setNom(string nom){_nom = nom;}
void setDescription(string des){_description = description;}


/*-----Autres méthodes-----*/
void afficher(){
  cout << "Nom : " << _nom << endl;
  cout << "Description : " << _description << endl;
}

void utiliser(Personnage p){

}
