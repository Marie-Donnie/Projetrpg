  /**
   * @name  Constructeur complet
   * @brief Créé une armure prenant les paramètres donnés.
   * @param nom le nom qu'on veut donner à l'armure
   * @param piece le type de pièce que c'est (Plastron, Jambieres ou
   * Heaume)
   * @param matiere la matiere (tissu, cuir, maille ou plaque)
   * @param dura sa durabilité, permet de déterminer si elle protège
   * ou non (dura = 0 plus de protection)
   * @param scA son score d'armure, c'est à dire sa capacité à amortir
   * les coups (voir défendre de la classe personnage)
   * @param mA le mallus d'agilité (pas encore utile)
   * @param scS le score de sauvegarde, permet aux armures lourdes
   * d'encaisser totalement un coup
   * @param poids son poids (pas encore utile)
   * @return Une armure
   */

  /**
   * @name  Constructeur partiel
   * @brief Créé une armure prenant les paramètres donnés, le reste
   * étant aléatoire en fonction de ce paramètre
   * @param piece le type de piece qu'on veut (Plastron, Jambieres ou
   * Heaume)
   * @return Une armure
   */

  /**
   * @name  Constructeur partiel
   * @brief Créé une armure par défaut prenant les paramètres donnés, le reste
   * étant aléatoire en fonction de ce paramètre, c'est le
   * constructeur des armures de base du personnage
   * @param piece le type de piece qu'on veut (Plastron, Jambieres ou
   * Heaume)
   * @param suff le suffixe qu'on veut appliquer
   * @return Une armure
   */

  /**
   * @name  Constructeur par défaut
   * @brief Créé une armure aléatoire
   * @return Une armure
   */

 /**
   * @name  afficher
   * @brief Affiche l'armure en détails
   */

//include guard
#ifndef ARMURE_HPP
#define ARMURE_HPP

//included dependencies
#include <string>

using namespace std;

class Armure{
private :
  string _nom;
  string _piece;
  string _matiere;
  int _durabilite;
  int _scoreArmure;
  int _mallusAgi;
  int _scoreSauvegarde;
  double _poids;

public :
  //Constructeur
  Armure(string nom, string piece, string matiere, int dura, int scA, int mA, int scS, double poids);
  Armure(string piece, string suff);
  Armure(string piece);
  Armure();
  //Getters
  string getNom();
  string getPiece();
  string getMat();
  int getDura();
  int getScA();
  int getMA();
  int getSauv();
  double getPoids();
  //Setters
  void setNom(string nom);
  void setPiece(string piece);
  void setDura(int dura);
  void changerDura(int dura);
  void setMat(string mat);
  void setScA(int scA);
  void setMA(int mA);
  void setSauv(int scS);
  void setPoids(double poids);

  //Autres méthodes
  void afficher();


};

#endif //ARMURE_HPP
