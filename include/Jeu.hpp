//include guard
#ifndef JEU_HPP
#define JEU_HPP

//Forward declared dependencies
//class PNJ;

//included dependencies
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "SFML/System.hpp"
#include "Membre.hpp"
#include "Personnage.hpp"
#include "Monde.hpp"
#include "PNJ.hpp"

class Jeu {
	private:
		Personnage _personnage;
		std::vector<PNJ> _pnjs; //plutôt un simple tableau ?
		Monde _monde;
		sf::Time _turnTime;			//temps du précédent tour de la boucle while principale
		sf::Vector2i _posSouris;	//position de la souris

		//méthodes internes
		void gestionPersonnage(); //appelée par : void gestion()
		void gestionPNJ();

	public:
		//CONSTRUCTEUR
		Jeu(std::string fic);

		//Création des entités mouvantes
		void creerPersonnage(int x, int y);
		//void supprimerPersonnage();

		void creerPNJ();
		//void supprimerPNJ(int num);

		//void popPersonnage(int num, float x, float y);
		//void popPNJ(int num, float x, float y);
		
		// gestion des entrées
		//>inputs
		void inputs(bool * in);
		void setPosSouris(sf::Vector2i posSouris);
		//>temps de tour
		void takeTurnTime(sf::Time turnTime);
		
		// traitement des données
		void gestion();
		
		// affichage global
		void draw(sf::RenderWindow & window);
};

#endif
