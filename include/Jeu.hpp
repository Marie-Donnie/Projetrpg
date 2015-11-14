#ifndef JEU_HPP
#define JEU_HPP

#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "SFML/System.hpp"
#include "Membre.hpp"
#include "Personnage.hpp"
#include "Monde.hpp"

class PNJ;


class Jeu {
	private:
		Personnage _personnage;
		std::vector<PNJ *> _pnjs; //plutôt un simple tableau ?
		Monde _monde;
		sf::Time _turnTime;			//temps du précédent tour de la boucle while principale
		sf::Vector2i _posSouris;	//position de la souris

		//méthodes internes
		void gestionPersonnage(); //appelée par : void gestion()

	public:
		//CONSTRUCTEUR
		Jeu();

		// gestion des inputs
		void inputs(bool * in);
		void setPosSouris(sf::Vector2i posSouris);

		/*void creerPersonnage(string nom, int age, double taille, double poids);
		void supprimerPersonnage(int num);

		void creerPNJ(string nom);
		void supprimerPNJ(int num);

		void popPersonnage(int num, float x, float y);
		void popPNJ(int num, float x, float y);*/

		void takeTurnTime(sf::Time turnTime);

		void gestion();

		void draw(sf::RenderWindow & window);
};

#endif
