#include "pile.h"
#include <stdlib.h>
#define NOMBREDEBLANC 4

void initialiser ( struct Pile * pile) { 
	pile->nombre= 0;
	pile->suivant= NULL;
};

void empiler( struct Pile ** pile){
	struct Pile * nouveau;
        nouveau= malloc(sizeof(struct Pile));
	if (pile==NULL || nouveau==NULL) exit(EXIT_FAILURE);
 	nouveau->nombre=(*pile)->nombre+NOMBREDEBLANC;
	nouveau->suivant=*pile;
	*pile=nouveau;	
};

int depiler(struct Pile ** pile) {
	if (pile==NULL) exit(EXIT_FAILURE);
	int nombreRetirer=(*pile)->nombre;
	struct Pile * adepiler = *pile;
	*pile=(*pile)->suivant;
	free(adepiler);
	return nombreRetirer;
}
	
