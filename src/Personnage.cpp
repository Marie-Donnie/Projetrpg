/**
 * @file Personnage.cpp
 * @author Marie Delavergne, Robin Wibaux
 * @since 2015
 * @brief Définition de la classe de personnage
 **/


#include "Personnage.hpp"


using namespace std;

/*-----Constructeur complet-----*/
Personnage::Personnage(string nom, int sexe, int age, double taille, double poids, int niveau, Stat stats, Corps corps, Equipement equipement){
    _nom = nom;
    _sexe = sexe;
    _age = age;
    _taille = taille;
    _poids = poids;
    _niveau = niveau;
    _stats = stats;
    _corps = corps;
    _equipement = equipement;
}

/*-----Constructeur partiel-----*/
Personnage::Personnage(string nom, int sexe, int age, double taille, double poids, int niveau){
    _nom = nom;
    _sexe = sexe;
    _age = age;
    _taille = taille;
    _poids = poids;
    _niveau = niveau;
    _stats = Stat();
    _corps = Corps();
    _equipement = Equipement();
}

/*-----Constructeur par défaut-----*/
Personnage::Personnage(){
  _sexe = (rand() % 2);
  /*ifstream prenom;
    ((_sexe==0)?(prenom.open("prenomm.txt")):(prenom.open("prenomf.txt")));*/
  _nom = "Rhand";
  _age = (rand() % 35 + 18);
  _taille = ((rand() % 150 + 70)/100.0);
  _poids = (rand() % 50 + 100);
  _niveau = 1;
  _stats = Stat();
  _corps = Corps();
  _equipement = Equipement("du sanatorium");
}


//Getters
string Personnage::getNom(){return _nom;}
int Personnage::getSexe(){return _sexe;}
int Personnage::getAge(){return _age;}
int Personnage::getNiveau(){return _niveau;}
double Personnage::getTaille(){return _taille;}
double Personnage::getPoids(){return _poids;}
Stat& Personnage::getStats(){return _stats;}
Corps& Personnage::getCorps(){return _corps;}
Equipement& Personnage::getEquipement(){return _equipement;}

//Setters
void Personnage::setAge(int age){
  _age = age;
}
void Personnage::setTaille(double taille){
  _taille = taille;
}
void Personnage::setPoids(double poids){
  _poids = poids;
}
void Personnage::setNiveau(int niveau){
  _niveau = niveau;
}
void Personnage::levelUp(){
  ++_niveau;
}


//Autres méthodes

void Personnage::afficher(){
  cout << "Salut je suis " << _nom << ", j'ai " << _age << " ans, je mesure " << _taille << "m et je fais " << _poids << "kg. Je suis niveau " << _niveau<< "." << endl;
  cout << "Je suis " << ((_sexe==0)?"un homme":"une femme") << endl;
  cout << "Voici mes stats : " << endl;
  _stats.afficher();
}

void Personnage::defendre(Personnage& attaquant){
  Membre* m;
  //Jet de défense, sur 100
  int def = (rand() %100 + 1);
  //cout << &_corps;
  cout << "rand def " << def << endl;
  //Si échec critique
  if (def < 100){
    //On cherche le membre touché
    int r = (rand() %6);
    cout << "rand membre " << r << endl;
    //Si c'est un bras ou une jambe
    if (r<4){
      //On précise la localisation (pied/main, genou/coude ou cuisse/épaule)
      int memb = (rand() %3);
      cout << "rand loca " << memb << endl;
      //Si c'est pied ou main, on désigne l'orteil ou le doigt
      if (memb == 0){
        int doigt = (rand() %6);
        cout << "rand extremite " << doigt << endl;
        //Si c'est 5, c'est la cheville ou le poignet (donc pied ou main)
        if (doigt == 5){
          m = &(_corps.getLMembres().at(r).getMembre(memb));}
        //Sinon c'est un doigt
        else {
          m = &(_corps.getLMembres().at(r).getMembre(memb).getMembre(doigt));}
      }
      //Sinon c'est le membre désigné
      else {
        m = &(_corps.getLMembres().at(r).getMembre(memb));}
    }
    //Sinon c'est la tête ou le torse
    else {
      //On désigne la loca
      int memb = (rand() %8);
      cout << "rand loca " << memb << endl;
      //si c'est 7, c'est la gorge pour la tête (donc la tête qui
      //prend), le torse pour le torse
      if (memb == 7){
        m = &(_corps.getLMembres().at(r));
      }
      //sinon c'est un "organe"
      else {
        m = &(_corps.getLMembres().at(r).getMembre(memb));
      }
    }
    //Calcul de dommages de l'échec critique :
    //On cherche maintenant l'armure qui défend cette localisation
    Armure* a;
    //Si c'est une armure qui protège les jambes, on retourne les jambières
    if (r < 2){
      a = &(_equipement.getArmure(0));
    }
    //Sinon si c'est une armure qui protège les bras et le torse, on
    //retourne le plastron
    else if (r < 5){
      a = &(_equipement.getArmure(1));
    }
    //Sinon c'est le heaume
    else a = &(_equipement.getArmure(2));
    //On teste si l'armure a encore de la durabilité pour savoir si on
    //est protégé
    if (a->getDura() > 0){
      //Calcul des dommages, avec le coup critique
      int coup = attaquant.getStats().getForce()+2-a->getScA();
      //Jet de sauvegarde
      int sauv = rand() %10 ;
      //Si le score de sauvegarde est plus grand que le rand, seule
      //l'armure prend le coup
      if (a->getSauv() > sauv && coup > 0){
        a->changerDura(coup);
        cout << _nom << " a perdu " << coup << " de durabilité sur " << a->getNom() <<endl;
      }
      //Sinon, l'armure et le membre subissent des dommages
      else if (coup >0) {
        m->changerPv(coup);
        a->changerDura(coup);
        //cout << &m << endl;
        cout << _nom << " a perdu " << coup << " de vie sur " << m->getNom() <<endl;
        cout << _nom << " a perdu " << coup << " de durabilité sur " << a->getNom() <<endl;
      }
    }//Fin du calcul de dommages de l'échec critique
  } //Fin de l'échec critique
  //Jet non critique, on vérifie si le coup passe
  else if (def < attaquant.getStats().getCc() - (_stats.getAgi())*10){
    //On cherche le membre touché
    int r = (rand() %6);
    cout << "rand membre " << r << endl;
    m = &(_corps.getLMembres().at(r));
    //Calcul de dommages de l'échec :
    //On cherche maintenant l'armure qui défend cette localisation
    Armure* a;
    //Si c'est une armure qui protège les jambes, on retourne les jambières
    if (r < 2){
      a = &(_equipement.getArmure(0));
    }
    //Sinon si c'est une armure qui protège les bras et le torse, on
    //retourne le plastron
    else if (r < 5){
      a = &(_equipement.getArmure(1));
    }
    //Sinon c'est le heaume
    else a = &(_equipement.getArmure(2));
    //On teste si l'armure a encore de la durabilité pour savoir si on
    //est protégé
    if (a->getDura() > 0){
      //Calcul des dommages
      int coup = (attaquant.getStats().getForce()-a->getScA());
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
  //Si le jet de défense est réussi, rien ne se passe
}//Fin de defendre(Personnage attaquant)

void Personnage::attaquer(Personnage& defendant){
  defendant.defendre(*this);
}
