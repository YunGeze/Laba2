#pragma once
#include"WORKER.h"
class State
{

	WORKER* bd;
	int size;
public:
	State();
	~State();
	void show();
	int getSize();
	void chek(int& index);
	void sort(WORKER* arr, int size);
	void find();
	void push(WORKER obj);
	WORKER pop();

};

