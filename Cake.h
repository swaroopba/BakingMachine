#pragma once
#include "items.h"
class Cake :
	public items
{
	int num_of_ingredients = 5;
	string ingredients[5] = { "oil","sugar","floor","nuts","cream" };
	float quantity[5] = { 0.01f,0.02f,0.05f,0.01f,0.5f };
	float bake_time = 30;
	float bake_temp = 80;
	float cost;
	float calories;



public:
	int getnum();
	string get_ingredient(int);
	string* get_ingredients();
	float get_quan(int);
	Cake();
	~Cake();
};

