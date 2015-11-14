#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include <string>
#include "SFML/Graphics.hpp" //RenderWindow

#ifndef MONDE_HPP
#define MONDE_HPP

class Monde {
	private:
		struct cell {
			bool accessibilite;	//true : peut accueillir une entité mouvante
			int occupant;		//id de l'occupant éventuel (-1: aucun, 0: personnage, 1..n: pnj d'indice 0 à n-1)
			int objet;			//id de l'objet éventuel
			int textureX;		//numero x de la texture
			int textureY;		//numero y
		};

		cell * _map;
		int _x;
		int _y;
		sf::VertexArray _terrain;
		sf::Texture _texture;

	public:
		Monde();
		Monde(int x, int y, std::string texture);

		//getters
		bool estAccessible(int x, int y);
		int getOccupant(int x, int y);
		int getObjet(int x, int y);
		int getX();
		int getY();

		//setters
		void setAccess(int x, int y, bool access);
		void switchAccess(int x, int y);

		void setOccupant(int x, int y, int occ);
		void setObjet(int x, int y, int obj);

		void moveOccupant(int x, int y, int x2, int y2);
		void moveObjet(int x, int y, int x2, int y2);

		void setSprite(int x, int y, int textX, int textY);

		void centrerSur(sf::Vector2f point);
		void centrerSur(float x, float y);
};

#endif
