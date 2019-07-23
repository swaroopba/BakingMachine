#pragma once
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;



class Ingredients
{
	int number_of_items = 7;
	string itemlist[7] = { "oil","sugar","floor","nuts" ,"baking_soda","cream","cheese" };
	float calories[7] = { 300,200,100,100,50,500,400 };
	float cost[7] = { 10,12,8,15,4,12,13 };

public:
	string getitem(int i);
	float getcalories(string);
	int getcost(string);
	Ingredients();
	~Ingredients();
};

