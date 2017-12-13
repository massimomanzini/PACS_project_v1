#include "stdafx.h"
#include "data_input.h"
#include <fstream>
#include <string>
#include "output.h"

void output_0(configuration *conf_step1_opt, configuration *conf_step2_opt, configuration *conf_step3_opt, double costo_opt){

	//questa funzione scrive su file e a video la configuration evolution ottima
	//costo totale, conf_step1, conf_step2, conf_step3
	std::cout << "The optimal configuration evolution is the following.\n";
	std::cout << "\n";

	//primo time bucket
	std::cout << "The first time bucket line layout.\n ";
	
	std::cout << "Control unit coordinates: X = " << conf_step1_opt->CU_posX << " Y = " << conf_step1_opt->CU_posY << "\n";
	std::cout << "Input station coordinates: X = " << conf_step1_opt->input_posX << " Y = " << conf_step1_opt->input_posY << "\n";
	std::cout << "Output station coordinates: X = " << conf_step1_opt->output_posX << " Y = " << conf_step1_opt->output_posX << "\n";
	std::cout << "Handling robot coordinates: X = " << conf_step1_opt->robot_posX << " Y = " << conf_step1_opt->robot_posY << "\n";

	//quanti FAG?
	switch(conf_step1_opt->num_FAG){
	case(1):
		std::cout << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		break;
	case(2):
		std::cout << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		break;
	case(3):
		std::cout << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		break;
	case(4):
		std::cout << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step1_opt->FAG4_name << ", coordinates: X = " << conf_step1_opt->FAG4_posX << " Y = " << conf_step1_opt->FAG4_posY << "\n";
		break;
	case(5):
		std::cout << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step1_opt->FAG4_name << ", coordinates: X = " << conf_step1_opt->FAG4_posX << " Y = " << conf_step1_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step1_opt->FAG5_name << ", coordinates: X = " << conf_step1_opt->FAG5_posX << " Y = " << conf_step1_opt->FAG5_posY << "\n";
		break;
	case(6):
		std::cout << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step1_opt->FAG4_name << ", coordinates: X = " << conf_step1_opt->FAG4_posX << " Y = " << conf_step1_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step1_opt->FAG5_name << ", coordinates: X = " << conf_step1_opt->FAG5_posX << " Y = " << conf_step1_opt->FAG5_posY << "\n";
		std::cout << "FAG 6, type " << conf_step1_opt->FAG6_name << ", coordinates: X = " << conf_step1_opt->FAG6_posX << " Y = " << conf_step1_opt->FAG6_posY << "\n";
		break;
	case(7):
		std::cout << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step1_opt->FAG4_name << ", coordinates: X = " << conf_step1_opt->FAG4_posX << " Y = " << conf_step1_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step1_opt->FAG5_name << ", coordinates: X = " << conf_step1_opt->FAG5_posX << " Y = " << conf_step1_opt->FAG5_posY << "\n";
		std::cout << "FAG 6, type " << conf_step1_opt->FAG6_name << ", coordinates: X = " << conf_step1_opt->FAG6_posX << " Y = " << conf_step1_opt->FAG6_posY << "\n";
		std::cout << "FAG 7, type " << conf_step1_opt->FAG7_name << ", coordinates: X = " << conf_step1_opt->FAG7_posX << " Y = " << conf_step1_opt->FAG7_posY << "\n";
		break;
	}

	//secondo time bucket
	std::cout << "\n";
	std::cout << "The second time bucket line layout.\n ";
	
	std::cout << "Control unit coordinates: X = " << conf_step2_opt->CU_posX << " Y = " << conf_step2_opt->CU_posY << "\n";
	std::cout << "Input station coordinates: X = " << conf_step2_opt->input_posX << " Y = " << conf_step2_opt->input_posY << "\n";
	std::cout << "Output station coordinates: X = " << conf_step2_opt->output_posX << " Y = " << conf_step2_opt->output_posX << "\n";
	std::cout << "Handling robot coordinates: X = " << conf_step2_opt->robot_posX << " Y = " << conf_step2_opt->robot_posY << "\n";

	//quanti FAG?
	switch(conf_step2_opt->num_FAG){
	case(1):
		std::cout << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		break;
	case(2):
		std::cout << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		break;
	case(3):
		std::cout << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		break;
	case(4):
		std::cout << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step2_opt->FAG4_name << ", coordinates: X = " << conf_step2_opt->FAG4_posX << " Y = " << conf_step2_opt->FAG4_posY << "\n";
		break;
	case(5):
		std::cout << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step2_opt->FAG4_name << ", coordinates: X = " << conf_step2_opt->FAG4_posX << " Y = " << conf_step2_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step2_opt->FAG5_name << ", coordinates: X = " << conf_step2_opt->FAG5_posX << " Y = " << conf_step2_opt->FAG5_posY << "\n";
		break;
	case(6):
		std::cout << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step2_opt->FAG4_name << ", coordinates: X = " << conf_step2_opt->FAG4_posX << " Y = " << conf_step2_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step2_opt->FAG5_name << ", coordinates: X = " << conf_step2_opt->FAG5_posX << " Y = " << conf_step2_opt->FAG5_posY << "\n";
		std::cout << "FAG 6, type " << conf_step2_opt->FAG6_name << ", coordinates: X = " << conf_step2_opt->FAG6_posX << " Y = " << conf_step2_opt->FAG6_posY << "\n";
		break;
	case(7):
		std::cout << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step2_opt->FAG4_name << ", coordinates: X = " << conf_step2_opt->FAG4_posX << " Y = " << conf_step2_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step2_opt->FAG5_name << ", coordinates: X = " << conf_step2_opt->FAG5_posX << " Y = " << conf_step2_opt->FAG5_posY << "\n";
		std::cout << "FAG 6, type " << conf_step2_opt->FAG6_name << ", coordinates: X = " << conf_step2_opt->FAG6_posX << " Y = " << conf_step2_opt->FAG6_posY << "\n";
		std::cout << "FAG 7, type " << conf_step2_opt->FAG7_name << ", coordinates: X = " << conf_step2_opt->FAG7_posX << " Y = " << conf_step2_opt->FAG7_posY << "\n";
		break;
	}

	//terzo time bucket
	std::cout << "\n";
	std::cout << "The third time bucket line layout.\n ";
	
	std::cout << "Control unit coordinates: X = " << conf_step3_opt->CU_posX << " Y = " << conf_step3_opt->CU_posY << "\n";
	std::cout << "Input station coordinates: X = " << conf_step3_opt->input_posX << " Y = " << conf_step3_opt->input_posY << "\n";
	std::cout << "Output station coordinates: X = " << conf_step3_opt->output_posX << " Y = " << conf_step3_opt->output_posX << "\n";
	std::cout << "Handling robot coordinates: X = " << conf_step3_opt->robot_posX << " Y = " << conf_step3_opt->robot_posY << "\n";

	//quanti FAG?
	switch(conf_step3_opt->num_FAG){
	case(1):
		std::cout << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		break;
	case(2):
		std::cout << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		break;
	case(3):
		std::cout << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		break;
	case(4):
		std::cout << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step3_opt->FAG4_name << ", coordinates: X = " << conf_step3_opt->FAG4_posX << " Y = " << conf_step3_opt->FAG4_posY << "\n";
		break;
	case(5):
		std::cout << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step3_opt->FAG4_name << ", coordinates: X = " << conf_step3_opt->FAG4_posX << " Y = " << conf_step3_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step3_opt->FAG5_name << ", coordinates: X = " << conf_step3_opt->FAG5_posX << " Y = " << conf_step3_opt->FAG5_posY << "\n";
		break;
	case(6):
		std::cout << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step3_opt->FAG4_name << ", coordinates: X = " << conf_step3_opt->FAG4_posX << " Y = " << conf_step3_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step3_opt->FAG5_name << ", coordinates: X = " << conf_step3_opt->FAG5_posX << " Y = " << conf_step3_opt->FAG5_posY << "\n";
		std::cout << "FAG 6, type " << conf_step3_opt->FAG6_name << ", coordinates: X = " << conf_step3_opt->FAG6_posX << " Y = " << conf_step3_opt->FAG6_posY << "\n";
		break;
	case(7):
		std::cout << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		std::cout << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		std::cout << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		std::cout << "FAG 4, type " << conf_step3_opt->FAG4_name << ", coordinates: X = " << conf_step3_opt->FAG4_posX << " Y = " << conf_step3_opt->FAG4_posY << "\n";
		std::cout << "FAG 5, type " << conf_step3_opt->FAG5_name << ", coordinates: X = " << conf_step3_opt->FAG5_posX << " Y = " << conf_step3_opt->FAG5_posY << "\n";
		std::cout << "FAG 6, type " << conf_step3_opt->FAG6_name << ", coordinates: X = " << conf_step3_opt->FAG6_posX << " Y = " << conf_step3_opt->FAG6_posY << "\n";
		std::cout << "FAG 7, type " << conf_step3_opt->FAG7_name << ", coordinates: X = " << conf_step3_opt->FAG7_posX << " Y = " << conf_step3_opt->FAG7_posY << "\n";
		break;
	}

	std::cout << "\n";
	std::cout << "The total discounted cost of the optimal configuration evolution is " << costo_opt << " Euro.\n";

	//stampa su file
	
	std::ofstream file_write;
	file_write.open("opt_cost.txt");
	file_write << costo_opt <<  " Euro";
	file_write.close();

	//std::ofstream file_write;
	file_write.open("configuration_evolution.txt");
	file_write << "The first time bucket line layout.\n ";
	file_write << "Control unit coordinates: X = " << conf_step1_opt->CU_posX << " Y = " << conf_step1_opt->CU_posY << "\n";
	file_write << "Input station coordinates: X = " << conf_step1_opt->input_posX << " Y = " << conf_step1_opt->input_posY << "\n";
	file_write << "Output station coordinates: X = " << conf_step1_opt->output_posX << " Y = " << conf_step1_opt->output_posX << "\n";
	file_write << "Handling robot coordinates: X = " << conf_step1_opt->robot_posX << " Y = " << conf_step1_opt->robot_posY << "\n";
	//quanti FAG?
	switch(conf_step1_opt->num_FAG){
	case(1):
		file_write << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		break;
	case(2):
		file_write << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		break;
	case(3):
		file_write << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		break;
	case(4):
		file_write << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step1_opt->FAG4_name << ", coordinates: X = " << conf_step1_opt->FAG4_posX << " Y = " << conf_step1_opt->FAG4_posY << "\n";
		break;
	case(5):
		file_write << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step1_opt->FAG4_name << ", coordinates: X = " << conf_step1_opt->FAG4_posX << " Y = " << conf_step1_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step1_opt->FAG5_name << ", coordinates: X = " << conf_step1_opt->FAG5_posX << " Y = " << conf_step1_opt->FAG5_posY << "\n";
		break;
	case(6):
		file_write << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step1_opt->FAG4_name << ", coordinates: X = " << conf_step1_opt->FAG4_posX << " Y = " << conf_step1_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step1_opt->FAG5_name << ", coordinates: X = " << conf_step1_opt->FAG5_posX << " Y = " << conf_step1_opt->FAG5_posY << "\n";
		file_write << "FAG 6, type " << conf_step1_opt->FAG6_name << ", coordinates: X = " << conf_step1_opt->FAG6_posX << " Y = " << conf_step1_opt->FAG6_posY << "\n";
		break;
	case(7):
		file_write << "FAG 1, type " << conf_step1_opt->FAG1_name << ", coordinates: X = " << conf_step1_opt->FAG1_posX << " Y = " << conf_step1_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step1_opt->FAG2_name << ", coordinates: X = " << conf_step1_opt->FAG2_posX << " Y = " << conf_step1_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step1_opt->FAG3_name << ", coordinates: X = " << conf_step1_opt->FAG3_posX << " Y = " << conf_step1_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step1_opt->FAG4_name << ", coordinates: X = " << conf_step1_opt->FAG4_posX << " Y = " << conf_step1_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step1_opt->FAG5_name << ", coordinates: X = " << conf_step1_opt->FAG5_posX << " Y = " << conf_step1_opt->FAG5_posY << "\n";
		file_write << "FAG 6, type " << conf_step1_opt->FAG6_name << ", coordinates: X = " << conf_step1_opt->FAG6_posX << " Y = " << conf_step1_opt->FAG6_posY << "\n";
		file_write << "FAG 7, type " << conf_step1_opt->FAG7_name << ", coordinates: X = " << conf_step1_opt->FAG7_posX << " Y = " << conf_step1_opt->FAG7_posY << "\n";
		break;
	}

	//secondo time bucket
	file_write << "\n";
	file_write << "The second time bucket line layout.\n ";
	
	file_write << "Control unit coordinates: X = " << conf_step2_opt->CU_posX << " Y = " << conf_step2_opt->CU_posY << "\n";
	file_write << "Input station coordinates: X = " << conf_step2_opt->input_posX << " Y = " << conf_step2_opt->input_posY << "\n";
	file_write << "Output station coordinates: X = " << conf_step2_opt->output_posX << " Y = " << conf_step2_opt->output_posX << "\n";
	file_write << "Handling robot coordinates: X = " << conf_step2_opt->robot_posX << " Y = " << conf_step2_opt->robot_posY << "\n";

	//quanti FAG?
	switch(conf_step2_opt->num_FAG){
	case(1):
		file_write << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		break;
	case(2):
		file_write << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		break;
	case(3):
		file_write << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		break;
	case(4):
		file_write << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step2_opt->FAG4_name << ", coordinates: X = " << conf_step2_opt->FAG4_posX << " Y = " << conf_step2_opt->FAG4_posY << "\n";
		break;
	case(5):
		file_write << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step2_opt->FAG4_name << ", coordinates: X = " << conf_step2_opt->FAG4_posX << " Y = " << conf_step2_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step2_opt->FAG5_name << ", coordinates: X = " << conf_step2_opt->FAG5_posX << " Y = " << conf_step2_opt->FAG5_posY << "\n";
		break;
	case(6):
		file_write << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step2_opt->FAG4_name << ", coordinates: X = " << conf_step2_opt->FAG4_posX << " Y = " << conf_step2_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step2_opt->FAG5_name << ", coordinates: X = " << conf_step2_opt->FAG5_posX << " Y = " << conf_step2_opt->FAG5_posY << "\n";
		file_write << "FAG 6, type " << conf_step2_opt->FAG6_name << ", coordinates: X = " << conf_step2_opt->FAG6_posX << " Y = " << conf_step2_opt->FAG6_posY << "\n";
		break;
	case(7):
		file_write << "FAG 1, type " << conf_step2_opt->FAG1_name << ", coordinates: X = " << conf_step2_opt->FAG1_posX << " Y = " << conf_step2_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step2_opt->FAG2_name << ", coordinates: X = " << conf_step2_opt->FAG2_posX << " Y = " << conf_step2_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step2_opt->FAG3_name << ", coordinates: X = " << conf_step2_opt->FAG3_posX << " Y = " << conf_step2_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step2_opt->FAG4_name << ", coordinates: X = " << conf_step2_opt->FAG4_posX << " Y = " << conf_step2_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step2_opt->FAG5_name << ", coordinates: X = " << conf_step2_opt->FAG5_posX << " Y = " << conf_step2_opt->FAG5_posY << "\n";
		file_write << "FAG 6, type " << conf_step2_opt->FAG6_name << ", coordinates: X = " << conf_step2_opt->FAG6_posX << " Y = " << conf_step2_opt->FAG6_posY << "\n";
		file_write << "FAG 7, type " << conf_step2_opt->FAG7_name << ", coordinates: X = " << conf_step2_opt->FAG7_posX << " Y = " << conf_step2_opt->FAG7_posY << "\n";
		break;
	}

	//terzo time bucket
	file_write << "\n";
	file_write << "The third time bucket line layout.\n ";
	
	file_write << "Control unit coordinates: X = " << conf_step3_opt->CU_posX << " Y = " << conf_step3_opt->CU_posY << "\n";
	file_write << "Input station coordinates: X = " << conf_step3_opt->input_posX << " Y = " << conf_step3_opt->input_posY << "\n";
	file_write << "Output station coordinates: X = " << conf_step3_opt->output_posX << " Y = " << conf_step3_opt->output_posX << "\n";
	file_write << "Handling robot coordinates: X = " << conf_step3_opt->robot_posX << " Y = " << conf_step3_opt->robot_posY << "\n";

	//quanti FAG?
	switch(conf_step3_opt->num_FAG){
	case(1):
		file_write << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		break;
	case(2):
		file_write << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		break;
	case(3):
		file_write << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		break;
	case(4):
		file_write << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step3_opt->FAG4_name << ", coordinates: X = " << conf_step3_opt->FAG4_posX << " Y = " << conf_step3_opt->FAG4_posY << "\n";
		break;
	case(5):
		file_write << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step3_opt->FAG4_name << ", coordinates: X = " << conf_step3_opt->FAG4_posX << " Y = " << conf_step3_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step3_opt->FAG5_name << ", coordinates: X = " << conf_step3_opt->FAG5_posX << " Y = " << conf_step3_opt->FAG5_posY << "\n";
		break;
	case(6):
		file_write << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step3_opt->FAG4_name << ", coordinates: X = " << conf_step3_opt->FAG4_posX << " Y = " << conf_step3_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step3_opt->FAG5_name << ", coordinates: X = " << conf_step3_opt->FAG5_posX << " Y = " << conf_step3_opt->FAG5_posY << "\n";
		file_write << "FAG 6, type " << conf_step3_opt->FAG6_name << ", coordinates: X = " << conf_step3_opt->FAG6_posX << " Y = " << conf_step3_opt->FAG6_posY << "\n";
		break;
	case(7):
		file_write << "FAG 1, type " << conf_step3_opt->FAG1_name << ", coordinates: X = " << conf_step3_opt->FAG1_posX << " Y = " << conf_step3_opt->FAG1_posY << "\n";
		file_write << "FAG 2, type " << conf_step3_opt->FAG2_name << ", coordinates: X = " << conf_step3_opt->FAG2_posX << " Y = " << conf_step3_opt->FAG2_posY << "\n";
		file_write << "FAG 3, type " << conf_step3_opt->FAG3_name << ", coordinates: X = " << conf_step3_opt->FAG3_posX << " Y = " << conf_step3_opt->FAG3_posY << "\n";
		file_write << "FAG 4, type " << conf_step3_opt->FAG4_name << ", coordinates: X = " << conf_step3_opt->FAG4_posX << " Y = " << conf_step3_opt->FAG4_posY << "\n";
		file_write << "FAG 5, type " << conf_step3_opt->FAG5_name << ", coordinates: X = " << conf_step3_opt->FAG5_posX << " Y = " << conf_step3_opt->FAG5_posY << "\n";
		file_write << "FAG 6, type " << conf_step3_opt->FAG6_name << ", coordinates: X = " << conf_step3_opt->FAG6_posX << " Y = " << conf_step3_opt->FAG6_posY << "\n";
		file_write << "FAG 7, type " << conf_step3_opt->FAG7_name << ", coordinates: X = " << conf_step3_opt->FAG7_posX << " Y = " << conf_step3_opt->FAG7_posY << "\n";
		break;
	}

	file_write.close();

}
