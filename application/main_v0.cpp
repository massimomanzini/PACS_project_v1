// PACS_v0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "data_input.h"
#include "input_process.h"
#include "equipment_elaboration.h"
#include "configuration_generation.h"
#include "performance_evaluator_1.h"
#include "evolution_gen.h"
#include "output.h"

#include <vector>


int main()
{
	//initialization
	char filename[] = "input/miscellaneous.txt";
	miscellaneous misc_data;	
	std::vector <scenario_node> set_scenarios;
	std::vector <scenario> set_evolutions;
	std::vector <product> set_products;
	std::vector<std::vector<int>> equipment_matrix;
	equipment_matrix.resize(11);
	std::vector <std::vector<configuration>> set_configurations;
	std::vector <configuration> configurations_new_1;
	std::vector <configuration> configurations_new_2;
	std::vector <configuration> configurations_new_3;
	std::vector<performances> performances_1;
	std::vector<performances> performances_2;
	std::vector<performances> performances_3;
	configuration conf_step1_opt;
	configuration conf_step2_opt;
	configuration conf_step3_opt;
	double costo_opt = 1000000000000;
	equipment set_equipment[11];
	int avanti;

	//inputs
	input_miscellaneous(filename, &misc_data);
	input_scenarios_3(&misc_data, set_scenarios);
	input_scenario_evo_1(&misc_data, set_evolutions);
	input_products_1(&misc_data, set_products);
	input_equipment(&misc_data, set_equipment);

	std::cout << "\n";
	std::cout << "Input phase completed! \n";
	//std::cout << "Press any integer to continue, please. \n";
	//std::cin >> avanti;
	
	//matrice FAG
	equipment_elaboration_2(equipment_matrix, &misc_data, set_scenarios, set_products);

	//generazione configurazioni
	configuration_gen_0(&misc_data, set_configurations, equipment_matrix, set_equipment, set_scenarios);

	std::cout << "\n";
	std::cout << "Configuration generation phase completed! \n";
	//std::cout << "Press any integer to continue, please. \n";
	//std::cin >> avanti;
	
	//performance evaluator
	performance_evaluator_3(set_scenarios, performances_1, performances_2, performances_3, set_products, set_equipment, &misc_data, set_configurations, configurations_new_1, configurations_new_2, configurations_new_3);

	std::cout << "\n";
	std::cout << "Performance evaluation phase completed! \n";
	//std::cout << "Press any integer to continue, please. \n";
	//std::cin >> avanti;

	//additional initializations
	configuration_initialization_0(&conf_step1_opt);
	configuration_initialization_0(&conf_step2_opt);
	configuration_initialization_0(&conf_step3_opt);

	//layout evolution generation and evaluation
	evolution_gen_v1(set_scenarios, performances_1, performances_2, performances_3, set_equipment, &misc_data, configurations_new_1, configurations_new_2, configurations_new_3, set_evolutions, &conf_step1_opt, &conf_step2_opt, &conf_step3_opt, costo_opt);
	
	std::cout << "\n";
	std::cout << "Layout evolution generation and evaluation phase completed! \n";
	//std::cout << "Press any integer to continue, please. \n";
	//std::cin >> avanti;

	//output, anche a video
	output_0(&conf_step1_opt, &conf_step2_opt, &conf_step3_opt, costo_opt);

	std::cout << "\n";
	std::cout << "Computation finished! \n";
	std::cout << "Press any integer to close, please. \n";
	std::cin >> avanti;

	return 0;
}

