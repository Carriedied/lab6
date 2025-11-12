#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdexcept>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();

int main()
{
	setlocale(LC_ALL, "Russian");

    try 
    {
       cout << "=== Задание 1 ===" << std::endl;

       task1();
       
       cout << "\n=== Задание 2 ===" << std::endl;
       
       task2();
       
       cout << "\n=== Задание 3 ===" << std::endl;
       
       task3();

       cout << "\n=== Задание 4 ===" << std::endl;

       task4();

       cout << "\n=== Задание 5 ===" << std::endl;

       task5();
    }
    catch (const std::exception& e) 
    {
        cerr << "Ошибка: " << e.what() << endl;

        return 1;
    }
}

void task1() 
{
    int n, m;

    cout << "Введите количество четных чисел для записи (n): ";
    cin >> n;

    if (n <= 0) 
    {
        cout << "Количество чисел должно быть положительным." << endl;

        return;
    }

    ofstream outFile("task1.txt");

    if (!outFile.is_open())
    {
        throw std::runtime_error("Не удалось открыть файл для записи.");
    }

    for (int i = 1; i <= n; ++i) 
    {
        outFile << (2 * i) << " ";
    }

    outFile.close();

    cout << "Введите количество чисел для чтения (m): ";
    cin >> m;

    if (m <= 0) 
    {
        cout << "Количество чисел для чтения должно быть положительным." << endl;

        return;
    }

    if (m > n) 
    {
        cout << "Количество чисел для чтения больше, чем записано. Будет прочитано " << n << " чисел." << endl;

        m = n;
    }

    ifstream inFile("task1.txt");

    if (!inFile.is_open()) 
    {
        throw runtime_error("Не удалось открыть файл для чтения.");
    }

    cout << "Прочитанные числа: ";

    int num;

    for (int i = 0; i < m; ++i) 
    {
        if (inFile >> num) 
        {
            cout << num << " ";
        }
    }

    cout << std::endl;

    inFile.close();
}

void task2() 
{
    ofstream outFile("task2.txt");

    if (!outFile.is_open()) 
    {
        throw runtime_error("Не удалось открыть файл для записи.");
    }

    outFile << "1 2 3 4 5 6 7 8 9 10 -2 -4 11 12";
    outFile.close();

    ifstream inFile("task2.txt");

    if (!inFile.is_open()) 
    {
        throw runtime_error("Не удалось открыть файл для чтения.");
    }

    int sum = 0;

    int num;

    while (inFile >> num) 
    {
        if (num % 2 == 0) 
        {
            sum += num;
        }
    }

    inFile.close();

    cout << "Сумма четных чисел: " << sum << endl;
}

void task3() 
{
    ofstream outFile("task3.txt");

    if (!outFile.is_open()) 
    {
        throw runtime_error("Не удалось открыть файл для записи.");
    }

    outFile << "-5 10 3 -2 0 7 1 -1 15";
    outFile.close();

    ifstream inFile("task3.txt");

    if (!inFile.is_open()) 
    {
        throw std::runtime_error("Не удалось открыть файл для чтения.");
    }

    int minPositive = 0;
    bool found = false;
    int num;

    while (inFile >> num) 
    {
        if (num > 0) 
        {
            if (!found || num < minPositive) 
            {
                minPositive = num;
                found = true;
            }
        }
    }

    inFile.close();

    if (found) 
    {
        cout << "Минимальное положительное число: " << minPositive << endl;
    }
    else 
    {
        cout << "Положительных чисел не найдено." << endl;
    }
}

void task4() 
{
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -2, -4, 11, 12 };
    ofstream outFile("task4.bin", ios::binary);

    if (!outFile.is_open()) 
    {
        throw runtime_error("Не удалось открыть бинарный файл для записи.");
    }

    outFile.write(reinterpret_cast<const char*>(numbers.data()), numbers.size() * sizeof(int));
    outFile.close();

    ifstream inFile("task4.bin", ios::binary);

    if (!inFile.is_open()) 
    {
        throw std::runtime_error("Не удалось открыть бинарный файл для чтения.");
    }

    int sum = 0;
    int num;

    while (inFile.read(reinterpret_cast<char*>(&num), sizeof(int))) 
    {
        if (num % 2 == 0) 
        {
            sum += num;
        }
    }

    inFile.close();

    cout << "Сумма четных чисел из бинарного файла: " << sum << endl;
}

void task5() 
{
    vector<int> numbers = { -5, 10, 3, -2, 0, 7, 1, -1, 15 };
    ofstream outFile("task5.bin", std::ios::binary);

    if (!outFile.is_open()) 
    {
        throw runtime_error("Не удалось открыть бинарный файл для записи.");
    }

    outFile.write(reinterpret_cast<const char*>(numbers.data()), numbers.size() * sizeof(int));
    outFile.close();

    ifstream inFile("task5.bin", ios::binary);

    if (!inFile.is_open()) 
    {
        throw runtime_error("Не удалось открыть бинарный файл для чтения.");
    }

    int minPositive = 0;
    bool found = false;
    int num;

    while (inFile.read(reinterpret_cast<char*>(&num), sizeof(int))) 
    {
        if (num > 0) 
        {
            if (!found || num < minPositive) 
            {
                minPositive = num;
                found = true;
            }
        }
    }

    inFile.close();

    if (found) 
    {
        cout << "Минимальное положительное число из бинарного файла: " << minPositive << endl;
    }
    else 
    {
        cout << "Положительных чисел не найдено." << endl;
    }
}
