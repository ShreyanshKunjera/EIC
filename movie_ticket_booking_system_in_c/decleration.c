#include "decleration.h"
#include<stdio.h>
#include<stdlib.h>
// #include<string.h>
#include<stdbool.h>

int count=0;                        //To keep track of the last booking person
int id2=1000;			    //Starting of the ticket id, will increament after each booking

struct persondetails person[300];  // Creating 300 person objects of type persondetails

void initialize_person()	   // Initializing all objects
{
    for(int i=0;i<300;i++)
    {
        person[i].index_of_seat=0;     // to keep track of the last seat that the person booked
        person[i].index_of_cancel_seat=0; // to keep track of the last seat that the person cacelled
        for(int j=0;j<50;j++)
        {
            person[i].seat[j]=-1;       // array of seats to store the seat no booked by person
            person[i].cancel_seat[j]=-1; // array of cancel seats to store the seat no cancelled by person
            person[i].id[j]=-1;         // seat id(ticket id) corresponding to booked ticket
            person[i].cancel_id[j]=-1;  // seat id(ticket id) corresponding to cancelled ticket
        }
    }    
}

    
    
int choice1(void)        // Ask the user one of the 5 actions
{
        int choice;

    printf("Select Option:\n");
    printf("1.See available seats\n");
    printf("2.View records\n");
    printf("3.Booking the ticket\n");
    printf("4.Cancel the ticket\n");
    printf("5.Exit\n");
        scanf("%d",&choice);
        printf("\n");
        return choice;
}


int print_available_seats(int array[],int slection,int time_of_movie)  // to print available seats(Action 1)
{
        int orig_seat_no=0; // To keep track of the starting index of seat array (to determine in which screen and time it is)
        char temp='A';      // taking char to print it as a seat no
        int seat_no=0;      // variable to traverse through the array of seats to print available seats
    if(slection==1 && time_of_movie==1)
    {
        seat_no=1;  // if it is 1st screen and 1st time then start with 1st index in array of seats
    }
    else if(slection==1 && time_of_movie==2)
    {
        seat_no=51;
    }
    else if(slection==1 && time_of_movie==3)
    {
        seat_no=101;
    }
    else if(slection==2 && time_of_movie==1)
    {
        seat_no=151;
    }
    else if(slection==2 && time_of_movie==2)
    {
        seat_no=201;
    }
    else if(slection==2 && time_of_movie==3)
    {
        seat_no=251;
    }

    orig_seat_no=seat_no; // setting the orig_seat to the right seat_no after determining it from above conditions
    for (int i=1;i<=10;i++) // printing seats in a tabular form
    {
        for(int j=1;j<=5;j++)
        {
            if(array[seat_no]!=0)
            {
                printf("   ");
            }
            else
            {
                printf("%c%d ",temp,j);
            }
            seat_no++;
        }
        printf("\n");
        temp++;  // increamenting temp to get next character aftr printing one row
    }
    printf("\n");
    return orig_seat_no;  // returning orig_seat_no to further use it in reservation (booking) function

}

void details() // to print the records of booking and cancelling of ticket
{       int count_of_records=0;
        for (int i=0;i<count;i++) // traverse through every person that have till now booked ticket (till count)
        {
            int j=0;
            while(person[i].seat[j]!=-1) // print every elements which are not -1 since they are empty
            {
                if(person[i].seat[j]!=-2) // entry with -2 in it are cancelled one so no need to print it
                {
                    char* arr=seat_no_to_char(person[i].seat[j]);
                    printf("seat no: %s is booked by %s with booking id %d of %s movie with time %s\n",arr,person[i].name,person[i].id[j],person[i].booked_movie[j],person[i].booked_time[j]);
		    count_of_records++;
                }
                j++;
            }
            j=0;
            while(person[i].cancel_seat[j]!=-1)
            {
                char* arr=seat_no_to_char(person[i].cancel_seat[j]);
                printf("seat no: %s is cancelled by %s with booking id %d of %s movie with time %s\n",arr,person[i].name,person[i].cancel_id[j],person[i].cancelled_movie[j],person[i].cancelled_time[j]);
                j++;
		count_of_records++;
            }

        }
	if(count_of_records==0)
	{
		printf("Till now, there is no booking or cancelling of any of the shows.\n");
	}
        printf("\n");

}

int movie() // ask the user for the movie
{
        int i;
//      system("cls");

        printf("Select one of the following movie:\n");
    printf("1.Spiderman-Across the spider verse\n");
    printf("2.Superman: Man of steel\n");
        scanf("%d",&i);
//      system("cls");
    printf("\n");
        return i;
}

int fun_movie_time() // asking the user for the time of the show
{
    int movie_time=0;
    printf("Choose one of the following time:\n");
    printf("1. 12:00 pm\n");
    printf("2. 03:00 pm\n");
    printf("3. 06:00 pm\n");
    scanf("%d",&movie_time);
    printf("\n");
    return movie_time;
}

void reservation(int array[],int price,int slection, int time1) // Function for booking the ticket
{
        int confirmation=-1; // for asking the user for confirmation
        int amount=0; // total amount of booked ticket(s)
        int index_of_seat=-1; // to keep track of last element of list_of_seats array
        int list_of_seats[51]; //To store the seat no of booked tickets
        int index=0; // to keep track of last element of list_of_seats array
        char input_of_seat[3]; // to store the input given by user of seat no in form of A1,A2,...
        int num_of_seats=0;  // to store the number of seats the user wants to book
        char temp='A';

        int orig_seat_no=print_available_seats(array,slection,time1); // to get value of orig_seat_no from available_seat function

        printf("Please enter your name: ");
	    scanf("%s",person[count].name);
        printf("Please enter your phone number: ");
        scanf("%s",person[count].phone);


        printf("How many seats you want to book?\n");
        scanf("%d",&num_of_seats);
        printf("Enter the seat number exactly as shown in available seats one by one\n");
        index=0;
        for(int i=0;i<num_of_seats;i++)
        {
            scanf("%s",input_of_seat);
            while(!((input_of_seat[0]>='A' && input_of_seat[0]<='J') && (input_of_seat[1]-'0'>=1 && input_of_seat[1]-'0'<=5)))
            {
                printf("Please give valid seat no as shown in available seat (From A1 to A5, B1 to B5, ... till J1 to J5)\n");
                scanf("%s",input_of_seat);
            }
            index_of_seat= (input_of_seat[0]-'A')*5 + input_of_seat[1]-'0';

            while(array[orig_seat_no+index_of_seat-1]==1)
            {
                printf("Sorry, this ticket is already booked! Please choose another seat.\n");
                scanf("%s",input_of_seat);
                index_of_seat= (input_of_seat[0]-'A')*5 + input_of_seat[1]-'0';
            }

            list_of_seats[index++]=index_of_seat;
            // array[orig_seat_no+index_of_seat-1]=1;  // In main array, marking the booked seat as 1 & orig_seat_nois for making changes in correct screen
        }
        
        
        amount=num_of_seats*(slection==1?400:600);
        printf("\n");
        printf("This is the total amount : %d\n",amount);
        printf("You want to confirm the ticket? \n1.Yes\n2.No\n");
        scanf("%d",&confirmation);
        printf("\n");
        if(confirmation==1)
        {
            for(int i=person[count].index_of_seat;i<index;i++)
            {
                array[orig_seat_no+list_of_seats[i]-1]=1;  // In main array, marking the booked seat as 1 & orig_seat_nois for making changes in correct screen
                person[count].seat[i]=list_of_seats[i];
                person[count].index_of_seat++;
            }
            printf("Your ticket is provided below:\n");
            for(int i=0;i<num_of_seats;i++)
            {
                person[count].id[i]=id2;
                if(slection==1)
                {
                    person[count].booked_movie[i]="Spiderman-Across the spider verse";
                    if(time1==1)
                    {
                        person[count].booked_time[i]="12:00 PM";
                        ticket(list_of_seats[i],id2,400,"12:00 pm","Spiderman-Across the spider verse",1);
                    }
                    else if(time1==2)
                    {
                        person[count].booked_time[i]="03:00 PM";
                        ticket(list_of_seats[i],id2,400,"03:00 pm","Spiderman-Across the spider verse",1);
                    }
                    else
                    {
                        person[count].booked_time[i]="06:00 PM";
                        ticket(list_of_seats[i],id2,400,"06:00 pm","Spiderman-Across the spider verse",1);
                    }
                }
                else if(slection==2)
                {
                    person[count].booked_movie[i]="Superman: Man of steel";
                    if(time1==1)
                    {
                        person[count].booked_time[i]="12:00 PM";
                        ticket(list_of_seats[i],id2,600,"12:00 pm","Superman: Man of steel",2);
                    }
                    else if(time1==2)
                    {
                        person[count].booked_time[i]="03:00 PM";
                        ticket(list_of_seats[i],id2,600,"03:00 pm","Superman: Man of steel",2);
                    }
                    else
                    {
                        person[count].booked_time[i]="06:00 PM";
                        ticket(list_of_seats[i],id2,600,"06:00 pm","Superman: Man of steel",2);   
                    }
                }
                id2++;
            }
        }
        else
        {
            printf("Your tickets are cancelled\n\n");
            
        }
        count++;
        printf("\n");
}

void ticket(int choice,int id2,int price, char time1[], char movie_name[],int screen_no)
{
    char * arr = seat_no_to_char(choice);

    printf("====================================================================\n");
    printf("Galaxy Cinema\n");
    printf("====================================================================\n");
    printf("Ticket No: %d\t\t\t\t\t\tMovie Ticket\n", id2);
    printf("====================================================================\n");
    printf("Screen: %d\t\t\t   %s\n",screen_no, movie_name);
    printf("Seat: %s\n", arr);
    printf("Time: %s\n", time1);
    printf("Date: 09/02/2024\t\t\t\t\t  Price: %d\n",price);
    printf("====================================================================\n");
    printf("\n");
}


void cancel(int *array)
{
      int seat_no_of_cancel,stop;
      bool flag=false;
          printf("Please enter ID number of ticket that you want to cancel: ");

        while(!flag)
        {
            scanf("%d",&seat_no_of_cancel);
            for (int i=0;i<count;i++)
            {
                int j=0;
                while(person[i].id[j]!=-1)
                {
                    if(seat_no_of_cancel==person[i].id[j])
                    {
                     flag=true;
            //       system("cls");
                     char* arr=seat_no_to_char(person[i].seat[j]);
                     printf("%s, your seat %s of %s movie with time %s is cancelled successfully\n",person[i].name,arr,person[i].booked_movie[j],person[i].booked_time[j]);
                     array[person[i].seat[j]]=0;
                     person[i].cancel_id[person[i].index_of_cancel_seat]=person[i].id[j];
                     person[i].cancel_seat[person[i].index_of_cancel_seat]=person[i].seat[j];
                     person[i].cancelled_movie[person[i].index_of_cancel_seat]=person[i].booked_movie[j];
                     person[i].cancelled_time[person[i].index_of_cancel_seat]=person[i].booked_time[j];
                     person[i].seat[j]=-2;
                     person[i].index_of_cancel_seat++;
                     i=300;
                     break;
                    }
                    j++;
                }

            }
          if(!flag)
          {
              printf("Ticket ID number is incorrect please enter right ticket no to cancel ticket: \n");
          }
        }
          printf("\n");

}

char* seat_no_to_char(int choice)
{
    char* arr = malloc(sizeof(char)*2);
    char first_index_of_seat=' ';
    int second_index_of_seat=0;
    if(choice%5==0)
    {
        first_index_of_seat= 'A'+((choice/5)-1);
        second_index_of_seat=5;
    }
    else{
        first_index_of_seat= 'A'+(choice/5);
        second_index_of_seat=choice%5;
    }
    char second_number = '0'+second_index_of_seat;
    arr[0] = first_index_of_seat;
    arr[1] =second_number;
    return arr;
}
