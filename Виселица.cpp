#include <Windows.h>
#include <iostream>
#include <string>		// Для слов
#include <cstdlib>		// Функции srand() и rand()
#include <ctime>		// Функция time()
#include <vector>
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
	string wordsForGame[] = { "бобер", "крановщик", "кровать", "маска", "растение", "творог", "автомобиль", "автомагистраль" };

	// Размер массива случайных слов
	int sizeArray = sizeof(wordsForGame) / sizeof(wordsForGame[0]);

	// Выбор слова
	int indexWord = (rand() % sizeArray);
	string currentWord = wordsForGame[indexWord];

	// Размер выбранного слова
	int currentSize = currentWord.length();

	//cout << "Загаданное слово состоит из " << currentSize << " букв : ";
	// Вывод количества букв слова

	/*
		Дописать массив, в котором будут записаны буквы...
	*/
	//string temp = currentWord;
	//cout << temp[0] << " - 0 element \n";
	//cout << temp[1] << " - 1 element \n";

	/*for (int count = 0; count < currentSize; count++)
	{
		char byLetter = currentWord[count];
		cout << "_ ";
	}*/
	return currentWord;
}

void game()
{
	vector<string> answerArray;						// Массив букв 
	string currentWord = choiceWord();				// Текущее слово
	int remainingLetters = currentWord.size();		// Размер загаданного слова
	string inputUser;								// Пользовательский ввод

	// Итоговый массив заполняем "_"

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
		/*else if (inputUser == '0')  <- Эта хуйня не работает
		{
			cout << "Игра досрочно завершена!\n";
			break;
		}*/
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