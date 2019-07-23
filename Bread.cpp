#include "Bread.h"

int Bread::getnum() {
	return this->num_of_ingredients;
}
string Bread::get_ingredient(int i) {
	return this->ingredients[i];
}

string* Bread::get_ingredients() {
	return this->ingredients;
}

float Bread::get_quan(int i) {
	return this->quantity[i];
}
Bread::Bread()
{
}


Bread::~Bread()
{
}
