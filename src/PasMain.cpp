#include "SFML/Graphics.hpp"	//RenderWindow
#include "SFML/Window.hpp"		//Window - VideoMode - Style
#include "SFML/System.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Jeu.hpp"

using namespace std;

int main(){
  /* initialize random seed: */
	srand (time(NULL));

	//Boutons (reste à en rajouter)
	//0:haut, 1:bas, 2:gauche, 3:droite,
	//4:clicG, 5:clicD,
	//6:E, 7:F, 8:I
	//9-18:0-9
	bool input[19];
	for(int i=0; i<19; ++i){
		input[i]=false;
	}

	//Coordonnées de la souris
	sf::Vector2i sourisInt;
	sf::Vector2f sourisFloat;

	//Choix du personnage
	int sexe;
	string nom;
	cout << "Saisissez votre sexe puis votre nom :\n(0:homme, 1:femme)" << endl;
	cin >> sexe;
	while( sexe!=0 and sexe!=1 )
	{
		cout << "Saisie invalide, choisissez 0 (homme) ou 1 (femme)" << endl;
		cin >> sexe;
	}
	cout << "Votre nom :" << endl;
	cin >> nom;

	//Création de la fenêtre
	int X = 800, Y = 600;
	std::string name = "Game";
	sf::RenderWindow window(sf::VideoMode(X, Y), name);

	//Création du jeu & du personnage
	Jeu jeu = Jeu("./data/map.txt", nom, sexe);

	jeu.popPersonnage(22,3);

	//textures
	string text = "./data/sprites/zombie.png";

	//pnj
	jeu.creerPNJ("Bob", text);
	jeu.creerPNJ("Desire", text);
	jeu.creerPNJ("Francis", text);
	jeu.creerPNJ("Michel(le)", text);
	jeu.creerPNJ("Modeste", text);

	jeu.popPNJ(0,12,5);
	jeu.popPNJ(1,7,30);
	jeu.popPNJ(2,18,29);
	jeu.popPNJ(3,18,27);
	jeu.popPNJ(4,27,17);

	//Lancement du jeu
	sf::Clock globalTime;
	sf::Time turnTime;

	//Démarrage de la boucle principale
	while (window.isOpen())
	{
		turnTime = globalTime.restart();
		jeu.takeTurnTime(turnTime); //se met à jour

		sf::Event event;
		while (window.pollEvent(event))
		{
			//fermeture
			if (event.type == sf::Event::Closed)
				window.close();

			//mouvement de la souris
			if (event.type == sf::Event::MouseMoved)
				jeu.setPosSouris(sf::Mouse::getPosition(window));

			//clics de la souris
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				input[4] = true;
			else
				input[4] = false;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				input[5] = true;
			else
				input[5] = false;

			//touches directionnelles
			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
				input[0] = true;
			else
				input[0] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) )
				input[1] = true;
			else
				input[1] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) )
				input[2] = true;
			else
				input[2] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) )
				input[3] = true;
			else
				input[3] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				input[6] = true;
			else
				input[6] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				input[7] = true;
			else
				input[7] = false;

		}

		//envoie des inputs
		jeu.inputs(input);

		jeu.gestion();

		//affichages

		window.clear();

		//window.draw(/* */);
		jeu.draw(window);

		window.display();
	}

}
