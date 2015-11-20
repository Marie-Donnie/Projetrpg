#include "SFML/Graphics.hpp"	//RenderWindow
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include <string>

#ifndef CASE_HPP
#define CASE_HPP

class Case {
	private:
		int _occupant;
		int _textX;
		int _textY;
		bool _transparent;
		
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
		
		int getHauteur();
		sf::Texture& getTexture();
		sf::Sprite& getSprite();
		
		sf::Vector2f getPosition();
		
		//setters
		void setOccupant(int occ);
		void setTransparent(bool t);
		
		void setPosition(sf::Vector2f pos);
		void setPosition(float x, float y);
		
		void setHauteur(int h);
		void setTexture(sf::Texture & t);
		
		void setSprite(int i, int j);
};

#endif
