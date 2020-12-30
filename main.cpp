#include <iostream>
#include "liste.h"

using namespace std;

void exo1();
void exo2();
void exo3();
void exo4();
void exo5() {};
void exo6() {};

int main() {
	int num;
	cout << "Selectionner un nombre entre 1 et 6 pour choisir un des sprints."
		<< endl << endl
		<< "Rappel :"
		<< endl
		<< "1. Lire une liste de mots saisie au clavier et afficher a l'ecran le nombre de points qu'elle represente ;"
		<< endl
		<< "2. Lire une liste de mots saisie au clavier et l'afficher a l'ecran sous forme canonique ;"
		<< endl
		<< "3. Lire deux listes de mots saisies au clavier et afficher a l'ecran les mots de la seconde liste n'apparaissant pas dans la premiere ;"
		<< endl
		<< "4. Lire deux listes de mots saisies au clavier et afficher a l'ecran les mots de la seconde liste apparaissant dans la premiere ;"
		<< endl
		<< "5. Lire une liste de listes de mots saisie au clavier et afficher a l'ecran la liste de tous les mots apparaissant dans au moins deux de ces listes ;"
		<< endl
		<< "6. Lire un plateau suivi d'une liste de mots saisis au clavier et afficher a l'ecran les mots de la liste etant presents sur la plateau."
		<< endl;
		cin >> num;
	cout << endl;
	switch (num) {
	case 1:
		cout << "Option 1 choisie. Vous pouvez maintenant inserer votre liste." << endl;  exo1(); break;
	case 2:
		cout << "Option 2 choisie. Vous pouvez maintenant inserer votre liste." << endl;  exo2(); break;
	case 3:
		cout << "Option 3 choisie. Vous pouvez maintenant inserer votre liste." << endl;  exo3(); break;
	case 4:
		cout << "Option 4 choisie. Vous pouvez maintenant inserer votre liste." << endl;  exo4(); break;
	case 5:
		exo5(); break;
	case 6:
		exo6(); break;
	}
}