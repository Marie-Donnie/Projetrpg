#include "SFML/Graphics.hpp"	//RenderWindow
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include <string>
#include "Case.hpp"

#ifndef MONDE_HPP
#define MONDE_HPP

class Monde {
	private:
		Case * _map;
		int _x;
		int _y;
		std::vector<sf::Texture *> _textures;
		
	public:
		//CONSTRUCTEUR
		Monde(std::string fic);
		
		//getters
		bool estAccessible(int x, int y);
		int getOccupant(int x, int y);
		//int getObjet(int x, int y);
		int getX();
		int getY();
		
		//setters
		void setOccupant(int x, int y, int occ);
		void setObjet(int x, int y, int obj);
		
		void moveOccupant(int x, int y, int x2, int y2);
		void moveObjet(int x, int y, int x2, int y2);
		
		//void setSprite(int x, int y, int textX, int textY);
		
		void centrerSur(sf::Vector2f point);
		void centrerSur(float x, float y);
};

#endif
