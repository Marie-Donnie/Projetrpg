//include guard
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
 //Constructeur
  Stat();
  Stat(int hp, int mana, int endu, int intel, int force, int agi, int esprit, int rP, int cc, int ct);
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
  void setHP(int hp);
  void setMana(int mana);
  void setEndu(int endu);
  void setIntel(int intel);
  void setForce(int force);
  void setAgi(int agi);
  void setEsprit(int esprit);
  void setRP(int rP);
  void setCc(int cc);
  void setCt(int ct);

  void afficher();
};

#endif //STAT_HPP
