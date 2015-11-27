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
		Case& getCase(int x, int y);
		
		bool estPlat(int x, int y);
		bool estAccessible(int x, int y);
		bool estTransparent(int x, int y);
		int getOccupant(int x, int y);
		Inventaire& getInventaire(int x, int y);
		int getInteraction(int x, int y);
		
		int getX();
		int getY();
		
		//setters
		void setOccupant(int x, int y, int occ);
		
		void setTexture(int x, int y, int num);
		void setInteraction(int x, int y, int i);
		
		//autres
		void moveOccupant(int x, int y, int x2, int y2);
		
		void centrerSur(sf::Vector2f point);
		void centrerSur(float x, float y);
		
		void interaction(int x, int y);
		
		void draw(sf::RenderWindow & window);
};

#endif
