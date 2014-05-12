/*
 *   Ce fichier fait parti d'un projet de programmation donné en Licence 3 
 *   à l'Université de Bordeaux 1
 *
 *   Copyright (C) 2014 Adrien Boussicault
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>

#include "automate.h"
#include "outils.h"

int main(){
	Automate* automate = creer_automate();

	// Les états seront ajoutés automatiquement

	ajouter_etat_initial(automate, 1);
	ajouter_transition(automate, 1, 'b', 2);
	ajouter_transition(automate, 1, 'a', 3);
	ajouter_transition(automate, 1, 'a', 2);
	ajouter_transition(automate, 4, 'b', 1);	
	ajouter_transition(automate, 2, 'a', 4);
	ajouter_transition(automate, 3, 'a', 2);
	ajouter_transition(automate, 3, 'b', 3);
	ajouter_transition(automate, 4, 'b', 3);
	ajouter_etat_final(automate, 4);	

	char mot[] = "babb";
	char mot2[] = "aaabb";
	char mot3[] = "ababa";
	char mot4[] = "abbaa";
	char mot5[] = "bbaaa";

	if (le_mot_est_reconnu(automate, mot))
	{
		print_ensemble(delta_star(automate, get_initiaux(automate), mot), NULL);		
		printf("\n'%s' est reconnu....\n", mot);
	}
	else
		printf("\n'%s' n'est pas reconnu....\n", mot);
	
	if (le_mot_est_reconnu(automate, mot2))
	{
		print_ensemble(delta_star(automate, get_initiaux(automate), mot2), NULL);
		printf("\n'%s' est reconnu....\n", mot2);
	}
	else
		printf("\n'%s' n'est pas reconnu....\n", mot2);
	
	if (le_mot_est_reconnu(automate, mot3))
	{
		print_ensemble(delta_star(automate, get_initiaux(automate), mot3), NULL);
		printf("\n'%s' est reconnu....\n", mot3);
	}
	else
		printf("\n'%s' n'est pas reconnu....\n", mot3);
	
	if (le_mot_est_reconnu(automate, mot4))
	{
		print_ensemble(delta_star(automate, get_initiaux(automate), mot4), NULL);
		printf("\n'%s' est reconnu....\n", mot4);
	}
	else
		printf("\n'%s' n'est pas reconnu....\n", mot4);
	
	if (le_mot_est_reconnu(automate, mot5))
	{
		print_ensemble(delta_star(automate, get_initiaux(automate), mot5), NULL);
		printf("\n'%s' est reconnu....\n", mot5);
	}
	else
		printf("\n'%s' n'est pas reconnu....\n", mot5);

	liberer_automate(automate);	

	exit(1);
}
