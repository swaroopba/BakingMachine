#include "items.h"

float items::get_temp() {
	return this->bake_temp;
}

float items::get_time() {
	return this->bake_time;
}

/*
string* items::get_ingredients() {
	return this->ingredients;
}
*/

float* items::get_quantity() {
	return this->quantity;
}

void items::set_calories(float value) {
	this->calories = value;
}

void items::set_cost(float rate) {
	this->cost = rate;
}

/*
string items::get_ingredient(int i) {
	return this->ingredients[i];
}


float items::get_quan(int i) {
	return this->quantity[i];
}
*/
items::items()
{
}


items::~items()
{
}
