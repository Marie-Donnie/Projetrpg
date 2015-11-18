/**
 * @file Monde.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la map monde
 **/

#include "SFML/Graphics.hpp"
#include "Monde.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Monde::Monde(std::string fic)
{
	_x = 52; _y = 33;
	_map = new Case[_x*_y];
	
	//chargement de toutes les textures
	//>0: floor
	sf::Texture * texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/floor2.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>1: hautmur
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/hautmur.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>2: hautmur2
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/hautmur2.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>3: mur
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/mur.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>4: murfenetre
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/murfenetre.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>5: portehaut
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/portehaut.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>6: armoire
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/armoire.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>7: litd
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/litd.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>8: litg
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/litg.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>9: comd
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/comd.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>10: comg
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/comg.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>11: table
	texture = new sf::Texture();
	if(!texture->loadFromFile("./data/sprites/table.ase")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//Lecture de map.txt, construction de la _map
	std::ifstream fichier(fic, std::ios::in);
	
	if(fichier)
	{
		char c;
		int i = 0;
		
		while( !fichier.eof() )
        {
			fichier.get(c);
			
			switch(c)
			{
				case ' ' :{break;}
				case 'X' :{ //0: floor2
					_map[i].setTexture(*_textures[0]);
					_map[i].setHauteur(0);
					
					break;
				}
				case '=' :{ //1: hautmur
					_map[i].setTexture(*_textures[1]);
					_map[i].setHauteur(1);
					
					break;
				}
				case '|' :{ //2: hautmur2
					_map[i].setTexture(*_textures[2]);
					_map[i].setHauteur(1);
					
					break;
				}
				case '_' :{ //3: mur
					_map[i].setTexture(*_textures[3]);
					_map[i].setHauteur(1);
					
					break;
				}
				case 'F' :{ //4: murfenetre
					_map[i].setTexture(*_textures[4]);
					_map[i].setHauteur(1);
					
					break;
				}
				case ';' :{ //5: portehaut l'haut-porte sunniste
					_map[i].setTexture(*_textures[5]);
					_map[i].setHauteur(1); //tombe à 0 si porte ouverte
					
					break;
				}
				case 'P' :{ //porte ?
					//2 _maps
					
					break;
				}
				case 'A' :{ //6: armoire, 2x2
					for(int a=0; a<2; ++a){
						for(int b=0; b<2; ++b){
							_map[i + a + (_x*b)].setTexture(*_textures[6]);
							_map[i + a + (_x*b)].setHauteur(2);
							
							_map[i + a + (_x*b)].setSprite(a,b);
						}
					}
					
					break;
				}
				case '+' :{ //crucifi ?
					
					break;
				}
				case 'D' :{ //la réponde D, 2x1
					_map[i].setTexture(*_textures[7]);
					_map[i].setHauteur(1);
					
					_map[i+1].setTexture(*_textures[7]);
					_map[i+1].setHauteur(1);
					_map[i + 1].setSprite(1,0);
					
					break;	//euh... non, en fait c'était 7: litd. 'Fin, tu vois l'idée...
				}
				case 'G' :{	//8: litg, 2x1
					_map[i].setTexture(*_textures[8]);
					_map[i].setHauteur(1);
					
					_map[i+1].setTexture(*_textures[8]);
					_map[i+1].setHauteur(1);
					_map[i + 1].setSprite(1,0);
					
					break;
				}
				case '>' :{	//9: comd
					_map[i].setTexture(*_textures[9]);
					_map[i].setHauteur(1);
					
					break;
				}
				case '<' :{ //10: comg
					_map[i].setTexture(*_textures[10]);
					_map[i].setHauteur(1);
					
					break;
				}
				case 'T' :{ //11: table pleine de sang dégueulasse, 6x3
					_map[i].setTexture(*_textures[11]);
					_map[i].setHauteur(1);
					
					for(int a=0; a<6; ++a){
						for(int b=0; b<3; ++b){
							_map[i + a + (_x*b)].setTexture(*_textures[11]);
							_map[i + a + (_x*b)].setHauteur(2);
							
							_map[i + a + (_x*b)].setSprite(a,b);
						}
					}
					
					break;
				}
				case 'J' :{ //jardin je suppose, 27x14 le bourrin
					
					break;
				}
			}
			
			++i;
		}
		
		fichier.close();
	}
	else
		std::cout << "Erreur lors du chargement du fichier " << fic << std::endl;//erreur
	
	
}

		
//getters
bool Monde::estAccessible(int i, int j){return _map[i+(_y*j)].estAccessible();}
int Monde::getOccupant(int i, int j){return _map[i+(_y*j)].getOccupant();}
int Monde::getX(){return _x;}
int Monde::getY(){return _y;}
		
//setters
/*void Monde::setAccess(int i, int j, bool access){
	_map[i+(_y*j)].accessibilite = access;
}
void Monde::switchAccess(int i, int j){
	_map[i+(_y*j)].accessibilite = !(_map[i+(_y*j)].accessibilite);
}*/

void Monde::setOccupant(int i, int j, int occ){
	_map[i+(_y*j)].setOccupant(occ);
}
void Monde::setObjet(int i, int j, int obj){
	//_map[i+(_y*j)].objet = obj;
}

void Monde::moveOccupant(int x, int y, int x2, int y2)
{
	bool encadrement = (x >= 0) && (x < _x) && (y >= 0) && (y < _y);
	bool encadrement2 = (x2 >= 0) && (x2 < _x) && (y2 >= 0) && (y2 < _y);
	bool occupant = (_map[x+(_y*y)].getOccupant() != -1);
	bool libre = (_map[x2+(_y*y2)].getOccupant() == -1);
	
	if( encadrement && encadrement2 && occupant && libre )
	{
		_map[x2+(_y*y2)].setOccupant( _map[x+(_y*y)].getOccupant() );
		_map[x+(_y*y)].setOccupant(-1);
	}
}
void Monde::moveObjet(int x, int y, int x2, int y2)
{
	
}
/* NOTE:
 * Les mobiliers de plus d'une case lanceront autant de fois cette méthode qu'il le faudra
 */

/*void Monde::setSprite(int i, int j, int textX, int textY){
	_map[i + j*_y].setTexture(...
}*/

// centrer le tableau de vertex sur un point
void Monde::centrerSur(sf::Vector2f point)
{
	float x = point.x;
	float y = point.y;
	
	float x2, y2;
	for(int i=0 ; i<(_x*_y) ; ++i)
	{
		x2 = _map[i].getPosition().x;
		y2 = _map[i].getPosition().y;
		
		_map[i].setPosition(x2-x, y2-y);
	}
}
void Monde::centrerSur(float x, float y)
{
	float x2, y2;
	for(int i=0 ; i<(_x*_y) ; ++i)
	{
		x2 = _map[i].getPosition().x;
		y2 = _map[i].getPosition().y;
		
		_map[i].setPosition(x2-x, y2-y);
	}
}

void Monde::draw(sf::RenderWindow & window)
{
	for(int i=0; i<(_x*_y); ++i)
	{
		window.draw(_map[i].getSprite());
	}
}
