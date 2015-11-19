/**
 * @file PNJ.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe Case
 **/


#include "Entite.hpp"


using namespace std;

Entite::Entite(){}

Entite::Entite(sf::Texture &texture){
	_texture = texture;

	_sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

//getters
int Entite::getHauteur(){return _hauteur;}
sf::Texture& Entite::getTexture(){return _texture;}
sf::Sprite& Entite::getSprite(){return _sprite;}

//setters
void Entite::setHauteur(int h){_hauteur = h;}
void Entite::setTexture(sf::Texture & t){
	_texture = t;
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

//choix de la zone de texture que prend le sprite
void Entite::setSprite(int i, int j)
{
	_sprite.setTextureRect(sf::IntRect(16*i, 16*j, 16, 16));
}
