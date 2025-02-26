#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonction.h"

int main ( int agrc ,const char *agrv[])
{
	int modeFacile = 0 ;
	int modeNormal = 0 ;
	int modeDifficile = 0;
	int choix = 0;
	
	
	Hero player;
	infoHeros(&player);

	printf("\n\n\t\t\t\t\t\t\tChoisissez le Mode de difficulté\n\n");
        printf("1.Mode facile\n2.Mode normal\n3.Mode difficile\n\n");
	choix=lireLong();
	if(choix == 1 )
	{
		modeFacile = 1;
		
	}
	if(choix == 2 )
	{
		modeNormal = 1;
	}
	if(choix == 3)
	{
		modeDifficile = 1;
	}



	

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
	Case labNormal[10][30];

	for( int i = 0 ; i < 10 ; i++)
	{
		for( int j = 0 ; j < 30 ; j ++)
		{
			labNormal[i][j].symbole = labyrinthe[i][j];
			labNormal[i][j].visible = 0 ;
		}
	}

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

		printf("\n\n\t\t\t\tBienvenue dans le jeu du labyrinthe : %s !\n\n",player.gamertag);

		

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


if(modeFacile)
{


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
		printf("MODE: FACILE\n\n\n");
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
	
}




else if(modeNormal)
{


	while(!player.win && player.nombredeVie >= 1 )
	{       

		curseurH3(&player,labNormal);
	
		if(player.y == 8 &&  player.x == 22 )
		{

			tresor3(&player,labNormal);
			player.win= 1 ;
		}
		else if (player.y == 2 && player.x ==8)
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 3  && player.x == 8 )
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 4 && player.x == 1 )
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 6 && player.x == 10 )
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 8 && player.x == 13 )
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 7 && player.x == 24 )
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 2 && player.x == 13 )
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 8 && player.x == 26 )
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 1  && player.x == 27 )
		{
			piege3(&player,labNormal);
		}
		else if (player.y == 2 && player.x == 25 )
		{
			piege3(&player,labNormal);
		}

        	printf("\n\t\t\t\t       Vous entrez dans le Labyrinthe...\n");
		printf("MODE: NORMAL\n\n\n");
        	printf("\n\t\t\t\t    Parcourez le à la recherche du trésor\n");
		printf("\t\t Mais attention où vous mettez les pieds,vous pourriez tomber sur un piège...\n\n\n");
	
		   afficheHaze3(&player,labNormal);

		


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
	



		if(mv == 'z' && labNormal[player.y-1][player.x].symbole == ' ')//haut
		{
			rmH3(&player,labNormal);
			player.y--;
		}
		else if(mv == 'q' && labNormal[player.y][player.x-1].symbole == ' ')///gauche
		{
			rmH3(&player,labNormal);
			player.x--;
		}

		else if(mv == 's' && labNormal[player.y+1][player.x].symbole == ' ')//bas
		{       
			rmH3(&player,labNormal);
			player.y++;
		}
		else if(mv == 'd' && labNormal[player.y][player.x+1].symbole == ' ')//droite
		{
			rmH3(&player,labNormal);
			player.x++;
		}

		system("clear");

	}

	printf("\n\n\n\n");


        afficheNormal(&player,labNormal);
	
}


if(modeDifficile)
{


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
		printf("MODE: DIFFICILE\n\n\n");
        	printf("\n\t\t\t\t    Parcourez le à la recherche du trésor\n");
		printf("\t\t Mais attention où vous mettez les pieds,vous pourriez tomber sur un piège...\n\n\n");
	
		   afficheHaze(&player,labyrinthe);

		


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
	
}
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



	





































