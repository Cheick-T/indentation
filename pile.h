#include <stddef.h>

#ifndef PILEH
#define PILEH
struct Pile { 
	int nombre;
	struct Pile * suivant;	

};
void initialiser( struct Pile * pile);
void empiler ( struct Pile ** pile);
int depiler ( struct Pile ** pile);
#endif 
