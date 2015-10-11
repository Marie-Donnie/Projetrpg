/**
 * @file Personnage.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe de personnage
 **/


#include "Personnage.hpp"
#include <iostream>


using namespace std;


Personnage::Personnage(string nom, int age, double taille, double poids){
    _nom = nom;
    _age = age;
    _taille = taille;
    _poids = poids;
    _stats = Stat();
}

void Personnage::afficher(){
  cout << "Salut je suis " << _nom << ", j'ai " << _age << " ans, je mesure " << _taille << "m et je fais " << _poids << "kg." << endl;
  cout << "Voici mes stats : " << endl;
  _stats.afficher();
}
