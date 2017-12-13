#include "stdafx.h"
#include "data_input.h"
#include "input_process.h"
#include "equipment_elaboration.h"
#include "evolution_gen.h"


void evolution_gen_v0(std::vector<int> conf_evo, std::vector<std::vector<double>> &performances, equipment set_equipment[], miscellaneous *misc_data, std::vector<std::vector<configuration>> &set_configurations, std::vector<scenario> set_evolutions){

	configuration conf_step1_temp;
	configuration conf_step2_temp;
	configuration conf_step3_temp;
	configuration conf_step1_opt;
	configuration conf_step2_opt;
	configuration conf_step3_opt;
	int costo_opt = 1000000000000;
	int costo_stimato = 1000000000000;

	//per ogni scenario evolution genero tutte le conf_evolution possibili
	for(int i; i < misc_data->num_scenario; i++){
		//T=3 è una constante
		//per ogni time instant del mio scenario
		
		//forse ad ogni iterazione mi conviene direttamente stimare il costo totale
		//e così tirat fuori l'evoluzione con costo atteso minore
		for(int j; j < set_configurations[set_evolutions[i].step1_name - 1].size(); j++){
			//metto in memoria la configurazione al primo step
			conf_step1_temp = set_configurations[set_evolutions[i].step1_name - 1][j];

			for(int k; k < set_configurations[set_evolutions[i].step2_name - 1].size(); k++){
				conf_step2_temp = set_configurations[set_evolutions[i].step2_name - 1][j];

				for(int h; h < set_configurations[set_evolutions[i].step3_name - 1].size(); h++){
					conf_step3_temp = set_configurations[set_evolutions[i].step3_name - 1][j];

					//calcolo costo totale atteso viene stimato calcolando il costo totale per ogni evolution
					//poi il costo totale di ogni scenario viene pesato per la sua probabilità di accadimento
					//come considero cost dello scenario node radice?
					
					//si considera:
					//	equipment_cost (inv), performances (operative), scenario_evaluation_prob
					//	costo di riconfigurazione, da stimare con un tool che identifica se
					//		tra una conf ed un'altra sia necessaria una riconfigurazione
					
					

					//.......function costo_totale


					//se costo totale stimato < costo ottimo, aggiorno 
					if(costo_stimato < costo_opt){

						costo_opt = costo_stimato;
						conf_step1_opt = conf_step1_temp;
						conf_step2_opt = conf_step2_temp;
						conf_step3_opt = conf_step3_temp;
					}

				}
			
			}
			
		}

	}




}

void evolution_gen_v1(std::vector <scenario_node> set_scenarios, std::vector<performances> &performances_1, std::vector<performances> &performances_2, std::vector<performances> &performances_3, equipment set_equipment[], miscellaneous *misc_data, std::vector<configuration> configurations_new_1, std::vector<configuration> &configurations_new_2, std::vector<configuration> &configurations_new_3, std::vector<scenario> set_evolutions, configuration *conf_step1_opt, configuration *conf_step2_opt, configuration *conf_step3_opt, double &costo_opt){


	configuration conf_step1_temp;
	configuration conf_step2_temp;
	configuration conf_step3_temp;
	
	double costo_stimato = 0;
	double costo_temp = 0;
	double tempo_operativo;
	int avanti;
		
	//genero tutti le possibili configuration evolution
	//	ogni volta che ne ho generata uno, stimo costo totale atteso
	//	se questo è minore del costo minore in memoria in quel momento, aggiorno.
	for(int j=0; j < configurations_new_1.size(); j++){

		//metto in memoria la configurazione al primo step
		conf_step1_temp = configurations_new_1[j];

		for(int k=0; k < configurations_new_2.size(); k++){
			conf_step2_temp = configurations_new_2[k];

			for(int h=0; h < configurations_new_3.size(); h++){
				conf_step3_temp = configurations_new_3[h];
				
				//inizializzazione costo_stimato per ogni evolution
				costo_stimato = 0;

				//calcolo costo totale atteso
				//	viene stimato calcolando il costo totale per ogni evolution
				//	poi il costo totale di ogni scenario viene pesato per la sua probabilità di accadimento
				for(int i=0; i<misc_data->num_scenario; i++){

					//si considera:
					//	equipment_cost (inv), performances (operative), scenario_evaluation_prob
					//	costo di riconfigurazione, da stimare con un tool che identifica se
					//		tra una conf ed un'altra sia necessaria una riconfigurazione

					//inizialiizazione cost_temp per ogni scenario
					costo_temp = 0;
					
					//record costi equipment fissi
					//input, output, CU
					costo_temp = costo_temp + set_equipment[1].cost;
					costo_temp = costo_temp + set_equipment[2].cost;
					costo_temp = costo_temp + set_equipment[3].cost;
					//cost 7 axis
					costo_temp = costo_temp + set_equipment[0].cost + misc_data->cost_track * conf_step1_temp.robot_posX * 2;
						
					//step_1

					//costo investimento
					switch(conf_step1_temp.num_FAG){
					case(1):
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG1_name - 1].cost;
						break;

					case(2):
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG1_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG2_name - 1].cost;
						break;

					case(3):
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG1_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG2_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG3_name - 1].cost;
						break;

					case(4):
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG1_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG2_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG3_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG4_name - 1].cost;
						break;

					case(5):
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG1_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG2_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG3_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG4_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG5_name - 1].cost;
						break;

					case(6):
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG1_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG2_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG3_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG4_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG5_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG6_name - 1].cost;
						break;

					case(7):
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG1_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG2_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG3_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG4_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG5_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG6_name - 1].cost;
						costo_temp = costo_temp + set_equipment[conf_step1_temp.FAG7_name - 1].cost;
						break;
					}

					
					//costo operativo
					tempo_operativo = 0;

					if(performances_1[j].prod_1 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step1_name - 1].demand_1 * (1/performances_1[j].prod_1))/3600;
					}
					if(performances_1[j].prod_2 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step1_name - 1].demand_2 * (1/performances_1[j].prod_2))/3600;
					}
					if(performances_1[j].prod_3 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step1_name - 1].demand_3 * (1/performances_1[j].prod_3))/3600;
					}
					if(performances_1[j].prod_4 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step1_name - 1].demand_4 * (1/performances_1[j].prod_4))/3600;
					}

					//check che tempo a disposizione sia sufficiente
					if(tempo_operativo <= misc_data->time_available){
						costo_temp = costo_temp + tempo_operativo * misc_data->op_cost;
					}
					else{
						costo_temp = costo_temp + 1000000000000;
					}

					//step2

					tempo_operativo = 0;

					//costo investimento
					//	nuovi investimenti solo nel caso di num_FAG2 <> num_FAG1
					if(conf_step1_temp.num_FAG < conf_step2_temp.num_FAG){
						//devo identificare quale FAG/s è/sono stati aggiunti
						//inoltre c'è investimento per lunghezza track aumentata e costo riconfigurazione
						
						int check_reconf_2[11];
						int check_reconf_1[11];
						
						check_reconf_1[0] = 1;
						check_reconf_1[1] = 1;
						check_reconf_1[2] = 1;
						check_reconf_1[3] = 1;
						
						check_reconf_2[0] = 1;
						check_reconf_2[1] = 1;
						check_reconf_2[2] = 1;
						check_reconf_2[3] = 1;

						//check quali FAG ci sono nella prima conf
						switch(conf_step1_temp.num_FAG){
						case(1):
							check_reconf_1[conf_step1_temp.FAG1_name - 1] = 1;
							break;
						case(2):
							check_reconf_1[conf_step1_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG2_name - 1] = 1;
							break;
						case(3):
							check_reconf_1[conf_step1_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG3_name - 1] = 1;
							break;
						case(4):
							check_reconf_1[conf_step1_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG3_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG4_name - 1] = 1;
							break;
						case(5):
							check_reconf_1[conf_step1_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG3_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG4_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG5_name - 1] = 1;
							break;
						case(6):
							check_reconf_1[conf_step1_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG3_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG4_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG5_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG6_name - 1] = 1;
							break;
						case(7):
							check_reconf_1[conf_step1_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG3_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG4_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG5_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG6_name - 1] = 1;
							check_reconf_1[conf_step1_temp.FAG7_name - 1] = 1;
							break;
						}

						//check quali FAG ci sono nella seconda conf
						switch(conf_step2_temp.num_FAG){
						case(1):
							check_reconf_2[conf_step2_temp.FAG1_name - 1] = 1;
							break;
						case(2):
							check_reconf_2[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG2_name - 1] = 1;
							break;
						case(3):
							check_reconf_2[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG3_name - 1] = 1;
							break;
						case(4):
							check_reconf_2[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG3_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG4_name - 1] = 1;
							break;
						case(5):
							check_reconf_2[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG3_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG4_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG5_name - 1] = 1;
							break;
						case(6):
							check_reconf_2[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG3_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG4_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG5_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG6_name - 1] = 1;
							break;
						case(7):
							check_reconf_2[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG3_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG4_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG5_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG6_name - 1] = 1;
							check_reconf_2[conf_step2_temp.FAG7_name - 1] = 1;
							break;
						}

						//se ci sono dei FAG in più li devo comprare
						for(int l=0; l<11; l++){
							if(check_reconf_2[l] > check_reconf_1[l]){
								costo_temp = costo_temp + (set_equipment[i].cost/(1 + misc_data->k_attualizzazione));
							}
						}
						//aggiugo allugamento track e costo reconf

						costo_temp = costo_temp + ((misc_data->cost_track * 2 * (conf_step2_temp.robot_posY - conf_step1_temp.robot_posY))/(1 + misc_data->k_attualizzazione));
						tempo_operativo = tempo_operativo + (misc_data->rec_time/(1 + misc_data->k_attualizzazione));
					}else if(conf_step1_temp.num_FAG > conf_step2_temp.num_FAG){
						tempo_operativo = tempo_operativo + (misc_data->rec_time/(1 + misc_data->k_attualizzazione));
						}

					//costo operativo

					if(performances_2[k].prod_1 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step2_name - 1].demand_1 * (1/performances_2[k].prod_1))/3600;
					}
					if(performances_2[k].prod_2 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step2_name - 1].demand_2 * (1/performances_2[k].prod_2))/3600;
					}
					if(performances_2[k].prod_3 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step2_name - 1].demand_3 * (1/performances_2[k].prod_3))/3600;
					}
					if(performances_2[k].prod_4 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step2_name - 1].demand_4 * (1/performances_2[k].prod_4))/3600;
					}

					//check che tempo a disposizione sia sufficiente
					if(tempo_operativo <= misc_data->time_available){
						costo_temp = costo_temp + (tempo_operativo * misc_data->op_cost)/(1 + misc_data->k_attualizzazione);
					}
					else{
						costo_temp = costo_temp + 1000000000000;
					}
					
					//step3
					tempo_operativo = 0;
					
					//costo investimento
					//	nuovi investimenti solo nel caso di num_FAG2 <> num_FAG1
					if(conf_step2_temp.num_FAG < conf_step3_temp.num_FAG){
						//devo identificare quale FAG/s è/sono stati aggiunti
						//inoltre c'è investimento per lunghezza track aumentata e costo riconfigurazione
						int check_reconf_2[11];
						int check_reconf_1[11];
						
						check_reconf_1[0] = 1;
						check_reconf_1[1] = 1;
						check_reconf_1[2] = 1;
						check_reconf_1[3] = 1;
						
						check_reconf_2[0] = 1;
						check_reconf_2[1] = 1;
						check_reconf_2[2] = 1;
						check_reconf_2[3] = 1;

						//check quali FAG ci sono nella prima conf
						switch(conf_step2_temp.num_FAG){
						case(1):
							check_reconf_1[conf_step2_temp.FAG1_name - 1] = 1;
							break;
						case(2):
							check_reconf_1[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG2_name - 1] = 1;
							break;
						case(3):
							check_reconf_1[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG3_name - 1] = 1;
							break;
						case(4):
							check_reconf_1[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG3_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG4_name - 1] = 1;
							break;
						case(5):
							check_reconf_1[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG3_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG4_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG5_name - 1] = 1;
							break;
						case(6):
							check_reconf_1[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG3_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG4_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG5_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG6_name - 1] = 1;
							break;
						case(7):
							check_reconf_1[conf_step2_temp.FAG1_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG2_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG3_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG4_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG5_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG6_name - 1] = 1;
							check_reconf_1[conf_step2_temp.FAG7_name - 1] = 1;
							break;
						}

						//check quali FAG ci sono nella seconda conf
						switch(conf_step3_temp.num_FAG){
						case(1):
							check_reconf_2[conf_step3_temp.FAG1_name - 1] = 1;
							break;
						case(2):
							check_reconf_2[conf_step3_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG2_name - 1] = 1;
							break;
						case(3):
							check_reconf_2[conf_step3_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG3_name - 1] = 1;
							break;
						case(4):
							check_reconf_2[conf_step3_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG3_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG4_name - 1] = 1;
							break;
						case(5):
							check_reconf_2[conf_step3_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG3_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG4_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG5_name - 1] = 1;
							break;
						case(6):
							check_reconf_2[conf_step3_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG3_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG4_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG5_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG6_name - 1] = 1;
							break;
						case(7):
							check_reconf_2[conf_step3_temp.FAG1_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG2_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG3_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG4_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG5_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG6_name - 1] = 1;
							check_reconf_2[conf_step3_temp.FAG7_name - 1] = 1;
							break;
						}

						//se ci sono dei FAG in più li devo comprare
						for(int l=0; l<11; l++){
							if(check_reconf_2[l] > check_reconf_1[l]){
								costo_temp = costo_temp + (set_equipment[i].cost/std::pow((1 + misc_data->k_attualizzazione),2));
							}
						}
						//aggiugo allugamento track e costo reconf

						costo_temp = costo_temp + ((misc_data->cost_track * 2 * (conf_step3_temp.robot_posY - conf_step2_temp.robot_posY))/std::pow((1 + misc_data->k_attualizzazione),2));
						tempo_operativo = tempo_operativo + (misc_data->rec_time/std::pow((1 + misc_data->k_attualizzazione),2));
					}else if(conf_step2_temp.num_FAG > conf_step3_temp.num_FAG){
						tempo_operativo = tempo_operativo + (misc_data->rec_time/std::pow((1 + misc_data->k_attualizzazione),2));
						}

					//costo operativo

					if(performances_3[h].prod_1 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step3_name - 1].demand_1 * (1/performances_3[h].prod_1))/3600;
					}
					if(performances_3[h].prod_2 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step3_name - 1].demand_2 * (1/performances_3[h].prod_2))/3600;
					}
					if(performances_3[h].prod_3 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step3_name - 1].demand_3 * (1/performances_3[h].prod_3))/3600;
					}
					if(performances_3[h].prod_4 > 0){
						tempo_operativo = tempo_operativo + (set_scenarios[set_evolutions[i].step3_name - 1].demand_4 * (1/performances_3[h].prod_4))/3600;
					}
					
					//check che tempo a disposizione sia sufficiente
					if(tempo_operativo <= misc_data->time_available){
						costo_temp = costo_temp + (tempo_operativo * misc_data->op_cost)/std::pow((1 + misc_data->k_attualizzazione), 2);
					}
					else{
						costo_temp = costo_temp + 1000000000000;
					}
					
					//function costo_totale
					costo_stimato = costo_stimato + set_evolutions[i].occur_prob * costo_temp;

				}
	
				//se costo totale stimato < costo ottimo, aggiorno 
				if(costo_stimato < costo_opt){

					costo_opt = costo_stimato;

					//time bucket 1
					conf_step1_opt->num_FAG = conf_step1_temp.num_FAG;
					conf_step1_opt->FAG1_name = conf_step1_temp.FAG1_name;
					conf_step1_opt->FAG1_posX = conf_step1_temp.FAG1_posX;
					conf_step1_opt->FAG1_posY = conf_step1_temp.FAG1_posY;
					conf_step1_opt->FAG2_name = conf_step1_temp.FAG2_name;
					conf_step1_opt->FAG2_posX = conf_step1_temp.FAG2_posX;
					conf_step1_opt->FAG2_posY = conf_step1_temp.FAG2_posY;
					conf_step1_opt->FAG3_name = conf_step1_temp.FAG3_name;
					conf_step1_opt->FAG3_posX = conf_step1_temp.FAG3_posX;
					conf_step1_opt->FAG3_posY = conf_step1_temp.FAG3_posY;
					conf_step1_opt->FAG4_name = conf_step1_temp.FAG4_name;
					conf_step1_opt->FAG4_posX = conf_step1_temp.FAG4_posX;
					conf_step1_opt->FAG4_posY = conf_step1_temp.FAG4_posY;
					conf_step1_opt->FAG5_name = conf_step1_temp.FAG5_name;
					conf_step1_opt->FAG5_posX = conf_step1_temp.FAG5_posX;
					conf_step1_opt->FAG5_posY = conf_step1_temp.FAG5_posY;
					conf_step1_opt->FAG6_name = conf_step1_temp.FAG6_name;
					conf_step1_opt->FAG6_posX = conf_step1_temp.FAG6_posX;
					conf_step1_opt->FAG6_posY = conf_step1_temp.FAG6_posY;
					conf_step1_opt->FAG7_name = conf_step1_temp.FAG7_name;
					conf_step1_opt->FAG7_posX = conf_step1_temp.FAG7_posX;
					conf_step1_opt->FAG7_posY = conf_step1_temp.FAG7_posY;
					conf_step1_opt->robot_posX = conf_step1_temp.robot_posX;
					conf_step1_opt->robot_posY = conf_step1_temp.robot_posY;
					conf_step1_opt->time_transport = conf_step1_temp.time_transport;
					conf_step1_opt->CU_posX = conf_step1_temp.CU_posX;
					conf_step1_opt->CU_posY = conf_step1_temp.CU_posY;
					conf_step1_opt->input_posX = conf_step1_temp.input_posX;
					conf_step1_opt->input_posY = conf_step1_temp.input_posY;
					conf_step1_opt->output_posX = conf_step1_temp.output_posX;
					conf_step1_opt->output_posY = conf_step1_temp.output_posY;

					//time bucket 2
					conf_step2_opt->num_FAG = conf_step2_temp.num_FAG;
					conf_step2_opt->FAG1_name = conf_step2_temp.FAG1_name;
					conf_step2_opt->FAG1_posX = conf_step2_temp.FAG1_posX;
					conf_step2_opt->FAG1_posY = conf_step2_temp.FAG1_posY;
					conf_step2_opt->FAG2_name = conf_step2_temp.FAG2_name;
					conf_step2_opt->FAG2_posX = conf_step2_temp.FAG2_posX;
					conf_step2_opt->FAG2_posY = conf_step2_temp.FAG2_posY;
					conf_step2_opt->FAG3_name = conf_step2_temp.FAG3_name;
					conf_step2_opt->FAG3_posX = conf_step2_temp.FAG3_posX;
					conf_step2_opt->FAG3_posY = conf_step2_temp.FAG3_posY;
					conf_step2_opt->FAG4_name = conf_step2_temp.FAG4_name;
					conf_step2_opt->FAG4_posX = conf_step2_temp.FAG4_posX;
					conf_step2_opt->FAG4_posY = conf_step2_temp.FAG4_posY;
					conf_step2_opt->FAG5_name = conf_step2_temp.FAG5_name;
					conf_step2_opt->FAG5_posX = conf_step2_temp.FAG5_posX;
					conf_step2_opt->FAG5_posY = conf_step2_temp.FAG5_posY;
					conf_step2_opt->FAG6_name = conf_step2_temp.FAG6_name;
					conf_step2_opt->FAG6_posX = conf_step2_temp.FAG6_posX;
					conf_step2_opt->FAG6_posY = conf_step2_temp.FAG6_posY;
					conf_step2_opt->FAG7_name = conf_step2_temp.FAG7_name;
					conf_step2_opt->FAG7_posX = conf_step2_temp.FAG7_posX;
					conf_step2_opt->FAG7_posY = conf_step2_temp.FAG7_posY;
					conf_step2_opt->robot_posX = conf_step2_temp.robot_posX;
					conf_step2_opt->robot_posY = conf_step2_temp.robot_posY;
					conf_step2_opt->time_transport = conf_step2_temp.time_transport;
					conf_step2_opt->CU_posX = conf_step2_temp.CU_posX;
					conf_step2_opt->CU_posY = conf_step2_temp.CU_posY;
					conf_step2_opt->input_posX = conf_step2_temp.input_posX;
					conf_step2_opt->input_posY = conf_step2_temp.input_posY;
					conf_step2_opt->output_posX = conf_step2_temp.output_posX;
					conf_step2_opt->output_posY = conf_step2_temp.output_posY;

					//time bucket 3
					conf_step3_opt->num_FAG = conf_step3_temp.num_FAG;
					conf_step3_opt->FAG1_name = conf_step3_temp.FAG1_name;
					conf_step3_opt->FAG1_posX = conf_step3_temp.FAG1_posX;
					conf_step3_opt->FAG1_posY = conf_step3_temp.FAG1_posY;
					conf_step3_opt->FAG2_name = conf_step3_temp.FAG2_name;
					conf_step3_opt->FAG2_posX = conf_step3_temp.FAG2_posX;
					conf_step3_opt->FAG2_posY = conf_step3_temp.FAG2_posY;
					conf_step3_opt->FAG3_name = conf_step3_temp.FAG3_name;
					conf_step3_opt->FAG3_posX = conf_step3_temp.FAG3_posX;
					conf_step3_opt->FAG3_posY = conf_step3_temp.FAG3_posY;
					conf_step3_opt->FAG4_name = conf_step3_temp.FAG4_name;
					conf_step3_opt->FAG4_posX = conf_step3_temp.FAG4_posX;
					conf_step3_opt->FAG4_posY = conf_step3_temp.FAG4_posY;
					conf_step3_opt->FAG5_name = conf_step3_temp.FAG5_name;
					conf_step3_opt->FAG5_posX = conf_step3_temp.FAG5_posX;
					conf_step3_opt->FAG5_posY = conf_step3_temp.FAG5_posY;
					conf_step3_opt->FAG6_name = conf_step3_temp.FAG6_name;
					conf_step3_opt->FAG6_posX = conf_step3_temp.FAG6_posX;
					conf_step3_opt->FAG6_posY = conf_step3_temp.FAG6_posY;
					conf_step3_opt->FAG7_name = conf_step3_temp.FAG7_name;
					conf_step3_opt->FAG7_posX = conf_step3_temp.FAG7_posX;
					conf_step3_opt->FAG7_posY = conf_step3_temp.FAG7_posY;
					conf_step3_opt->robot_posX = conf_step3_temp.robot_posX;
					conf_step3_opt->robot_posY = conf_step3_temp.robot_posY;
					conf_step3_opt->time_transport = conf_step3_temp.time_transport;
					conf_step3_opt->CU_posX = conf_step3_temp.CU_posX;
					conf_step3_opt->CU_posY = conf_step3_temp.CU_posY;
					conf_step3_opt->input_posX = conf_step3_temp.input_posX;
					conf_step3_opt->input_posY = conf_step3_temp.input_posY;
					conf_step3_opt->output_posX = conf_step3_temp.output_posX;
					conf_step3_opt->output_posY = conf_step3_temp.output_posY;

					
				}

			}
			
		}
			
	}

}

void evolution_trial(std::vector<std::vector<configuration>> &set_configurations, std::vector<configuration> &configurations_new_1){

	for(int i=0; i < set_configurations[0].size(); i++){
		configurations_new_1.push_back(set_configurations[0][i]);
	}
	
	std::cout << "size new vector: " << configurations_new_1.size() <<"\n";
}

void evolution_trial_2(std::vector<performances> &performances_1){


	for(int i=0; i < performances_1.size(); i++){
		std::cout << "performances: " << performances_1[i].prod_1 << "\n";
		std::cout << "time: " << 1/performances_1[i].prod_1 << "\n";
		std::cout << "domanda 100: " << 1/performances_1[i].prod_1 * 100 << "\n";
	}


}


