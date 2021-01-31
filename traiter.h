#include <stddef.h>

#ifndef TRAITER
#define TRAITER
char * espacer (int i);
char * indenter(FILE * file, char * contenu, struct Pile ** pile);
void ecrire(FILE * file, char * contenu);
#endif
