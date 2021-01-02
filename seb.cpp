#pragma warning (disable : 4996)
#include <iostream>
#include <string.h>
#include "listes.h"

using namespace std;

void initialiser(listeDeMots& ref_liste, unsigned int capa, unsigned int p) {
	assert(capa > 0 || p > 0);
	ref_liste.capacite = capa;
	ref_liste.pasExtension = p;
	ref_liste.TabDeMots = new Mot[capa];
	ref_liste.nombreDeMots = 0;
}





void essaie(Listes& listes) {

	for (unsigned int i = 1; i < listes.nb_listes; i++) {
		bool condition = false;
			for (unsigned int k = 0; k < listes.tab_listes[0].nb_mots; k++) {

				for (unsigned int j = 0; j < listes.tab_listes[i].nb_mots; j++) {
					if (strcmp(listes.tab_listes[0].tab_mots[k], listes.tab_listes[i].tab_mots[j]) == 0) {
						condition = true;
						break;
					}
				}
				if (condition == true) {
					break;
				}
			}
			if (condition == false) {
				strcpy(listes.tab_listes[2].tab_mots[listes.tab_listes[2].nb_mots++], listes.tab_listes[1].tab_mots[i]);
			}
	}
}

void comparaison_doublonsV2(Listes& listes) {
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

void exo5() {
	Mot buffer;
	Listes listes;
	for (int i = 0; i < MAX_LISTES; i++) {
		listes.tab_listes[i].nb_mots = 0;
	};
	listes.nb_listes = 0;

	for (int k = 0; k < MAX_LISTES; k++) {
		while (strcmp(buffer, "*") != 0) {
			lire_et_comparer(buffer, listes);
		}
		strcpy(buffer, "NULL");
		listes.nb_listes++;
	}
	for (int j = 0; j < listes.nb_listes; j++) {
		tri_alphabetique(listes.tab_listes[j]);
	}
	comparaison_doublonsV2(listes);
	for (int z = 0; z < listes.tab_listes[2].nb_mots; z++) {
		cout << listes.tab_listes[2].tab_mots[z] << endl;
	}
	cout << "*" << endl;
}
