/**
 * @file Jeu.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la gestion du jeu
 **/

#include "PNJ.hpp"
#include "Jeu.hpp"


//CONSTRUCTEUR
Jeu::Jeu(std::string fic) : _monde(fic)
{
	_pnjs = std::vector<PNJ *>();
}

// relevé du temps du tour
void Jeu::takeTurnTime(sf::Time turnTime)
{
	_turnTime = turnTime;
}


// gestion des inputs
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
			if( (y2 >= 0) and (_monde.estAccessible(x,y2)) and (_monde.getOccupant(x,y2)==-1) /*and pas d'objet encombrant*/ )
			{
				_personnage.move(0);
				_monde.moveOccupant(x, y1, x, y2);
			}
		}
		else if(in[1])
		{ //bas
			int x = _personnage.getPosX();
			int y1 = _personnage.getPosY();
			int y2 = _personnage.getPosY() + 1;
			if( (y2 < _monde.getY()) and (_monde.estAccessible(x,y2)) and (_monde.getOccupant(x,y2)==-1) /*and pas d'objet encombrant*/ )
			{
				_personnage.move(1);
				_monde.moveOccupant(x, y1, x, y2);
			}
		}
		else if(in[2])
		{ //gauche
			int x1 = _personnage.getPosX();
			int x2 = _personnage.getPosX() - 1;
			int y = _personnage.getPosY();
			if( (x2 >= 0) and (_monde.estAccessible(x2,y)) and (_monde.getOccupant(x2,y)==-1) /*and pas d'objet encombrant*/ )
			{
				_personnage.move(2);
				_monde.moveOccupant(x1, y, x2, y);
			}
		}
		else if(in[3])
		{ //droite
			int x1 = _personnage.getPosX();
			int x2 = _personnage.getPosX() + 1;
			int y = _personnage.getPosY();
			if( (x2 < _monde.getX()) and (_monde.estAccessible(x2,y)) and (_monde.getOccupant(x2,y)==-1) /*and pas d'objet encombrant*/ )
			{
				_personnage.move(3);
				_monde.moveOccupant(x1, y, x2, y);
			}
		}
		else if(false)
		{

		}
	}
}

void Jeu::setPosSouris(sf::Vector2i posSouris)
{
	_posSouris = posSouris;
}


void Jeu::gestion()
{
	gestionPersonnage();


}

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
			{
				_personnage.setDirection(2);
				_personnage.setSprite(2);
			}
			else
			{
				_personnage.setDirection(3);
				_personnage.setSprite(3);
			}
		}
		else
		{
			if(sourisY < 0)
			{
				_personnage.setDirection(0);
				_personnage.setSprite(0);
			}
			else
			{
				_personnage.setDirection(1);
				_personnage.setSprite(1);
			}
		}
	}
}

void draw(sf::RenderWindow & window)
{

}
