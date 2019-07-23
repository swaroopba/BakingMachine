#pragma once
#include<iostream>
#include<string>
using namespace std;
class items
{
	string *ingredients;
	float *quantity;
	float bake_temp;
	float bake_time;
	float calories;
	float cost;


public:
	items();
	~items();
	float get_time();
	float get_temp();
	float* get_quantity();
	//string * get_ingredients();
	void set_calories(float val);
	void set_cost(float rate);
	//string get_ingredient(int);
	//float get_quan(int i);



};

