#include "pile.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char *  espacer(int i) {
	char * espace= malloc(i*sizeof(char));
	char * esc = " ";
	for (int j=0; j<i;j++) strncat(espace,esc,1);
//	printf("%s", espace);
       	return espace;	
}

char * indenter(FILE * file, char * contenu,struct Pile ** pile) { 
	char* ch; ch =malloc(1);
	char * ouvrante="{", * fermante="}", * fin=";", * inclus=">", *ligne="\n";
	while ((*ch=fgetc(file)) !=EOF) {
		
	 	if (strcmp(ch,inclus)==0|| strcmp(ch,fin)==0){
			strncat(contenu,ch,1);
			strncat(contenu,ligne,1);
			//printf("%s",ch);espacer((*pile)->nombre);
			strncat(contenu,espacer((*pile)->nombre),(*pile)->nombre);
		}else {
			if (strcmp(ch,ouvrante)==0) { 
				empiler(pile);
				strncat(contenu,ch,1);
				strncat(contenu,ligne,1);
				strncat(contenu,espacer((*pile)->nombre),(*pile)->nombre);
				//printf("%s",ch);espacer((*pile)->nombre);
	
			} else { 
				if (strcmp(ch,fermante)==0){ 
					depiler(pile);
					strncat(contenu,ligne,1);
					strncat(contenu,espacer((*pile)->nombre),(*pile)->nombre);
					strncat(contenu,ch,1);
				//	printf("%s",ch);espacer((*pile)->nombre);
				}else strncat(contenu,ch,1);
			}
		}
	}
}	


void ecrire(FILE * file, char * contenu) {
	fputs(contenu,file);
}
