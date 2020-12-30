#pragma warning (disable : 4996)
#include <iostream>
#include <string.h>
#include "lecture.h"
#include "points.h"

using namespace std;

void initialiser(Liste& liste) {
	liste.nb_mots = 0;
	liste.nb_points = 0;
	liste.capa = 1;
	liste.pas_extension = 2;
	Mot* newT = new Mot[1];
	liste.tab_mots = newT;
}

void comptage_de_points(int nb_lettres_mot, Liste& liste) {
	int nb_points_mot = 0;
	if (nb_lettres_mot <= 2) {
		nb_points_mot = 0;
	}
	if (nb_lettres_mot == 3 || nb_lettres_mot == 4) {
		nb_points_mot = 1;
	}
	if (nb_lettres_mot == 5) {
		nb_points_mot = 2;
	}
	if (nb_lettres_mot == 6) {
		nb_points_mot = 3;
	}
	if (nb_lettres_mot == 7) {
		nb_points_mot = 5;
	}
	if (nb_lettres_mot == 8) {
		nb_points_mot = 11;
	}
	liste.nb_points += nb_points_mot;
}

void exo1() {
	Mot buffer;
	Liste liste;
	while (strcmp(buffer, "*") != 0) {
		lire_liste(buffer, liste);
		comptage_de_points(strlen(buffer), liste);
	}
	cout << liste.nb_points;
}