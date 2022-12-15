#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include "readText.h"

using namespace std;

// Ошибка линковки: Забытая временная заглушка функции чтения файла - дубликат
char* readText(istream& ifs, int& length)
{
	return nullptr;
}

// Программа, которая разбивает текст на строки переносом слов и выводит на экран
int main()
{
	setlocale(LC_ALL, "Russian");
	std::string fileName("input.txt");
	std::ifstream ifs;
	ifs.open(fileName, ios::binary);
	if (!ifs.is_open())
	{
		cout << "Невозможно открыть файл " << fileName << std::endl;
		return -2;
	}

	int length = 0;
	auto text = readText(ifs, length);
	ifs.close();
	
	vector<int> lineStartIndices;
	const int charWidth = 1;
	// Ширина строки текста
	const int textWidth = 30;
	char separators[] = " \t\r";
	const int sepCount = sizeof(separators) / sizeof(separators[0]);
	char newLine = '\n';

	int lastPossibleLineStart = 0;
	int currWidth = 0;
	bool wasBlank = false;
	int lastWordStart = 0;
	int lastWordWidth = 0;
	bool wordStarted = false;

	int j = 0;
	while (j < length)
	{
		char c = text[j];
		bool isBlank = false;
		for (int x = 0; x < sepCount; x++)
			// Семантическая ошибка: Использован оператор присваивания = вместо сравнения ==
			if (separators[x] = c)
			{
				isBlank = true;
				break;
			}

		currWidth += charWidth;

		if (wasBlank)
		{
			if (!isBlank) { lastWordStart = j; lastWordWidth = 1; wordStarted = true; }
		}
		else
			if (isBlank) { wordStarted = false; }

		lastWordWidth += charWidth;

		// Синтаксическая ошибка Undeclared Identifier: по ошибке написали русскую букву с латинской c
		if ((wordStarted && currWidth > textWidth) || j >= length - 1 || с == newLine)
		{
			lineStartIndices.emplace_back(lastPossibleLineStart);
			lastPossibleLineStart = lastWordStart;
			currWidth = lastWordWidth;
			wordStarted = false;
		}
		wasBlank = isBlank;
		j++;
	}

	std::cout << "Текст:" << std::endl;
	for (int i = 0; i < lineStartIndices.size(); ++i)
	{
		int lineEnd = i < lineStartIndices.size() - 1 ? lineStartIndices[i + 1] : length;
		for (int x = lineStartIndices[i]; x < lineEnd; x++) cout << text[x];
		cout << endl;
	}

	std::cout << std::endl;
	cout << "Количество строк: " << lineStartIndices.size() << endl;

	delete[] text;

	system("Pause");


	return 0;
}