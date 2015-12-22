/**
* @file table.c
* @brief 
* @author Durand Valentin TP3 Informatique Promo 2018
* @date Decembre 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "table.h"

int main(int argc, char *argv[])
{
	int i;
	color_table cTable, ssTable;
	char *fichier = argv[1];
	int searchColor[3];
	image input = FAIRE_image();
	image_charger(input,fichier);
	cTable = create_color_table(input);
	ssTable = color_table_duplicate(cTable, 2, 10);
	for (i = 0; i < cTable->count; i++){
		printf("%d | %d | %d\n", cTable->table[0][i], cTable->table[1][i], cTable->table[2][i]);
	}
	printf("\n\n");
	for (i = 0; i < ssTable->count; i++){
		printf("%d | %d | %d\n", ssTable->table[0][i], ssTable->table[1][i], ssTable->table[2][i]);
	}
	printf("cT : %d ; %d\nssT : %d ; %d\n", cTable->count, cTable->owner, ssTable->count, ssTable->owner);
	color_table_get_color(cTable, 2, searchColor);
	printf("color 2 = %d %d %d\n", searchColor[0], searchColor[1], searchColor[2]);
	destroy_color_table(ssTable);
	destroy_color_table(cTable);
	return 0;
}