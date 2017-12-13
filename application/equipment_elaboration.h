#ifndef EQUIPMENT_ELAB_H
#define EQUIPMENT_ELAB_H

//**int equipment_elaboration(miscellaneous *misc_data,  scenario_node set_scenarios[], product set_products[]);
//int equipment_elaboration(miscellaneous *misc_data,  scenario_node set_scenarios[], product set_products[]);
void equipment_elaboration(int *i, miscellaneous *misc_data,  scenario_node set_scenarios[], product set_products[], int *equipment_matrix[]);
void equipment_elaboration_1(std::vector<std::vector<int>> &equipment_matrix, miscellaneous *misc_data, std::vector<scenario_node> &set_scenarios, std::vector<product> &set_products);
void equipment_elaboration_2(std::vector<std::vector<int>> &equipment_matrix, miscellaneous *misc_data, std::vector<scenario_node> &set_scenarios, std::vector<product> &set_products);

#endif