#include "Cake.h"

int Cake::getnum() {
	return this->num_of_ingredients;
}
string Cake::get_ingredient(int i) {
	return this->ingredients[i];
}


float Cake::get_quan(int i) {
	return this->quantity[i];
}

string* Cake::get_ingredients() {
	return this->ingredients;
}

Cake::Cake()
{
}


Cake::~Cake()
{
}
