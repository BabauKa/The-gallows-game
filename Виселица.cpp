﻿#include <Windows.h>
#include <iostream>
#include <string>		// Для слов
#include <cstdlib>		// Функции srand() и rand()
#include <ctime>		// Функция time()
using namespace std;

/*
	1. Вывод сообщения, которое приветстует игрока и рассказывает поэтапно правила
	2. Предлагает игроку ввести свое имя
	3. Загадывается слово для игры
	4. Начало игры. Визуальное представление о слове
	5. Ввод попыток игрока
	6. Результат (Победа/поражение)
	7. Статистика
*/

void welcomeMessage()
{
	cout << "* * * * * * * * * * * * * * * * * * * *\n";
	cout << "* Добро пожаловать в игру Виселица!\n";
	cout << "* \n";
	cout << "* Вам предстоит угадать загаданное слово за 10 попыток,\n";
	cout << "* После чего игра будет окончена!\n";
	cout << "* \n";
	cout << "* Удачи и веселой игры!\n";
	cout << "* * * * * * * * * * * * * * * * * * * *\n";
}

string inputName()
{
	cout << "Введите ваше имя: ";
	string name;
	getline(cin, name);
	return name;
}

void choiceWord()
{
	// Список случайных слов
	string wordsForGame[] = {"бобер", "крановщик", "кровать", "маска", "растение"};

	// Размер массива
	int sizeArray = sizeof(wordsForGame) / sizeof(wordsForGame[0]);

	// Выбор слова
	int indexWord = (rand() % sizeArray + 1);
	string *selectedWord = new string[indexWord];
	cout << "Я скушал байт: " << sizeof(selectedWord[indexWord]) << "\n";
	cout << *selectedWord;
	delete[] selectedWord;

	// Вывод количества букв
	/*for (int count = 1; count <= indexWord; count++)
	{

	}*/
}

int main()
{
	// setlocale(LC_ALL, "russian");
	// Кодировка кириллицы для консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//
	//srand(static_cast<unsigned int>(time(0)));
	//string name = inputName();
	//cout << name << endl;
	//welcomeMessage();
	choiceWord();
	return 0;
}