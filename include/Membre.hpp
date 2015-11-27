  /**
   * @name  Constructeur partiel
   * @brief Créé un membre en définissant ses paramètres, sauf les
   * _sousMembre qui sont un vecteur vide
   * @param pv les points de vie du membre
   * @param pvmax les points de vie maximum, quand le personnage/pnj
   * n'a pas pris de dommages
   * @param nom le nom du membre
   * @param o l'observer à qui il envoie les informations, c'est à
   * dire le corps
   * @return Un membre dont les sousmembres ne sont pas encore initialisés
   */

  /**
   * @name  changerPv
   * @brief Applique les dommages subits sur un membre, en vérifiant
   * qu'il ne va pas tomber en points de vie négatif
   * @param pv les points de vie qu'il devrait perdre
   */

  /**
   * @name  checkPv
   * @brief Est appelé dans la défense du personnage ou pnj, enclenche
   * la chaîne d'observers
   */

//include guard
#ifndef MEMBRE_HPP
#define MEMBRE_HPP

//forward declared dependencies
class Observer;

//included dependencies
#include <string>
#include <vector>


using namespace std;

class Membre{
private :
  int _pv;
  int _pvmax;
  string _nom;
  vector<Membre> _sousMembre;
  Observer* _corps;
public :
  //Constructeur
  Membre(int pv, int pvmax, string nom, vector<Membre> sousm, Observer* o);
  Membre(int pv, int pvmax, string nom, Observer* o);
  Membre(int pv, int pvmax, string nom);
  Membre();
  //Getters
  int getPv();
  int getPvMax();
  string getNom();
  vector<Membre>& getMembres();
  Membre& getMembre(int loca);
  //Setters
  void setPv(int pv);
  void setPvMax(int pv);
  void setNom(string nom);
  void setObs(Observer* o);
  void changerPv(int pv);
  void changerMembre(Membre& m, int loca);

  void checkPv();
};

#endif //MEMBRE_HPP
