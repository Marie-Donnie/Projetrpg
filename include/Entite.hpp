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
		sf::Sprite _sprite;
		sf::Texture _texture;
		int _hauteur;
		
	public:
		Entite();
		Entite(sf::Texture & texture);
		
		//getters
		int getHauteur();
		sf::Texture& getTexture();
		sf::Sprite& getSprite();
		
		//setters
		void setHauteur(int h);
		void setTexture(sf::Texture & t);
		
		
		void setSprite(int i, int j);
};

#endif
