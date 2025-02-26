#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef FONCTION_H
#define FONCTION_H

typedef struct Hero
{
	char gamertag[30];
	long age;

	int nombredeVie;
	int win;
	int x ;
	int y ;

}Hero;

typedef struct Case
{
	char symbole;
	int visible;
}Case;

int lireUser(char *chaine , int taille);

int lireUserC();


void viderBuffer();

void afficheLab(Hero* player,char salle[10][30]);

void afficheLab3(Hero * player ,Case salle[10][30]);

void afficheHaze(Hero* player,char salle[10][30]);

void afficheHaze3(Hero* player,Case salle[10][30]);

int infoHeros(Hero* player);

long lireLong();

void curseurH(Hero* player , char salle[10][30]);

void curseurH3(Hero* player , Case salle[10][30]);

int  move(Hero* player, char salle[10][30]);

void rmH(Hero* player , char salle[10][30]);

void rmH3(Hero* player , Case salle[10][30]);

void piege(Hero* player , char salle[10][30]);

void tresor(Hero* player ,char salle[10][30]);

void piege3(Hero* player ,Case  salle[10][30]);

void tresor3(Hero* player ,Case salle[10][30]);


#endif



















