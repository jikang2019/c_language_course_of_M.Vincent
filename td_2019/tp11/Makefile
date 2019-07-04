CC = gcc             # le compilateur à utiliser
CFLAGS = -Wall  # les options du compilateur
LDFLAGS =  -lm    # les options pour l'éditeur de liens
SRC = calc.c pile.c cal.c  # les fichiers sources
PROG = calc          # nom de l'exécutable
OBJS =  $(SRC:.c=.o) # les .o qui en découlent
.SUFFIXES: .c .o     # lien entre les suffixes

all: $(PROG)

# étapes de compilation et d'édition de liens
# $@ la cible  $^ toutes les dépendances	
$(PROG): $(OBJS)
	$(CC)  -o $@ $^ $(LDFLAGS)

calac.o: pile.h cal.h
pile.o: pile.h
cal.o: pile.h cal.h
# le lien entre .o et .c
# $< dernière dépendance	
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# pour faire propre
.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)
