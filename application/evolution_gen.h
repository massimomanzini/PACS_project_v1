#ifndef EVOLUTION_GENERATION_H
#define EVOLUTION_GENERATION_H

void evolution_gen_v0(std::vector<int> conf_evo, std::vector<std::vector<double>> &performances, equipment set_equipment[], miscellaneous *misc_data, std::vector<std::vector<configuration>> &set_configurations, std::vector<scenario> set_evolutions);
void evolution_gen_v1(std::vector <scenario_node> set_scenarios, std::vector<performances> &performances_1, std::vector<performances> &performances_2, std::vector<performances> &performances_3, equipment set_equipment[], miscellaneous *misc_data, std::vector<configuration> configurations_new_1, std::vector<configuration> &configurations_new_2, std::vector<configuration> &configurations_new_3, std::vector<scenario> set_evolutions, configuration *conf_step1_opt, configuration *conf_step2_opt, configuration *conf_step3_opt, double &costo_opt);

void evolution_trial(std::vector<std::vector<configuration>> &set_configurations, std::vector<configuration> &configurations_new_1);
void evolution_trial_2(std::vector<performances> &performances_1);

#endif