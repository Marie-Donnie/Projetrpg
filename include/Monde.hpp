/**
 * @file Monde.hpp
 * @author Marie Delavergne, Robin Wibaux
 * @date October, 2015
 * @brief Définition de la classe de Monde
 **/

/**
  * @name  	Constructeur
  * @brief 	Construit le monde à partir d'un fichier texte
  * Le fichier texte contient une matrice de lettres correspondantes aux différentes cases
  * Charge aussi toutes les textures dans un vecteur.
  * Chaque case, selon son type (défini par une lettre spécifique dans la matrice),
  *  a une certaine texture, une certaine accessibilité, interactivité, transparence.
  * Certains élément de la map prennent plusieurs cases, seule la case supérieure droite
  *  est alors indiquée sur la matrice, les autres cases étant donc représentées par des espaces.
  * @param 	fic l'adresse du fichier
  */

/**
  * @name  	getters, setters...
  * @brief 	La plupart des méthodes ne font qu'exécuter la même méthode de la case indiquée en paramètre
  * @param 	x, l'abscisse de la case
  * @param 	y, l'ordonnée de la case
  */

/**
  * @name  	moveOccupant
  * @brief 	Déplace l'occupant de la case 1 dans la case 2
  * @param 	x1, abscisse de la case 1
  * @param 	y1, ordonnée de la case 1
  * @param 	x2, abscisse de la case 2
  * @param 	y2, ordonnée de la case 2
  */

/**
  * @name  	centrerSur
  * @brief 	Centre les sprites de toutes les cases autour d'un point.
  * Est utilisé pour faire du Personnage le centre de tout.
  * @param 	point, coordonnées du point sur lequel on centre tout
  */

/**
  * @name  	draw
  * @brief 	Lance le dessin de toutes les cases
  * @param 	window, sur lequel on dessine tout
  */


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
