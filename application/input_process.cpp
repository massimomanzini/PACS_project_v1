#include "stdafx.h"
#include "data_input.h"
#include "input_process.h"
#include <vector>


using namespace std;


void input_miscellaneous(char filename[], miscellaneous *misc_data){

	ifstream myfile;
	myfile.open(filename);
	if (myfile.is_open()){
		myfile >> misc_data->num_scenario >> misc_data->num_scenarionodes >> misc_data->num_products >> misc_data->op_cost >> misc_data->rec_cost >> misc_data->rec_time >> misc_data->robot_speed >> misc_data->input_time >> misc_data->output_time >> misc_data->time_available >> misc_data->cost_track >> misc_data->k_attualizzazione;
		myfile.close();
	}
	else cout << "Unable to open file";
}

//dopo questo, nel main, ci sono da creare le variabili per gli input veri e propri

void input_scenarionodes_1(miscellaneous *misc_data, scenario_node set_scenarios[]){
	

	for(int a = 0; a < misc_data->num_scenarionodes; a++) {

		std::stringstream temp_name;
		temp_name << "input/scenarionode_" << a+1 <<".txt";
		std::string namefile = temp_name.str();
		temp_name.clear();

		ifstream myfile;
		myfile.open(namefile);

		if (myfile.is_open()){

			myfile >> set_scenarios[a].name >> set_scenarios[a].tnode >> set_scenarios[a].num_prod;

			switch(set_scenarios[a].num_prod){
			case(1):
				myfile >> set_scenarios[a].demand_1;
				break;
			case(2):
				myfile >> set_scenarios[a].demand_1 >> set_scenarios[a].demand_2;
				//std::cout << "eccoci! \n";
				break;
			case(3):
				myfile >> set_scenarios[a].demand_1 >> set_scenarios[a].demand_2 >> set_scenarios[a].demand_3;
				break;
			case(4):
				myfile >>  set_scenarios[a].demand_1 >> set_scenarios[a].demand_2 >> set_scenarios[a].demand_3 >> set_scenarios[a].demand_4;
				break;
			default:
				cout << "An error happened somewhere! \n"; //error!
			}
			myfile.close();
		}
		else cout << "Unable to open file " << namefile << "!\n";
	}
}

void input_scenarios_2(miscellaneous *misc_data, std::vector<scenario_node> &set_scenarios){

	for(int a = 0; a < misc_data->num_scenarionodes; a++) {

		set_scenarios.push_back(scenario_node());

		std::stringstream temp_name;
		temp_name << "input/scenarionode_" << a+1 <<".txt";
		std::string namefile = temp_name.str();
		temp_name.clear();

		ifstream myfile;
		myfile.open(namefile);

		if (myfile.is_open()){

			myfile >> set_scenarios[a].name >> set_scenarios[a].tnode >> set_scenarios[a].num_prod;

			switch(set_scenarios[a].num_prod){
			case(1):
				myfile >> set_scenarios[a].name_1 >> set_scenarios[a].demand_1;
				break;
			case(2):
				myfile >> set_scenarios[a].name_1 >> set_scenarios[a].demand_1 >> set_scenarios[a].name_2 >> set_scenarios[a].demand_2;
				break;
			case(3):
				myfile >> set_scenarios[a].name_1 >> set_scenarios[a].demand_1 >> set_scenarios[a].name_2 >> set_scenarios[a].demand_2 >> set_scenarios[a].name_3 >> set_scenarios[a].demand_3;
				break;
			case(4):
				myfile >> set_scenarios[a].name_1 >> set_scenarios[a].demand_1 >> set_scenarios[a].name_2 >> set_scenarios[a].demand_2 >> set_scenarios[a].name_3 >> set_scenarios[a].demand_3 >> set_scenarios[a].name_4 >> set_scenarios[a].demand_4;
				break;
			default:
				cout << "An error happened somewhere! \n"; //error!
			}
			myfile.close();
		}
		else cout << "Unable to open file " << namefile << "!\n";
	}
}

void input_scenarios_3(miscellaneous *misc_data, std::vector<scenario_node> &set_scenarios){

	int nome_temporaneo;
	int temp_demand;

	for(int a = 0; a < misc_data->num_scenarionodes; a++) {

		set_scenarios.push_back(scenario_node());

		std::stringstream temp_name;
		temp_name << "input/scenarionode_" << a+1 <<".txt";
		std::string namefile = temp_name.str();
		temp_name.clear();

		ifstream myfile;
		myfile.open(namefile);

		if (myfile.is_open()){

			myfile >> set_scenarios[a].name >> set_scenarios[a].tnode >> set_scenarios[a].num_prod;

			for(int i=0; i<set_scenarios[a].num_prod; i++){
				nome_temporaneo = -1;
				temp_demand = -1;

				myfile >> nome_temporaneo >> temp_demand;

				//vado ad allocare questi dati
				//così facendo demand_1 sarà relativa a prodotto denominato 1 e via così
				//in questo modo ho allineamento con vettori perfomances
				switch(nome_temporaneo){
				case(1):
					set_scenarios[a].name_1 = nome_temporaneo;
					set_scenarios[a].demand_1 = temp_demand;
					break;
				case(2):
					set_scenarios[a].name_2 = nome_temporaneo;
					set_scenarios[a].demand_2 = temp_demand;
					break;
				case(3):
					set_scenarios[a].name_3 = nome_temporaneo;
					set_scenarios[a].demand_3 = temp_demand;
					break;
				case(4):
					set_scenarios[a].name_4 = nome_temporaneo;
					set_scenarios[a].demand_4 = temp_demand;
					break;
				default:
				cout << "An error happened somewhere! \n"; //error!
				}
			}
			myfile.close();
		}
		else cout << "Unable to open file " << namefile << "!\n";
	}
}

void input_scenario_evo(miscellaneous *misc_data, scenario set_evolutions[]){
	//non è un void ma da in output lo struct set_scenarios
	string namefile;
	set_evolutions = new scenario[misc_data->num_scenario];

	for(int a = 0; a < misc_data->num_scenario; a++) {
	

		std::stringstream temp_name;
		temp_name << "input/scenario_" << a+1 <<".txt";
		std::string namefile = temp_name.str();
		temp_name.clear();

		ifstream myfile;
		myfile.open(namefile);

		if (myfile.is_open()){
			//std::cout << namefile << " has been opened! \n";
			myfile >> set_evolutions[a].step1_name >> set_evolutions[a].step2_name >> set_evolutions[a].step3_name >> set_evolutions[a].occur_prob;
			myfile.close();
		}
		else cout << "Unable to open file "<< namefile <<"!\n";
	}
}

void input_scenario_evo_1(miscellaneous *misc_data, std::vector<scenario> &set_evolutions){
	string namefile;

	for(int a = 0; a < misc_data->num_scenario; a++) {
	
		set_evolutions.push_back(scenario());

		std::stringstream temp_name;
		temp_name << "input/scenario_" << a+1 <<".txt";
		std::string namefile = temp_name.str();
		temp_name.clear();

		ifstream myfile;
		myfile.open(namefile);

		if (myfile.is_open()){
			myfile >> set_evolutions[a].step1_name >> set_evolutions[a].step2_name >> set_evolutions[a].step3_name >> set_evolutions[a].occur_prob;
			myfile.close();
		}
		else cout << "Unable to open file "<< namefile <<"!\n";
	}



}

void input_products(miscellaneous *misc_data, product set_products[]){
	//non è un void ma da in output lo struct set_prod
	//sistemare void e mettere il return alla fine
	string namefile;
	set_products = new product[misc_data->num_products];

	for(int a = 0; a < misc_data-> num_products; a++) {
	
		std::stringstream temp_name;
		temp_name << "input/product_" <<a+1 << ".txt";
		std::string namefile = temp_name.str();
		temp_name.clear();

		ifstream myfile;
		myfile.open(namefile);

		if (myfile.is_open()){
			//std::cout << namefile << " has been opened!\n";
			myfile >> set_products[a].name >> set_products[a].step1_FAG >> set_products[a].step1_prodrate >> set_products[a].step2_FAG >> set_products[a].step2_prodrate >> set_products[a].step3_FAG >> set_products[a].step3_prodrate;
			myfile.close();
		}
		else cout << "Unable to open file " << namefile <<"!\n";
	}
}

void input_products_1(miscellaneous *misc_data, std::vector<product> &set_products){

	string namefile;

	for(int a = 0; a < misc_data-> num_products; a++) {
		
		set_products.push_back(product());

		std::stringstream temp_name;
		temp_name << "input/product_" <<a+1 << ".txt";
		std::string namefile = temp_name.str();
		temp_name.clear();

		ifstream myfile;
		myfile.open(namefile);

		if (myfile.is_open()){
			//std::cout << namefile << " has been opened!\n";
			myfile >> set_products[a].name >> set_products[a].step1_FAG >> set_products[a].step1_prodrate >> set_products[a].step2_FAG >> set_products[a].step2_prodrate >> set_products[a].step3_FAG >> set_products[a].step3_prodrate;
			myfile.close();
		}
		else cout << "Unable to open file " << namefile <<"!\n";
	}


}

void input_equipment(miscellaneous *misc_data, equipment set_equipment[]){

	string namefile;

	for(int a = 0; a < 11; a++) {

		std::stringstream temp_name;
		temp_name << "input/equipment_" << a+1 << ".txt";
		std::string namefile = temp_name.str();
		temp_name.clear();

		ifstream myfile;
		myfile.open(namefile);

		if (myfile.is_open()){

			myfile >> set_equipment[a].FAG >> set_equipment[a].x >> set_equipment[a].y >> set_equipment[a].fail_rate >> set_equipment[a].rep_rate >> set_equipment[a].cost;
			myfile.close();
		}
		else cout << "Unable to open file!\n";
	}
}





		