//include guard
#ifndef PNJ_HPP
#define PNJ_HPP

//included dependencies
#include "SFML/Graphics.hpp"
#include <string>
#include "Stat.hpp"


using namespace std;

class PNJ {
private :
	string _nom;
	Stat _stats;
	//focus : ce que suit le PNJ -> rien, une entité, une position
	//state : l'action en cours du PNJ <- PATERN STATE ! (Patern ou pattern ? Gggnnnh!)
	bool _actif;

	sf::Vector2i _location;
	sf::Vector2f _position;
	sf::Texture _texture;
	sf::Sprite _sprite;


public :
	PNJ(string nom); //Constructeur sans texture
	PNJ(string nom, string texture); //Constructeur

	void afficher();

	//getters
	sf::Vector2i getLocation();
	sf::Vector2f getPosition();
	sf::Texture& getTexture();
	sf::Sprite& getSprite();

	//setters
	void setLocation(sf::Vector2i loc);
	void setLocation(int x, int y);
	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	void setTexture(string texture);
	void setSprite(int x, int y); //le sprite se sert dans la texture
	void setSprite(); //sprite par défaut

	//Mouvements
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	//activité
	bool isActif();
	void setActivity(bool activity);
	void switchActivity();


};

#endif //truc_HPP
