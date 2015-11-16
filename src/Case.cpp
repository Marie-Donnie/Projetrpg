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
	return true;
}

int Case::getOccupant(){return _occupant;}

sf::Vector2f Case::getPosition(){return Entite::_sprite.getPosition();}

//setters

void Case::setOccupant(int occ){
	_occupant = occ;
}


void Case::setPosition(sf::Vector2f pos){Entite::_sprite.setPosition(pos);}
void Case::setPosition(float x, float y){Entite::_sprite.setPosition(x,y);}