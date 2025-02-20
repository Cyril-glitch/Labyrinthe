#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonction.h"

int main ( int agrc ,const char *agrv[])
{
	Hero player;
	infoHeros(&player);



	printf("\n\n\t\t\t\tBienvenue dans le jeu du labyrinthe : %s !\n\n",player.gamertag);


do
{

	int enter = 0 ;
	char mv = 0 ;

	
	player.y = 4;
	player.x = 14;

	player.nombredeVie = 5 ;
	player.win= 0 ;
	
	char hall[10][30]={"******************************",
		           "*                            *",
		           "*                            *",
		           "*                            *",
		           "*                             ",
		           "*                             ",
		           "*                            *",
		           "*                            *",
		           "*                            *",
		           "******************************",};


	char labyrinthe[10][30]={"******************************",
	                      	 "                     *    *  *",
		                 "**** *** **** *****  **** ** *",
		                 "**** *** ****        **** ** *",
		                 "*             *********** ** *",
		                 "* ** ** ** ** *********** ** *",
		                 "* ** ** ** **                *",
		                 "* ** ** ***** ****** **  *****",
		                 "*    **              *     ***",
		                 "******************************",};
/*
//emplacements des pieges et du trésor :

	                         "******************************",
				 "                     *    *X *",
	                         "**** ***X****X*****  **** ** *",
	                         "**** ***X****        **** ** *",
	                         "*X            *********** ** *",
	                         "* ** ** ** ** *********** ** *",
	                         "* ** ** **X**                *",
	                         "* ** ** ***** ****** ** X*****",
	                         "*    **      X       *$   X***",
	                         "******************************"

	   
*/



	while(!enter)

	{
		if(player.x ==29 && (player.y == 4 || player.y == 5))
		{

			enter = 1;
		}

           	printf("\n\t\t\t\t Vous voici dans l'antichambre du Labyrinthe\n\n");


		curseurH(&player,hall);



		afficheLab(&player,hall);

		printf("\n\t\tAppuyez sur z,q,s,d puis <ENTER> pour vous déplacer jusqu'a l'entrée du labyrinthe\n");
		printf("\t\t\t\t  Astuce : Vous pouvez combiner des directions");
		printf("\n\t\t\t\t\t    position y°: %d / x°: %d \n",player.y,player.x);
		printf("\t\t\t\t\t\t");
		printf("   ");

		for(int j = 0 ; j < player.nombredeVie ; j++)
		{
			   printf("❤️ ");
		}
		
		printf("\n\n\n");
		printf("\t\t\t\t\t\t");
		

		mv = lireUserC(); 

		if(mv == 'z' && hall[player.y-1][player.x] == ' ')//haut
		{
			rmH(&player,hall);
			player.y--;
		}
		else if(mv == 'q' && hall[player.y][player.x-1] == ' ')///gauche
		{
			rmH(&player,hall);
			player.x--;
		}

		else if(mv == 's' && hall[player.y+1][player.x] == ' ')//bas
		{       
			rmH(&player,hall);
			player.y++;
		}
		else if(mv == 'd' && hall[player.y][player.x+1] == ' ')//droite
		{
			rmH(&player,hall);
			player.x++;
		}

		system("clear");

	}


	//deuxieme partie du jeu
	

	player.y = 1;
	player.x = 1;






	while(!player.win && player.nombredeVie >= 1 )
	{       

		curseurH(&player,labyrinthe);
	
		if(player.y == 8 &&  player.x == 22 )
		{

			tresor(&player,labyrinthe);
			player.win= 1 ;
		}
		else if (player.y == 2 && player.x ==8)
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 3  && player.x == 8 )
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 4 && player.x == 1 )
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 6 && player.x == 10 )
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 8 && player.x == 13 )
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 7 && player.x == 24 )
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 2 && player.x == 13 )
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 8 && player.x == 26 )
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 1  && player.x == 27 )
		{
			piege(&player,labyrinthe);
		}
		else if (player.y == 2 && player.x == 25 )
		{
			piege(&player,labyrinthe);
		}
        	printf("\n\t\t\t\t       Vous entrez dans le Labyrinthe...\n");
        	printf("\n\t\t\t\t    Parcourez le à la recherche du trésor\n");
		printf("\t\t Mais attention où vous mettez les pieds,vous pourriez tomber sur un piège...\n\n\n");


		afficheLab(&player,labyrinthe);

		printf("\n\t\tAppuyez sur z,q,s,d puis <ENTER> pour vous déplacer jusqu'a l'entrée du labyrinthe\n");
		printf("\t\t\t\t  Astuce : Vous pouvez combiner des directions");
		printf("\n\t\t\t\t\t    position y°: %d / x°: %d \n",player.y,player.x);
                printf("\t\t\t\t\t\t");
		printf("   ");

		for(int j = 0 ; j < player.nombredeVie ; j++)
		{
			   printf("❤️ ");
		}
		
		printf("\n\n\n");
		printf("\t\t\t\t\t\t");

				
		mv = lireUserC(); 
	

		if(mv == 'z' && labyrinthe[player.y-1][player.x] == ' ')//haut
		{
			rmH(&player,labyrinthe);
			player.y--;
		}
		else if(mv == 'q' && labyrinthe[player.y][player.x-1] == ' ')///gauche
		{
			rmH(&player,labyrinthe);
			player.x--;
		}

		else if(mv == 's' && labyrinthe[player.y+1][player.x] == ' ')//bas
		{       
			rmH(&player,labyrinthe);
			player.y++;
		}
		else if(mv == 'd' && labyrinthe[player.y][player.x+1] == ' ')//droite
		{
			rmH(&player,labyrinthe);
			player.x++;
		}

		system("clear");

	}

	printf("\n\n\n\n");


        afficheLab(&player,labyrinthe);
	

        if(player.nombredeVie < 1)
        {
	   char c = 0 ;	   
	   printf("\n\t\t\t\t\t\t GAME OVER...\n");
	   printf("\n\t\t\t\t\t Voulez-vous réessayer ? (y/n)\n");
	   	  do
		  {

		   c = lireUserC();
		   if( c == 'y')
		   {
			   system("clear");
		   }
		   else if(c == 'n')
		   {
			   return 0;

		   }
	   }while(c == 'y' || c == 'n');

        }

        else
	{
	  printf("\n\n\t\t\t\t      BIEN JOUE VOUS AVEZ TROUVE LE TRESOR !\n\n\n");
	}


	
}while(!player.win);
        
	
return 0;


}	



	





































