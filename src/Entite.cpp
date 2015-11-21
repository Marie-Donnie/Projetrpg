/**
 * @file PNJ.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe Case
 **/

#include "SFML/Graphics.hpp"

#include <string>
#include "Entite.hpp"


using namespace std;

//CONSTRUCTEURS
Entite::Entite(){
	_direction = 1;
	_actif = false;
	
    _sprite.setPosition(392,292); //le centre de l'écran : (400,300) moins une demi case de 16px
}

Entite::Entite(string texture)
{
	_direction = 1;
	_actif = false;
    
    if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}

    _sprite.setPosition(392,292); //le centre de l'écran est : (400,300)
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
}

//Getters
sf::Vector2i Entite::getLocation(){return _location;}
int Entite::getLocX(){return _location.x;}
int Entite::getLocY(){return _location.y;}

sf::Vector2f Entite::getPosition(){return _position;}
float Entite::getPosX(){return _position.x;}
float Entite::getPosY(){return _position.y;}

sf::Texture& Entite::getTexture(){return _texture;}
sf::Sprite& Entite::getSprite(){return _sprite;}

bool Entite::estActif(){return _actif;}
int Entite::getAction(){return _action;}
int Entite::getDirection(){return _direction;}

bool Entite::estImmobile(){
	return (_action != 0) or !_actif;
}


//Setters
void Entite::setLocation(sf::Vector2i loc){
	_location.x = loc.x; _location.y = loc.y;
}
void Entite::setLocation(int x, int y){
	_location.x = x; _location.y = y;
}
void Entite::setPosition(sf::Vector2f pos){
	_position.x = pos.x; _position.y = pos.y;
}
void Entite::setPosition(float x, float y){
	_position.x = x; _position.y = y;
}
void Entite::setTexture(string texture)
{
	if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_sprite.setTexture(_texture);
	setSprite();
}
void Entite::setSprite(int d) //direction haut, bas, gauche, droite
{
	_sprite.setTextureRect(sf::IntRect((d*16), 0, 16, 16));
}
void Entite::setSprite()
{
	_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16)); //pour avoir celui de face
}
void Entite::setDirection(int d)
{
	_direction = d;
}
void Entite::setAction(int a)
{
	_action = a;
}

//mouvements
//>Mises en mouvement
void Entite::move(int direction)
{
	_actif = true;
	_direction = direction;
	_action = 0; //0: déplacement
	_tempsAction = sf::Time::Zero;

	if(_direction == 0)
		_location.y -= 1;
	else if (_direction == 1)
		_location.y += 1;
	else if (_direction == 2)
		_location.x -= 1;
	else if (_direction == 3)
		_location.x += 1;


}

//>Mouvement en cours
void Entite::move(sf::Time turnTime)
{
	move(turnTime, sf::seconds(0.33));
}
void Entite::move(sf::Time turnTime, sf::Time d)
{
	_tempsAction += turnTime;
	sf::Time duree = d;

	if(_tempsAction < duree)
	{
		float rapport = _tempsAction.asSeconds() / duree.asSeconds();
		if(_direction==0)
			_position.y = (float)(_location.y * 16) + 16 - (16*rapport);
		else if(_direction==1)
			_position.y = (float)(_location.y * 16) - 16 + (16*rapport);
		else if(_direction==2)
			_position.x = (float)(_location.x * 16) + 16 - (16*rapport);
		else if(_direction==3)
			_position.x = (float)(_location.x * 16) - 16 + (16*rapport);

	}
	else
	{
		_position.x = (float)(_location.x * 16);
		_position.y = (float)(_location.y * 16);

		_actif = false;
	}
}

