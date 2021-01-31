#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"
#include "traiter.h"

long taille;
char * contenuIndenter;

int main(int nbreArgs, char** args) {

	FILE * fichierAindenter;
	FILE * fichierIndenter=NULL;

	// affecter les pointeurs de fichier selon les cas  
	
	if (nbreArgs==2)fichierAindenter=fopen(args[1],"w+");
	else{ 
		if (nbreArgs==3) { 
			fichierAindenter=fopen(args[1],"r");
			fichierIndenter=fopen(args[2],"w");
		} else {
			puts("Nombre d'arguments incorrectes");
			exit(EXIT_FAILURE);	
		}
       	}

	// reservation de la taille du tableau recevant le contenu indenté du fichier
	fseek(fichierAindenter,0,SEEK_END);
	taille=ftell(fichierAindenter);
	fseek(fichierAindenter,0,SEEK_SET);
	contenuIndenter=malloc(2*taille);

	// creation du pinteur de la pile
	struct Pile * tete;
	tete=malloc(sizeof(struct Pile));
	initialiser(tete);

	// Application de la fonction indenter pour indenter le fichier
	indenter(fichierAindenter,contenuIndenter,&tete);
	printf("%p",fichierIndenter);
	// 
	if (fichierIndenter!=NULL) ecrire(fichierIndenter, contenuIndenter);
       	else { ecrire(fichierAindenter, contenuIndenter);puts("a la fin");}
} 

