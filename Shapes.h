#pragma once
#include<iostream>
#include<string>
#include<conio.h>


using namespace std;

class Shapes
{

	//various available shapes
	string shape[5] = { "circular","star","square","rectangular","diamond" };
	//wastages for each shape
	float wastage[5] = { 0.01f,0.05f,0.01f,0.01f,0.05f };
	//extra percentage added for each shape
	float extra[5] = { 0.1f,0.25f,0.15f,0.1f,0.45f };


public:
	string getshape(int i);
	float getwastage(int i);
	float getextra(int i);
	Shapes();
	~Shapes();


};

