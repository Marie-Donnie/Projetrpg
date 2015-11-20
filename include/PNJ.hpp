//include guard
#ifndef PNJ_HPP
#define PNJ_HPP

//Forward declared dependencies
class Monde;
class Personnage;

//included dependencies
#include "SFML/Graphics.hpp"
#include <string>
#include "Stat.hpp"
#include "Equipement.hpp"
#include "Corps.hpp"
#include "Observer.hpp"
#include "Entite.hpp"

using namespace std;

class PNJ : public Observer, public Entite {
private :
	string _nom;
	Stat _stats;
	Equipement _equi;
	Corps _corps;

	int _state;	//state : l'action en cours du PNJ <- PATERN STATE ! (Patern ou pattern ? Gggnnnh!)
	sf::Vector2i _destination;	//si _destinnation == _location : reste sur place
	int _focus;	//-1: rien, 0: personnage, 1..n: pnj de 0 à n-1

	bool _enJeu; //un pnj pourrait pop ou depop


public :
	PNJ(string nom); //Constructeur sans texture
	PNJ(string nom, string texture); //Constructeur

	void afficher();

	//getters
	string getNom();
	Stat& getStats();
	Corps& getCorps();
	Equipement& getEquipement();

	//setters

  //Methodes de l'Observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  virtual void traiter(Membre& m, int pv);
  virtual void passer(Membre& m);

	//activité
	bool estEnJeu();
	void setEnJeu(bool set);

	//vision
	bool voitCase(sf::Vector2i loc, Monde & monde);
	bool voitCase(int i, int j, Monde & monde);

	//combat
	void defendre(Personnage& attaquant);
};

#endif //truc_HPP
