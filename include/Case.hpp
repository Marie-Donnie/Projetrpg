#include "SFML/Graphics.hpp"	//RenderWindow
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include <string>
#include "Entite.hpp"

#ifndef CASE_HPP
#define CASE_HPP

class Case : public Entite {
	private:
		int _occupant;
		int _textX;
		int _textY;
		
	public:
		//constructeur
		Case();
		
		//getters
		bool estAccessible();
		int getOccupant();
		
		sf::Vector2f getPosition();
		
		//setters
		void setOccupant(int occ);
		
		void setPosition(sf::Vector2f pos);
		void setPosition(float x, float y);
};

#endif
