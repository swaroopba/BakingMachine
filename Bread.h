#pragma once
#include "items.h"
class Bread :
	public items
{
	int num_of_ingredients = 4;
	string ingredients[4] = { "oil","sugar","floor","baking_soda" };
	float quantity[4] = { 0.02f,0.03f,0.07f,0.01f };
	float bake_time = 30;
	float bake_temp = 100;
	float cost;
	float calories;


public:
	int getnum();
	string* get_ingredients();
	string get_ingredient(int);
	float get_quan(int);
	Bread();
	~Bread();
};

