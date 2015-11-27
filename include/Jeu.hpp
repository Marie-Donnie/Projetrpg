/**
 * @file Jeu.hpp
 * @author Marie Delavergne, Robin Wibaux
 * @date October, 2015
 * @brief Définition de la classe de Jeu
 **/

/**
  * @name   Constructeur
  * @brief  Créée le Jeu, lance la construction de Monde et Personnage avec leurs paramètres respectifs.
  * @param  fic, l'adresse du fichier de la map
  * @param  nom, le nom du personnage à créer
  * @param  sexe, le numéro du sexe du personnage
  */
/**
  * @name   popPersonnage
  * @brief  Place le personnage sur la carte aux coordonnées voulues
  * @param  X, l'abscisse d'apparition
  * @param  Y, l'ordonnée d'apparition
  */
/**
  * @name   creerPNJ
  * @brief  Créée un nouveau PNJ dans le vecteur à PNJ du Jeu
  * @param  nom, le nom du PNJ
  * @param  texture, la texture que charge le PNJ
  */
/**
  * @name   popPNJ
  * @brief  Place le pnj voulu sur la carte à l'emplacement voulu
  * @param  Num, le numéro du pnj dans le vecteur de Jeu
  * @param  X, l'abscisse d'apparition
  * @param  Y, l'ordonnée d'apparition
  * @param  dir, la direction
  */
/**
  * @name   input
  * @brief  Traite les touches pressées.
  * Selon la touche, lance l'action correspondantes.
  * Si le personnage est déjà en action, ne fait rien.
  * @param  in, un tableau de booléens
  */
/**
  * @name   setPositionSouris
  * @brief  Met à jour la position de la souris sur l'écran
  * @param  posSouris, la position entière de la souris
  */
/**
  * @name   directionSouris
  * @brief  Méthode privée
  * Selon la position de la souris enregistrée en attribut, renvoie la direction correspondante
  * @return Le numéro de la direction selon le code employé : 0,1,2,3 pour respectivement haut,bas,gauche,droite
  */
/**
  * @name   takeTurnTime
  * @brief  Prend le temps du tour de boucle de main
  * @param  Le temps turnTime
  */
/**
  * @name   gestion
  * @brief  Gère le jeu selon la situation, les données, etc...
  * La gestion est partagée entre les méthodes privée gestionPersonnage et gestionPNJ.
  */
/**
  * @name   gestionPersonnage
  * @brief  Méthode privée
  * Gère le personnage selon son action en cours.
  * Si aucune action en cours, l'oriente vers la souris.
  */
/**
  * @name   gestionPNJ
  * @brief  Méthode privée
  * Gère tous les pnj en jeu selon s'ils voient le Personnage, sont à distance d'attaque, etc...
  */
/**
  * @name   draw
  * @brief  Dessine tout.
  * Dessine le sprite du Personnage, ceux des PNJ en jeu et lance la méthode draw de Monde.
  * @param  window, la fenêtre dans laquelle on dessine tout
  */

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
