#include "Personnage.hpp"
#include "PNJ.hpp"
#include "Membre.hpp"



using namespace std;

/*-----Constructeur complet-----*/
Personnage::Personnage(string nom, int sexe, int age, double taille, double poids, int niveau, Stat stats, Corps corps, Inventaire inventaire, Equipement equipement, string texture) : Entite(texture), _stats(stats), _corps(corps), _inventaire(inventaire), _equipement(equipement){
    _nom = nom;
    _sexe = sexe;
    _age = age;
    _taille = taille;
    _poids = poids;
    _niveau = niveau;
    _corps.updateObs();
    _corps.setSuiv(this);
    _deuxmains = true;
    suiv = NULL;
    
    setTexture((sexe==0)?"./data/sprites/homme.png":"./data/sprites/femme.png");
}

/*-----Constructeur partiel-----*/
Personnage::Personnage(string nom, int sexe, int age, double taille, double poids, int niveau){
    _nom = nom;
    _sexe = sexe;
    _age = age;
    _taille = taille;
    _poids = poids;
    _niveau = niveau;
    _corps.setSuiv(this);
    _deuxmains = true;
    suiv = NULL;
    
    setTexture((sexe==0)?"./data/sprites/homme.png":"./data/sprites/femme.png");
}

Personnage::Personnage(string nom, int sexe) : _equipement(Equipement("du sanatorium")){
  _sexe = sexe;
  _nom = nom;
  _age = (rand() % 35 + 18);
  _taille = ((rand() % 150 + 70)/100.0);
  _poids = (rand() % 50 + 100);
  _niveau = 1;
  _corps.setSuiv(this);
  _deuxmains = true;
    suiv = NULL;
    
    setTexture((sexe==0)?"./data/sprites/homme.png":"./data/sprites/femme.png");
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
  _corps.setSuiv(this);
  _equipement = Equipement("du sanatorium");
  _deuxmains = true;
    suiv = NULL;
}


/*--------Getters--------*/

string Personnage::getNom(){return _nom;}
int Personnage::getSexe(){return _sexe;}
int Personnage::getAge(){return _age;}
int Personnage::getNiveau(){return _niveau;}
double Personnage::getTaille(){return _taille;}
double Personnage::getPoids(){return _poids;}
Stat& Personnage::getStats(){return _stats;}
Corps& Personnage::getCorps(){return _corps;}
Inventaire& Personnage::getInventaire(){return _inventaire;}
Equipement& Personnage::getEquipement(){return _equipement;}


/*--------Setters--------*/

void Personnage::setAge(int age){_age = age;}
void Personnage::setTaille(double taille){_taille = taille;}
void Personnage::setPoids(double poids){_poids = poids;}
void Personnage::setNiveau(int niveau){_niveau = niveau;}
void Personnage::levelUp(){++_niveau;}


  //Methodes de l'Observer
Observer* Personnage::getSuiv(){return suiv;}
void Personnage::setSuiv(Observer* o){suiv = o;}
void Personnage::passer(Membre& m){
  if (suiv)
    suiv->traiter(m, m.getPv());
}
void Personnage::traiter(Membre& m, int pv){
  //si le membre n'a plus de point de vie
  if (pv == 0){
    //et que c'est une des partie du bras
    if (m.getNom().find("Bras")!=string::npos || m.getNom().find("Coude")!=string::npos || m.getNom().find("Epaule")!=string::npos || m.getNom().find("Main")!=string::npos){
      //s'il ne lui manquait pas de main
      if (_deuxmains){
        //il lui en manque une
        _deuxmains = false;
        _stats.baisserCc();
        //on retire son arme si c'est une qui nécessite deux mains
        if (_equipement.getArme().getMains() == 2){
          Arme a = Arme("Mains nues");
          Arme b = _equipement.changerArme(a);
          _inventaire.ajouterArme(b);
        }
      }
      //sinon il n'a plus de bras
      else {
        Arme a = Arme("Plus de bras, plus d'armes");
        Arme b = _equipement.changerArme(a);
        _inventaire.ajouterArme(b);
        _stats.baisserCc();
      }
    }
    //si c'est une partie d'une jambe
    else if (m.getNom().find("Jambe")!=string::npos || m.getNom().find("Genou")!=string::npos || m.getNom().find("Cuisse")!=string::npos || m.getNom().find("Pied")!=string::npos){
      _stats.baisserVitesse();
    }
    //si c'est la tête ou le coeur
    else if (m.getNom().compare("Tête") == 0 || m.getNom().compare("Coeur") == 0){
      cout << "Le personnage est mort" << endl;
    }
  }
  _stats.setHP(_corps.getPv());
  passer(m);
}



//Autres méthodes

void Personnage::afficher(){
  cout << "Salut je suis " << _nom << ", j'ai " << _age << " ans, je mesure " << _taille << "m et je fais " << _poids << "kg. Je suis niveau " << _niveau<< "." << endl;
  cout << "Je suis " << ((_sexe==0)?"un homme":"une femme") << endl;
  cout << "Voici mes stats : " << endl;
  _stats.afficher();
}

void Personnage::defendre(PNJ& attaquant){
  Membre* m;
  //Jet de défense, sur 100
  int def = (rand() %100 + 1);
  //cout << &_corps;
  cout << "rand def " << def << endl;
  //Si échec critique
  if (def < 4){
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
      int coup = attaquant.getStats().getForce()+3-a->getScA();
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
        m->checkPv();
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
      int coup = (attaquant.getStats().getForce()+1-a->getScA());
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
        m->checkPv();
        a->changerDura(coup);
        cout << _nom << " a perdu " << coup << " de vie sur " << m->getNom() <<endl;
        cout << _nom << " a perdu " << coup << " de durabilité sur " << a->getNom() <<endl;
      }
    }//Fin du calcul de dommages de l'échec
  }//Fin de l'échec
  //Si le jet de défense est réussi, rien ne se passe
}//Fin de defendre(Personnage attaquant)

void Personnage::attaquer(PNJ& defendant){
  _actif = true;
  _tempsAction = sf::Time::Zero;
	
  defendant.defendre(*this);
}

void Personnage::soin(){
  _corps.soin();
}

void Personnage::bandage(){
  _corps.bandage(_niveau);
}

void Personnage::action(sf::Time turnTime){
	_tempsAction += turnTime;
	sf::Time duree;
	
	if(_action == 1)
		duree = sf::seconds(0.33)*float(_equipement.getArme().getVitesse());
	else if (_action == 2)
		duree = sf::seconds(0.80)*float(_equipement.getArme().getVitesse());
	
	if(_tempsAction >= duree)
		_actif = false;
}
