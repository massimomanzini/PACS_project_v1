#include "stdafx.h"
#include "data_input.h"
#include "input_process.h"
#include "equipment_elaboration.h"


using namespace std;


void equipment_elaboration(int *i, miscellaneous *misc_data,  scenario_node set_scenarios[], product set_products[], int *equipment_matrix[]){

	int y = *i;
	
		switch(set_scenarios[y].num_prod){
			case(1):{
				equipment_matrix[set_products[set_scenarios[y].name_1].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_1].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_1].step3_FAG][y] = 1;

				break;
				}
			case(2):{
				equipment_matrix[set_products[set_scenarios[y].name_1].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_1].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_1].step3_FAG][y] = 1;

				equipment_matrix[set_products[set_scenarios[y].name_2].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_2].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_2].step3_FAG][y] = 1;

				break;
				}
			case(3):{
				equipment_matrix[set_products[set_scenarios[y].name_1].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_1].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_1].step3_FAG][y] = 1;

				equipment_matrix[set_products[set_scenarios[y].name_2].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_2].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_2].step3_FAG][y] = 1;

				equipment_matrix[set_products[set_scenarios[y].name_3].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_3].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_3].step3_FAG][y] = 1;
				
				break;
				}
		case(4):{
				equipment_matrix[set_products[set_scenarios[y].name_1].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_1].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_1].step3_FAG][y] = 1;

				equipment_matrix[set_products[set_scenarios[y].name_2].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_2].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_2].step3_FAG][y] = 1;

				equipment_matrix[set_products[set_scenarios[y].name_3].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_3].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_3].step3_FAG][y] = 1;

				equipment_matrix[set_products[set_scenarios[y].name_4].step1_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_4].step2_FAG][y] = 1;
				equipment_matrix[set_products[set_scenarios[y].name_4].step3_FAG][y] = 1;
				
				break;
				}
		}

	/*
	switch(set_scenarios[y].num_prod){
			case(1):{
				equipment_matrix[set_products[set_scenarios[*i].name_1].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_1].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_1].step3_FAG][*i] = 1;

				break;
				}
			case(2):{
				equipment_matrix[set_products[set_scenarios[*i].name_1].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_1].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_1].step3_FAG][*i] = 1;

				equipment_matrix[set_products[set_scenarios[*i].name_2].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_2].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_2].step3_FAG][*i] = 1;

				break;
				}
			case(3):{
				equipment_matrix[set_products[set_scenarios[*i].name_1].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_1].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_1].step3_FAG][*i] = 1;

				equipment_matrix[set_products[set_scenarios[*i].name_2].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_2].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_2].step3_FAG][*i] = 1;

				equipment_matrix[set_products[set_scenarios[*i].name_3].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_3].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_3].step3_FAG][*i] = 1;
				
				break;
				}
		case(4):{
				equipment_matrix[set_products[set_scenarios[*i].name_1].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_1].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_1].step3_FAG][*i] = 1;

				equipment_matrix[set_products[set_scenarios[*i].name_2].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_2].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_2].step3_FAG][*i] = 1;

				equipment_matrix[set_products[set_scenarios[*i].name_3].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_3].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_3].step3_FAG][*i] = 1;

				equipment_matrix[set_products[set_scenarios[*i].name_4].step1_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_4].step2_FAG][*i] = 1;
				equipment_matrix[set_products[set_scenarios[*i].name_4].step3_FAG][*i] = 1;
				
				break;
				}
		}
		*/
	
}

void equipment_elaboration_1(std::vector<std::vector<int>> &equipment_matrix, miscellaneous *misc_data, std::vector<scenario_node> &set_scenarios, std::vector<product> &set_products){
	//questa funzion elabora input ricevuti e crea la equipment matrix fatta di numeri binari che mi dicono
	//	quale FAG (riga) è richiesto da quale scenario node (colonne)


	for(int b=0; b<11; b++){
		//faccio un resize di tutte le righe del mio vettore, matrice
		equipment_matrix[b].resize(misc_data->num_scenarionodes);

		//già che sono nel ciclo, metto 1 nei primi 4 FAG
		//che sono CU, input, output, 7-axis
		if (b<4){
			for(int i=0; i<misc_data->num_scenarionodes; i++){
				equipment_matrix[b][i] = 1;
			}	
		}
	}


	for (int i=0; i < misc_data->num_scenarionodes; i++){
		//per ogni scenarionode vado a prendere ogni prodotto e analizzo il suo processo

		switch(set_scenarios[i].num_prod){
			case(1):{
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step3_FAG - 1][i] = 1;

				break;
				}
			case(2):{
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step3_FAG - 1][i] = 1;

				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step3_FAG - 1][i] = 1;

				break;
				}
			case(3):{
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step3_FAG - 1][i] = 1;

				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step3_FAG - 1][i] = 1;

				equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step3_FAG - 1][i] = 1;
				
				break;
				}
		case(4):{
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step3_FAG - 1][i] = 1;

				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step3_FAG - 1][i] = 1;

				equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step3_FAG - 1][i] = 1;

				equipment_matrix[set_products[set_scenarios[i].name_4 - 1].step1_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_4 - 1].step2_FAG - 1][i] = 1;
				equipment_matrix[set_products[set_scenarios[i].name_4 - 1].step3_FAG - 1][i] = 1;
				
				break;
				}
		}
		

	}

}

void equipment_elaboration_2(std::vector<std::vector<int>> &equipment_matrix, miscellaneous *misc_data, std::vector<scenario_node> &set_scenarios, std::vector<product> &set_products){
	//questa funzion elabora input ricevuti e crea la equipment matrix fatta di numeri binari che mi dicono
	//	quale FAG (riga) è richiesto da quale scenario node (colonne)


	for(int b=0; b<11; b++){
		//faccio un resize di tutte le righe del mio vettore, matrice
		equipment_matrix[b].resize(misc_data->num_scenarionodes);

		//già che sono nel ciclo, metto 1 nei primi 4 FAG
		//che sono CU, input, output, 7-axis
		if (b<4){
			for(int i=0; i<misc_data->num_scenarionodes; i++){
				equipment_matrix[b][i] = 1;
			}	
		}
	}


	for (int i=0; i < misc_data->num_scenarionodes; i++){
		//per ogni scenarionode vado a prendere ogni prodotto e analizzo il suo processo

		if(set_scenarios[i].name_1 > 0){
			equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step1_FAG - 1][i] = 1;
			equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step2_FAG - 1][i] = 1;
			equipment_matrix[set_products[set_scenarios[i].name_1 - 1].step3_FAG - 1][i] = 1;
		}

		if(set_scenarios[i].name_2 > 0){
			equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step1_FAG - 1][i] = 1;
			equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step2_FAG - 1][i] = 1;
			equipment_matrix[set_products[set_scenarios[i].name_2 - 1].step3_FAG - 1][i] = 1;
		}

		if(set_scenarios[i].name_3 > 0){
			equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step1_FAG - 1][i] = 1;
			equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step2_FAG - 1][i] = 1;
			equipment_matrix[set_products[set_scenarios[i].name_3 - 1].step3_FAG - 1][i] = 1;
		}

		if(set_scenarios[i].name_4 > 0){
			equipment_matrix[set_products[set_scenarios[i].name_4 - 1].step1_FAG - 1][i] = 1;
			equipment_matrix[set_products[set_scenarios[i].name_4 - 1].step2_FAG - 1][i] = 1;
			equipment_matrix[set_products[set_scenarios[i].name_4 - 1].step3_FAG - 1][i] = 1;
		}

	}

}
