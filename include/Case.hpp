/**
  * @name    Constructeur
  * @brief   Construit à vide
  */
 /**
  * @name    makeInventaire
  * @brief   Construit un inventaire.
  * Selon le nom saisi en paramètre, ce qu'il contiendra sera différent
  * @param   nom une chaine de caractères
  */
/**
  * @name    getInventaire
  * @return  l'Inventaire pointé par l'attribut pointeur de la Case
  */
/**
  * @name    getInventaireAdress
  * @return  Le pointeur de la Case
  */
/**
  * @name    setSprite
  * @brief   change la zone de texture carré que prend le sprite de la case
  * @param   i, le numéro de la colonne de la zone de texture
  * @param   j, le numéro de la ligne de la zone de texture
  */
/**
  * @name    interaction
  * @brief   Contient la réaction de la case si on interagit avec, selon son numéro d'interaction
  */

  
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
		
		Inventaire * _inventaire;
		int _interaction; //0: rien, 1: inventaire, 2: message, 3: dialogue
		
		sf::Sprite _sprite;
		sf::Texture _texture;
		int _hauteur;
		
	public:
		//constructeur
		Case();
		
		//construction d'inventaire
		void makeInventaire(std::string nom);
		
		//getters
		bool estAccessible();
		int getOccupant();
		bool estTransparent();
		
		Inventaire& getInventaire();
		Inventaire* getInventaireAdress();
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
		
		void setInventaire(Inventaire* inv);
		void setInteraction(int i);
		
		void setHauteur(int h);
		void setTexture(sf::Texture & t);
		
		void setSprite(int i, int j);
		
		//interaction
		void interaction();
};

#endif
