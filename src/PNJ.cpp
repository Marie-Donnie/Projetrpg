/**
 * @file PNJ.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe des pnjs
 **/


#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "PNJ.hpp"
#include "Membre.hpp"
#include "Personnage.hpp"
#include "Entite.hpp"


using namespace std;

//CONSTRUCTEUR
PNJ::PNJ(string nom){
	_nom = nom;
        _corps.setSuiv(this);
        suiv = NULL;
        _focus = -1;
        _enJeu = false;
}
PNJ::PNJ(string nom, string texture) : Entite(texture){
	_nom = nom;
        _equi = Equipement();
	_stats = Stat();
        _corps.setSuiv(this);
        suiv = NULL;
        _focus = -1;
        _enJeu = false;
}

PNJ::PNJ(const PNJ& lautre)
  : Observer(lautre),
    Entite(lautre),
    _nom(lautre._nom),
    _stats(lautre._stats),
    _equi(lautre._equi),
    _corps(lautre._corps),
    _destination(lautre._destination),
    _focus(lautre._focus),
    _enJeu(lautre._enJeu)
 {
   _corps.setSuiv(this);
}

PNJ& PNJ::operator=(const PNJ& lautre){
  _nom=(lautre._nom);
  _stats=(lautre._stats);
  _equi=(lautre._equi);
  _corps=(lautre._corps);
  _destination=(lautre._destination);
  _focus=(lautre._focus);
  _enJeu=(lautre._enJeu);
  _corps.setSuiv(this);
  suiv=(lautre.suiv);
  return *this;
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

bool PNJ::estEnJeu()
{
	return _enJeu;
}

//setters
void PNJ::setTexture(sf::Texture & texture)
{
	Entite::_texture = texture;
	Entite::_sprite.setTexture(_texture);
}
void PNJ::setTexture(string text)
{
	if(!(Entite::_texture).loadFromFile(text)){
		std::cout << "Erreur lors du chargement de " << text << std::endl;
	}
	Entite::_sprite.setTexture(_texture);
}

void PNJ::setEnJeu(bool set)
{
	_enJeu = set;
}

//Observer
Observer* PNJ::getSuiv(){return suiv;}
void PNJ::setSuiv(Observer* o){suiv = o;}
void PNJ::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, 1);
  else cout << "PNJ n'a pas de suivant" << endl;
}
void PNJ::traiter(Membre& m, int pv){
  if (pv == 0){
    if (m.getNom().find("Bras")!=string::npos || m.getNom().find("Coude")!=string::npos || m.getNom().find("Epaule")!=string::npos || m.getNom().find("Main")!=string::npos){
      _stats.baisserCc();
      }
      else if (m.getNom().find("Jambe")!=string::npos || m.getNom().find("Genou")!=string::npos || m.getNom().find("Cuisse")!=string::npos || m.getNom().find("Pied")!=string::npos){
          _stats.baisserVitesse();
        }
      else if (m.getNom().compare("Tête")==0){
        pnjMort(*this);
      }
  }
  _stats.setHP(_corps.getPv());
  passer(m);
}
void PNJ::pnjMort(PNJ& p){
  if (suiv)
    suiv->pnjMort(*this);
}

//vision
bool PNJ::voitCase(int i, int j, Monde & monde)
{
	/*int dI = i - _location.x;
	int dJ = j - _location.y;
	int signeI = (dI<0)?-1:1;	//prend -1 si dI négatif, 1 sinon
	int signeJ = (dJ<0)?-1:1;

	if( dI == 0 )
	{ //ligne verticale
		for( int k = 1 ; k < (dJ*signeJ) ; ++k )	//dJ*signeJ est forcément positif, idem pour dI*signeI
		{
			if( !monde.estTransparant(_location.x, _location.y + (k*signeJ)) )
				return false;
		}
	}
	else if ( dJ == 0 )
	{ //ligne horizontale
		for( int k = 1 ; k < (dI*signeI) ; ++k )
		{
			if( !monde.estTransparant(_location.x + (k*signeI), _location.y) )
				return false;
		}
	}
	else if ( (dI*dI) == (dJ*dJ) )
	{ //diagonale
		for( int k = 1 ; k < (dI*signeI) ; ++k )
		{
			if( !monde.estTransparant(_location.x + (k*signeI), _location.y + (k*signeJ)) )
				return false;
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
//ne tient compte que de la distance
bool PNJ::detecteCase(int i, int j)
{
	int dI = i - _location.x, dJ = j - _location.y;
	return ( (dI*dI)+(dJ*dJ) ) <= 8*8; //Pour 8 cases de distance à vol d'oiseau
}
bool PNJ::detecteCase(sf::Vector2i loc)
{
	return detecteCase(loc.x,loc.y); //Pour 8 cases de distance à vol d'oiseau
}

//Mouvement
void PNJ::move(int direction)
{
	Entite::move(direction);
}
void PNJ::move(sf::Time turnTime)
{
	Entite::move(turnTime, sf::seconds(0.5));
}

//Attaque/Defense
void PNJ::defendre(Personnage& attaquant){
  Membre* m;
  //Jet de défense, sur 100
  int def = (rand() %100 + 1);
  //cout << &_corps;
  //cout << "rand def " << def << endl;
  //On vérifie si le coup passe
  if (def < attaquant.getStats().getCc() - (_stats.getAgi())*10){
    //On cherche le membre touché
    int r = (rand() %9);
    // cout << "rand membre " << r << endl;
    m = &(_corps.getLMembres().at((r<6)?r:5));
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
    Arme* armeattaq = &(attaquant.getEquipement().getArme());
    int dmgarme = (rand()% (armeattaq->getDmgmax()- armeattaq->getDmgmin()+1)+armeattaq->getDmgmin());
    //Calcul des dommages
    int coup = ((attaquant.getStats().getForce()+dmgarme)+3-((a->getDura() >0)?a->getScA():0));
      //Jet de sauvegarde
      int sauv = rand() %10 ;
      //Si le score de sauvegarde est plus grand que le rand, seule
      //l'armure prend le coup
      if (a->getSauv() > sauv && coup > 0){
        a->changerDura(coup);
        //cout << _nom << " a perdu " << coup << " de durabilité sur " << a->getNom() <<endl;
      }
      //Sinon, l'armure et le membre subissent des dommages
      else if (coup > 0) {
        m->changerPv(coup);
        m->checkPv();
        a->changerDura(coup);
        //cout << _nom << " a perdu " << coup << " de vie sur " << m->getNom() <<endl;
        //cout << _nom << " a perdu " << coup << " de durabilité sur " << a->getNom() <<endl;
      }
    }//Fin du calcul de dommages de l'échec
  //Fin de l'échec
}//Fin de defendre(PNJ attaquant)

void PNJ::attaquer(Personnage& defendant){
  _actif = true;
  _tempsAction = sf::Time::Zero;

  defendant.defendre(*this);
}

void PNJ::action(sf::Time turnTime){
	_tempsAction += turnTime;
	sf::Time duree = sf::seconds(1.0)*float(_equi.getArme().getVitesse());

	if(_tempsAction >= duree)
		_actif = false;
}
