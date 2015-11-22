/**
 * @file Jeu.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la gestion du jeu
 **/

#include "Jeu.hpp"
#include <string>

using namespace std;

//CONSTRUCTEUR
Jeu::Jeu(string fic, string nom, int sexe) :  _personnage(nom,sexe), _monde(fic)
{
  suiv = NULL;
//_pnjs = std::vector<PNJ>;
}

//Getters
Personnage& Jeu::getPerso(){return _personnage;}
vector<PNJ>& Jeu::getPNJs(){return _pnjs;}
vector<sf::Texture *>& Jeu::getTextures(){return _pnjTextures;}
Monde& Jeu::getMonde(){return _monde;}

//CREATION DES ENTITES MOUVANTES
//>Personnage
void Jeu::popPersonnage(int x, int y)
{
	_personnage.setLocation(x,y);
	_personnage.setPosition(16*x,16*y);

	_monde.setOccupant(x,y,0); //occupant 0 : Personnage
}
//>PNJ
void Jeu::creerPNJ(string nom, int text)
{
	_pnjs.push_back(PNJ(nom));
	_pnjs.back().setTexture(*_pnjTextures[text]);
        _pnjs.back().setSprite();
}
void Jeu::creerPNJ(string nom, string text)
{
  _pnjs.push_back(PNJ(nom,text));
}
void Jeu::ajouterTexture(string text)
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
  int dir = directionSouris();

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
    else if(in[4])
    { //clicG
      int x = _personnage.getLocX();
      int y = _personnage.getLocY();
      int dX, dY;

      int p = _personnage.getEquipement().getArme().getPortee();
      bool espace = true;

      //Determination de la direction
      if((dir == 0) or (dir == 1))
      { //axe vertical
        dY = (dir==0)?-1:1;

        for(int i=1; i<=p; ++i)
        {//pour toutes les cases à portée
          if(_monde.estPlat(x,y+(i*dY)) and espace)
          {//si aucun obstacle rencontré maintenant ou avant
            if(_monde.getOccupant(x,y+(i*dY))!=-1)
            {//si pnj
              _personnage.attaquer(_pnjs[_monde.getOccupant(x,y+(i*dY))-1]);
            //les indices de pnjs vont de 0 à n, ceux de getOccupant vont de 1 à n+1 pour les pnj
            }
          }
        else
          espace = false;
        }
      }
      else
      { //axe horizontale
        dX = (dir==2)?-1:1;

        for(int i=1; i<=p; ++i){
          if(_monde.estPlat(x+(i*dX),y) and espace){
            if(_monde.getOccupant(x+(i*dX),y)!=-1){
              _personnage.attaquer(_pnjs[_monde.getOccupant(x+(i*dX),y)-1]);
            }
          }
          else
            espace = false;
        }
      }

      _personnage.setDirection(dir);
      _personnage.setAction(1);
      _personnage.setSprite(dir);
    }
    else if(in[5])
    { //clicD
      int x = _personnage.getLocX();
      int y = _personnage.getLocY();

      //Determination de la direction
      if(dir == 0) //haut
      {
        if( _monde.estPlat(x-1,y-1) and // XXX
            _monde.estPlat(x  ,y-1) and // .O.
            _monde.estPlat(x+1,y-1) )		// ...
        {
          for(int i=-1; i<2; ++i) { //pour les 3 cases X
            if(_monde.getOccupant(x+i,y-1)!=-1) //s'il y a un occupant
              _personnage.attaquer(_pnjs[_monde.getOccupant(x+i,y-1)-1]);
          }
        }

        _personnage.setDirection(dir);
        _personnage.setAction(1);
        _personnage.setSprite(dir);
      }
      else if(dir==1) //bas
      {
        if( _monde.estPlat(x-1,y+1) and // ...
            _monde.estPlat(x  ,y+1) and // .O.
            _monde.estPlat(x+1,y+1) )   // XXX
        {
          for(int i=-1; i<2; ++i)
          {
            if(_monde.getOccupant(x+i,y+1)!=-1)
              _personnage.attaquer(_pnjs[_monde.getOccupant(x+i,y+1)-1]);
          }
        }

        _personnage.setDirection(dir);
        _personnage.setAction(1);
        _personnage.setSprite(dir);
      }
      else if(dir==2) //gauche
      {
        if( _monde.estPlat(x-1,y-1) and // X..
            _monde.estPlat(x-1,y  ) and // XO.
            _monde.estPlat(x-1,y+1) )   // X..
        {
          for(int i=-1; i<2; ++i){
            if(_monde.getOccupant(x-1,y+i)!=-1)
              _personnage.attaquer(_pnjs[_monde.getOccupant(x-1,y+i)-1]);
          }
        }

        _personnage.setDirection(dir);
        _personnage.setAction(1);
        _personnage.setSprite(dir);
      }
      else if(dir==3) //droite
      {
        if( _monde.estPlat(x+1,y-1) and // ..X
            _monde.estPlat(x+1,y  ) and // .OX
            _monde.estPlat(x+1,y+1) )   // ..X
        {
          for(int i=-1; i<2; ++i) {
            if(_monde.getOccupant(x+1,y+i)!=-1)
              _personnage.attaquer(_pnjs[_monde.getOccupant(x+1,y+i)-1]);
          }
        }

        _personnage.setDirection(dir);
        _personnage.setAction(1);
        _personnage.setSprite(dir);
      }
    } //fin in[5]
  }
}

//>> Méthode privée, direction de la souris
int Jeu::directionSouris()
{
	int sourisX = _posSouris.x - 400 ;
	int sourisY = _posSouris.y - 300 ;

	int x2 = sourisX*sourisX;
	int y2 = sourisY*sourisY;

	if(x2 > y2)
	{
		if(sourisX < 0) //gauche
			return 2;
		else 			//droite
			return 3;
	}
	else
	{
		if(sourisY < 0) //haut
			return 0;
		else 			//bas
			return 1;
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
void Jeu::gestionPersonnage(){
	if(_personnage.estActif()){
		switch(_personnage.getAction())	{
			case 0 :{ //deplacement
				_personnage.move(_turnTime);
				_personnage.setSprite(_personnage.getDirection());

				break;
			}
			case 1 :{ //attaqueG
				//personnage.attaque(direction)
				_personnage.action(_turnTime);
				break;
			}
			case 2 :{ //attaqueD
				//personnage.attaque(direction)
				_personnage.action(_turnTime);
				break;
			}
			case 3 :{ //soin

				break;
			}
			case 4 :{ //interaction

			}
		}
	}
	else
	{
		//changer la direction et le sprite du personnage selon l'endroit de la souris
		int dir = directionSouris();

		_personnage.setDirection(dir);
		_personnage.setSprite(dir);
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

  for(PNJ& pnj : _pnjs){
    if(pnj.getCorps().getPv() <= 0){
      pnj.setEnJeu(false);
    }

    if(pnj.estEnJeu()){ //pnj mort : false
      if(pnj.estActif()){	//action en cours
        switch(pnj.getAction()){
          case 0 :{ //deplacement
            pnj.move(_turnTime);
						break;
          }
          case 1 :{ //attaque
            pnj.action(_turnTime); //cooldown
					}
        }
      }
      else
      {	//Peut démarrer une nouvelle action
        if( pnj.detecteCase(_personnage.getLocation()) and pnj.voitCase(_personnage.getLocation(), _monde) )
				{ //pnj a vu personnage et veux s'en approcher !
          i = pnj.getLocX();
					j = pnj.getLocY();
					dI = pnj.getLocX()-_personnage.getLocX();
          dJ = pnj.getLocY()-_personnage.getLocY();
          signeI = (dI<0)?-1:1;
          signeJ = (dJ<0)?-1:1;

          if( (dI*dI)+(dJ*dJ) <= 1 ) //à 1 de distance... ou 0.
          {
						pnj.attaquer(_personnage);
						pnj.setAction(1);

						//direction
						if(dI > 0)
							pnj.setDirection(2);
						else if (dI < 0)
							pnj.setDirection(3);
						else if (dJ > 0)
							pnj.setDirection(0);
						else
							pnj.setDirection(1);

						pnj.setSprite(pnj.getDirection());
					}	//attaque!
          else
          {
            if(dI==0) //ils sont alignés verticalement
						{
							if( _monde.estAccessible(i,j-signeJ) ) //si la case du dessus/dessous est accessible
							{
								_monde.moveOccupant(i,j, i,j-signeJ); //maj de la map
								pnj.move( (signeJ>0)?0:1 );	//mise en mouvement
								pnj.setSprite(pnj.getDirection()); //maj du sprite
							}
						}
						else if(dJ==0) //alignés horrizontalement
						{
							if( _monde.estAccessible(i-signeI,j) )
							{
								_monde.moveOccupant(i,j, i-signeI,j);
								pnj.move( (signeI>0)?2:3 );
								pnj.setSprite(pnj.getDirection());
							}
						}
						else //pas alignés
						{
							if( _monde.estAccessible(i,j-signeJ) )
							{
								_monde.moveOccupant(i,j, i,j-signeJ);
								pnj.move( (signeJ>0)?0:1 );
								pnj.setSprite(pnj.getDirection());
							}
							else if( _monde.estAccessible(i-signeI,j) )
							{
								_monde.moveOccupant(i,j, i-signeI,j);
								pnj.move( (signeI>0)?2:3 );
								pnj.setSprite(pnj.getDirection());
							}
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
          x = pnj.getPosX() - _personnage.getPosX() + 392;
          y = pnj.getPosY() - _personnage.getPosY() + 292;

          pnj.getSprite().setPosition(x,y);

          window.draw(pnj.getSprite());
        }
    }

  //>Personnage
  window.draw(_personnage.getSprite());
}



//Observer
Observer* Jeu::getSuiv(){return suiv;}
void Jeu::setSuiv(Observer* o){suiv = o;}
void Jeu::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, m.getPv());
}
void Jeu::traiter(Membre& m, int pv){
  passer(m);
}

void Jeu::personnageMort(){
  if (suiv)
    suiv->personnageMort();
}

void Jeu::pnjMort(){


}
