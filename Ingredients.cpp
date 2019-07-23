#include "Ingredients.h"

Ingredients::Ingredients()
{
}


Ingredients::~Ingredients()
{
}


float Ingredients::getcalories(string a) {
	int i;
	for (i = 0; i < number_of_items; i++) {
		if (itemlist[i] == a) {
			return calories[i];
		}
	}
	return 0;
}

int Ingredients::getcost(string a) {
	int i;
	for (i = 0; i < number_of_items; i++) {
		if (itemlist[i] == a) {
			return (int)(cost[i]);
		}
	}
	return 0;
}

string Ingredients::getitem(int i) {
	return itemlist[i];
}


