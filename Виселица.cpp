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
	6. Результат (Победа/поражение) (todo)
	7. Статистика (todo)
	8. Выбор уровня сложности (todo)
*/

void welcomeMessage()
{
	cout << "* * * * * * * * * * * * * * * * * * * *\n";
	cout << "* Добро пожаловать в игру Виселица!\n";
	cout << "* \n";
	cout << "* Вам предстоит угадать загаданное слово за 10 попыток,\n";
	cout << "* После чего игра будет окончена! (В данной версии попыток неограниченно!)\n";
	cout << "*\n";
	cout << "* Если вы захотите досрочно завершить игру, то введите следующий символ - 0 (нолик)\n";
	cout << "*\n";
	cout << "* Правила:";
	cout << "* Дано случайно слово, которое побуквенно отображается у игрока на экране\n";
	cout << "* С каждой угаданной буквой будет уменьшаться все неизвестные\n";
	cout << "* Условие победы выполнится тогда, когда все буквы будут угаданы!\n";
	cout << "* \n";
	cout << "* Удачи и веселой игры!\n";
	cout << "* * * * * * * * * * * * * * * * * * * *\n";
}

//string inputName()
//{
//	cout << "Введите ваше имя: ";
//	string name;
//	getline(cin, name);
//	return name;
//}

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

	// Пока количество символов в угадываемом слове будет больше 0
	while (remainingLetters > 0)
	{
		cin >> inputUser;
		cout << "\n";

		// Проверка пользовательского ввода
		if (inputUser.size() > 1)
		{
			cout << "\033[31;1mОШИБКА! Нельзя вводить больше 1 символа!\nПовторите ввод!\n \033[0m";
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
				}
			}
		}
	}

	cout << "\n";
	cout << "Вы победили! Было выбранно слово: \033[32;1m" << currentWord << "\n \033[0m";
}

int main()
{
	// Кодировка кириллицы для консоли
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//
	srand(static_cast<unsigned int>(time(0)));
	welcomeMessage();
	game();
	return 0;
}