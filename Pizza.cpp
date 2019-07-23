#include "Pizza.h"

int Pizza::getnum() {
	return this->num_of_ingredients;
}

string Pizza::get_ingredient(int i) {
	return this->ingredients[i];
}

string* Pizza::get_ingredients() {
	return this->ingredients;
}

float Pizza::get_quan(int i) {
	return this->quantity[i];
}

Pizza::Pizza()
{
}


Pizza::~Pizza()
{
}
