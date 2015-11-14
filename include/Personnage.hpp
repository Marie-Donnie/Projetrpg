/**
 * @file Personnage.hpp
 * @author Marie Delavergne, Robin Wibaux
 * @date October, 2015
 * @brief Définition de la classe de personnage
 **/

  /**
   * @name  Constructeur complet
   * @brief Créé un personnage prenant les paramètres donnés.
   * @param nom le nom qu'on veut donner au personnage
   * @param sexe le sexe du personnage (0 pour homme et 1 pour femme)
   * @param age l'âge du personnage
   * @param taille sa taille (type 1.50, pour 1 mètre et 50 centimètres)
   * @param poids son poids (type 50.3)
   * @param niveau son niveau
   * @param stats les stats qu'on veut lui donner
   * @param corps le corps du personnage
   * @param inventaire l'inventaire qu'il aura
   * @param equipement l'équipement qu'il porte
   * @return Un personnage tout prêt !
   */


#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Stat.hpp"
#include "Corps.hpp"
#include "Equipement.hpp"
#include "Inventaire.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


using namespace std;

class Personnage {
private :
  string _nom;
  int _sexe;
  int _age;
  double _taille;
  double _poids;
  int _niveau;
  Stat _stats;
  Corps _corps;
  Inventaire _inventaire;
  Equipement _equipement;

  sf::Vector2i _location;
  sf::Vector2f _position;
  sf::Texture _texture;
  sf::Sprite _sprite;

  bool _actif;
  int _action; //0:deplacement, 1:attaqueG, 2:attaqueD, 3:magie, 4:interaction
  int _direction; //0:haut, 1:bas, 2:gauche, 3:droite
  sf::Time _tempsAction; //une fois un seuil dépacé, l'action prend fin

public :
  //Constructeurs
  Personnage(string nom, int sexe, int age, double taille, double poids, int niveau, Stat stats, Corps corps, Inventaire inventaire, Equipement equipement, string texture);
  Personnage(string nom, int sexe, int age, double taille, double poids, int niveau);
  Personnage();

  //Getters
  string getNom();
  int getSexe();
  int getAge();
  double getTaille();
  double getPoids();
  int getNiveau();
  Stat& getStats();
  Corps& getCorps();
  Inventaire& getInventaire();
  Equipement& getEquipement();

  sf::Vector2i getLocation();
  int getLocalX();
  int getLocalY();
  sf::Vector2f getPosition();
  float getPosX();
  float getPosY();
  sf::Texture& getTexture();
  sf::Sprite& getSprite();

  bool estActif();
  int getAction();
  int getDirection();

  //Setters
  void setAge(int age);
  void setTaille(double taille);
  void setPoids(double poids);
  void setNiveau(int niveau);
  void levelUp();

  void setLocation(sf::Vector2i loc);
  void setLocation(int x, int y);
  void setPosition(sf::Vector2f pos);
  void setPosition(float x, float y);
  void setTexture(string texture); //charge directement un fichier png
  void setSprite(int direction); //0:haut, 1:bas, 2:gauche, 3:droite
  void setSprite(); //sprite par défaut

  void setDirection(int d);


  //Mouvements
  //>Mises en mouvement
  void move(int direction);
  //>Mouvement en cours
  void move(sf::Time turnTime);

  //Autres méthodes
  void afficher();
  void defendre(Personnage& attaquant);
  void attaquer(Personnage& defendant);
};

#endif //PERSONNAGE_HPP
