#pragma once
#include "Biscuit.h"
#include "Bread.h"
#include "Cake.h"
#include "Pizza.h"

class baking_machine:
	public Biscuit, Bread, Cake, Pizza
{
	int n;
	string *inpData;
	float *inpQuantity;
	float avail_temp;
	float avail_time;

public:
	void acceptInput();
	string* getInput();
	int getN();
	float* getQuan();
	string* calculate_shape(string*);
	void checkProducts(string*, int);
	float calculate_price(string *a, string b, int n);
	void calculateCalories(string *a, int n, int num);
	void calculate_quantity(float *inp);

	baking_machine();
	~baking_machine();
};

