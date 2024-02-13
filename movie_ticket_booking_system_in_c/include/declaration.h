#ifndef declaration_h
#define declaration_h

struct persondetails{
	char name[25];
    	char phone[15];
    	int seat[50];
    	int index_of_seat;
    	int cancel_seat[50];
    	int index_of_cancel_seat;
    	int id[50];
    	int cancel_id[50];
    	char *booked_movie[50];
	char *cancelled_movie[50];
	char *booked_time[50];
	char *cancelled_time[50];
};

void initialize_person();
int fun_movie_time();
void reservation(int *,int,int,int );
int choice();
void cancel(int *);
void ticket(int choice,int id2,int price, char time1[], char movie_name[], int screen_no);
int movie();
void details();
int print_available_seats();
char* seat_no_to_char(int);

#endif
