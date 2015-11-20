/**
 * @file PNJ.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe des pnjs
 **/


#include <iostream>
#include "PNJ.hpp"
#include "Membre.hpp"
#include "Personnage.hpp"


using namespace std;

//CONSTRUCTEUR
PNJ::PNJ(string nom){
	_nom = nom;
        _equi = Equipement();
	_stats = Stat();
        _corps = Corps();

	_actif = false;
	_direction = 1;
}

PNJ::PNJ(string nom, string texture){
	_nom = nom;
        _equi = Equipement();
	_stats = Stat();
        _corps = Corps();

    if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}

    _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

	_actif = false; //revoir les attributs...
	_direction = 1;
}

void PNJ::afficher(){
	cout << "Salut je suis " << _nom << ", Nyark nyark !" << endl;
	cout << "Voici pas mes stats. Nah!" << endl;
	//_stats.afficher();
}

//getters
string PNJ::getNom(){return _nom;}
Stat& PNJ::getStats(){return _stats;}
Corps& PNJ::getCorps(){return _corps;}
Equipement& PNJ::getEquipement(){return _equi;}

sf::Vector2i PNJ::getLocation(){return _location;}
sf::Vector2f PNJ::getPosition(){return _position;}
sf::Texture& PNJ::getTexture(){return _texture;}
sf::Sprite& PNJ::getSprite(){return _sprite;}

bool PNJ::estActif(){return _actif;}
int PNJ::getAction(){return _action;}
int PNJ::getDirection(){return _direction;}

bool PNJ::estImmobile(){
	return !_actif or (_action!=0);
}

//setters
void PNJ::setLocation(sf::Vector2i loc){
	_location.x = loc.x; _location.y = loc.y;
}
void PNJ::setLocation(int x, int y){
	_location.x = x; _location.y = y;
}
void PNJ::setPosition(sf::Vector2f pos){
	_position.x = pos.x; _position.y = pos.y;
}
void PNJ::setPosition(float x, float y){
	_position.x = x; _position.y = y;
}
void PNJ::setTexture(string texture)
{
	if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
}
void PNJ::setSprite(int x, int y) //à actualiser !
{
	_sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(x*16, y*16, 16, 16));
}
void PNJ::setSprite()
{
	_sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

//mouvements
//>Mises en mouvement
void PNJ::move(int direction)
{
	_actif = true;
	_direction = direction;
	_action = 0; //0: déplacement
	_tempsAction = sf::Time::Zero;

	if(_direction == 0)
		_location.y -= 1;
	else if (_direction == 1)
		_location.y += 1;
	else if (_direction == 2)
		_location.x -= 1;
	else if (_direction == 3)
		_location.x += 1;


}
//>Mouvement en cours
void PNJ::move(sf::Time turnTime)
{
	_tempsAction += turnTime;
	sf::Time duree = sf::seconds(0.40); //plus lent que joueur

	if(_tempsAction >= duree)
	{
		float rapport = _tempsAction.asSeconds() / duree.asSeconds();
		if(_direction==0)
			_position.y = (float)(_location.y * 16) + (16*rapport);
		else if(_direction==1)
			_position.y = (float)(_location.y * 16) - (16*rapport);
		else if(_direction==2)
			_position.x = (float)(_location.x * 16) + (16*rapport);
		else if(_direction==3)
			_position.x = (float)(_location.x * 16) - (16*rapport);

	}
	else
	{
		_position.x = (float)(_location.x * 16);
		_position.y = (float)(_location.y * 16);

		_actif = false;
	}
}

//activité
bool PNJ::estEnJeu()
{
	return _enJeu;
}
void PNJ::setEnJeu(bool set)
{
	_enJeu = set;
}

//vision
bool PNJ::voitCase(int i, int j, Monde & monde)
{
	/*int dI = i - _location.x;
	int dJ = j - _location.y;

	if( dI == 0 )
	{ //ligne verticale
		for( int k = 1 ; k < dJ ; ++k )
		{

		}
	}
	else if ( dJ == 0 )
	{ //ligne horizontale
		for( int k = 1 ; k < dI ; ++k )
		{

		}
	}
	else if ( (dI*dI) == (dJ*dJ) )
	{ //diagonale
		for( int k = 1 ; k < dI ; ++k )
		{

		}
	}
	else if ( (dI*dI) > (dJ*dJ) )
	{
		double rapport = (double)(dJ) / (double)(dI);
		double somme = 0;
		double fraction;

		int lookI, lookJ;

		for( int k = 1 ; k < dI ; ++k )
		{
			lookI = _location.x + k;

			somme += rapport;
			lookJ = _location.y + int(somme + 0.5); //


		}
	}
	else
	{
		double rapport = (double)(dI) / (double)(dJ);
		double somme = 0;
		double fraction;

		int lookI, lookJ;

		for( int k = 1 ; k < dI ; ++k )
		{
			lookJ = _location.y + k;

			somme += rapport;
			lookI = _location.x + int(somme + 0.5); //


		}
	}*/

	return true;
}
bool PNJ::voitCase(sf::Vector2i loc, Monde & monde)
{
	return voitCase(loc.x, loc.y, monde);
}

//Attaque/Defence
void PNJ::defendre(Personnage& attaquant){
  Membre* m;
  //Jet de défense, sur 100
  int def = (rand() %100 + 1);
  //cout << &_corps;
  cout << "rand def " << def << endl;
  //On vérifie si le coup passe
  if (def < attaquant.getStats().getCc() - (_stats.getAgi())*10){
    //On cherche le membre touché
    int r = (rand() %6);
    cout << "rand membre " << r << endl;
    m = &(_corps.getLMembres().at(r));
    //Calcul de dommages de l'échec :
    //On cherche maintenant l'armure qui défend cette localisation
    Armure* a;
    //Si c'est une armure qui protège les jambes, on retourne les jambières
    if (r < 2){
      a = &(_equi.getArmure(0));
    }
    //Sinon si c'est une armure qui protège les bras et le torse, on
    //retourne le plastron
    else if (r < 5){
      a = &(_equi.getArmure(1));
    }
    //Sinon c'est le heaume
    else a = &(_equi.getArmure(2));
    //On teste si l'armure a encore de la durabilité pour savoir si on
    //est protégé
    if (a->getDura() > 0){
      //Calcul des dommages
      Arme* armeattaq = attaquant.getEquipement().getArme();
      int dmgarme = (rand()% (armeattaq->getDmgmax()- armeattaq->getDmgmin()+1)+armeattaq->getDmgmin());
      int coup = ((attaquant.getStats().getForce()+dmgarme)-a->getScA());
      //Jet de sauvegarde
      int sauv = rand() %10 ;
      //Si le score de sauvegarde est plus grand que le rand, seule
      //l'armure prend le coup
      if (a->getSauv() > sauv && coup > 0){
        a->changerDura(coup);
        cout << _nom << " a perdu " << coup << " de durabilité sur " << a->getNom() <<endl;
      }
      //Sinon, l'armure et le membre subissent des dommages
      else if (coup > 0) {
        m->changerPv(coup);
        a->changerDura(coup);
        cout << _nom << " a perdu " << coup << " de vie sur " << m->getNom() <<endl;
        cout << _nom << " a perdu " << coup << " de durabilité sur " << a->getNom() <<endl;
      }
    }//Fin du calcul de dommages de l'échec
  }//Fin de l'échec
}//Fin de defendre(PNJ attaquant)
