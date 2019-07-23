#pragma once
#include "items.h"
class Pizza :
	public items
{
	int num_of_ingredients = 4;
	string ingredients[4] = { "oil","sugar","floor","cheese" };
	float quantity[4] = { 0.04f,0.01f,0.1f,0.05f };
	float bake_time = 30;
	float bake_temp = 80;
	float cost;
	float calories;

public:
	int getnum();
	string get_ingredient(int);
	string* get_ingredients();
	float get_quan(int);
	Pizza();
	~Pizza();
};

