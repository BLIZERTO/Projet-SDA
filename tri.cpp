#pragma warning (disable : 4996)
#include <iostream>
#include <string.h>
#include "liste.h"

using namespace std;

bool verification_doublon(Liste& liste, Mot& id) {
	unsigned int i;
	for (i = 0; i < liste.nb_mots; i++) {
		if (strcmp(liste.tab_mots[i], id) == 0)
			return true;
	}
	return false;
}


void lire_et_enregistrer(Mot& id, Liste& liste) {
	cin >> id;
	if (strcmp(id, "*") != 0) {
		if (verification_doublon(liste, id) == false) {
			strcpy(liste.tab_mots[liste.nb_mots++], id);
		}
	}
}


void tri_alphabetique(Liste& liste) {
	for (int i = 0; i < liste.nb_mots; i++) {
		for (int j = i + 1; j < liste.nb_mots; j++) {
			if (strcmp(liste.tab_mots[i], liste.tab_mots[j]) > 0) {
				Mot tmp;
				strcpy(tmp, liste.tab_mots[i]);
				strcpy(liste.tab_mots[i], liste.tab_mots[j]);
				strcpy(liste.tab_mots[j], tmp);
			}
		}
	}
}

void exo2() {
	Mot buffer;
	Liste liste;
	liste.nb_mots = 0;
	liste.nb_points = 0;
	while (strcmp(buffer, "*") != 0) {
		lire_et_enregistrer(buffer, liste);
	}
	tri_alphabetique(liste);
	for (int i = 0; i < liste.nb_mots; i++) {
		cout << liste.tab_mots[i] << endl;
	}
	cout << "*" << endl;
}