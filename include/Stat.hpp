  /**
   * @name  Constructeur complet
   * @brief Créé un ensemble de stats modulables
   * @param hp les points de vie du personnage
   * @param mana sa mana (pas encore utilisée)
   * @param endu son endurance (pas encore utilisée)
   * @param intel son intelligence (pas encore utilisée)
   * @param force sa force, qui sert pour les dommages
   * @param agi son agilité, qui sert pour éviter les coups
   * @param esprit sa regeneration de mana (pas encore utilisé)
   * @param rP sa résistance à la peste (pas encore utilisée)
   * @param cc sa capacité de combat, qui sert pour arriver à toucher
   * @param ct sa capacité de tir (pas encore utilisé)
   * @param vitesse sa vitesse, qui n'est pas totalement implémentée
   * @return Les stats du personnage !
   */

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
  int _vitesse;

public :
 //Constructeur
  Stat();
  Stat(int hp, int mana, int endu, int intel, int force, int agi, int esprit, int rP, int cc, int ct, int vitesse);
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
  int getVitesse();

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
  void baisserCc();
  void monterCc();
  void setCt(int ct);
  void baisserVitesse();
  void monterVitesse();

  void afficher();
};

#endif //STAT_HPP
