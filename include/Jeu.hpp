//include guard
#ifndef JEU_HPP
#define JEU_HPP


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
#include "Observer.hpp"
#include "Interface.hpp"

using namespace std;

class Jeu : public Observer{
private:
  Personnage _personnage;
  vector<PNJ> _pnjs;
  Monde _monde;
  sf::Time _turnTime;//temps du précédent tour de la boucle while principale
  sf::Vector2i _posSouris;//position de la souris
  Interface  * _interface;
  bool _saisie; //pour les touches devant être relâchées avant nouvelles pressions

  //méthodes internes
  void gestionPersonnage(); //appelée par : void gestion()
  void gestionPNJ();

  int directionSouris();

public:
  //CONSTRUCTEUR
  Jeu(string fic, std::string nom, int sexe);

  Jeu(const Jeu& lautre);
  Jeu& operator=(const Jeu& lautre);

  //Getters
  Personnage& getPerso();
  vector<PNJ>& getPNJs();
  Monde& getMonde();
  Interface& getInterface();
  
  //Setters
  void setInterface(Interface* interface);


  //Création des entités mouvantes
  void popPersonnage(int x, int y);

  void creerPNJ(string nom, string text);
  void popPNJ(int num, int x, int y, int dir=1);

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

  //Méthodes de l'observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  void traiter(Membre& m, int pv);
  void passer(Membre& m);
  void personnageMort();
  void pnjMort(PNJ& p);
};

#endif
