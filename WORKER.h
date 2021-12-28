#pragma once
#include<string>
#include<iostream>
class WORKER
{
	std::string fio;
	std::string status;
	int year;

public:
	WORKER();
	WORKER(const WORKER& obj);
	WORKER(std::string fio, std::string status, int year);

	int getYear();
	std::string getFio();
	std::string getStatus();

	void setYear(int year);
	void setFio(std::string fio);
	void setStatus(std::string status);
	WORKER& operator=(const WORKER& obj);
	friend std::ostream& operator<<(std::ostream& out, const WORKER& other);
	friend bool operator<(const WORKER& ob1, const WORKER& ob2);
	friend bool operator>(const WORKER& ob1, const WORKER& ob2);
	friend bool operator==(const WORKER& ob1, const WORKER& ob2);
	friend bool operator!=(const WORKER& ob1, const WORKER& ob2);

};

