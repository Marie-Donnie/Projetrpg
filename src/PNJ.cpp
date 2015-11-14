/**
 * @file PNJ.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe des pnjs
 **/


#include "../include/PNJ.hpp"
#include <iostream>


using namespace std;

PNJ::PNJ(string nom){
	_nom = nom;
	
	_stats = Stat();
	
	
	_position = sf::Vector2f(0,0);
	_actif = false;
}

PNJ::PNJ(string nom, string texture){
	_nom = nom;
	
	_stats = Stat();
	
	_actif = false; //revoir les attributs...
    
    if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
    
    _sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    _sprite.setOrigin(15.0,15.0);
	
	_position = sf::Vector2f(0,0);
}

void PNJ::afficher(){
	cout << "Salut je suis " << _nom << ", Nyark nyark !" << endl;
	cout << "Voici pas mes stats. Nah!" << endl;
	//_stats.afficher();
}

//getters
sf::Vector2i PNJ::getLocation(){return _location;}
sf::Vector2f PNJ::getPosition(){return _position;}
sf::Texture& PNJ::getTexture(){return _texture;}
sf::Sprite& PNJ::getSprite(){return _sprite;}

//setters
void PNJ::setLocation(sf::Vector2i loc){
	_location.x = loc.x; _location.y = loc.y;
}
void PNJ::setLocation(int x, int y){
	_location.x = x; _location.y = y;
}
void PNJ::setPosition(sf::Vector2f pos){
	_position.x = pos.x; _position.y = pos.y;
}
void PNJ::setPosition(float x, float y){
	_position.x = x; _position.y = y;
}
void PNJ::setTexture(string texture)
{
	if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
}
void PNJ::setSprite(int x, int y)
{
	_sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(x, y, x+16, y+16));
}
void PNJ::setSprite()
{
	_sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

//activité
bool PNJ::isActif()
{
	return _actif;
}
void PNJ::setActivity(bool activity)
{
	_actif = activity;
}
void PNJ::switchActivity()
{
	_actif = !_actif;
}
