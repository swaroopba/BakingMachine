#include<iostream>
#include<string>
#include<conio.h>
#include "baking_machine.h"
#include "OrderItems.h"
using namespace std;

int main() {
	int ch;
	baking_machine bm;
	bm.acceptInput();
	
	cout << "Enter 1 for customers to order pizzas\n";
	cin >> ch;
	if (ch == 1) {
		OrderItems o;
		o.orderItems();
	}

	_getch();
	return 0;
}