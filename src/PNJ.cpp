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

PNJ::PNJ(string nom){
	_nom = nom;
        _equi = Equipement();
	_stats = Stat();
        _corps = Corps();
	_position = sf::Vector2f(0,0);
	_actif = false;
}

PNJ::PNJ(string nom, string texture){
	_nom = nom;
        _equi = Equipement();
	_stats = Stat();
        _corps = Corps();
	_actif = false; //revoir les attributs...

    if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}

    _sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    _sprite.setOrigin(15.0,15.0);

	_position = sf::Vector2f(0,0);
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
void PNJ::setSprite(int x, int y)
{
	_sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(x, y, x+16, y+16));
}
void PNJ::setSprite()
{
	_sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

//activité
bool PNJ::isActif()
{
	return _actif;
}
void PNJ::setActivity(bool activity)
{
	_actif = activity;
}
void PNJ::switchActivity()
{
	_actif = !_actif;
}


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
      int coup = (attaquant.getStats().getForce()+1-a->getScA());
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
