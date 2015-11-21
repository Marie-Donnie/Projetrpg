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
void Jeu::creerPNJ(std::string nom, int text)
{
	_pnjs.push_back(PNJ(nom));
	_pnjs.back().setTexture(*_pnjTextures[text]);
    _pnjs.back().setSprite();
}
void Jeu::creerPNJ(std::string nom, std::string text)
{
	_pnjs.push_back(PNJ(nom, text));
}
void Jeu::ajouterTexture(std::string text)
{
	sf::Texture * texture = new sf::Texture();
	if(!(*texture).loadFromFile(text)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	
	_pnjTextures.push_back(texture);
}
void Jeu::popPNJ(int num, int x, int y)
{
	_pnjs[num].setEnJeu(true);
	
	_pnjs[num].setLocation(x,y);
	_pnjs[num].setPosition(16*x,16*y);
	
	_monde.setOccupant(x,y,num+1);
}

//>>méthode privée
void Jeu::setTexturePNJ(int num)
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
			int x = _personnage.getLocX();
			int y1 = _personnage.getLocY();
			int y2 = _personnage.getLocY() - 1;
			if( (y2 >= 0) and (_monde.estAccessible(x,y2)) )
			{
				_personnage.move(0);
				_monde.moveOccupant(x, y1, x, y2);
			}
		}
		else if(in[1])
		{ //bas
			int x = _personnage.getLocX();
			int y1 = _personnage.getLocY();
			int y2 = _personnage.getLocY() + 1;
			if( (y2 < _monde.getY()) and (_monde.estAccessible(x,y2)) )
			{
				_personnage.move(1);
				_monde.moveOccupant(x, y1, x, y2);
			}
		}
		else if(in[2])
		{ //gauche
			int x1 = _personnage.getLocX();
			int x2 = _personnage.getLocX() - 1;
			int y = _personnage.getLocY();
			if( (x2 >= 0) and (_monde.estAccessible(x2,y)) )
			{
				_personnage.move(2);
				_monde.moveOccupant(x1, y, x2, y);
			}
		}
		else if(in[3])
		{ //droite
			int x1 = _personnage.getLocX();
			int x2 = _personnage.getLocX() + 1;
			int y = _personnage.getLocY();
			if( (x2 < _monde.getX()) and (_monde.estAccessible(x2,y)) )
			{
				_personnage.move(3);
				_monde.moveOccupant(x1, y, x2, y);
			}
		}
		else if(false)
		{

		}
		
		if(in[0] or in[1] or in[2] or in[3])
		{	//provisoire, juste pour que ça soit plus sympa
			//changer la direction et le sprite du personnage selon l'endroit de la souris
			int sourisX = _posSouris.x - 512;
			int sourisY = _posSouris.y - 384;

			int x2 = sourisX*sourisX;
			int y2 = sourisY*sourisY;

			if(x2 > y2)
			{
				if(sourisX < 0)
				{	//gauche
					_personnage.setSprite(2);
				}
				else
				{	//droite
					_personnage.setSprite(3);
				}
			}
			else
			{
				if(sourisY < 0)
				{	//haut
					_personnage.setSprite(0);
				}
				else
				{	//bas
					_personnage.setSprite(1);
				}
			}
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

	int i,j,dI,dJ,signeI,signeJ;

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
				if( pnj.detecteCase(_personnage.getLocation()) and pnj.voitCase(_personnage.getLocation(), _monde) )
				{
					dI = pnj.getLocX()-_personnage.getLocX();
					dJ = pnj.getLocY()-_personnage.getLocY();
					signeI = (dI<0)?-1:1;
					signeJ = (dJ<0)?-1:1;
					
					if( (dI*dI)+(dJ*dJ) <= 1 ) //à 1 de distance... ou 0.
					{}	//attaque!
					else
					{
						if( (pnj.getLocX() != _personnage.getLocX()) and _monde.estAccessible(pnj.getLocX() - signeI, pnj.getLocY()))
						{ //déplacement sur l'axe x
							_monde.moveOccupant(pnj.getLocX(), pnj.getLocY(), pnj.getLocX()-signeI, pnj.getLocY());
							pnj.move( (signeI>0)?2:3 ); //signeI positif -> personnage à gauche -> move(2), sinon move(3)
							
							pnj.setSprite(pnj.getDirection());
						}
						else if( (pnj.getLocY() != _personnage.getLocY()) and _monde.estAccessible(pnj.getLocX(), pnj.getLocY()) - signeJ)
						{ //déplacement sur l'axe y
							_monde.moveOccupant(pnj.getLocX(), pnj.getLocY(), pnj.getLocX(), pnj.getLocY()-signeJ);
							pnj.move( (signeJ>0)?0:1 ); //signeJ positif -> personnage au dessus -> move(0), sinon move(1)
							
							pnj.setSprite(pnj.getDirection());
							
						}
						//else : bloqué ! C'est con un zombie
					}
				}
			}
		}
	}
}


void Jeu::draw(sf::RenderWindow & window)
{
	float x, y;
	
	//monde -> personnage & PNJ -> HUD
	//>Monde
	_monde.centrerSur(_personnage.getPosition());
	_monde.draw(window);

	//>PNJ
	for(PNJ pnj : _pnjs)
	{
		if(pnj.estEnJeu())
		{
			x = pnj.getPosX() - _personnage.getPosX() + 504;
			y = pnj.getPosY() - _personnage.getPosY() + 376;
			
			pnj.getSprite().setPosition(x,y);
			
			window.draw(pnj.getSprite());
		}
	}

	//>Personnage
	window.draw(_personnage.getSprite());

	//>HUD

}
