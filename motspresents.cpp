#pragma warning (disable : 4996)
#include <iostream>
#include <string.h>
#include "listes.h"

using namespace std;

void lire_et_comparer(Mot& id, Listes& listes) {
	cin >> id;
	if (strcmp(id, "*") != 0) {
		if (verification_doublon(listes.tab_listes[listes.nb_listes], id) == false) {
			strcpy(listes.tab_listes[listes.nb_listes].tab_mots[listes.tab_listes[listes.nb_listes].nb_mots++], id);
		}
	}
	else {
		listes.nb_listes++;
	}
}

void comparaison_doublons(Listes& listes) {
	for (unsigned int i = 0; i < listes.tab_listes[1].nb_mots; i++) {
		bool condition = false;
		for (unsigned int j = 0; j < listes.tab_listes[0].nb_mots; j++) {
			if (strcmp(listes.tab_listes[0].tab_mots[j], listes.tab_listes[1].tab_mots[i]) == 0) {
				condition = true;
				break;
			}
		}
		if (condition == false) {
			strcpy(listes.tab_listes[2].tab_mots[listes.tab_listes[2].nb_mots++], listes.tab_listes[1].tab_mots[i]);
		}
	}
}

void exo3() {
	Mot buffer;
	strcpy(buffer, "NULL");
	Listes listes;
	for (int i = 0; i < MAX_LISTES; i++) {
		listes.tab_listes[i].nb_mots = 0;
	};
	listes.nb_listes = 0;
	
	for (int k = 0; k < 2; k++) {
		while (strcmp(buffer, "*") != 0) {
			lire_et_comparer(buffer, listes);
		}
		strcpy(buffer, "NULL");
	}
	for (int j = 0; j < listes.nb_listes; j++) {
		tri_alphabetique(listes.tab_listes[j]);
	}
	comparaison_doublons(listes);
	for (int z = 0; z < listes.tab_listes[2].nb_mots; z++) {
		cout << listes.tab_listes[2].tab_mots[z] << endl;
	}
	cout << "*" << endl;
}