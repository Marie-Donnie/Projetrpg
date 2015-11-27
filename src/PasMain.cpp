#include "SFML/Graphics.hpp"	//RenderWindow
#include "SFML/Window.hpp"		//Window - VideoMode - Style
#include "SFML/System.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Jeu.hpp"
#include "Interface.hpp"
#include "Etats.hpp"
#include "Observer.hpp"

using namespace std;

int main(){
  /* initialize random seed: */
	srand (time(NULL));

	//Boutons (reste à en rajouter)
	//0:haut, 1:bas, 2:gauche, 3:droite,
	//4:clicG, 5:clicD,
	//6:E, 7:F, 8:I, 9:R, 10:A, 11:H
	//12-21:0-9
	bool input[21];
	for(int i=0; i<21; ++i){
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

	jeu.popPersonnage(41,6);

        Interface interface = Interface(jeu.getPerso());
        jeu.setSuiv(&interface);
        interface.setEtat(&Interface::abase);
        interface.setSuiv(&Interface::abase);
        interface.affichage();

	//textures
	string text = "./data/sprites/zombie.png";

	//création des pnj
	jeu.creerPNJ("Bob", text);			//0
	jeu.creerPNJ("Desire", text);
	jeu.creerPNJ("Francis", text);
	jeu.creerPNJ("Michel(le)", text);
	jeu.creerPNJ("Modeste", text);
	jeu.creerPNJ("Constante", text);	//5
	jeu.creerPNJ("Songleton", text);
	jeu.creerPNJ("Phillipe", text);
	jeu.creerPNJ("Arnaud", text);
	jeu.creerPNJ("Guillaume", text);
	jeu.creerPNJ("Sylvain", text);		//10
	jeu.creerPNJ("Jean", text);
	jeu.creerPNJ("Xavier", text);
	jeu.creerPNJ("Robert", text);
	jeu.creerPNJ("Donald", text);
	jeu.creerPNJ("Duck", text);		//15
	jeu.creerPNJ("No", text);
	jeu.creerPNJ("More", text);
	jeu.creerPNJ("Name", text);

	//placement des pnj
	//>Hall d'entrée
	jeu.popPNJ(0,12,5, 0);
	jeu.popPNJ(7,22,2, 1);
	jeu.popPNJ(6,24,4, 3);

	//>Couloir ouest
	jeu.popPNJ(17,7,7, 0);
	jeu.popPNJ(18,11,7, 0);
	
	//>Chambres ouest
	jeu.popPNJ(15,1,10, 3);
	jeu.popPNJ(16,2,10, 2);
	
	//>Salle à manger
	jeu.popPNJ(1,18,25, 0);
	jeu.popPNJ(2,18,28, 3);
	jeu.popPNJ(3,13,25);
	jeu.popPNJ(5,14,29, 0);
	

	//>Salle Sud

	//>Lits est-sud-est
	jeu.popPNJ(8,14,50, 1);
	jeu.popPNJ(9,41,20, 3);
	jeu.popPNJ(10,49,20, 2);
	jeu.popPNJ(11,42,30, 2);

	//>Jardin (pour la déco)
	jeu.popPNJ(4,33,10, 0);
	jeu.popPNJ(12,29,14, 2);
	jeu.popPNJ(13,23,14, 3);
	jeu.popPNJ(14,18,22, 1);

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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
				input[8] = true;
			else
				input[8] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				input[9] = true;
			else
				input[9] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				input[10] = true;
			else
				input[10] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				input[11] = true;
			else
				input[11] = false;
			
			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) )
				input[12] = true;
			else
				input[12] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) )
				input[13] = true;
			else
				input[13] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) )
				input[14] = true;
			else
				input[14] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) )
				input[15] = true;
			else
				input[15] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) )
				input[16] = true;
			else
				input[16] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)) )
				input[17] = true;
			else
				input[17] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) )
				input[18] = true;
			else
				input[18] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) )
				input[19] = true;
			else
				input[19] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) )
				input[20] = true;
			else
				input[20] = false;

			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) )
				input[21] = true;
			else
				input[21] = false;

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
