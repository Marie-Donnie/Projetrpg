/**
 * @file Monde.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la map monde
 **/

#include "Monde.hpp"

Monde::Monde(){}

Monde::Monde(const int x, const int y, std::string texture)
{
	_x = x;
	_y = y;
	_map = new cell[x*y];
	_terrain.setPrimitiveType(sf::Quads);
	_terrain.resize(x * y * 4);

	if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}

	int indice;
	for(int i = 0 ; i < x ; ++i)
	{
		for(int j = 0 ; j < y ; ++i)
		{
			//initialisation de la matrice map
			indice = i + y*j;
			_map[indice].accessibilite = true;
			_map[indice].occupant = 0;
			_map[indice].objet = 0;
			_map[indice].textureX = 0;
			_map[indice].textureY = 0;

			//"initialisation" du tableau de vertex
			_terrain[4*indice].position = sf::Vector2f( 16*i, 16*j);
			_terrain[(4*indice)+1].position = sf::Vector2f( 16*(i+1), 16*j);
			_terrain[(4*indice)+2].position = sf::Vector2f( 16*(i+1), 16*(j+1));
			_terrain[(4*indice)+3].position = sf::Vector2f( 16*i, 16*(j+1));
			//Note: les coordonnées des cases évolueront constamment parallèlement au personnage

			//initialisation des sprites
			_terrain[4*indice].texCoords = sf::Vector2f(0, 0);
			_terrain[(4*indice)+1].texCoords = sf::Vector2f(16, 0);
			_terrain[(4*indice)+2].texCoords = sf::Vector2f(16, 16);
			_terrain[(4*indice)+3].texCoords = sf::Vector2f(0, 16);
		}
	}
}

//getters
bool Monde::estAccessible(int i, int j){return _map[i+(_y*j)].accessibilite;}
int Monde::getOccupant(int i, int j){return _map[i+(_y*j)].occupant;}
int Monde::getObjet(int i, int j){return _map[i+(_y*j)].objet;}
int Monde::getX(){return _x;}
int Monde::getY(){return _y;}

//setters
void Monde::setAccess(int i, int j, bool access){
	_map[i+(_y*j)].accessibilite = access;
}
void Monde::switchAccess(int i, int j){
	_map[i+(_y*j)].accessibilite = !(_map[i+(_y*j)].accessibilite);
}

void Monde::setOccupant(int i, int j, int occ){
	_map[i+(_y*j)].occupant = occ;
}
void Monde::setObjet(int i, int j, int obj){
	_map[i+(_y*j)].objet = obj;
}

void Monde::moveOccupant(int x, int y, int x2, int y2)
{
	bool encadrement = (x >= 0) && (x < _x) && (y >= 0) && (y < _y);
	bool encadrement2 = (x2 >= 0) && (x2 < _x) && (y2 >= 0) && (y2 < _y);
	bool occupant = (_map[x+(_y*y)].occupant != -1);
	bool libre = (_map[x2+(_y*y2)].occupant == -1);

	if( encadrement && encadrement2 && occupant && libre )
	{
		_map[x2+(_y*y2)].occupant = _map[x+(_y*y)].occupant;
		_map[x+(_y*y)].occupant = -1;
	}
}
void Monde::moveObjet(int x, int y, int x2, int y2)
{

}
/* NOTE:
 * Les mobiliers de plus d'une case lanceront autant de fois cette méthode qu'il le faudra
 */

void Monde::setSprite(int i, int j, int textX, int textY){
	_map[i + j*_y].textureX = textX;
	_map[i + j*_y].textureY = textY;

	_terrain[4*(i + j*_y)].texCoords = sf::Vector2f(16*textX, 16*textY);
	_terrain[(4*(i + j*_y))+1].texCoords = sf::Vector2f((16*textX)+16, 16*textY);
	_terrain[(4*(i + j*_y))+2].texCoords = sf::Vector2f((16*textX)+16, (16*textY)+16);
	_terrain[(4*(i + j*_y))+3].texCoords = sf::Vector2f(16*textX, (16*textY)+16);
}

// centrer le tableau de vertex sur un point
void Monde::centrerSur(sf::Vector2f point)
{
	float x = point.x;
	float y = point.y;
	int indice;

	for(int i = 0 ; i < _x ; ++i)
	{
		for(int j = 0 ; j < _y ; ++i)
		{
			_terrain[4*indice].position = sf::Vector2f( 16*i - x, 16*j - y);
			_terrain[(4*indice)+1].position = sf::Vector2f( 16*(i+1) - x, 16*j - y);
			_terrain[(4*indice)+2].position = sf::Vector2f( 16*(i+1) - x, 16*(j+1) - y);
			_terrain[(4*indice)+3].position = sf::Vector2f( 16*i - x, 16*(j+1) - y);
		}
	}
}
void Monde::centrerSur(float x, float y)
{
	int indice;

	for(int i = 0 ; i < _x ; ++i)
	{
		for(int j = 0 ; j < _y ; ++i)
		{
			_terrain[4*indice].position = sf::Vector2f( 16*i - x, 16*j - y);
			_terrain[(4*indice)+1].position = sf::Vector2f( 16*(i+1) - x, 16*j - y);
			_terrain[(4*indice)+2].position = sf::Vector2f( 16*(i+1) - x, 16*(j+1) - y);
			_terrain[(4*indice)+3].position = sf::Vector2f( 16*i - x, 16*(j+1) - y);
		}
	}
}
