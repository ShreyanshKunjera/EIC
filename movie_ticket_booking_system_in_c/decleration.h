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
        char *movie[50];
};

void initialize_person();
int fun_movie_time(void);
void reservation(int *,int,int,int );
int choice1(void);
void cancel(int *);
void ticket(int choice,int id2,int price, char time1[], char movie_name[], int screen_no);
int movie(void);
void details(void);
int print_available_seats();

#endif
