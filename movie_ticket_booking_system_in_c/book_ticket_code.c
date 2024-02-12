#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"decleration.h" 
// #include<string.h>

int main()
{
    int time_of_movie=0;
	int **seat,choice,price,slection,i;
	seat=(int **)malloc(2*sizeof(int *));
	for (i=0;i<2;i++)
		*(seat+i)=(int *)malloc(151*sizeof(int ));
	
	initialize_person();
	
	int x;
	while(x!=5)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
			    slection=movie();
				time_of_movie=fun_movie_time();
				print_available_seats(seat[slection-1],slection,time_of_movie);
				break;
			case 2:
				details();
				break;	
			case 3:	
				slection=movie();
				time_of_movie=fun_movie_time();
				reservation(seat[slection-1],price,slection,time_of_movie);	
				break;
			case 4:
				cancel(seat[slection-1]);	
				break;
			case 5:
				x=5;
				break;
			default: 
				printf("Choice not available\n");
				break;	
		}
	}
}




