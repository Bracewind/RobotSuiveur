#ifndef Plateforme_h
#define Plateforme_h

#include "Moteur.h"
#include <Arduino.h>

/*
 * Les noms de cette classe n'ont de sens que si la gauche du robot coincide
 * avec notre gauche
 */

class PlateformeBuilder {
private:
  Moteur m_moteurGauche;
  Moteur m_moteurDroit;

public:
  PlateformeBuilder *avecMoteurGauche(int pinGauche, int pinDroite, int pinPWM);
  PlateformeBuilder *avecMoteurDroit(int pinGauche, int pinDroite, int pinPWM);
  Plateforme build();
};

class Plateforme {
private:
  Moteur m_moteurGauche;
  Moteur m_moteurDroit;

public:
  static int vitesseEnTournant;

  Plateforme(int pinGaucheMGauche, int pinDroiteMGauche, int pinPWMMGauche,
             int pinGaucheMDroite, int pinDroiteMDroite, int pinPWMMDroite);
  void connecteMoteurGauche(int pinGauche, int pinDroite, int pinPWM);
  void connecteMoteurDroit(int pinGauche, int pinDroite, int pinPWM);
  void setup();

  void stop();
  void avance(unsigned int vitesse);
  void recule(unsigned int vitesse);
  void tournerAGauche(unsigned int vitesseEnTournant);
  void tournerADroite(unsigned int vitesseEnTournant);
};

#endif