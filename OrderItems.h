#pragma once
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class OrderItems
{
	int totaldest = 6;
	string destination[6] = { "A","B","C","D","E","F" };
	const int traveltime[6] = { 12,5,7,10,4,10 };


	
public:
	void orderItems();
	OrderItems();
	~OrderItems();
};

