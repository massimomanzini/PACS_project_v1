#include "stdafx.h"
#include "data_input.h"
#include "configuration_generation.h"
#include <math.h>
#include <algorithm>

void configuration_gen_0(miscellaneous *misc_data, std::vector<std::vector<configuration>> &set_configurations, std::vector<std::vector<int>> &equipment_matrix, equipment set_equipment[], std::vector <scenario_node> set_scenarios){
	//da equipment_matrix vedo quali FAG sono richiesti dagli scenari nodes e genero configurazioni

	//definisco flag per gli scenari nodes
	int num_members_1 = -1;
	int num_members_2 = -1;
	int num_members_3 = -1;

	//file configuration temporaneo che uso come supporto.
	configuration temp_conf; 

	//resize del vettore
	set_configurations.resize(misc_data->num_scenarionodes);

	//analizzo uno scenario alla volta
	for (int h=0; h<misc_data->num_scenarionodes; h++){

		//conto il numero di FAG richiesti in ogni scenario
		int cont_temp = 0;
		std::vector<int> members_in_conf;

		for (int j=4; j<11; j++){


			if (equipment_matrix[j][h] == 1){
				cont_temp++;
				
				//tengo traccia dei FAG richiesti nello scenario node
				members_in_conf.push_back(j+1);
			}
		}
		
		//ID flag per ogni time bucket e numero equipment
		if(set_scenarios[h].tnode == 1){
			if(num_members_1 == -1){
				num_members_1 = cont_temp;
			}
		}else if(set_scenarios[h].tnode == 2){
			if(num_members_2 == -1){
				num_members_2 = cont_temp;
			}
		}else{
			if(num_members_3 == -1){
				num_members_3 = cont_temp;
			}
		}


		//divido nord e sud
		//numero di elementi a N e a S
		int temp_N, temp_S;

		if(cont_temp % 2 == 0){ //cont_temp pari
			temp_N = cont_temp/2;
			temp_S = temp_N;
		}
		else{ //dispari
			temp_S = cont_temp/2;
			temp_N = cont_temp - temp_S;
		}

		//creo vettori di int nord e sud e poi trovo tutte le permutazioni
		//i primi temp_N li metto a nord, i secondi temp_S li metto a sud
		//FAG 2/3 li metto a N, 2 (CU) al primo posto e 3 (output) all'ultimo
		//FAG 4 lo metto a sud, al primo posto
		std::vector<int> members_N;
		std::vector<int> members_S;

		for (int i=0; i<cont_temp; i++){
			if (i < temp_N){
				members_N.push_back(members_in_conf[i]);
			}
			else{
				members_S.push_back(members_in_conf[i]);
			}
		}

		//li dispongo random in N e S ultizzando permutazioni
		std::vector<std::vector<int>> permutation_N;
		int perm_N = 0;
		do {
			perm_N++;
			//registro la permutazione aggiungendo elementi all'inizio e alla fine
			permutation_N.push_back(members_N);
		} while (std::next_permutation(members_N.begin(), members_N.end()));


		std::vector<std::vector<int>> permutation_S;
		int perm_S = 0;
		do {
			perm_S++;
			//registro la permutazione aggiungendo elementi all'inizio
			permutation_S.push_back(members_S);
		} while (std::next_permutation(members_S.begin(), members_S.end()));


		//ora devo creare le coppie
		//calcolare le misure
		//inserire elementi aggiuntivi
		//inserirle in set configurations
		for(int i=0; i<perm_N; i++){

			//uso un file temporaneo di supporto
			//lo creo ciclicamente all'interno di questo for perchè alla fine lo cancello per riaverlo vuoto
			configuration_initialization_0(&temp_conf);

			//inizio con N
			int max_x = 0;
			int max_y = 0;
			temp_conf.CU_posX = set_equipment[1].x/2;
			temp_conf.CU_posY = set_equipment[1].y/2;
			max_y = temp_conf.CU_posY + set_equipment[1].y/2;
					
			for(int k=0; k<temp_N; k++){

				switch(k){
				case(0):
					temp_conf.FAG1_name = permutation_N[i][k];
					temp_conf.FAG1_posX = temp_conf.CU_posX +  set_equipment[1].x/2 + set_equipment[permutation_N[i][k] - 1].x/2;
					temp_conf.FAG1_posY = set_equipment[permutation_N[i][k] - 1].y/2;
					if (temp_conf.FAG1_posY + set_equipment[permutation_N[i][k] - 1].y/2 > max_y) max_y = temp_conf.FAG1_posY + set_equipment[permutation_N[i][k] - 1].y/2;
					break;
						
				case(1):
					temp_conf.FAG2_name = permutation_N[i][k];
					temp_conf.FAG2_posX = temp_conf.FAG1_posX +  set_equipment[permutation_N[i][k-1] - 1].x/2 + set_equipment[permutation_N[i][k] - 1].x/2;
					temp_conf.FAG2_posY = set_equipment[permutation_N[i][k] - 1].y/2;
					if (temp_conf.FAG2_posY + set_equipment[permutation_N[i][k] - 1].y/2 > max_y) max_y = temp_conf.FAG2_posY + set_equipment[permutation_N[i][k] - 1].y/2;
					break;

				case(2):
					temp_conf.FAG3_name = permutation_N[i][k];
					temp_conf.FAG3_posX = temp_conf.FAG2_posX +  set_equipment[permutation_N[i][k-1] - 1].x/2 + set_equipment[permutation_N[i][k] - 1].x/2;
					temp_conf.FAG3_posY = set_equipment[permutation_N[i][k] - 1].y/2;
					if (temp_conf.FAG3_posY + set_equipment[permutation_N[i][k] - 1].y/2 > max_y) max_y = temp_conf.FAG3_posY + set_equipment[permutation_N[i][k] - 1].y/2;
					break;

				case(3):
					temp_conf.FAG4_name = permutation_N[i][k];
					temp_conf.FAG4_posX = temp_conf.FAG3_posX +  set_equipment[permutation_N[i][k-1] - 1].x/2 + set_equipment[permutation_N[i][k] - 1].x/2;
					temp_conf.FAG4_posY = set_equipment[permutation_N[i][k] - 1].y/2;
					if (temp_conf.FAG4_posY + set_equipment[permutation_N[i][k] - 1].y/2 > max_y) max_y = temp_conf.FAG4_posY + set_equipment[permutation_N[i][k] - 1].y/2;
					break;
				}
			}

			switch(temp_N){
			case(1): temp_conf.output_posX = temp_conf.FAG1_posX + set_equipment[permutation_N[i][0] - 1].x/2 + set_equipment[2].x/2;
				break;
			case(2): temp_conf.output_posX = temp_conf.FAG2_posX + set_equipment[permutation_N[i][1] - 1].x/2 + set_equipment[2].x/2;
				break;
			case(3): temp_conf.output_posX = temp_conf.FAG3_posX + set_equipment[permutation_N[i][2] - 1].x/2 + set_equipment[2].x/2;
				break;
			case(4): temp_conf.output_posX = temp_conf.FAG4_posX + set_equipment[permutation_N[i][3] - 1].x/2 + set_equipment[2].x/2;
				break;
			}
			temp_conf.output_posY = set_equipment[2].y/2;
			if (temp_conf.output_posY + set_equipment[2].y/2> max_y){ 
				max_y = temp_conf.output_posY + set_equipment[2].y/2;
			}
			max_x = temp_conf.output_posX + set_equipment[2].x/2;

			//posiziono track sopra FAG in N
			temp_conf.robot_posX = max_x/2;
			temp_conf.robot_posY = max_y + set_equipment[0].y/2;

			//aggiorno max_y
			max_y = temp_conf.robot_posY + set_equipment[0].y/2;
			
			//per ogni coppia, memorizzo in set_conf e ragiono sulle distanze
			temp_conf.num_FAG = temp_N + temp_S;

			for(int j=0; j<perm_S; j++){

				max_x = 0;
				
				//posiziono vettore S sopra track
				//ragiono sul numero di temp_N, temp_S <= temp_N
				temp_conf.input_posY = max_y + set_equipment[3].y/2;
				temp_conf.input_posX = max_x + set_equipment[3].x/2;
				max_x = set_equipment[3].x;

				switch(temp_N){
				case(1): 
					temp_conf.FAG2_name = permutation_S[j][0];
					temp_conf.FAG2_posY = max_y + set_equipment[permutation_S[j][0] - 1].y/2;
					temp_conf.FAG2_posX = max_x + set_equipment[permutation_S[j][0] - 1].x/2;
					max_x = max_x + set_equipment[permutation_S[j][0] - 1].x;
					break;

				case(2):
					if(temp_S == 1){
						temp_conf.FAG3_name = permutation_S[j][0];
						temp_conf.FAG3_posY = max_y + set_equipment[permutation_S[j][0] - 1].y/2;
						temp_conf.FAG3_posX = max_x + set_equipment[permutation_S[j][0] - 1].x/2;
						max_x = max_x + set_equipment[permutation_S[j][0] - 1].x;
						}
					else{ //temp_S = 2
						temp_conf.FAG3_name = permutation_S[j][0];
						temp_conf.FAG3_posY = max_y + set_equipment[permutation_S[j][0] - 1].y/2;
						temp_conf.FAG3_posX = max_x + set_equipment[permutation_S[j][0] - 1].x/2;
						max_x = max_x + set_equipment[permutation_S[j][0] - 1].x;

						temp_conf.FAG4_name = permutation_S[j][1];
						temp_conf.FAG4_posY = max_y + set_equipment[permutation_S[j][1] - 1].y/2;
						temp_conf.FAG4_posX = max_x + set_equipment[permutation_S[j][1] - 1].x/2;
						max_x = max_x + set_equipment[permutation_S[j][1] - 1].x;
					}
					break;

				case(3):
					if(temp_S == 2){
						temp_conf.FAG4_name = permutation_S[j][0];
						temp_conf.FAG4_posY = max_y + set_equipment[permutation_S[j][0] - 1].y/2;
						temp_conf.FAG4_posX = max_x + set_equipment[permutation_S[j][0] - 1].x/2;
						max_x = max_x + set_equipment[permutation_S[j][0] - 1].x;

						temp_conf.FAG5_name = permutation_S[j][1];
						temp_conf.FAG5_posY = max_y + set_equipment[permutation_S[j][1] - 1].y/2;
						temp_conf.FAG5_posX = max_x + set_equipment[permutation_S[j][1] - 1].x/2;
						max_x = max_x + set_equipment[permutation_S[j][1] - 1].x;
					}
					else{ //temp_S = 3
						temp_conf.FAG4_name = permutation_S[j][0];
						temp_conf.FAG4_posY = max_y + set_equipment[permutation_S[j][0] - 1].y/2;
						temp_conf.FAG4_posX = max_x + set_equipment[permutation_S[j][0] - 1].x/2;
						max_x = max_x + set_equipment[permutation_S[j][0] - 1].x;

						temp_conf.FAG5_name = permutation_S[j][1];
						temp_conf.FAG5_posY = max_y + set_equipment[permutation_S[j][1] - 1].y/2;
						temp_conf.FAG5_posX = max_x + set_equipment[permutation_S[j][1] - 1].x/2;
						max_x = max_x + set_equipment[permutation_S[j][1] - 1].x;

						temp_conf.FAG6_name = permutation_S[j][1];
						temp_conf.FAG6_posY = max_y + set_equipment[permutation_S[j][2] - 1].y/2;
						temp_conf.FAG6_posX = max_x + set_equipment[permutation_S[j][2] - 1].x/2;
						max_x = max_x + set_equipment[permutation_S[j][2] - 1].x;
					}
					break;

				case(4): //temp_S = 3
					temp_conf.FAG5_name = permutation_S[j][0];
					temp_conf.FAG5_posY = max_y + set_equipment[permutation_S[j][0] - 1].y/2;
					temp_conf.FAG5_posX = max_x + set_equipment[permutation_S[j][0] - 1].x/2;
					max_x = max_x + set_equipment[permutation_S[j][0] - 1].x;

					temp_conf.FAG6_name = permutation_S[j][1];
					temp_conf.FAG6_posY = max_y + set_equipment[permutation_S[j][1] - 1].y/2;
					temp_conf.FAG6_posX = max_x + set_equipment[permutation_S[j][1] - 1].x/2;
					max_x = max_x + set_equipment[permutation_S[j][1] - 1].x;

					temp_conf.FAG7_name = permutation_S[j][1];
					temp_conf.FAG7_posY = max_y + set_equipment[permutation_S[j][2] - 1].y/2;
					temp_conf.FAG7_posX = max_x + set_equipment[permutation_S[j][2] - 1].x/2;
					max_x = max_x + set_equipment[permutation_S[j][2] - 1].x;
					break;
				}

				//calcolo misure
				int x_tot = 0;
				int y_tot = 0;
				switch(temp_conf.num_FAG){
				case(2):
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG1_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG2_posX);
					x_tot = x_tot/2;

					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG1_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG2_posY);
					y_tot = y_tot/2;
					break;

				case(3):
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG1_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG2_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG3_posX);
					x_tot = x_tot/3;

					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG1_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG2_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG3_posY);
					y_tot = y_tot/3;
					break;

				case(4):
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG1_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG2_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG3_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG4_posX);
					x_tot = x_tot/4;

					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG1_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG2_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG3_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG4_posY);
					y_tot = y_tot/4;
					break;

				case(5):
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG1_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG2_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG3_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG4_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG5_posX);
					x_tot = x_tot/5;

					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG1_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG2_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG3_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG4_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG5_posY);
					y_tot = y_tot/5;
					break;

				case(6):
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG1_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG2_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG3_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG4_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG5_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG6_posX);
					x_tot = x_tot/6;

					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG1_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG2_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG3_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG4_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG5_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG6_posY);
					y_tot = y_tot/6;
					break;

				case(7):
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG1_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG2_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG3_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG4_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG5_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG6_posX);
					x_tot = x_tot + std::abs(temp_conf.robot_posX - temp_conf.FAG7_posX);
					x_tot = x_tot/7;

					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG1_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG2_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG3_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG4_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG5_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG6_posY);
					y_tot = y_tot + std::abs(temp_conf.robot_posY - temp_conf.FAG7_posY);
					y_tot = y_tot/7;
					break;
				}

				//e il tempo di movimentazione del robot
				// velocità espressa in mm/secondo
				//x_tot + y_tot è in mm, quindi ok
				temp_conf.time_transport = (x_tot + y_tot)/misc_data->robot_speed;
				
				//metto a memoria temp_conf
				set_configurations[h].push_back(temp_conf);

				//temp_conf viene generato da nuovo per ogni perm_N
				//al girare di ogni perm_N vengono attribuiti dei valori per solo una parte delle variabili di temp_conf
				//le restanti variabili sono definite al variare di perm_S
				//quindi, ad ogni perm_S vengono mantenute le variabili definite da perm_N e ridefinite le altre
				//

			}
			
		}
		members_in_conf.clear();
		members_S.clear();
		members_N.clear();
	}


	//aggiunta configurazioni collaterali

	//1<>2
	if(num_members_1 > num_members_2){
		for(int i=0; i < misc_data->num_scenarionodes; i++){

			if(set_scenarios[i].tnode == 1){
				for(int j=0; j < misc_data->num_scenarionodes; j++){

					if (set_scenarios[j].tnode == 2){
						for(int h=0; h<set_configurations[i].size(); h++){
							set_configurations[j].push_back(set_configurations[i][h]);
						}
					}
				}
				break;
			}
		}
	}else if(num_members_2 > num_members_1){
		for(int i=0; i < misc_data->num_scenarionodes; i++){

			if(set_scenarios[i].tnode == 2){
				for(int j=0; j < misc_data->num_scenarionodes; j++){

					if (set_scenarios[j].tnode == 1){
						for(int h=0; h<set_configurations[i].size(); h++){
							set_configurations[j].push_back(set_configurations[i][h]);

						}
					}
				}
				break;
			}
		}
	}

	//1<>3
	if(num_members_1 > num_members_3){
		for(int i=0; i < misc_data->num_scenarionodes; i++){

			if(set_scenarios[i].tnode == 1){
				for(int j=0; j < misc_data->num_scenarionodes; j++){

					if (set_scenarios[j].tnode == 3){
						for(int h=0; h<set_configurations[i].size(); h++){
							set_configurations[j].push_back(set_configurations[i][h]);
						}
					}
				}
				break;
			}
		}
	}else if(num_members_3 > num_members_1){
		for(int i=0; i < misc_data->num_scenarionodes; i++){

			if(set_scenarios[i].tnode == 3){
				for(int j=0; j < misc_data->num_scenarionodes; j++){

					if (set_scenarios[j].tnode == 1){
						for(int h=0; h<set_configurations[i].size(); h++){
							set_configurations[j].push_back(set_configurations[i][h]);
						}
					}
				}
				break;
			}
		}
	}

	//2<>3
	if(num_members_2 > num_members_3){
		for(int i=0; i < misc_data->num_scenarionodes; i++){

			if(set_scenarios[i].tnode == 2){
				for(int j=0; j < misc_data->num_scenarionodes; j++){

					if (set_scenarios[j].tnode == 3){
						for(int h=0; h<set_configurations[i].size(); h++){
							set_configurations[j].push_back(set_configurations[i][h]);
						}
					}
				}
				break;
			}
		}
	}else if(num_members_3 > num_members_2){
		for(int i=0; i < misc_data->num_scenarionodes; i++){

			if(set_scenarios[i].tnode == 3){
				for(int j=0; j < misc_data->num_scenarionodes; j++){

					if (set_scenarios[j].tnode == 2){
						for(int h=0; h<set_configurations[i].size(); h++){
							set_configurations[j].push_back(set_configurations[i][h]);
						}
					}
				}
				break;
			}
		}
	}

}


void configuration_initialization_0(configuration *conf){

	conf->num_FAG = 0;
	conf->FAG1_name = 0;
	conf->FAG1_posX = 0;
	conf->FAG1_posY = 0;
	conf->FAG2_name = 0;
	conf->FAG2_posX = 0;
	conf->FAG2_posY = 0;
	conf->FAG3_name = 0;
	conf->FAG3_posX = 0;
	conf->FAG3_posY = 0;
	conf->FAG4_name = 0;
	conf->FAG4_posX = 0;
	conf->FAG4_posY = 0;
	conf->FAG5_name = 0;
	conf->FAG5_posX = 0;
	conf->FAG5_posY = 0;
	conf->FAG6_name = 0;
	conf->FAG6_posX = 0;
	conf->FAG6_posY = 0;
	conf->FAG7_name = 0;
	conf->FAG7_posX = 0;
	conf->FAG7_posY = 0;
	conf->robot_posX = 0;
	conf->robot_posY = 0;
	conf->time_transport = 0;
	conf->CU_posX = 0;
	conf->CU_posY = 0;
	conf->input_posX = 0;
	conf->input_posY = 0;
	conf->output_posX = 0;
	conf->output_posY = 0;
}