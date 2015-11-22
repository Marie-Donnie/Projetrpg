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

	int _state;	//state : à définir
	sf::Vector2i _destination;	//si _destinnation == _location : reste sur place
	int _focus;	//-1: rien, 0: personnage, 1..n: pnj de 0 à n-1

	bool _enJeu; //un pnj pourrait pop ou depop


public :
  PNJ(string nom); //Constructeur sans texture
  PNJ(string nom, string texture); //Constructeur

  PNJ(const PNJ& lautre);
  PNJ& operator=(const PNJ& lautre);

  void afficher();

  //getters
  string getNom();
  Stat& getStats();
  Corps& getCorps();
  Equipement& getEquipement();

  bool estEnJeu();

  //setters
  void setTexture(sf::Texture & texture);
  void setTexture(string texture);
  void setEnJeu(bool set);

  //Methodes de l'Observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  void traiter(Membre& m, int pv);
  void passer(Membre& m);

	//vision
	bool voitCase(sf::Vector2i loc, Monde & monde);
	bool voitCase(int i, int j, Monde & monde);
	bool detecteCase(int i, int j);
	bool detecteCase(sf::Vector2i loc);

	//Mouvement
	void move(int direction);
	void move(sf::Time turnTime); //durée par défaut différente

	//combat
	void defendre(Personnage& attaquant);
  void attaquer(Personnage& defendant);
  
  void action(sf::Time turnTime);
};

#endif //truc_HPP
