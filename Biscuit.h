#pragma once
#include "items.h"
class Biscuit :
	public items
{
	int num_of_ingredients = 4;
	string ingredients[4] = { "oil","sugar","floor","nuts" };
	float quantity[4] = { 0.01f,0.02f,0.05f,0.01f };
	float bake_time = 50;
	float bake_temp = 100;
	float cost;
	float calories;
public:
	string * get_ingredients();
	int getnum();
	string get_ingredient(int);
	float get_quan(int);
	Biscuit();
	~Biscuit();
};

