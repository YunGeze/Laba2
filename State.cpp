#include "State.h"

State::State()
{
	size = 0;
	bd = nullptr;
	int inp = 0,year = 0;
	bool in = true;
	std::string fio = "",name = "",surname = "", status = "";
	while (in) {
		try {
			std::cout << "Menu:\n";
			std::cout << "1.Add workers:\n";
			std::cout << "2.Delete workers:\n";
			std::cout << "3.Change data workers\n";
			std::cout << "4.Find workers\n";
			std::cout << "5.Show all workers\n";
			std::cout << "6.Exit\n";
			std::cout << "Enter command: ";
			std::cin >> inp;

			switch (inp)
			{
			case 1:
				std::cout << "\nEnter FIO: ";
				std::cout << "\nEnter name: ";
				std::cin >> name;
				std::cout << "\nEnter surname: ";
				std::cin >> surname;
				fio = surname + " " + name;
				std::cout << "\nEnter status: ";
				std::cin >> status;
				std::cout << "\nEnter year start: ";
				std::cin >> year;
				push(WORKER(fio,status,year));
				sort(bd, size);
				break;
			case 2:
				show();
				std::cout << "\nEnter deleted index: ";
				std::cin >> year;
				
				chek(year);
				bd[year].setFio("");
				sort(bd, size);
				pop();

				
				show();
				break;
			case 3:
				std::cout << "\nEnter changed index: ";
				std::cin >> inp;
				std::cout << "\nEnter FIO: ";
				std::cin >> fio;
				std::cout << "\nEnter status: ";
				std::cin >> status;
				std::cout << "\nEnter year start: ";
				std::cin >> year;

				break;
			case 4:
				find();
				break;
			case 5:
				show();
				break;
			case 6:
				in = false;
				break;
			default:
				std::cout << "\nNo find command ";
				break;
			}

		}
		catch (const char* exc) {
			std::cout << exc<<"\n";
		}
	}


}

State::~State()
{
	if (size != 0)
		delete[] bd;

}

void State::show()
{
	if (size == 0)
		throw "No WORKERS";
	std::cout << "----------------------------------\n";
	for (int i = 0; i < size; i++)
		std::cout << "[" << i << "]:\n" << bd[i];
	
	std::cout << "----------------------------------\n";

}

int State::getSize()
{
	return size;
}

void State::sort(WORKER* arr, int size)
{
	int i = 0, j = size - 1;
	WORKER x = arr[size / 2];

	do {
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j) {
			WORKER tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;


		}
	} while (i <= j);

	if (j > 0)
		sort(arr, j + 1);
	if (i < size)
		sort(&arr[i], size - i);
}

void State::find()
{
	int stage;
	std::cout << "Enter stage worker: ";
	std::cin >> stage;
	int inc = 0;
	std::cout << "----------------------------------\n";
	for (int i = 0; i < size; i++) {
		if (2021 - bd[i].getYear() >= stage) {
			std::cout << "[" << inc << "]:" << bd[i];
			inc++;
		}

	}
	if (inc == 0)
		std::cout << "No workers with this stage\n";
	std::cout << "----------------------------------\n";

}

void State::push(WORKER obj)
{
	WORKER* arr = new WORKER[size + 1];

	if (size != 0) {
		for (int i = 0; i < size; i++)
			arr[i] = bd[i];
		arr[size] = obj;
	}
	else
		arr[size] = obj;

	size++;
	WORKER* ptr = bd;
	bd = arr;
	delete[] ptr;
}

WORKER State::pop()
{
	if (size == 0)
		throw "NO WORKERS";

	WORKER w(bd[0]), * ptr = bd;
	WORKER* arr = new WORKER[size - 1];//выделили память под новый массив
	if (size == 1) {
		delete[] bd;
		bd = nullptr;
		size--;
		return WORKER(w);
	}
	for (int i = 1; i < size; i++)//начиная со второго элемента заполняем новый массив
		arr[i - 1] = bd[i];

	bd = arr;
	delete[] ptr;
	size--;
	return WORKER(w);
}

void State::chek(int& index) {

	if (index >= size)
		index = size - 1;
	else if (index < 0)
		index = 0;

}