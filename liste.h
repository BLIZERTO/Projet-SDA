#pragma once

const unsigned int MAX_LETTRES = 15;
const unsigned int MAX_MOTS = 50;

typedef char Mot[MAX_LETTRES + 1];

struct Liste {
	Mot tab_mots[MAX_MOTS + 1];
	unsigned int nb_mots;
	unsigned int nb_points;
};

void lire_et_compter(Mot& id, Liste& liste);
void lire_et_enregistrer(Mot& id, Liste& liste);
void tri_alphabetique(Liste& liste);
void comptage_de_points(int nb_lettres_mot, Liste& liste);
bool verification_doublon(Liste& liste, Mot& id);