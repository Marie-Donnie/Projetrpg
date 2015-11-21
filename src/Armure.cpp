#include "Armure.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Armure::Armure(string nom, string piece, string matiere, int dura, int scA, int mA, int scS, double poids){
  _nom = nom;
  _piece = piece;
  _matiere = matiere;
  _durabilite = dura;
  _scoreArmure = scA;
  _mallusAgi = mA;
  _scoreSauvegarde = scS;
  _poids = poids;
}

Armure::Armure(string piece){
  _piece = piece;
  //Choix du matériau
  string matieres[4];
  matieres[0] = "tissu";
  matieres[1] = "cuir";
  matieres[2] = "maille";
  matieres[3] = "plaque";
  int mat = (rand() %4);
  _matiere = matieres[mat];
  _nom = _piece + " en " + _matiere;
  _durabilite = (rand() % 20 + 40);
  _scoreArmure = 2*(mat);
  _mallusAgi = 1*(mat-1);
  _scoreSauvegarde = mat;
  _poids = 0.75+(pow(mat,2));
}
Armure::Armure(){
  //Choix de la pièce
  string pieces[3];
  pieces[0] = "Plastron";
  pieces[1] = "Jambieres";
  pieces[2] = "Heaume";
  int piece = (rand()%3);
  _piece = pieces[piece];
  //Choix du matériau
  string matieres[4];
  matieres[0] = "tissu";
  matieres[1] = "cuir";
  matieres[2] = "maille";
  matieres[3] = "plaque";
  int mat = (rand() %4);
  _matiere = matieres[mat];
  _nom = _piece + " en " + _matiere;
  _durabilite = (rand() % 20 + 40);
  _scoreArmure = 2*(mat);
  _mallusAgi = 1*(mat-1);
  _scoreSauvegarde = mat;
  _poids = 0.75+(pow(mat,2));
}

Armure::Armure(string piece, string suff){
  _matiere = "tissu";
  _piece = piece;
  _nom = _piece + " en " + _matiere + " "+ suff;
  _durabilite = 100;
  _scoreArmure = 0;
  _mallusAgi = 0;
  _scoreSauvegarde = 0;
  _poids = 0.51;
}


//Getters
string Armure::getNom(){return _nom;}
string Armure::getPiece(){return _piece;}
string Armure::getMat(){return _matiere;}
int Armure::getDura(){return _durabilite;}
int Armure::getScA(){return _scoreArmure;}
int Armure::getMA(){return _mallusAgi;}
int Armure::getSauv(){return _scoreSauvegarde;}
double Armure::getPoids(){return _poids;}

//Setters
void Armure::setNom(string nom){_nom = nom;}
void Armure::setPiece(string piece){_piece = piece;}
void Armure::setMat(string mat){_matiere = mat;}
void Armure::setDura(int dura){_durabilite = dura;}
void Armure::changerDura(int dura){ _durabilite -= dura;}
void Armure::setScA(int scA){_scoreArmure = scA;}
void Armure::setMA(int mA){_mallusAgi = mA;}
void Armure::setSauv(int scS){_scoreSauvegarde = scS;}
void Armure::setPoids(double poids){_poids = poids;}

 void Armure::afficher(){
   cout << "Nom \t\t" << _nom << endl;
   cout << "Type \t\t" << _piece << endl;
   cout << "Matiere \t" << _matiere << endl;
   cout << "Durabilite\t" << _durabilite << endl;
   cout << "Score d'armure\t" << _scoreArmure << endl;
   cout << "Mallus d'agilité " << _mallusAgi << endl;
   cout << "Poids\t\t" << _poids << endl;
 }
