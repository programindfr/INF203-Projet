CC=gcc

NEWCOW=newcow.c cow.c cow_traitement.c cow_affichage.c chaine_operation.c printf_color.c
WILDCOW=wildcow.c cow.c cow_traitement.c cow_affichage.c chaine_operation.c printf_color.c
READING_COW=reading_cow.c cow.c cow_traitement.c cow_affichage.c chaine_operation.c printf_color.c cow_read.c
AUTOMATE=automate.c cow_affichage.c cow_read.c

all: newcow wildcow reading_cow automate

newcow: $(NEWCOW)
	$(CC) -o newcow $(NEWCOW)

wildcow: $(WILDCOW)
	$(CC) -o wildcow $(WILDCOW)

reading_cow: $(READING_COW)
	$(CC) -o reading_cow $(READING_COW)

automate: $(AUTOMATE)
	$(CC) -o automate $(AUTOMATE)