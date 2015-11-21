//include guard
#ifndef JEU_HPP
#define JEU_HPP

//Forward declared dependencies
//class PNJ;

//included dependencies
#include <string>
#include <stdio.h>				//printf
#include <iostream>				//cin cout
#include <vector>
#include "SFML/System.hpp"
#include "Membre.hpp"
#include "Personnage.hpp"
#include "Monde.hpp"
#include "PNJ.hpp"

using namespace std;

class Jeu {
private:
  Personnage _personnage;
  vector<PNJ> _pnjs;
  vector<sf::Texture *> _pnjTextures;
  Monde _monde;
  sf::Time _turnTime;//temps du précédent tour de la boucle while principale
  sf::Vector2i _posSouris;//position de la souris

  //méthodes internes
  void gestionPersonnage(); //appelée par : void gestion()
  void gestionPNJ();

  void setTexturePNJ(int num);

public:
  //CONSTRUCTEUR
  Jeu(string fic);

  //Getters
  Personnage& getPerso();
  vector<PNJ>& getPNJs();
  vector<sf::Texture *>& getTextures();
  Monde& getMonde();


  //Création des entités mouvantes
  void creerPersonnage(int x, int y, string nom, int sexe);
  //void supprimerPersonnage();

  void creerPNJ(string nom, int text);
  void creerPNJ(string nom, string text);
  //void supprimerPNJ(int num);
  void ajouterTexture(string texture);
  void popPNJ(int num, int x, int y);

  // gestion des entrées
  //>inputs
  void inputs(bool * in);
  void setPosSouris(sf::Vector2i posSouris);
  //>temps de tour
  void takeTurnTime(sf::Time turnTime);

  // traitement des données
  void gestion();

  // affichage global
  void draw(sf::RenderWindow & window);
};

#endif
