#include <iostream>
#include<string>

using namespace std;


/* A. Новая история
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Сейчас активно развивается новая история, основателем которой является Профессор А.С. Багиров. 
Он выяснил, что на протяжении многих лет на земле вместе с людьми существовали ящеры. 
Строительство пирамид, захват Байкала и еще много разных событий произошли благодаря ящерам.
Учёные ещё не выяснили, сколько времени ящеры существовали на земле. Они находят разные данные 
в виде даты начала и даты окончания, и чтобы проверить их на корректность, необходимо посчитать, 
сколько дней ящеры существовали для двух конкретных дат. Календарь ящеров очень похож 
на григорианский, лишь с тем исключением, что там нет високосных годов.
Вам даны дата начала и дата окончания существования ящеров, нужно найти количество полных дней 
и секунд в неполном дне, чтобы учёные смогли оценить, насколько даты корректны.

Формат ввода
В первой строке содержатся 6 целых чисел year1,month1,day1,hour1,min1,sec1
(1≤year1≤9999,1≤month1≤12,1≤day1≤31,0≤hour1≤23,0≤min1≤59,0≤sec1≤59)- дата начала существования ящеров.
Во второй строке содержатся 6 целых чисел year2,month2,day2,hour2,min2,sec2
(1≤year2≤9999,1≤month2≤12,1≤day2≤31,0≤hour2≤23,0≤min2≤59,0≤sec2≤59) - дата окончания существования ящеров.
Гарантируется, что дата начала меньше,чем дата конца.

Формат вывода
В первой и единственной строке выведите 2 числа: количество дней, сколько существовали ящеры, 
а также количество секунд в неполном дне.
Пример 1
Ввод	Вывод
980 2 12 10 30 1
980 3 1 10 31 37
17 96
Пример 2
Ввод	Вывод
1001 5 20 14 15 16
9009 9 11 12 21 11
2923033 79555
Примечания
В одном году 365 дней. Год делится на 12 месяцев, количество дней в каждом месяце: 
[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]. В одном дне 24 часа (от 0 до 23), 
в одном часу 60 минут (от 0 до 59), в одной минуте 60 секунд (от 0 до 59).
В первом тестовом примере года совпадают, а между 12 февраля и 1 марта прошло 17 полных дней, 
начало было в 10:30:01, а конец в 10:31:37,таким образом прошла 1 минута и 36 секунд, 
что в сумме получается 96 секунд.*/





int main()
{

	// Ввод данных

	string End;
	string Start;

	/* Вводим две строки, и делим их на год, месяц, день, час, минуты, и секунды. */

	// Первая сторка
	getline(cin, Start);

	string YearStart;
	string MonthStart;
	string DayStart;
	string HourStart;
	string MinuteStart;
	string SecondStart;

	string delimiter = " ";
	int FirstErase = 0;
	int LastErase = 0;

	LastErase = Start.find(delimiter);
	YearStart = Start.substr(FirstErase, LastErase);
	Start.erase(FirstErase, LastErase + 1);

	LastErase = Start.find(delimiter);
	MonthStart = Start.substr(FirstErase, LastErase);
	Start.erase(FirstErase, LastErase + 1);

	LastErase = Start.find(delimiter);
	DayStart = Start.substr(FirstErase, LastErase);
	Start.erase(FirstErase, LastErase + 1);

	LastErase = Start.find(delimiter);
	HourStart = Start.substr(FirstErase, LastErase);
	Start.erase(FirstErase, LastErase + 1);

	LastErase = Start.find(delimiter);
	MinuteStart = Start.substr(FirstErase, LastErase);
	Start.erase(FirstErase, LastErase + 1);

	LastErase = Start.find(delimiter);
	SecondStart = Start.substr(FirstErase, LastErase);
	Start.erase(FirstErase, LastErase + 1);

	// Вторая строка
	getline(cin, End);

	string YearEnd;
	string MonthEnd;
	string DayEnd;
	string HourEnd;
	string MinuteEnd;
	string SecondEnd;

	LastErase = End.find(delimiter);
	YearEnd = End.substr(FirstErase, LastErase);
	End.erase(FirstErase, LastErase + 1);

	LastErase = End.find(delimiter);
	MonthEnd = End.substr(FirstErase, LastErase);
	End.erase(FirstErase, LastErase + 1);

	LastErase = End.find(delimiter);
	DayEnd = End.substr(FirstErase, LastErase);
	End.erase(FirstErase, LastErase + 1);

	LastErase = End.find(delimiter);
	HourEnd = End.substr(FirstErase, LastErase);
	End.erase(FirstErase, LastErase + 1);

	LastErase = End.find(delimiter);
	MinuteEnd = End.substr(FirstErase, LastErase);
	End.erase(FirstErase, LastErase + 1);

	LastErase = End.find(delimiter);
	SecondEnd = End.substr(FirstErase, LastErase);
	End.erase(FirstErase, LastErase + 1);


	//Переводим строки в int

	int YearStartInt = stoi(YearStart);
	int MonthStartInt = stoi(MonthStart);
	int DayStartInt = stoi(DayStart);
	int HoureStartInt = stoi(HourStart);
	int MinuteStartInt = stoi(MinuteStart);
	int SecondStartInt = stoi(SecondStart);

	int YearEndInt = stoi(YearEnd);
	int MonthEndInt = stoi(MonthEnd);
	int DayEndInt = stoi(DayEnd);
	int HoureEndInt = stoi(HourEnd);
	int MinuteEndInt = stoi(MinuteEnd);
	int SecondEndInt = stoi(SecondEnd);


	// Количество дней


	/* Подссчитываем количество дней, которое прошло от нулевого года до первой даты,
	   и от нулевого года до второй даты, и вычитаем количество дней второй и первой даты.
	   Необходимо использовать long, так как числа получаются больше 32тыс., больше чем может хранить int. */

	// Количество дней от нудевого года до года даты.
	long YearDaysStart;
	long YearDaysEnd;
	
	YearDaysStart = YearStartInt * 365;
	YearDaysEnd = YearEndInt * 365;
	
	/* Количество дней от начала года, до месяца даты. - 1, так как сам месяц прошел не полностью.
	   К нему прибавляем количество дней даты. */
	 
	int ArrMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // Количество дней в каждом месяце.

	    // Первая дата.
     	int MonthDaysStart =0;
		for (int i = 0; i < MonthStartInt - 1; i++)
		{
			MonthDaysStart = MonthDaysStart + ArrMonth[i];
		}

		// Вторая дата.
		int MonthDaysEnd=0;
		for (int i = 0; i < MonthEndInt - 1; i++)
		{
			MonthDaysEnd = MonthDaysEnd + ArrMonth[i];
	

		}
	   
		long DaysResult;
	    DaysResult = (MonthDaysEnd + DayEndInt + YearDaysEnd) - (MonthDaysStart + DayStartInt + YearDaysStart);
		
		/* Когда считается количество дней в году, то дни считаются от 1 января, до 1 января, и когда затем считаются дни
		   в месяцах, то 1 января считается два раза. Когда года в датах одинаковые, то получается 0,
		   и этот второй день отнимается. Когда года разные, то получается дублирование 1 января. Поэтому нужно отнять 1 день. */

	    if (YearStartInt != YearEndInt)
	    {
		DaysResult = DaysResult - 1;
	    }

	// Время

		/* Складываем секунды в часах и минутах, и прибавляем количество секунд, которое прошло. */

	int SecondsStart;
	int SecondsEnd;

	SecondsStart = HoureStartInt * 3600 + MinuteStartInt * 60 + SecondStartInt;
	
	SecondsEnd = HoureEndInt * 3600 + MinuteEndInt * 60 + SecondEndInt;
	
	int SecondsResult = SecondsEnd - SecondsStart;

	/*Если часы одинаковые, значит прошел полный день, поэтому поэтому разница только в минутах и секундах.
	  Если часы не одинаковые то это не полный день, и нужно считать время между днями. В одном дне 86400 секунд. */

	   if (HoureStartInt != HoureEndInt)
	   {
		SecondsResult = SecondsResult + 86400;
	   }

	   cout << DaysResult << " " << SecondsResult << endl;

	return 0;
}