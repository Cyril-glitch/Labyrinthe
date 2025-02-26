#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonction.h"



int lireUser(char *chaine , int taille)
{
	char *alaligne =NULL;

	if(fgets(chaine,taille,stdin) != NULL)
	{
		alaligne=strchr(chaine,'\n');

		if (alaligne != NULL)
		{
			*alaligne = '\0';

		}
		else
		{
			printf("erreur\n");
			viderBuffer();
		}
		return 1;
	}
	else
	{
		printf("erreur\n");
		viderBuffer();
		return 0;
	}

}

int lireUserC()
{
	int c = fgetc(stdin);
	viderBuffer();
	return c;
}



void viderBuffer()
{
	int c = 0;

	while( c != '\0' && c != EOF)
	{
		c = getchar();
	}
}



void afficheLab(Hero* player,char salle[10][30])
{
	
	for(int i = 0 ; i < 10 ; i++)
	{
		printf("\t\t\t\t\t");
		for(int j = 0 ; j <  30 ; j++)
		{
			printf("%c",salle[i][j]);
		}

		printf("\n");
	}
}
void afficheHaze(Hero* player,char salle[10][30])
{//on veut que la fonction affiche seulement les cases aux alentours de H

	
	for(int i = 0 ; i <= player->y+2 ; i++)
	{
		printf("\t\t\t\t\t");
		for(int j = 0 ; j <= player->x+2 ; j++)
		{
			if( i >= player->y-2 && j >= player->x -2)
			{
			  printf("%c",salle[i][j]);
			}
		}

		printf("\n");
	}
}

void afficheHaze3(Hero* player,Case salle[10][30])
{//on veut que la fonction rende visible les case du labyrinthe uniquement une fois que le cuseur H et passer aux alentours 

	
	for(int i = 0 ; i <= player->y+2 ; i++)
	{
		
		for(int j = 0 ; j <= player->x+2 ; j++)
		{
			if( i >= player->y-2 && j >= player->x -2)
			{
			     salle[i][j].visible = 1; 
			}
		}

	}
	for(int i = 0 ; i < 10 ; i++)
	{
		printf("\t\t\t\t\t");
		for(int j = 0 ; j <  30 ; j++)
		{
			if(salle[i][j].visible)
			{
			printf("%c",salle[i][j].symbole);
			}
		}

		printf("\n");
	}

}


void afficheLab3(Hero * player ,Case salle[10][30])
{
	for(int i = 0 ; i < 10 ; i++)
	{
		printf("\t\t\t\t\t");
		for(int j = 0 ; j <  30 ; j++)
		{
			printf("%c",salle[i][j].symbole);
		}

		printf("\n");
	}
}




int  infoHeros(Hero* player)
{
	if(player != NULL)
	{
		printf("Entrez votre Prénom :\n");
		lireUser(player->gamertag,30);

		printf("Entrez votre age :\n");
		player->age = lireLong();
	}
	else
	{
		printf("erreur\n");
		return 0;
	}
	return 0;

}

long lireLong()
{
	char nombreaLire[100]={0}; 

	if(lireUser(nombreaLire,sizeof(nombreaLire)))
	{
		return strtol(nombreaLire,NULL,10);
	}
	else
	{
		printf("erreur\n");
		return 0;
	}

}

void curseurH(Hero* player , char salle[10][30])
{
	int i = 0 , j =0 ;

	i = player->y;
	j = player->x;

	if ( i != 0 && j != 0 )
	{      
		salle[i][j]='H';
	}
}

void curseurH3(Hero* player , Case salle[10][30])
{
	int i = 0 , j =0 ;

	i = player->y;
	j = player->x;

	if ( i != 0 && j != 0 )
	{      
		salle[i][j].symbole='H';
	}
}


void piege(Hero* player , char salle[10][30])
{
	int i = 0 , j =0 ;

	i = player->y;
	j = player->x;

	if ( i != 0 && j != 0 )
	{      
		salle[i][j]='X';
	}
	player->nombredeVie--;
	player->y = 1 ;
	player->x = 1 ;
}
void tresor(Hero* player ,char salle[10][30])
{
	int i = 0 , j =0 ;

	i = player->y;
	j = player->x;

	if ( i != 0 && j != 0 )
	{      
		salle[i][j]='$';
	}

	player->win = 1;

}


void piege3(Hero* player ,Case salle[10][30])
{
	int i = 0 , j =0 ;

	i = player->y;
	j = player->x;

	if ( i != 0 && j != 0 )
	{      
		salle[i][j].symbole='X';
	}
	player->nombredeVie--;
	player->y = 1 ;
	player->x = 1 ;
}


void tresor3(Hero* player ,Case salle[10][30])
{
	int i = 0 , j =0 ;

	i = player->y;
	j = player->x;

	if ( i != 0 && j != 0 )
	{      
		salle[i][j].symbole='$';
	}

	player->win = 1;

}

int move(Hero* player,char salle[10][30])
{

	char mv = 0 ;


	if(player != NULL)
	{
			mv = lireUserC(); 

			if(mv == 'z' && salle[player->y-1][player->x] == ' ')//haut
			{
				rmH(player,salle);
				player->y--;
			}
			else if(mv == 'q' && salle[player->y][player->x-1] == ' ')///gauche
			{
                                rmH(player,salle);
				player->x--;
			}
			
			else if(mv == 's' && salle[player->y+1][player->x] == ' ')//bas
			{       
				rmH(player,salle);
				player->y++;
			}
			else if(mv == 'd' && salle[player->y][player->x+1] == ' ')//droite
			{
				rmH(player,salle);
				player->x++;
			}

	}
	else
	{
		printf("error player not found ");
		return 0;
	}

	return 0;
	
	
}


void rmH(Hero* player , char salle[10][30])
{
	
	int i = 0 , j =0 ;

	i = player->y;
	j = player->x;

	if ( i != 0 && j != 0 )
	{      
		salle[i][j]=' ' ;
	}

}

void rmH3(Hero* player , Case salle[10][30])
{
	
	int i = 0 , j =0 ;

	i = player->y;
	j = player->x;

	if ( i != 0 && j != 0 )
	{      
		salle[i][j].symbole=' ' ;
	}

}
