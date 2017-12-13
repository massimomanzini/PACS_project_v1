#include "stdafx.h"
#include "data_input.h"
#include "performance_evaluator_1.h"
#include <fstream>
#include <string>

void performance_evaluator_2(std::vector<scenario_node> &set_scenarios, std::vector<performances> &performances_1, std::vector<performances> &performances_2, std::vector<performances> &performances_3, std::vector<product> &set_products, equipment set_equipment[], miscellaneous *misc_data, std::vector<std::vector<configuration>> &set_configurations, std::vector<configuration> &configurations_new_1, std::vector<configuration> &configurations_new_2, std::vector<configuration> &configurations_new_3){

	//creo una matrice della stessa dimensione di set_configurations ed in ogni cella metto performances 
	//performances in temini di tempo necessario per la produzione di tutta la domanda di quello scenario node

	//mi serve 
	//	tempo per ogni attività (assemblaggio e trasporto)
	//	probabilità fail e repair
	//	domanda prodotti


	//prima cosa è definire size delle matrici performances_1/2/3
	int contatore_0 = 0;
	int contatore_1 = 0;
	int contatore_2 = 0;
	int avanti;

	for (int h=0; h<misc_data->num_scenarionodes; h++){
		switch(set_scenarios[h].tnode){
		case(1):
			contatore_0 = contatore_0 + set_configurations[h].size();
			break;
		case(2):
			contatore_1 = contatore_1 + set_configurations[h].size();
			break;
		case(3):
			contatore_2 = contatore_2 + set_configurations[h].size();
			break;
		}
	}

	std::cout << "contatore_0: " << contatore_0 << "\n";
	std::cout << "contatore_1: " << contatore_1 << "\n";
	std::cout << "contatore_2: " << contatore_2 << "\n";
	std::cout <<"insert integer \n";
	std::cin >> avanti;
	
	//resize 
	performances_1.resize(contatore_0);
	performances_2.resize(contatore_1);
	performances_3.resize(contatore_2);

	contatore_0 = -1;
	contatore_1 = -1;
	contatore_2 = -1;
	
	//temp_perf.resize(misc_data->num_products);
	double temp_perf[4];

	for (int h=0; h<misc_data->num_scenarionodes; h++){
		//analizzo uno scenarionode alla volta

		int num_conf = set_configurations[h].size();

		for (int i=0; i<num_conf; i++){
			//analizzo una configurazione alla volta

			temp_perf[0] = 0;
			temp_perf[1] = 0;
			temp_perf[2] = 0;
			temp_perf[3] = 0;

			for (int k=0; k<set_scenarios[h].num_prod; k++){

				//analizzo un prodotto alla volta

				//std::cout << "prodotto: " << k << "\n";

				//write text file
				std::ofstream file_write;
				file_write.open("input.txt");
				//per ogni prodotto sono 3 lavorazioni + input/output + traporto

				//input
				file_write << "Exp ";
				file_write << set_equipment[3].fail_rate;
				file_write << " ";
				file_write << set_equipment[3].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->input_time;
				file_write << "\n";

				switch(k){
				case(0):
					//lav 1
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_1 - 1].step1_FAG - 1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step1_FAG - 1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_1 - 1].step1_prodrate;
					file_write << "\n";

					//lav 2
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step2_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step2_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_1 - 1].step2_prodrate;
					file_write << "\n";

					//lav 3
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step3_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step3_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_1-1].step3_prodrate;
					file_write << "\n";
					break;

				case(1):
					//lav 1
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step1_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step1_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_2-1].step1_prodrate;
					file_write << "\n";

					//lav 2
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step2_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step2_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_2-1].step2_prodrate;
					file_write << "\n";

					//lav 3
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step3_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step3_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_2-1].step3_prodrate;
					file_write << "\n";
					break;

				case(2):
					//lav 1
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step1_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step1_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_3-1].step1_prodrate;
					file_write << "\n";

					//lav 2
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step2_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step2_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_3-1].step2_prodrate;
					file_write << "\n";

					//lav 3
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step3_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step3_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_3-1].step3_prodrate;
					file_write << "\n";
					break;

				case(3):
					//lav 1
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step1_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step1_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_4-1].step1_prodrate;
					file_write << "\n";

					//lav 2
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step2_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step2_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_4-1].step2_prodrate;
					file_write << "\n";

					//lav 3
					file_write << "Exp ";
					file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step3_FAG-1].fail_rate;
					file_write << " ";
					file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step3_FAG-1].rep_rate;
					file_write << " ";
					file_write << 1/set_products[set_scenarios[h].name_4-1].step3_prodrate;
					file_write << "\n";
					break;
				}

				//output
				file_write << "Exp ";
				file_write << set_equipment[2].fail_rate;
				file_write << " ";
				file_write << set_equipment[2].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->output_time;
				file_write << "\n";

				//7-axis
				file_write << "Exp ";
				file_write << set_equipment[0].fail_rate;
				file_write << " ";
				file_write << set_equipment[0].rep_rate;
				file_write << " ";
				file_write << 1/set_configurations[h][i].time_transport;
				file_write << "\n";

				/*
				std::cout << "transport time: " << set_configurations[h][i].time_transport << "\n";
				std::cout << "transport rate: " << 1/set_configurations[h][i].time_transport << "\n";
				std::cout << "press any integer \n";
				std::cin >> avanti;
				*/

				//chiusura file
				file_write.close();

				//stima performance, avvio calcolo
				system("java -jar VoestAlpine.jar input.txt output.txt");

				//lettura performance da file
				std::ifstream file_read;
				file_read.open("output.txt");

				switch(k){
				case(0):
					file_read >> temp_perf[set_scenarios[h].name_1 - 1];
					break;
				case(1):
					file_read >> temp_perf[set_scenarios[h].name_2 - 1];
					break;
				case(2):
					file_read >> temp_perf[set_scenarios[h].name_3 - 1];
					break;
				case(3):
					file_read >> temp_perf[set_scenarios[h].name_4 - 1];
					break;
				}

				file_read.close();

			}

			//std::cout << "A\n";
			
			switch(set_scenarios[h].tnode){
				case(1):
					contatore_0++;
					//std::cout << contatore_0 << "\n";
					//std::cout << "insert integer\n";
					//std::cin >> avanti;

					configurations_new_1.push_back(set_configurations[h][i]);
					performances_1[contatore_0].prod_1 = temp_perf[0];
					performances_1[contatore_0].prod_2 = temp_perf[1];
					performances_1[contatore_0].prod_3 = temp_perf[2];
					performances_1[contatore_0].prod_4 = temp_perf[3];

					break;

				case(2):
					contatore_1++;
					configurations_new_2.push_back(set_configurations[h][i]);
					performances_2[contatore_1].prod_1 = temp_perf[0];
					performances_2[contatore_1].prod_2 = temp_perf[1];
					performances_2[contatore_1].prod_3 = temp_perf[2];
					performances_2[contatore_1].prod_4 = temp_perf[3];
					
					break;

				case(3):
					contatore_2++;
					configurations_new_3.push_back(set_configurations[h][i]);
					performances_3[contatore_2].prod_1 = temp_perf[0];
					performances_3[contatore_2].prod_2 = temp_perf[1];
					performances_3[contatore_2].prod_3 = temp_perf[2];
					performances_3[contatore_2].prod_4 = temp_perf[3];

					break;
			}
			

		}


	}


}

void performance_evaluator_3(std::vector<scenario_node> &set_scenarios, std::vector<performances> &performances_1, std::vector<performances> &performances_2, std::vector<performances> &performances_3, std::vector<product> &set_products, equipment set_equipment[], miscellaneous *misc_data, std::vector<std::vector<configuration>> &set_configurations, std::vector<configuration> &configurations_new_1, std::vector<configuration> &configurations_new_2, std::vector<configuration> &configurations_new_3){

	//creo una matrice della stessa dimensione di set_configurations ed in ogni cella metto performances 
	//performances in temini di tempo necessario per la produzione di tutta la domanda di quello scenario node

	//mi serve 
	//	tempo per ogni attività (assemblaggio e trasporto)
	//	probabilità fail e repair
	//	domanda prodotti


	//prima cosa è definire size delle matrici performances_1/2/3
	int contatore_0 = 0;
	int contatore_1 = 0;
	int contatore_2 = 0;
	int avanti;

	for (int h=0; h<misc_data->num_scenarionodes; h++){
		switch(set_scenarios[h].tnode){
		case(1):
			contatore_0 = contatore_0 + set_configurations[h].size();
			break;
		case(2):
			contatore_1 = contatore_1 + set_configurations[h].size();
			break;
		case(3):
			contatore_2 = contatore_2 + set_configurations[h].size();
			break;
		}
	}


	//resize 
	performances_1.resize(contatore_0);
	performances_2.resize(contatore_1);
	performances_3.resize(contatore_2);

	contatore_0 = -1;
	contatore_1 = -1;
	contatore_2 = -1;
	
	//temp_perf.resize(misc_data->num_products);
	double temp_perf[4];

	for (int h=0; h<misc_data->num_scenarionodes; h++){
		//analizzo uno scenarionode alla volta

		int num_conf = set_configurations[h].size();

		for (int i=0; i<num_conf; i++){
			//analizzo una configurazione alla volta

			temp_perf[0] = 0;
			temp_perf[1] = 0;
			temp_perf[2] = 0;
			temp_perf[3] = 0;

			//analizzo un prodotto alla volta
			if (set_scenarios[h].demand_1 > 0){
				//write text file
				std::ofstream file_write;
				file_write.open("input.txt");
				//per ogni prodotto sono 3 lavorazioni + input/output + traporto

				//input
				file_write << "Exp ";
				file_write << set_equipment[3].fail_rate;
				file_write << " ";
				file_write << set_equipment[3].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->input_time;
				file_write << "\n";

				//lav 1
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_1 - 1].step1_FAG - 1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step1_FAG - 1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_1 - 1].step1_prodrate;
				file_write << "\n";

				//lav 2
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step2_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step2_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_1 - 1].step2_prodrate;
				file_write << "\n";

				//lav 3
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step3_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_1-1].step3_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_1-1].step3_prodrate;
				file_write << "\n";

				//output
				file_write << "Exp ";
				file_write << set_equipment[2].fail_rate;
				file_write << " ";
				file_write << set_equipment[2].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->output_time;
				file_write << "\n";

				//7-axis
				file_write << "Exp ";
				file_write << set_equipment[0].fail_rate;
				file_write << " ";
				file_write << set_equipment[0].rep_rate;
				file_write << " ";
				file_write << 1/set_configurations[h][i].time_transport;
				file_write << "\n";

				file_write.close();

				//stima performance, avvio calcolo
				system("java -jar VoestAlpine.jar input.txt output.txt");

				//lettura performance da file
				std::ifstream file_read;
				file_read.open("output.txt");

				file_read >> temp_perf[0];
				file_read.close();
			}
			if (set_scenarios[h].demand_2 > 0){
				//write text file
				std::ofstream file_write;
				file_write.open("input.txt");
				//per ogni prodotto sono 3 lavorazioni + input/output + traporto

				//input
				file_write << "Exp ";
				file_write << set_equipment[3].fail_rate;
				file_write << " ";
				file_write << set_equipment[3].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->input_time;
				file_write << "\n";

				//lav 1
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step1_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step1_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_2-1].step1_prodrate;
				file_write << "\n";

				//lav 2
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step2_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step2_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_2-1].step2_prodrate;
				file_write << "\n";

				//lav 3
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step3_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_2-1].step3_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_2-1].step3_prodrate;
				file_write << "\n";

				//output
				file_write << "Exp ";
				file_write << set_equipment[2].fail_rate;
				file_write << " ";
				file_write << set_equipment[2].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->output_time;
				file_write << "\n";

				//7-axis
				file_write << "Exp ";
				file_write << set_equipment[0].fail_rate;
				file_write << " ";
				file_write << set_equipment[0].rep_rate;
				file_write << " ";
				file_write << 1/set_configurations[h][i].time_transport;
				file_write << "\n";

				file_write.close();

				//stima performance, avvio calcolo
				system("java -jar VoestAlpine.jar input.txt output.txt");

				//lettura performance da file
				std::ifstream file_read;
				file_read.open("output.txt");

				file_read >> temp_perf[1];
				file_read.close();
			}
			if (set_scenarios[h].demand_3 > 0){
				//write text file
				std::ofstream file_write;
				file_write.open("input.txt");
				//per ogni prodotto sono 3 lavorazioni + input/output + traporto

				//input
				file_write << "Exp ";
				file_write << set_equipment[3].fail_rate;
				file_write << " ";
				file_write << set_equipment[3].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->input_time;
				file_write << "\n";

				//lav 1
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step1_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step1_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_3-1].step1_prodrate;
				file_write << "\n";

				//lav 2
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step2_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step2_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_3-1].step2_prodrate;
				file_write << "\n";

				//lav 3
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step3_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_3-1].step3_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_3-1].step3_prodrate;
				file_write << "\n";

				//output
				file_write << "Exp ";
				file_write << set_equipment[2].fail_rate;
				file_write << " ";
				file_write << set_equipment[2].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->output_time;
				file_write << "\n";

				//7-axis
				file_write << "Exp ";
				file_write << set_equipment[0].fail_rate;
				file_write << " ";
				file_write << set_equipment[0].rep_rate;
				file_write << " ";
				file_write << 1/set_configurations[h][i].time_transport;
				file_write << "\n";

				file_write.close();

				//stima performance, avvio calcolo
				system("java -jar VoestAlpine.jar input.txt output.txt");

				//lettura performance da file
				std::ifstream file_read;
				file_read.open("output.txt");

				
				file_read >> temp_perf[2];
				file_read.close();
			}
			if (set_scenarios[h].demand_4 > 0){
				//write text file
				std::ofstream file_write;
				file_write.open("input.txt");
				//per ogni prodotto sono 3 lavorazioni + input/output + traporto

				//input
				file_write << "Exp ";
				file_write << set_equipment[3].fail_rate;
				file_write << " ";
				file_write << set_equipment[3].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->input_time;
				file_write << "\n";

				//lav 1
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step1_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step1_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_4-1].step1_prodrate;
				file_write << "\n";

				//lav 2
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step2_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step2_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_4-1].step2_prodrate;
				file_write << "\n";

				//lav 3
				file_write << "Exp ";
				file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step3_FAG-1].fail_rate;
				file_write << " ";
				file_write << set_equipment[set_products[set_scenarios[h].name_4-1].step3_FAG-1].rep_rate;
				file_write << " ";
				file_write << 1/set_products[set_scenarios[h].name_4-1].step3_prodrate;
				file_write << "\n";

				//output
				file_write << "Exp ";
				file_write << set_equipment[2].fail_rate;
				file_write << " ";
				file_write << set_equipment[2].rep_rate;
				file_write << " ";
				file_write << 1/misc_data->output_time;
				file_write << "\n";

				//7-axis
				file_write << "Exp ";
				file_write << set_equipment[0].fail_rate;
				file_write << " ";
				file_write << set_equipment[0].rep_rate;
				file_write << " ";
				file_write << 1/set_configurations[h][i].time_transport;
				file_write << "\n";

				file_write.close();

				//stima performance, avvio calcolo
				system("java -jar VoestAlpine.jar input.txt output.txt");

				//lettura performance da file
				std::ifstream file_read;
				file_read.open("output.txt");

				
				file_read >> temp_perf[3];
				file_read.close();

			}

			switch(set_scenarios[h].tnode){
				case(1):
					contatore_0++;

					configurations_new_1.push_back(set_configurations[h][i]);
					performances_1[contatore_0].prod_1 = temp_perf[0];
					performances_1[contatore_0].prod_2 = temp_perf[1];
					performances_1[contatore_0].prod_3 = temp_perf[2];
					performances_1[contatore_0].prod_4 = temp_perf[3];

					break;

				case(2):
					contatore_1++;
					configurations_new_2.push_back(set_configurations[h][i]);
					performances_2[contatore_1].prod_1 = temp_perf[0];
					performances_2[contatore_1].prod_2 = temp_perf[1];
					performances_2[contatore_1].prod_3 = temp_perf[2];
					performances_2[contatore_1].prod_4 = temp_perf[3];
					
					break;

				case(3):
					contatore_2++;
					configurations_new_3.push_back(set_configurations[h][i]);
					performances_3[contatore_2].prod_1 = temp_perf[0];
					performances_3[contatore_2].prod_2 = temp_perf[1];
					performances_3[contatore_2].prod_3 = temp_perf[2];
					performances_3[contatore_2].prod_4 = temp_perf[3];

					break;
			}

		}

	}

}

