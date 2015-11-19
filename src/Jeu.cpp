/**
 * @file Jeu.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la gestion du jeu
 **/

#include "Jeu.hpp"
#include <string>

//CONSTRUCTEUR
Jeu::Jeu(std::string fic) : _monde(fic)
{
	//_pnjs = std::vector<PNJ>;
}

//CREATION DES ENTITES MOUVANTES
//>Personnage
void Jeu::creerPersonnage(int x, int y)
{
	std::string texture = "data/sprites/homme.png";

	_personnage = Personnage();

	if(_personnage.getSexe() == 0)
		_personnage.setTexture("data/sprites/homme.png");
	else
		_personnage.setTexture("data/sprites/femme.png");

	_personnage.setSprite();

	_personnage.setLocation(x,y);
	_personnage.setPosition(16*x,16*y);
	
	_monde.setOccupant(x,y,0); //occupant 0 : Personnage
}
//>PNJ
void Jeu::creerPNJ()
{

}

//GESTION DES ENTREES
//> relevé du temps du tour
void Jeu::takeTurnTime(sf::Time turnTime)
{
	_turnTime = turnTime;
}

//> gestion des inputs
void Jeu::inputs(bool * in)
{
	//mettre en priorité les inputs liés à l'interface, au menu ?

	if(!_personnage.estActif())
	{	//choisir les priorités : deplacement - attaque - interaction
		if(in[0])
		{ //haut
			int x = _personnage.getPosX();
			int y1 = _personnage.getPosY();
			int y2 = _personnage.getPosY() - 1;
			//if( (y2 >= 0) and (_monde.estAccessible(x,y2)) and (_monde.getOccupant(x,y2)==-1) )
			//{
				_personnage.move(0);
			//	_monde.moveOccupant(x, y1, x, y2);
			//}
		}
		else if(in[1])
		{ //bas
			int x = _personnage.getPosX();
			int y1 = _personnage.getPosY();
			int y2 = _personnage.getPosY() + 1;
			//if( (y2 < _monde.getY()) and (_monde.estAccessible(x,y2)) and (_monde.getOccupant(x,y2)==-1) )
			//{
				_personnage.move(1);
			//	_monde.moveOccupant(x, y1, x, y2);
			//}
		}
		else if(in[2])
		{ //gauche
			int x1 = _personnage.getPosX();
			int x2 = _personnage.getPosX() - 1;
			int y = _personnage.getPosY();
			//if( (x2 >= 0) and (_monde.estAccessible(x2,y)) and (_monde.getOccupant(x2,y)==-1) )
			//{
				_personnage.move(2);
			//	_monde.moveOccupant(x1, y, x2, y);
			//}
		}
		else if(in[3])
		{ //droite
			int x1 = _personnage.getPosX();
			int x2 = _personnage.getPosX() + 1;
			int y = _personnage.getPosY();
			//if( (x2 < _monde.getX()) and (_monde.estAccessible(x2,y)) and (_monde.getOccupant(x2,y)==-1) )
			//{
				_personnage.move(3);
			//	_monde.moveOccupant(x1, y, x2, y);
			//}
		}
		else if(false)
		{

		}
	}
}

//relevé de la position de la souris
void Jeu::setPosSouris(sf::Vector2i posSouris)
{
	_posSouris = posSouris;
}

//GESTION DU JEU
void Jeu::gestion()
{
	gestionPersonnage();

	gestionPNJ();
}

//>Gestion du Personnage
void Jeu::gestionPersonnage()
{
	if(_personnage.estActif())
	{
		switch(_personnage.getAction())
		{
			case 0 :{ //deplacement
				_personnage.move(_turnTime);

				break;
			}
			case 1 :{ //attaqueG
				//personnage.attaque(direction)

				break;
			}
			case 2 :{ //attaqueD
				//personnage.attaque(direction)

				break;
			}
			case 3 :{ //magie

				break;
			}
			case 4 :{ //interaction

			}
		}
	}
	else
	{
		//changer la direction et le sprite du personnage selon l'endroit de la souris
		int sourisX = _posSouris.x - 512;
		int sourisY = _posSouris.y - 384;

		int x2 = sourisX*sourisX;
		int y2 = sourisY*sourisY;

		if(x2 > y2)
		{
			if(sourisX < 0)
			{	//gauche
				_personnage.setDirection(2);
				_personnage.setSprite(2);
			}
			else
			{	//droite
				_personnage.setDirection(3);
				_personnage.setSprite(3);
			}
		}
		else
		{
			if(sourisY < 0)
			{	//haut
				_personnage.setDirection(0);
				_personnage.setSprite(0);
			}
			else
			{	//bas
				_personnage.setDirection(1);
				_personnage.setSprite(1);
			}
		}
	}
}

//>Gestion des PNJ
void Jeu::gestionPNJ()
{
	//Pour chaque PNJ:
	//>Si en jeu
	//>>Check données entrantes :
	//>> Interactions, dégâts reçus, vie restante
	//>> Voit personnage ?
	//>>> Si oui: Distance == 1 ?
	//>>Check état:
	//>> Si

	for(PNJ& pnj : _pnjs)
	{
		if(pnj.estEnJeu()) //pnj mort : false
		{
			if(pnj.estActif())
			{	//action en cours
				switch(pnj.getAction())
				{
					case 0 :{ //deplacement
						pnj.move(_turnTime);

						break;
					}
					case 1 :{ //attaque
						//personnage.attaque(direction)

					}
				}
			}
			else
			{	//Peut démarrer une nouvelle action

			}
		}
	}
}


void Jeu::draw(sf::RenderWindow & window)
{
	//monde -> personnage & PNJ -> HUD
	//>Monde
	_monde.centrerSur(_personnage.getPosition());
	_monde.draw(window);

	//>PNJ
	for(PNJ pnj : _pnjs)
	{
		if(pnj.estEnJeu())
			window.draw(pnj.getSprite());
	}

	//>Personnage
	window.draw(_personnage.getSprite());

	//>HUD

}
