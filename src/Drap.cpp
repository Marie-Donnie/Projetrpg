#include "Drap.hpp"


using namespace std;

/*-----Constructeur-----*/
Drap::Drap(){
  _nom = "Drap";
  _description = "Un drap en lin. Déchirez pour créer des bandages."
}

/*-----Constructeur-----*/
Drap::Drap(string nom, string des){
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
