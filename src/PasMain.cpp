#include "SFML/Graphics.hpp"	//RenderWindow
#include "SFML/Window.hpp"		//Window - VideoMode - Style
#include "SFML/System.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Jeu.hpp"

using namespace std;

// int main(){
//   /* initialize random seed: */
// 	srand (time(NULL));

// 	//avec RenderWindow
// 	int X = 1024, Y = 768;
// 	std::string name = "Game";
// 	sf::RenderWindow window(sf::VideoMode(X, Y), name);

// 	Jeu jeu = Jeu("./data/map.txt");

// 	jeu.creerPersonnage(22,3);

// 	//Boutons (reste à en rajouter)
// 	bool input[8] = {0,0,0,0,0,0,0,0}; //boutons 0:haut, 1:bas, 2:gauche, 3:droite, 4:clicD, 5:clicG, 6:E, 7:F

// 	//Coordonnées de la souris
// 	sf::Vector2i sourisInt;
// 	sf::Vector2f sourisFloat;

// 	//Utilisés pour obtenir le temps de chaque tour
// 	sf::Clock globalTime;
// 	sf::Time turnTime;

// 	//Démarrage de la boucle principale
// 	while (window.isOpen())
// 	{
// 		turnTime = globalTime.restart();
// 		jeu.takeTurnTime(turnTime); //se met à jour

// 		sf::Event event;
// 		while (window.pollEvent(event))
// 		{
// 			//fermeture
// 			if (event.type == sf::Event::Closed)
// 				window.close();

// 			//mouvement de la souris
// 			if (event.type == sf::Event::MouseMoved)
// 				jeu.setPosSouris(sf::Mouse::getPosition(window));

// 			//clics de la souris
// 			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
// 				input[4] = true;
// 			else
// 				input[4] = false;

// 			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
// 				input[5] = true;
// 			else
// 				input[5] = false;

// 			//touches directionnelles
// 			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) )
// 				input[0] = true;
// 			else
// 				input[0] = false;

// 			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) )
// 				input[1] = true;
// 			else
// 				input[1] = false;

// 			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) )
// 				input[2] = true;
// 			else
// 				input[2] = false;

// 			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) )
// 				input[3] = true;
// 			else
// 				input[3] = false;

// 			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
// 				input[6] = true;
// 			else
// 				input[6] = false;

// 			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
// 				input[7] = true;
// 			else
// 				input[7] = false;

// 		}

// 		//envoie des inputs
// 		jeu.inputs(input);

// 		jeu.gestion();

// 		//affichages

// 		window.clear();

// 		//window.draw(/* */);
// 		jeu.draw(window);

// 		window.display();
// 	}

// }
