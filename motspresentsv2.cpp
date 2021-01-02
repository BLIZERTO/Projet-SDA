#pragma warning (disable : 4996)
#include <iostream>
#include <string.h>
#include "lecture.h"
#include "canonique.h"
#include "dynam.h"

using namespace std;

void mots_apparentsv2(Listes& listes) {
	for (unsigned int i = 0; i < listes.nb_listes; i++) {
		for (unsigned int j = i + 1; j < listes.nb_listes; j++) {
			for (unsigned int k = 0; k < listes.tab_listes[i].nb_mots; k++) {
				for (unsigned int m = 0; m < listes.tab_listes[j].nb_mots; m++) {
					if (strcmp(listes.tab_listes[i].tab_mots[k], listes.tab_listes[j].tab_mots[m]) == 0) {
						ecrire(listes.tab_listes[i], listes.tab_listes[j].tab_mots[m]);
						break;
					}
				}
			}
		}
	}
}

void exo5() {
	Mot buffer;
	strcpy(buffer, "NULL");
	Listes listes;
	initialiser_listes(listes);
	initialiser(listes.tab_listes[0]);
	for (unsigned int k = 0; k < listes.nb_listes+1; k++) {
		while (strcmp(buffer, "*") != 0) {
			lire_listes(buffer, listes, k);
			if (listes.tab_listes[listes.nb_listes].nb_mots == 0 && strcmp(buffer, "*") == 0) {
				break;
			}
		}
		strcpy(buffer, "NULL");
	}
	for (unsigned int j = 0; j < listes.nb_listes; j++) {
		tri_alphabetique(listes.tab_listes[j]);
	}
	mots_apparentsv2(listes);
	for (unsigned int z = 0; z < listes.tab_listes[listes.nb_listes].nb_mots; z++) {
		cout << listes.tab_listes[listes.nb_listes].tab_mots[z] << endl;
	}
	cout << "*" << endl;
	for (unsigned int m = 0; m < listes.nb_listes; m++) {
		detruire(listes.tab_listes[m]);
	}
	delete[] listes.tab_listes;
}