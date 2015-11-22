#include "SFML/Graphics.hpp"	//RenderWindow
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include <string>
#include "Inventaire.hpp"

#ifndef CASE_HPP
#define CASE_HPP

class Case {
	private:
		int _occupant;
		int _textX;
		int _textY;
		bool _transparent;
		
		Inventaire _inventaire;
		int _interaction; //0: rien, 1: inventaire, 2: message, 3: dialogue
		
		sf::Sprite _sprite;
		sf::Texture _texture;
		int _hauteur;
		
	public:
		//constructeur
		Case();
		
		//getters
		bool estAccessible();
		int getOccupant();
		bool estTransparent();
		
		Inventaire& getInventaire();
		int getInteraction();
		
		int getHauteur();
		sf::Texture& getTexture();
		sf::Sprite& getSprite();
		
		sf::Vector2f getPosition();
		
		//setters
		void setOccupant(int occ);
		void setTransparent(bool t);
		
		void setPosition(sf::Vector2f pos);
		void setPosition(float x, float y);
		
		void setInteraction(int i);
		
		void setHauteur(int h);
		void setTexture(sf::Texture & t);
		
		void setSprite(int i, int j);
		
		//interaction
		void interaction();
};

#endif
