#include "Personnage.hpp"
#include "PNJ.hpp"
#include "Membre.hpp"



using namespace std;

/*-----Constructeur complet-----*/
Personnage::Personnage(string nom, int sexe, int age, double taille, double poids, int niveau, Stat stats, Corps corps, Inventaire inventaire, Equipement equipement, string texture){
    _nom = nom;
    _sexe = sexe;
    _age = age;
    _taille = taille;
    _poids = poids;
    _niveau = niveau;
    _stats = stats;
    _corps = corps;
    _inventaire = inventaire;
    _equipement = equipement;
    _deuxmains = true;
    _actif = false;

    if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}

    _sprite.setPosition(504,376); //le centre de l'écran est : (512,384)
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
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
    _inventaire = Inventaire();
    _equipement = Equipement();
    _deuxmains = true;
    _actif = false;
    _sprite.setPosition(504,376); //le centre de l'écran est : (512,384)
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
  _inventaire = Inventaire();
  _equipement = Equipement("du sanatorium");
  _deuxmains = true;
    _actif = false;
  _sprite.setPosition(504,376); //le centre de l'écran est : (512,384)
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

sf::Vector2i Personnage::getLocation(){return _location;}
int Personnage::getLocalX(){return _location.x;}
int Personnage::getLocalY(){return _location.y;}

sf::Vector2f Personnage::getPosition(){return _position;}
float Personnage::getPosX(){return _position.x;}
float Personnage::getPosY(){return _position.y;}

sf::Texture& Personnage::getTexture(){return _texture;}
sf::Sprite& Personnage::getSprite(){return _sprite;}

bool Personnage::estActif(){return _actif;}
int Personnage::getAction(){return _action;}
int Personnage::getDirection(){return _direction;}

bool Personnage::estImmobile(){
	return (_action != 0) or !_actif;
}

/*--------Setters--------*/

void Personnage::setAge(int age){_age = age;}
void Personnage::setTaille(double taille){_taille = taille;}
void Personnage::setPoids(double poids){_poids = poids;}
void Personnage::setNiveau(int niveau){_niveau = niveau;}
void Personnage::levelUp(){++_niveau;}

void Personnage::setLocation(sf::Vector2i loc){
	_location.x = loc.x; _location.y = loc.y;
}
void Personnage::setLocation(int x, int y){
	_location.x = x; _location.y = y;
}
void Personnage::setPosition(sf::Vector2f pos){
	_position.x = pos.x; _position.y = pos.y;
}
void Personnage::setPosition(float x, float y){
	_position.x = x; _position.y = y;
}
void Personnage::setTexture(string texture)
{
	if(!_texture.loadFromFile(texture)){
		std::cout << "Erreur lors du chargement de " << texture << std::endl;
	}
	_sprite.setTexture(_texture);
	setSprite();
}
void Personnage::setSprite(int d) //direction haut, bas, gauche, droite
{
	_sprite.setTextureRect(sf::IntRect((d*16), 0, 16, 16));
}
void Personnage::setSprite()
{
	_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16)); //pour avoir celui de face
}
void Personnage::setDirection(int d)
{
	_direction = d;
}

//mouvements
//>Mises en mouvement
void Personnage::move(int direction)
{
	_actif = true;
	_direction = direction;
	_action = 0; //0: déplacement
	_tempsAction = sf::Time::Zero;

	if(_direction == 0)
		_location.y -= 1;
	else if (_direction == 1)
		_location.y += 1;
	else if (_direction == 2)
		_location.x -= 1;
	else if (_direction == 3)
		_location.x += 1;


}
//>Mouvement en cours
void Personnage::move(sf::Time turnTime)
{
	_tempsAction += turnTime;
	sf::Time duree = sf::seconds(1.5);

	if(_tempsAction < duree)
	{
		float rapport = _tempsAction.asSeconds() / duree.asSeconds();
		if(_direction==0)
			_position.y = (float)(_location.y * 16) + (16*rapport);
		else if(_direction==1)
			_position.y = (float)(_location.y * 16) - (16*rapport);
		else if(_direction==2)
			_position.x = (float)(_location.x * 16) + (16*rapport);
		else if(_direction==3)
			_position.x = (float)(_location.x * 16) - (16*rapport);

	}
	else
	{
		_position.x = (float)(_location.x * 16);
		_position.y = (float)(_location.y * 16);

		_actif = false;
	}
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

void Personnage::attaquer(PNJ& defendant){
  defendant.defendre(*this);
}

void Personnage::soin(int membre){
  _corps.soin(membre);
}

void Personnage::bandage(int membre){
  _corps.bandage(membre, _niveau);
}
