#pragma once
#include "liste.h"

const unsigned int MAX_LISTES = 10;

struct Listes {
	Liste tab_listes[MAX_LISTES + 1];
	unsigned int nb_listes;
};

void comparaison_doublons(Listes& listes);
void lire_et_comparer(Mot& id, Listes& listes);