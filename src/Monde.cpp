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
	if(!texture->loadFromFile("data/sprites/floor2.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>1: hautmur
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/hautmur.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>2: hautmur2
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/hautmur2.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>3: mur
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/mur.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>4: murfenetre
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/murfenetre.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>5: portehaut
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/portehaut.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//6> porte
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/porte.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>7: armoire
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/armoire.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>8: litd
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/litd.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>9: litg
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/litg.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>10: comd
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/comd.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>11: comg
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/comg.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>12: table
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/table.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);
	
	//>13: jardin
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/jardin.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>14: cadavre
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/cadavre.png")){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_textures.push_back(texture);

	//>15: inconnu
	texture = new sf::Texture();
	if(!texture->loadFromFile("data/sprites/inconnu.png")){
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

			if( c != '\n' ){
				switch(c)
				{
					case ' ' :{break;}
					case 'X' :{ //0: floor2
						_map[i].setTexture(*_textures[0]);
						_map[i].setHauteur(0);
						_map[i].setInteraction(0);
						_map[i].makeInventaire(""); //créée un inventaire vide
						
						break;
					}
					case '=' :{ //1: hautmur
						_map[i].setTexture(*_textures[1]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(0);
						_map[i].makeInventaire("");
						
						break;
					}
					case '|' :{ //2: hautmur2
						_map[i].setTexture(*_textures[2]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(0);
						_map[i].makeInventaire("");
						
						break;
					}
					case '_' :{ //3: mur
						_map[i].setTexture(*_textures[3]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(0);
						_map[i].makeInventaire("");
						
						break;
					}
					case 'F' :{ //4: murfenetre
						_map[i].setTexture(*_textures[4]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(0);
						_map[i].makeInventaire("");
						
						break;
					}
					case ';' :{ //5: portehaut l'haut-porte sunniste
						_map[i].setTexture(*_textures[5]);
						_map[i].setHauteur(1); //tombe à 0 si porte ouverte
						_map[i].setInteraction(2); //message
						_map[i].makeInventaire("");
						
						break;
					}
					case 'P' :{ //6: porte double
						_map[i].setTexture(*_textures[6]); //sprite provisoire de mêmes dimensions
						_map[i].setHauteur(1);
						_map[i].setInteraction(2);
						_map[i].makeInventaire("");
						
						_map[i+1].setTexture(*_textures[6]);
						_map[i+1].setHauteur(1);
						_map[i+1].setSprite(1,0);
						_map[i+1].setInteraction(2);
						_map[i+1].setInventaire(_map[i].getInventaireAdress());
						
						
						break;
					}
					case 'A' :{ //7: armoire, 2x2
						//mettre à tous le même inventaire
						_map[i].makeInventaire("Armoire");
						
						for(int a=0; a<2; ++a){
							for(int b=0; b<2; ++b){
								_map[i + a + (_x*b)].setTexture(*_textures[7]);
								_map[i + a + (_x*b)].setHauteur(1);
								_map[i + a + (_x*b)].setInteraction(1);
								
								_map[i + a + (_x*b)].setSprite(a,b);
								
								_map[i + a + (_x*b)].setInventaire(_map[i].getInventaireAdress());
							}
						}
						
						break;
					}
					case '+' :{ //7: armoire spéciale (même sprite)
						_map[i].makeInventaire("Armoire spe");
						
						for(int a=0; a<2; ++a){
							for(int b=0; b<2; ++b){
								_map[i + a + (_x*b)].setTexture(*_textures[7]);
								_map[i + a + (_x*b)].setHauteur(1);
								_map[i + a + (_x*b)].setInteraction(1);
								
								_map[i + a + (_x*b)].setSprite(a,b);
								
								_map[i + a + (_x*b)].setInventaire(_map[i].getInventaireAdress());
							}
						}
						
						break;
					}
					case 'D' :{ //la réponde D, 2x1
						//mettre à tous le même inventaire par référence
						_map[i].setTexture(*_textures[8]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(1);
						_map[i].makeInventaire("Lit");
						
						_map[i+1].setTexture(*_textures[8]);
						_map[i+1].setHauteur(1);
						_map[i+1].setSprite(1,0);
						_map[i+1].setInteraction(1);
						_map[i+1].setInventaire(_map[i].getInventaireAdress());
						
						break;	//euh... non, en fait c'était 8: litd. 'Fin, tu vois l'idée...
					}
					case 'G' :{	//9: litg, 2x1
						//mettre à tous le même inventaire par référence
						_map[i].setTexture(*_textures[9]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(1);
						_map[i].makeInventaire("Lit");
						
						_map[i+1].setTexture(*_textures[9]);
						_map[i+1].setHauteur(1);
						_map[i+1].setSprite(1,0);
						_map[i+1].setInteraction(1);
						_map[i+1].setInventaire(_map[i].getInventaireAdress());
						
						break;
					}
					case '>' :{	//10: comd
						_map[i].setTexture(*_textures[10]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(0);
						_map[i].makeInventaire("");
						
						break;
					}
					case '<' :{ //11: comg
						_map[i].setTexture(*_textures[11]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(0);
						_map[i].makeInventaire("");
						
						break;
					}
					case 'T' :{ //12: table pleine de sang dégueulasse, 6x3
						_map[i].setTexture(*_textures[12]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(0);
						_map[i].makeInventaire("");
						
						for(int a=0; a<6; ++a){
							for(int b=0; b<3; ++b){
								_map[i + a + (_x*b)].setTexture(*_textures[12]);
								_map[i + a + (_x*b)].setHauteur(1);
								_map[i].setInteraction(0);
								
								_map[i + a + (_x*b)].setSprite(a,b);
								
								_map[i + a + (_x*b)].setInventaire(_map[i].getInventaireAdress());
							}
						}
						
						break;
					}
					case 'J' :{ //jardin tout joli
						_map[i].makeInventaire("");
						
						for(int a=0; a<27; ++a){
							for(int b=0; b<14; ++b){
								_map[i + a + (_x*b)].setTexture(*_textures[13]);
								_map[i + a + (_x*b)].setHauteur(1);
								_map[i + a + (_x*b)].setInteraction(0);
								
								_map[i + a + (_x*b)].setSprite(a,b);
								
								_map[i + a + (_x*b)].setInventaire(_map[i].getInventaireAdress());
							}
						}
						
						break;
					}
					case 'I' :{ //15: Le mystérieux inconnu
						_map[i].setTexture(*_textures[15]);
						_map[i].setHauteur(1);
						_map[i].setInteraction(3); //dialogue
						_map[i].makeInventaire("");
					}
				}
				
				_map[i].setOccupant(-1);
				
				++i;
			}
		}

		fichier.close();
	}
	else
		std::cout << "Erreur lors du chargement du fichier " << fic << std::endl;//erreur


}


//getters
bool Monde::estPlat(int i, int j){return (_map[i+(_x*j)].getHauteur()==0)?true:false;}
bool Monde::estAccessible(int i, int j){return _map[i+(_x*j)].estAccessible();}
bool Monde::estTransparent(int i, int j){return _map[i+(_x*j)].estTransparent();}
int Monde::getOccupant(int i, int j){return _map[i+(_x*j)].getOccupant();}
int Monde::getX(){return _x;}
int Monde::getY(){return _y;}

Inventaire& Monde::getInventaire(int x, int y){
	return _map[x+(_x*y)].getInventaire();
}

int Monde::getInteraction(int x, int y){
	return _map[x+(_x*y)].getInteraction();
}

//setters

void Monde::setOccupant(int i, int j, int occ){
	_map[i+(_x*j)].setOccupant(occ);
}

void Monde::moveOccupant(int x, int y, int x2, int y2)
{
	_map[x2+(_x*y2)].setOccupant( _map[x+(_x*y)].getOccupant() );
	_map[x+(_x*y)].setOccupant(-1);
}

void Monde::setTexture(int x, int y, int num)
{
	_map[x+(_x*y)].setTexture(*_textures[num]);
}

void Monde::setInteraction(int x, int y, int i)
{
	_map[x+(_x*y)].setInteraction(i);
}

// centrer le tableau de vertex sur un point
void Monde::centrerSur(sf::Vector2f point)
{
	centrerSur(point.x, point.y);
}
void Monde::centrerSur(float x, float y)
{
	float x2, y2;	//coordonnées des cases du décor
	int i2,j2;		//indices des cases du décor
	for(int i=0 ; i<(_x*_y) ; ++i)
	{
		i2 = i%_x;
		j2 = i/_x;
		
		x2 = i2*16;
		y2 = j2*16;
		
		_map[i].setPosition(x2-x + 392, y2-y + 292);
	}
}

void Monde::interaction(int x, int y){
	_map[x+(_x*y)].interaction();
}

void Monde::draw(sf::RenderWindow & window)
{
	for(int i=0; i<(_x*_y); ++i)
	{
		window.draw(_map[i].getSprite());
	}
}
