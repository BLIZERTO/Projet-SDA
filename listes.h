#pragma once
#include "liste.h"

const unsigned int MAX_LISTES = 10;

struct Listes {
	Liste tab_listes[MAX_LISTES + 1];
	unsigned int nb_listes;
};

void mots_apparents(Listes& listes);
void mots_pas_apparents(Listes& listes);
