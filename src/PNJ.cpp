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
        _corps.setSuiv(this);
        suiv = NULL;
}

PNJ::PNJ(string nom, string texture) : Entite(texture){
	_nom = nom;
        _equi = Equipement();
	_stats = Stat();
        _corps = Corps();
        _corps.setSuiv(this);
        suiv = NULL;
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

//setters

//Observer
Observer* PNJ::getSuiv(){return suiv;}
void PNJ::setSuiv(Observer* o){suiv = o;}
void PNJ::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, m.getPv());
}
void PNJ::traiter(Membre& m, int pv){
  if (pv == 0){
    if (m.getNom().find("Bras")!=string::npos || m.getNom().find("Coude")!=string::npos || m.getNom().find("Epaule")!=string::npos || m.getNom().find("Main")!=string::npos){
      _stats.baisserCc();
      }
      else if (m.getNom().find("Jambe")!=string::npos || m.getNom().find("Genou")!=string::npos || m.getNom().find("Cuisse")!=string::npos || m.getNom().find("Pied")!=string::npos){
          _stats.baisserVitesse();
        }
      else if (m.getNom().compare("Tête") || m.getNom().compare("Coeur")){
        cout << "Le zombie est mort" << endl;
      }
  }
  _stats.setHP(_corps.getPv());
  passer(m);
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

//Attaque/Defense
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
      Arme* armeattaq = &(attaquant.getEquipement().getArme());
      int dmgarme = (rand()% (armeattaq->getDmgmax()- armeattaq->getDmgmin()+1)+armeattaq->getDmgmin());
      cout << dmgarme << endl;
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
        m->checkPv();
        a->changerDura(coup);
        cout << _nom << " a perdu " << coup << " de vie sur " << m->getNom() <<endl;
        cout << _nom << " a perdu " << coup << " de durabilité sur " << a->getNom() <<endl;
      }
    }//Fin du calcul de dommages de l'échec
  }//Fin de l'échec
}//Fin de defendre(PNJ attaquant)
