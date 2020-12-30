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

void ecrire(Liste& liste, Mot id) {
	if (liste.nb_mots >= liste.capa) {
		unsigned int newTaille = (liste.capa+1) * liste.pas_extension;
		Mot* newT = new Mot[newTaille];
		unsigned int i;
		for (i = 0; i < liste.nb_mots; ++i) {
			strcpy(newT[i], liste.tab_mots[i]);
		}
		delete[] liste.tab_mots;
		liste.tab_mots = newT;
		liste.capa = newTaille;
	}
	strcpy(liste.tab_mots[liste.nb_mots], id);
	liste.nb_mots++;
}


void lire_liste(Mot& id, Liste& liste) {
	cin >> id;
	if (strcmp(id, "*") != 0) {
		if (verification_doublon(liste, id) == false) {
			ecrire(liste, id);
		}
	}
}


void tri_alphabetique(Liste& liste) {
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		for (unsigned int j = i + 1; j < liste.nb_mots; j++) {
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
	initialiser(liste);
	while (strcmp(buffer, "*") != 0) {
		lire_liste(buffer, liste);
	}
	tri_alphabetique(liste);
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		cout << liste.tab_mots[i] << endl;
	}
	cout << "*" << endl;
}