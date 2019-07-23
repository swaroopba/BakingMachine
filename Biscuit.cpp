#include "Biscuit.h"

int Biscuit::getnum() {
	return num_of_ingredients;
}

string Biscuit::get_ingredient(int i) {
	return this->ingredients[i];
}

string* Biscuit::get_ingredients() {
	return this->ingredients;
}

float Biscuit::get_quan(int i) {
	return this->quantity[i];
}

Biscuit::Biscuit()
{
}


Biscuit::~Biscuit()
{
}
