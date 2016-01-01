/**
* @file trivial.c
* @brief 
* @author Durand Valentin TP3 Informatique Promo 2018
* @date Decembre 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "image.h"
#include "table.h"

int main(int argc, char *argv[])
{
	int i, *pix;
	int closest[3];
	color_table cTable;
	char *fichierImg, *fichierTable;
	image img, table;

	assert(argc == 3);

	fichierImg = argv[1];
	fichierTable = argv[2];

	/* Creation image */
	img = FAIRE_image();
	image_charger(img,fichierImg);

	/* Creation de la table */
	table = FAIRE_image();
	image_charger(table,fichierTable);
	cTable = create_color_table(table);

	image_debut(img);
	do
    {
    	pix = image_lire_pixel(img);
    	closest[red] = cTable->table[red][0];
    	closest[green] = cTable->table[green][0];
    	closest[blue] = cTable->table[blue][0];
    	for(i = 1; i < cTable->count; i++){
    		if(sqrt(
    				pow(pix[red]-cTable->table[red][i], 2)
    				+
    				pow(pix[green]-cTable->table[green][i], 2)
    				+
    				pow(pix[blue]-cTable->table[blue][i], 2)
					)
    			<
    			sqrt(
    				pow(pix[red]-closest[red], 2)
    				+
    				pow(pix[green]-closest[green], 2)
    				+
    				pow(pix[blue]-closest[blue], 2)
    				)
				)
    		{
    			closest[red] = cTable->table[red][i];
		    	closest[green] = cTable->table[green][i];
		    	closest[blue] = cTable->table[blue][i];
    		}
  		}
  		image_ecrire_pixel(img, closest);
    }
  	while(image_pixel_suivant(img));

  	image_sauvegarder(img, "result.ppm");

	destroy_color_table(cTable);

	return 0;
}