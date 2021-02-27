#include <Windows.h>
#include <iostream>
#include <string>		// Для слов
#include <cstdlib>		// Функции srand() и rand()
#include <ctime>		// Функция time()
#include <vector>		// Использование векторных массовов
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

string choiceWord()
{
	// Список случайных слов для игры
	string wordsForGame[] = { "бобер", "крановщик", "кровать", "маска", "растение", "творог", "автомобиль", "автомагистраль", "кратер" };

	// Размер массива случайных слов
	int sizeArray = sizeof(wordsForGame) / sizeof(wordsForGame[0]);

	// Выбор слова
	int indexWord = (rand() % sizeArray);
	string currentWord = wordsForGame[indexWord];

	return currentWord;
}

void game()
{
	vector<string> answerArray;						// Массив букв 
	string currentWord = choiceWord();				// Текущее слово
	int remainingLetters = currentWord.size();		// Размер загаданного слова
	string inputUser;								// Пользовательский ввод
	string nolik = "0";								// Шуточка переменная =)

	// Заполнение массива элементов нижнее подчеркивание "_"
	for (int count = 0; count < remainingLetters; count++)
		answerArray.push_back("_");
		// Вывод элементов массива
		for (auto const element : answerArray)
			cout << element << ' ';
	cout << "\n";

	while (remainingLetters > 0)
	{
		cin >> inputUser;

		// Проверка пользовательского ввода
		if (inputUser.size() > 1)
		{
			cout << "ОШИБКА!\n";
		}
		else if (inputUser == nolik)
		{
			cout << "Игра досрочно завершена!\n";
			break;
		}
		else
		{
			for (int count = 0; count < answerArray.size(); count++)
			{
				if (string(1, currentWord[count]) == inputUser)
				{
					answerArray[count] = inputUser;
					for (auto element : answerArray)
						cout << element << ' ';
					remainingLetters--;
					cout << remainingLetters << " <- количество символов оствлось\n";
				}
			}
		}
	}


	cout << "ФУНКЦИЯ GAME: " << currentWord;
}

int main()
{
	// setlocale(LC_ALL, "russian");
	// Кодировка кириллицы для консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//
	srand(static_cast<unsigned int>(time(0)));
	//string name = inputName();
	//cout << name << endl;
	//welcomeMessage();
	game();
	return 0;
}