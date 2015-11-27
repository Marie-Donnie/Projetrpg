/**
 * @file  Entite.hpp
 * @Author Marie Delavergne, Robin Wibaux
 * @date   November, 2015
 * @brief  Définit la classe Entite dont hériteront les entités mouvantes
 */


  /**
   * @name    Constructeur
   * @brief   Créée une entité mouvante
   * Le constructeur initialise l'activité à faux et la position du sprite au centre de l'écran.
   * La position est au centre pour le Personnage qui ne bougera jamais du centre de l'écran.
   * Les autres verront leur position calculée selon le Personnage.
   * Si une adresse de texture est mise en paramètre, alors elle est chargée pour une image de 16*16 pixels.
   * @param  texture l'adresse de la texture à charger
   */
   
   /**
   * @name    estImmobile
   * @brief   Renvoie si l'entité est en mouvement ou non :
   * Est vrai s'il est inactif ou s'il fait autre chose que de se déplacer
   * @return  Un booléen
   */
   
   /**
   * @name    setTexture
   * @brief   Charge une nouvelle texture
   * @param   Le chemin de la nouvelle texture
   */
   /**
   * @name    setSprite
   * @brief   définie la zone de la texture à prendre selon la direction
   * @param   La direction, car une entité mouvante a toujours 4 images possibles rangées dans un ordre précis
   */
   
   /**
   * @name    move(direction)
   * @brief   Met en mouvement l'entité :
   * l'attribut _actif passe à true, _action à 1 et l'attribut temps est initialisé à zéro.
   * Selon la direction en paramètre, modifie la localisation entière.
   * @param   Un entier direction
   */
   /**
   * @name    move(temps)
   * @brief   Fait évolué l'entité en mouvement en incrémentant son temps avec le temps entré en paramètre :
   * Si le temps atteint un seuil le mouvement prend fin ;
   * Sinon la position est recalculée.
   * @param   Un temps, du type sf::Time
   */
   
   
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
