/**
 * @file PNJ.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe Case
 **/


#include "Case.hpp"
#include <iostream>


using namespace std;

Case::Case(){}

//getters
bool Case::estAccessible()
{
	return (_hauteur == 0) and (_occupant == -1);
}
bool Case::estTransparent()
{
	return _transparent;
}

int Case::getOccupant(){return _occupant;}

sf::Vector2f Case::getPosition(){return _sprite.getPosition();}

int Case::getHauteur(){return _hauteur;}
sf::Texture& Case::getTexture(){return _texture;}
sf::Sprite& Case::getSprite(){return _sprite;}


//setters

void Case::setOccupant(int occ){
	_occupant = occ;
}

void Case::setTransparent(bool t){
	_transparent = t;
}

void Case::setPosition(sf::Vector2f pos){_sprite.setPosition(pos);}
void Case::setPosition(float x, float y){_sprite.setPosition(x,y);}

void Case::setHauteur(int h){_hauteur = h;}
void Case::setTexture(sf::Texture & t){
	_texture = t;
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

//choix de la zone de texture que prend le sprite
void Case::setSprite(int i, int j)
{
	_sprite.setTextureRect(sf::IntRect(16*i, 16*j, 16, 16));
}

