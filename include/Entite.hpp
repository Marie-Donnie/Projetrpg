#include "SFML/Graphics.hpp"	//RenderWindow
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include <string>

#ifndef ENTITE_HPP
#define ENTITE_HPP

class Entite {
	protected:
		sf::Vector2i _location;
		sf::Vector2f _position;
		sf::Texture _texture;
		sf::Sprite _sprite;

		bool _actif;
		int _action; //0:deplacement, 1:attaqueG, 2:attaqueD, 3:magie, 4:interaction
		int _direction; //0:haut, 1:bas, 2:gauche, 3:droite
		sf::Time _tempsAction; //une fois un seuil dépacé, l'action prend fin
		
	public:
		//Constructeur
		Entite();
		Entite(std::string texture);
		
		//Getters
		sf::Vector2i getLocation();
		int getLocX();
		int getLocY();
		sf::Vector2f getPosition();
		float getPosX();
		float getPosY();
		sf::Texture& getTexture();
		sf::Sprite& getSprite();
		
		bool estActif();
		int getAction();
		int getDirection();
		
		bool estImmobile();
		
		//Setters
		void setLocation(sf::Vector2i loc);
		void setLocation(int x, int y);
		void setPosition(sf::Vector2f pos);
		void setPosition(float x, float y);
		void setTexture(std::string texture); //charge directement un fichier png
		void setSprite(int direction); //0:haut, 1:bas, 2:gauche, 3:droite
		void setSprite(); //sprite par défaut
		
		void setDirection(int d);
		void setAction(int a);
	
		//Mouvements
		//>Mises en mouvement
		void move(int direction);
		//>Mouvement en cours
		void move(sf::Time turnTime, sf::Time duree);
		void move(sf::Time turnTime); //prend une durée par défaut
		
};

#endif
