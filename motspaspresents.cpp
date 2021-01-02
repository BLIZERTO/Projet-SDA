#pragma warning (disable : 4996)
#include <iostream>
#include <string.h>
#include "listes.h"
#include "canonique.h"
#include "dynam.h"

using namespace std;

void initialiser_listes(Listes& listes) {
	listes.nb_listes = 0;
	listes.capalistes = 5;
	listes.PE_listes = 5;
	Liste* newT = new Liste[listes.capalistes];
	listes.tab_listes = newT;
}

void lire_listes(Mot& id, Listes& listes, unsigned int i) {
	cin >> id;
	if (strcmp(id, "*") != 0) {
		if (verification_doublon(listes.tab_listes[listes.nb_listes], id) == false) {
			ecrire(listes.tab_listes[listes.nb_listes], id);
		}
	}
	else {
		if (listes.nb_listes >= listes.capalistes)
		{
			Liste* listeMot = new Liste[listes.capalistes + 2];

			for (unsigned int k = 0; k <= i; k++)
			{
				initialiser(listeMot[i]);
			}

			if (listes.capalistes != 0) {
				for (unsigned int j = 0; j < listes.nb_listes; j++)
				{
					listeMot[j] =listes.tab_listes[j];
				}
				delete[] listes.tab_listes;
			}

			listes.tab_listes = listeMot;
			listes.capalistes = listes.capalistes +2;

		}
		listes.nb_listes++;
	}
}

void mots_pas_apparents(Listes& listes) {
	for (unsigned int i = 0; i < listes.tab_listes[1].nb_mots; i++) {
		bool condition = false;
		for (unsigned int j = 0; j < listes.tab_listes[0].nb_mots; j++) {
			if (strcmp(listes.tab_listes[0].tab_mots[j], listes.tab_listes[1].tab_mots[i]) == 0) {
				condition = true;
				break;
			}
		}
		if (condition == false) {
			ecrire(listes.tab_listes[2], listes.tab_listes[1].tab_mots[i]);
		}
	}
}

void exo3() {
	Mot buffer;
	strcpy(buffer, "NULL");
	Listes listes;
	initialiser_listes(listes);
	for (unsigned int e = 0; e <= 2; e++) {
		initialiser(listes.tab_listes[e]);
	}
	for (unsigned int k = 0; k < 2; k++) {
		while (strcmp(buffer, "*") != 0) {
			lire_listes(buffer, listes, k);
		}
		strcpy(buffer, "NULL");
	}
	for (unsigned int j = 0; j < listes.nb_listes; j++) {
		tri_alphabetique(listes.tab_listes[j]);
	}
	mots_pas_apparents(listes);
	for (unsigned int z = 0; z < listes.tab_listes[2].nb_mots; z++) {
		cout << listes.tab_listes[2].tab_mots[z] << endl;
	}
	cout << "*" << endl;
	for (unsigned int m = 0; m < listes.nb_listes; m++) {
		detruire(listes.tab_listes[m]);
	}
	delete[] listes.tab_listes;
}
