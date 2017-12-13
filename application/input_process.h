#ifndef INPUT_PROCESS_H
#define INPUT_PROCESS_H

void input_miscellaneous(char filename[], miscellaneous *misc_data);
void input_scenarionodes_1(miscellaneous *misc_data, scenario_node set_scenarios[]);

void input_scenarios_2(miscellaneous *misc_data, std::vector<scenario_node> &set_scenarios);
void input_scenarios_3(miscellaneous *misc_data, std::vector<scenario_node> &set_scenarios);

void input_scenario_evo(miscellaneous *misc_data, scenario set_evolutions[]);
void input_scenario_evo_1(miscellaneous *misc_data, std::vector<scenario> &set_evolutions);

void input_products(miscellaneous *misc_data, product set_product[]);
void input_products_1(miscellaneous *misc_data, std::vector<product> &set_products);

void input_equipment(miscellaneous *misc_data, equipment set_equipment[]);


#endif