#include "Objet.hpp"


using namespace std;


/*-----Constructeur-----*/
Objet::Objet(string nom, string des){
  _nom = nom;
  _description = des;
}


/*-----Getters-----*/
virtual string getNom(){return _nom;}
virtual string getDescription(){return _description;}

/*-----Setters-----*/
virtual void setNom(string nom){_nom = nom;}
virtual void setDescription(string des){_description = description;}


/*-----Autres méthodes-----*/
virtual void afficher(){
  cout << "Nom : " << _nom << endl;
  cout << "Description : " << _description << endl;
}

virtual void utiliser(Personnage p){}
