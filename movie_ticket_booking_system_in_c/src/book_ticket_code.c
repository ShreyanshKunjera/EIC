#include<stdio.h>
#include<stdlib.h>
#include"declaration.h" 


int main()
{
	int time_of_movie=0;
	int **seat,action,price,selection;
	seat=(int **)malloc(2*sizeof(int *));
	for (int i=0;i<2;i++)
	{
		*(seat+i)=(int *)malloc(151*sizeof(int ));
	}
	
	initialize_person();
	
	int x=0;
	while(x!=1)
	{
		action=choice();
		switch(action)
		{
			case 1:
				selection=movie();
				time_of_movie=fun_movie_time();
				print_available_seats(seat[selection-1],selection,time_of_movie);
				break;
			case 2:
				details();
				break;	
			case 3:	
				selection=movie();
				time_of_movie=fun_movie_time();
				reservation(seat[selection-1],price,selection,time_of_movie);	
				break;
			case 4:
				cancel(seat[selection-1]);	
				break;
			case 5:
				x=1;
				break;
			default: 
				printf("Action not available\n");
				break;	
		}
	}
}




