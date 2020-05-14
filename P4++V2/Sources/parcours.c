#include <stdio.h>
#include <stdlib.h>
#include "../Includes/strD.h"
#include "../Includes/parcours.h"

/**

* \file  parcours.c
* \brief Programme regroupant les fonctions de parcours de la matrice jeu du puissance 4++
* \author Aaron Amani
* \version 1.0
* \date 17 fevrier 2020

*/


/**
 * \fn int parcours(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui utilise des sous fonctions afin de parcourir toute la matrice et vaut vrai si le pion du joueur afin de determiner la victoire de celui-ci
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 * \return int
*/

extern int parcours(int x, int y, char mat[N][M],joueur *j){

/*--------Parcours ligne haute---------*/

int val=0;

val=parcoursLigneH(x,y,mat,j);
val+=parcoursLigneB(x,y,mat,j);

if (val>=5) {
  return(1);
}


/*--------Parcours ligne bas----------*/

val=0;

val=parcoursLigneB(x,y,mat,j);
val+=parcoursLigneH(x,y,mat,j);

 if (val>=5) {
  return(1);
}


/*--------Parcours colone droite----------*/

val=0;

val=parcoursColonneD(x,y,mat,j);
val+=parcoursColonneG(x,y,mat,j);


 if (val>=5) {
  return(1);
}


/*--------Parcours colone gauche---------*/

val=0;

val=parcoursColonneG(x,y,mat,j);
val+=parcoursColonneD(x,y,mat,j);


 if (val>=5) {
  return(1);
}

/*--------Parcours diagonale droite haute----------*/

val=0;

val=parcoursDiagDH(x,y,mat,j);
val+=parcoursDiagGB(x,y,mat,j);


 if (val>=5) {
  return(1);
}

//*--------Parcours diagonale gauche basse----------*/

val=0;

val=parcoursDiagGB(x,y,mat,j);
val+=parcoursDiagDH(x,y,mat,j);


 if (val>=5) {
  return(1);
}

/*--------Parcours diagonale droite basse----------*/

val=0;

val=parcoursDiagDB(x,y,mat,j);
val+=parcoursDiagGH(x,y,mat,j);


 if (val>=5) {
  return(1);
}

/*--------Parcours diagonale gauche haute---------*/

val=0;

val=parcoursDiagGH(x,y,mat,j);
val+=parcoursDiagDB(x,y,mat,j);

 if (val>=5) {
  return(1);
}

/*------Si il n'y a pas de pion alignée---------*/

return(0);


}


/**
 * \fn int parcoursLigneB(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en ligne a partir du bas
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/


int parcoursLigneB(int x, int y, char mat[N][M],joueur *j){

  /*--------Parcours ligne bas----------*/
  int val;
  for (val=0; mat[x+val][y]== j->couleur && val<=4 ; val++);

  return(val);

}

/**
 * \fn int parcoursLigneH(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en ligne a partir du haut
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursLigneH(int x, int y, char mat[N][M],joueur *j){

  /*--------Parcours ligne haut----------*/
  int val;
  for (val=0; mat[x-val][y]==j->couleur && val<=4 ; val++);

  return(val);

}

/**
 * \fn int parcoursColonneD(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en colonne a partir de la droite
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursColonneD(int x, int y, char mat[N][M],joueur *j){

  /*--------Parcours colonne droit----------*/
  int val;
  for (val=0; mat[x][y+val]== j->couleur && val<=4 ; val++);

  return(val);

}

/**
 * \fn int parcoursColonneG(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en colonne a partir de la gauche
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/
int parcoursColonneG(int x, int y, char mat[N][M],joueur *j){

  /*--------Parcours colonne gauche----------*/
  int val;
  for (val=0; mat[x][y-val]== j->couleur && val<=4 ; val++);

  return(val);

}

/**
 * \fn int parcoursDiagDH(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en diagonale a partir de la droite en bas
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursDiagDB(int x, int y, char mat[N][M],joueur *j){


  /*--------Parcours diagonale droite haute----------*/

  int val;
  for (val=0; mat[x+val][y+val]== j->couleur && val<=4 ; val++);

  return(val);

}

/**
 * \fn int parcoursDiagGH(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en diagonale a partir de la gauche en haut
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursDiagGH(int x, int y, char mat[N][M],joueur *j){

  //*--------Parcours diagonale gauche basse----------*/
  int val;
  for (val=0; mat[x-val][y-val]== j->couleur && val<=4 ; val++);

  return(val);
}

/**
 * \fn int parcoursDiagGB(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en diagonale en partant a gauche en bas
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursDiagGB(int x, int y, char mat[N][M],joueur *j){

  /*--------Parcours diagonale droite basse----------*/
  int val;
  for (val=0; mat[x+val][y-val]== j->couleur && val<=4 ; val++);

  return(val);

}

/**
 * \fn int parcoursDiagDH(int x, int y, char mat[N][M],joueur *j)
 * \brief fonction qui parcours la matrice a partir du pion en diagonale a partir de la droite en haut
 *
 * \param x coordonnée du pion du joueur en abscisse .
 * \param y coordonnée du pion du joueur en ordonnée.
 * \param mat du jeu.
 * \param structure du joueur contenant le couleur du joueur
 *
 *
*/

int parcoursDiagDH(int x, int y, char mat[N][M],joueur *j){

  /*--------Parcours diagonale gauche haute---------*/
  int val;
  for (val=0; mat[x-val][y+val]== j->couleur && val<=4 ; val++);

  return(val);
}
