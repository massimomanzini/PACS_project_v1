#ifndef DATAINPUT_H
#define DATAINPUT_H

/*enum FAGtype {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};			//serie di FAG, includi track e I/O e CU (1-10)

tolgo la definizione di questo FAGtype, perchè mi da errore sull'enum
sarà mio dovere, quando faccio input dati, fare un check sul FAGtype:
- che sia compreso in questi 10 
- che sia uguale a 1, ove necessario

/*
1: 7-axis robot (for which 1 is the minimum value allowed);
2: control unit (for which 1 is the only allowed value);
3: output station (for which 1 is the only allowed value);
4: input station, turning table (for which 1 is the only allowed value);
5: mechanical joining;
6: resistance joining;
7: MIG joining;
8: adhesive joining;
9: hemming;
10: manual operations;
11: other;
*/

//enum distribution_type {exponential, erlang};

struct equipment {
	int FAG;				//FAG type forom the enumeration (they have a char name)
	//questo FAG deve essere compreso tra 1 e 10 secondo le direttive espresse sopra
	int x;						//x axes dimention in [mm]
	int y;						//x axes dimention in [mm]
	double fail_rate;			//failure rate
	double rep_rate;			//repair rate
	int cost;					//investment cost in [€]

};

//assuption, each scenario can have 3 levels maximum


//assumption, each scenario can have 4 product maximum in its demand
//occhio a nome prodotto, è un char (traduzione int?)
struct scenario_node{
	int name;
	int tnode;
	//tnode è il timeline dello scenario, compreso tra 1 e 3, che ho commentato sopra
	int num_prod;
	int name_1;
	int demand_1;
	int name_2;
	int demand_2;
	int name_3;
	int demand_3;
	int name_4;
	int demand_4;
};

//assuption, each scenario can have 3 levels maximum
struct scenario {
	int step1_name;
	int step2_name;
	int step3_name;
	double occur_prob;
};

//assumption, each product assembly process is 3 steps longer
struct product{
	int name;						//product ID
	int step1_FAG;					//FAG used for the first step
	double step1_prodrate;			//production TIME for the first step (1/time for the operation)
	int step2_FAG;					//FAG used for the second step
	double step2_prodrate;			//production TIME for the second step (1/time for the operation)
	int step3_FAG;				
	double step3_prodrate;			
};

//set of miscellanous cost and information

// insieme a queste info devo includere anche la numerosità dei miei input
//così da poter creare immediatamente le mie strutture dati con l'esatta numerosità

struct miscellaneous{	
	int num_scenario;
	int num_scenarionodes;
	int num_products;
	int op_cost;
	int rec_cost;
	int rec_time;
	double robot_speed;
	double input_time;
	double output_time;
	int time_available; //in ore
	double cost_track; //cost of a mm of track
	double k_attualizzazione;
};


struct configuration{
	//numero FAG max è 7 (dal 5 al 11)
	//ma può variare in base al numero di FAG richiesti dalla produzione
	int num_FAG;

	int FAG1_name;
	int FAG1_posX;
	int FAG1_posY;

	int FAG2_name;
	int FAG2_posX;
	int FAG2_posY;

	int FAG3_name;
	int FAG3_posX;
	int FAG3_posY;

	int FAG4_name;
	int FAG4_posX;
	int FAG4_posY;

	int FAG5_name;
	int FAG5_posX;
	int FAG5_posY;

	int FAG6_name;
	int FAG6_posX;
	int FAG6_posY;

	int FAG7_name;
	int FAG7_posX;
	int FAG7_posY;

	//e poi tutti gli equipment fissi
	int robot_posX;
	int robot_posY;
	double time_transport;

	int CU_posX;
	int CU_posY;
	int input_posX;
	int input_posY;
	int output_posX;
	int output_posY;
};

struct performances{
	double prod_1;
	double prod_2;
	double prod_3;
	double prod_4;
};

#endif