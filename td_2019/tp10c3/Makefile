CC = gcc             # le compilateur à utiliser
CFLAGS = -Wall  # les options du compilateur
LDFLAGS =       # les options pour l'éditeur de liens
SRC = tp10c3.c tabdyn.c   # les fichiers sources
PROG = tp10c3          # nom de l'exécutable
OBJS =  $(SRC:.c=.o) # les .o qui en découlent
.SUFFIXES: .c .o     # lien entre les suffixes

all: $(PROG)

# étapes de compilation et d'édition de liens
# $@ la cible  $^ toutes les dépendances	
$(PROG): $(OBJS)
	$(CC)  -o $@ $^ $(LDFLAGS)

tp10c3.o: tabdyn.h
tabdyn.o: tabdyn.h
# le lien entre .o et .c
# $< dernière dépendance	
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# pour faire propre
.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)
