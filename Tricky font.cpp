#include<iostream>
#include <string>
#include <sstream>

using namespace std;


/* Задача: Хитрый шифр.
Ограничение времени	2 секунды
Ограничение памяти	512Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Известная компания Тындекс в очередной раз проводит набор стажёров.
Заботясь о персональных данных соискателей, компания придумала хитрый алгоритм шифрования:

Подсчитывается количество различных символов в ФИО (регистр важен, А и а — разные символы).
Берётся сумма цифр в дне и месяце рождения, умноженная на 64.
Для первой (по позиции в слове) буквы фамилии определяется её номер в алфавите 
(в 1-индексации), умноженный на 256 (регистр буквы не важен).
Полученные числа суммируются.
Результат переводится в 16-чную систему счисления (в верхнем регистре).
У результата сохраняются только 3 младших разряда (если значимых разрядов меньше, 
то шифр дополняется до 3-х разрядов ведущими нулями).
Ваша задача — помочь вычислить для каждого кандидата его шифр.

Формат ввода
В первой строке вводится число N(1≤N≤10000) — количество кандидатов и шифров.
Далее следует N строк в формате CSV (fj,ij,oj,dj,mj,yj) — информация о кандидатах:
Фамилия fj, имя ij и отчество oj(1≤∣∣fj∣∣,∣∣ij∣∣,∣∣oj∣∣≤15) — строки, состоящие из латинских букв верхнего и нижнего регистра;
день рождения dj, месяц рождения mj и год рождения yj — целые числа, задающие корректную дату 
в промежутке от 1 января 1950 года до 31 декабря 2021 года.

Формат вывода
В единственной строке выведите N строк k1, k2, …, kN, где kj — шифр j-го кандидата (в верхнем регистре). 
Кандидаты нумеруются с 1 до N в порядке ввода.

Пример
Ввод	
2
Volozh,Arcady,Yurievich,11,2,1964
Segalovich,Ilya,Valentinovich,13,9,1964

Вывод
710 64F 

Примечания
Рассмотрим тестовый пример.
Первый кандидат — Volozh,Arcady,Yurievich,11,2,1964:

Различные символы в ФИО: V, o, l, z, h, A, r, c, a, d, y, Y, u, i, e, v - всего их 16.
Сумма цифр в дне и месяце рождения равна 1+1+2= 4.
Номер в алфавите первой буквы фамилии V равен 22.
Итоговое значение шифра равно 16+4⋅64+22⋅256= 5904.
В 16-ричной системе счисления это число представимо как 1710.
Нас интересуют только 3 последние разряда, поэтому остаётся 710.

Второй кандидат — Segalovich,Ilya,Valentinovich,13,9,1964:
Различные символы в ФИО: S, e, g, a, l, o, v, i, c, h, I, y, V, n, t - всего их 15.
Сумма цифр в дне и месяце рождения равна 1+3+9= 13.
Номер в алфавите первой буквы фамилии S равен 19.
Итоговое значение шифра равно 15+13⋅64+19⋅256= 5711.
В 16-ричной системе счисления это число представимо как 164F.
Нас интересуют только 3 последние разряда, поэтому остаётся 64F.*/





int main()
{
	setlocale (LC_ALL, "ru");
	int N;
	cout << "Введите число кандидатов" << endl;
	cin >> N;
	
	string Data;
	string Final;

	

	for (int i = 0; i < N; i++)
	{
		cin >> Data;

		string Surname;
		string Name;
		string SecondName;
		string Date;
		string Month;


		/* Разделеляем входящую строку на подстроки с фамилией = Suname, именем = Name, отчеством = SecondName,
		   днем рождения = Date, и месяцем рождения. */

		string delimiter = ",";
		int FirstErase = 0;
		int LastErase;
		
		LastErase = Data.find(delimiter);
		string Substring1 = Data.substr(FirstErase, LastErase);
		Surname = Substring1;
		Data.erase(FirstErase, LastErase + 1);

		LastErase = Data.find(delimiter);
		string Substring2 = Data.substr(FirstErase, LastErase);
		Name = Substring2;
		Data.erase(FirstErase, LastErase + 1);

		LastErase = Data.find(delimiter);
		string Substring3 = Data.substr(FirstErase, LastErase);
		SecondName = Substring3;
		Data.erase(FirstErase, LastErase + 1);

		LastErase = Data.find(delimiter);
		string Substring4 = Data.substr(FirstErase, LastErase);
		Date = Substring4;
		Data.erase(FirstErase, LastErase + 1);

		LastErase = Data.find(delimiter);
		string Substring5 = Data.substr(FirstErase, LastErase);
		Month = Substring5;
		Data.erase(FirstErase, LastErase + 1);
		

		// Количество уникальных букв в ФИО.

		/* Создаем строку, в которую будем переносить уникальные символы, чтобы их посчитать.
		   Выделяем во входящей строке подстроку в один символ.
		   С помощью метода find ищем есть ли этот символ в строке с уникальными символами.
		   Если нет, то записываем в нее символ. */

		string SumSNS;
		SumSNS = Surname + Name + SecondName;
		int SumSNSlength = SumSNS.length();

		string UniqueLetter;
		string UniqueLetterIter;
		int UniqueLetterIterInt;

		for (int i = 0; i < SumSNSlength; i++)
		{
			UniqueLetterIter = SumSNS.substr(i, 1);
			UniqueLetterIterInt = UniqueLetter.find(UniqueLetterIter);

			if (UniqueLetterIterInt == -1) // потому что, если find ничего не находит, то возвращает -1.
			{
				UniqueLetter = UniqueLetter + UniqueLetterIter;
			}
			else
			{
				continue;
			}
		}
		int UniqueLetterLength;
		UniqueLetterLength = UniqueLetter.length();

		cout << endl;
		cout << "Количество уникальных символов в ФИО = " << UniqueLetterLength << endl;


		// Сумма цифр в дне и месяце * 64.

		/* Складываем строки дня и месяца. Выделяем каждый символ в подстроку,
		   и переводим в int, с помощью метода stoi. Складываем цифры, и умножаем на 64. */

		string SumDateMonth;
		SumDateMonth = Date + Month;
		int SumDateMonthLength;
		SumDateMonthLength = SumDateMonth.length();

		string StringIter;
		int IntIter;
		int SumDateMonthResult = 0;
		for (int i = 0; i < SumDateMonthLength; i++)
		{
			StringIter = SumDateMonth.substr(i, 1);
			IntIter = stoi(StringIter);
			SumDateMonthResult = SumDateMonthResult + IntIter;
		}

		int SumDateMonthResult64;
		SumDateMonthResult64 = SumDateMonthResult * 64;

		cout << "Сумма цифр дня и месяца = " << SumDateMonthResult << endl;
	    cout << "Сумма цифр дня и месяца * 64 = " << SumDateMonthResult64 << endl;

		//Первая буква фамилии - номер в алфавите * 256

		/* Выделяем первую букву в подстроку. Создаем строку с буквами в алфавите. 
		   С помощью метода find ищем порядковый номер этой буквы в строке с буквами. 
		   Умножаем это число на 256. */

		string FirstLetter;
		FirstLetter = Surname.substr(0, 1);
		string alfavit = " ABCDIFGHIJKLMNOPQRSTUVWXYZ"; // Пробел перед A нужен потому что find начинает считать, начиная с 0.
		int FirstLetterNumber = alfavit.find(FirstLetter);

		cout << "Номер первой буквы = " << FirstLetterNumber << endl;

		int FirstNum256;
		FirstNum256 = FirstLetterNumber * 256;

		cout << "Номер первой буквы в алфавите * 256 = " << FirstNum256 << endl;


		//Сумма всех чисел

		/* Складываем количество уникальных букв в ФИО, сумму цифр дня и месяца * 64,
		   и номер первой буквы в алфавите * 256. */

		int SumAll;
		SumAll = UniqueLetterLength + SumDateMonthResult64 + FirstNum256;

		cout << "Сумма всех чисел = " << SumAll << endl;


		//Перевод в 16-тиричную систему

		/* С помощью метода hex переводим полученное число в 16-тичную систему.
		   С помощью метода uppercase выводим буквы в верхнем регистре. */

		string Num16;

		std::stringstream sstream;
		sstream << uppercase << hex << SumAll;
		Num16 = sstream.str();

		cout << "Число в 16-ричной системе = " << Num16 << endl;


		// Последние три цифры

		/* Берем последние три цифры полученного числа. Если число состоит из 2 символов,
		   то дописываем один ноль перед числом, если состоит из одной цифры, то два нуля. */
		
		string FinalResult;
		int Num16Length = Num16.length();

		string prefix0 = "0";
		if (Num16Length == 1)
		{
			FinalResult = prefix0 + prefix0 + Num16;
		}
		else if (Num16Length == 2)
		{
			FinalResult = prefix0 + Num16;
		}
		else
		{
			FinalResult = Num16.substr(Num16Length - 3, Num16Length);
		}
		
		// Итоговый результат.
		string Probel = " ";

		Final = Final + Probel + FinalResult;
		
	}//Первый for.

	Final.erase(0, 1);
	cout << Final << endl;

	return 0;
}