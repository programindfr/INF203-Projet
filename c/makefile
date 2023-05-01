CC=gcc

all: newcow wildcow reading_cow

newcow: newcow.c
	$(CC) -o newcow newcow.c cow.c cow_traitement.c cow_affichage.c chaine_operation.c printf_color.c

wildcow: wildcow.c
	$(CC) -o wildcow wildcow.c cow.c cow_traitement.c cow_affichage.c chaine_operation.c printf_color.c

reading_cow: reading_cow.c cow.c cow_traitement.c cow_affichage.c chaine_operation.c printf_color.c cow_read.c
	$(CC) -o reading_cow reading_cow.c cow.c cow_traitement.c cow_affichage.c chaine_operation.c printf_color.c cow_read.c