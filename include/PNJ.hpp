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


using namespace std;

class PNJ {
private :
	string _nom;
	Stat _stats;
	Equipement _equi;
	Corps _corps;
	
	int _state;	//state : l'action en cours du PNJ <- PATERN STATE ! (Patern ou pattern ? Gggnnnh!)
	sf::Vector2i _destination;	//si _destinnation == _location : reste sur place
	int _focus;	//-1: rien, 0: personnage, 1..n: pnj de 0 à n-1
	
	bool _enJeu; //un pnj pourrait pop ou depop
	
	bool _actif;
	int _action;
	int _direction;
	sf::Time _tempsAction;
  
	sf::Vector2i _location;
	sf::Vector2f _position;
	sf::Texture _texture;
	sf::Sprite _sprite;


public :
	PNJ(string nom); //Constructeur sans texture
	PNJ(string nom, string texture); //Constructeur
	
	void afficher();

	//getters
	string getNom();
	Stat& getStats();
	Corps& getCorps();
	Equipement& getEquipement();
	
	sf::Vector2i getLocation();
	sf::Vector2f getPosition();
	sf::Texture& getTexture();
	sf::Sprite& getSprite();
	
	bool estActif();
	int getAction();
	int getDirection();
	
	bool estImmobile();
	
	//setters
	void setLocation(sf::Vector2i loc);
	void setLocation(int x, int y);
	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	void setTexture(string texture);
	void setSprite(int x, int y);  //à actualiser !
	void setSprite(); //sprite par défaut
	
	//Mouvements
	void move(int direction);
	void move(sf::Time turnTime);
  
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
