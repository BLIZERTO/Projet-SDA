#pragma once
#include "liste.h"

struct Listes {
	Liste* tab_listes;
	unsigned int nb_listes;
	unsigned int capalistes;
	unsigned int PE_listes;
};

void mots_apparents(Listes& listes);
void mots_pas_apparents(Listes& listes);
