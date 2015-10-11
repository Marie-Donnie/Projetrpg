#ifndef STAT_HPP
#define STAT_HPP

class Stat {
private :
  int _hitPoint;
  int _mana;
  int _endu;
  int _intel;
  int _force;
  int _agi;
  int _esprit;
  int _resiPeste;
  int _capCombat;
  int _capTir;


public :
  Stat(); //Constructeur
  /*-----Getters-----*/
  int getHP();
  int getMana();
  int getIntel();
  int getEndu();
  int getForce();
  int getAgi();
  int getEsprit();
  int getRP();
  int getCc();
  int getCt();

  /*-----Setters-----*/
  void setHP(int);
  void setMana(int);
  void setEndu(int);
  void setIntel(int);
  void setForce(int);
  void setAgi(int);
  void setEsprit(int);
  void setRP(int);
  void setCc(int);
  void setCt(int);

  void afficher();
};

#endif //STAT_HPP
