#include <string>

#ifndef ARMURE_HPP
#define ARMURE_HPP

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
