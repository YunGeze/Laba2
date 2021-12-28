// YanGez2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"State.h"
#include "FindText.h"
int main()
{
    setlocale(LC_ALL, "rus");
    bool in = true;
    int choose = 0;
    while (in) {
        std::cout << "Main menu:\n";
        std::cout << "1.First\n";
        std::cout << "2.Second\n";
        std::cout << "3.Exit\n";
        std::cout << "Choose: ";
        std::cin >> choose;
        if (choose == 1)
            State b;
        else if (choose == 2)
            FindText f;
        else if (choose == 3)
            in = false;
        else
            std::cout << "\nNo find command ";
            
    }

}

