#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<list>

using namespace std;



/* B.Через тернии к клиенту
Все языки	Clang 16.0.0 C++20	GNU GCC 12.2 C++20
Ограничение времени	5 секунд	1 секунда	1 секунда
Ограничение памяти	512Mb	512Mb	512Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Известная компания Тындекс идёт в ногу со временем — с началом активных космических перелётов 
в компании открылся сервис Тындекс.Ракетакси: пользователю необходимо лишь указать координаты начала 
и конца перелёта, после чего за ним вылетит персональная ракета.
По сути любой заказ можно описать в виде событий четырёх типов :

A(accepted) - заказ принят в работу(ракета вылетела за клиентом);
B(boarding) - клиент сел в ракету;
S(success) - заказ успешно завершён(клиент вышел на планете назначения);
C(cancelled) - заказ отменён.
Все происходящие с ракетами события отправляются на сервера, где сразу логируются.
Вот только из - за проблем со связью(метеоритные потоки, вспышки на звездах и т.д.) 
отправка событий иногда затягивается, из - за чего записи в получившемся логе могут идти не по порядку.
Гарантируется, что все описанные в логе события задают один из следующих сценариев :

A - B - S
A - B - C
A - C
Вам, как главному аналитику(и по совместительству главному программисту) ракетопарка, 
необходимо исследовать лог за прошедший год и определить для каждой ракеты 
суммарное время движения(в минутах) в течение заказов.
В каждый момент времени ракета выполняет только один заказ.Будем считать, 
что каждая ракета в каждый момент времени :
или стоит на месте в ожидании заказа,
или перемещается по космосу, выполняя заказ.
Движение начинается после принятия заказа и завершается после отмены или завершения заказа.
За одну минуту не может произойти несколько событий, связанных с одной и той же ракетой.

Формат ввода
В первой строке дано целое число N (2≤N≤200000) — количество записей в логе.
Следующие N строк содержат записи в логе в формате day hour minute id status: 
day(1≤d≤365) — номер дня(сквозная нумерация с начала календарного года);
hour(0≤h<24) — часы;
minute(0≤m<60) — минуты;
id(0≤id≤109) — уникальный идентификатор ракеты;
status∈{A,B,S,C} — буква, обозначающая тип события.
Формат вывода
В единственной строке выведите через пробел суммарное время движения на заказах 
для каждой упомянутой в логе ракеты.Данные необходимо выводить 
в порядке возрастания идентификаторов ракет.
Пример
Ввод	Вывод
8
50 7 25 3632 A
14 23 52 212372 S
15 0 5 3632 C
14 21 30 212372 A
50 7 26 3632 C
14 21 30 3632 A
14 21 40 212372 B
14 23 52 3632 B
156 142
Примечания
Ракета №3632
в 14 - й день года в 21:30 получила заказ(шестая запись в логе);
забрала пассажира в 23:52 того же дня(восьмая запись в логе);
после чего заказ был отменён в 15 - й день года в 00:05 (третья запись в логе);
в 50 - й день года в 7:25 получила заказ(первая запись в логе);
заказ был отменён уже через минуту(четвёртая запись в логе).
Таким образом ракета №3632 провела в движении с 14 - го дня 21:30 до 15 - го дня 
00 : 05 и с 50 - го дня 7 : 25 до 50 - го дня 7 : 26 — всего
156 минут.
Ракета №212372
в 14 - й день года в 21:30 получила заказ(третья запись в логе);
через 10 минут забрала пассажира(седьмая запись в логе);
в 23:52 прибыла на место назначения(вторая запись в логе).
Всего ракета №212372 провела в движении с 14 - го дня 21 : 30 до 14 - го дня 
23 : 52 —142 минуты. */




int main()
{
    setlocale(LC_ALL, "ru");

    /* Вводим данные из файла.*/
    ifstream DataIn;
    DataIn.open("Data.txt");

    if (DataIn.is_open())
    {
        cout << "Файл открыт" << endl;
    }
    else
    {
        cout << "Ошибка чтения файла" << endl;
    }

    /* Контейнер set упорядочивает строки по элементам, которые в них находятся. Сначала по дню,
       затем, часу, минутам, номеру ракеты, и типу события. В итоге записи раположатся в хронологическом порядке,
       по каждой ракете, и останется только взять все записи по кажой ракете, и последовательно посчитать
       разницу во времени между событиями. */

    string Data;
    set<string> SetData;


    while (getline(DataIn, Data))
    {
        SetData.insert(Data);
    }

    string RocketNumber1;
    string RocketNumber2;
    int Delimetr;

    string Iter;
    string Iter2;

    /* Выделить группу записей по одной ракете в одном set нельзя так как нельзя удалить элемент, который
       располагается не в начале и не в конце set, поэтому нужно необходимые записи записываем в SetRocketNumber,
       и затем считем время, а остальные в OtherData. */

    set<string> SetRocketNumber;
    set<string>OtherData;
    set<string>::iterator It;
    set<string>::iterator It2;

    /* Счетчики для циклов. */

    int SetRocketNumberCount = 0;
    int SetDataCount = SetData.size();
    int ResultIntCount;
    
    int Result =0;
    string ResultStr;
    string FinalResult;

    /* Для того, чтобы вывести результат в порядке возрастания номера ракеты, нужно записать их в лист
       в обратном порядке. В программе они считаются в порядке убывания, так как set упорядочивает 
       от большего номера к меньшему. */

    list<int> ResultInt; 
    list<int>::iterator It3;
    int Iter3;
   
    /* Разыменовываем первый элемент в set, выделяем в помощью substring номер ракеты, затем
       разыменовываем все остальные и сравниваем с первым. Если номер тот же запивываем всю строку
       в один set, если отличается в другой. */

        while (!SetData.empty())
        {
        for (It = SetData.begin(); It != SetData.end(); It++)
        {
            Iter = *SetData.begin();
        }

        for (int i = 0; i < 4; i++)
        {
            Delimetr = Iter.find(' ');
            RocketNumber1 = Iter.substr(0, Delimetr);
            Iter.erase(0, Delimetr + 1);
        }

        string Iter2;

        for (int i = 0; i < SetDataCount - SetRocketNumberCount; i++)
        {
            for (It = SetData.begin(); It != SetData.end(); It++)
            {
                Iter2 = *SetData.begin();
                Iter = *SetData.begin();
            }
            
            for (int i = 0; i < 4; i++)
            {
                Delimetr = Iter.find(' ');
                RocketNumber2 = Iter.substr(0, Delimetr);
                Iter.erase(0, Delimetr + 1);
            }

            if (RocketNumber2 == RocketNumber1)
            {
                SetRocketNumber.insert(Iter2);
                SetData.erase(SetData.begin());
            }
            else
            {
                OtherData.insert(Iter2);
                SetData.erase(SetData.begin());
            }
        }

        SetRocketNumberCount = SetRocketNumber.size();

        /* Разделяем каждую строку в set с одинаковыми номерами ракет, ищем в строке номер события,
           и в зависимости от этого считаем время. Все элементы расположены в хронологическом порядке,
           поэтому нужно только определить тип события. В set у одной ракеты может быть несколько вызовов,
           и после A может идти B или C. Чтобы определить как считать С, нужно определиить какое событие 
           было до этого, A или B. Если события B не было, то B=0, если было, то считаем данные B.
           Нужно инициализировать каждый раз B=0, чтобы если события B, при очередном цикле событий, не было, 
           не оставались данные от предыдущего цикла. Это нужно делать после C и S, потому что они 
           обязательно есть в цикле событий, и после них данные B нужны. */

        int DayA = 0, DayB = 0, DayC = 0, DayS = 0;
        int HourA = 0, HourB = 0, HourC = 0, HourS = 0;
        int MinuteA = 0, MinuteB = 0, MinuteC = 0, MinuteS = 0;
        int RocketNumberA, RocketNumberB, RocketNumberC, RocketNumberS;
        string EventTypeA, EventTypeB, EventTypeC, EventTypeS;
       
        int Result = 0;

        for (int i = 0; i < SetRocketNumberCount; i++)
        {

            for (It2 = SetRocketNumber.begin(); It2 != SetRocketNumber.end(); It2++)
            {
                Iter2 = *SetRocketNumber.begin();
            }

            string Day;
            string Hour;
            string Minute;
            string RocketNumber;
            string EventType;

            char Delimetr2 = ' ';

            Delimetr = Iter2.find(' ');
            Day = Iter2.substr(0, Delimetr);
            Iter2.erase(0, Delimetr + 1);

            Delimetr = Iter2.find(' ');
            Hour = Iter2.substr(0, Delimetr);
            Iter2.erase(0, Delimetr + 1);

            Delimetr = Iter2.find(' ');
            Minute = Iter2.substr(0, Delimetr);
            Iter2.erase(0, Delimetr + 1);

            Delimetr = Iter2.find(' ');
            RocketNumber = Iter2.substr(0, Delimetr);
            Iter2.erase(0, Delimetr + 1);

            Delimetr = Iter2.find(' ');
            EventType = Iter2.substr(0, 1);

            if (EventType == "A")
            {
                DayA = stoi(Day);
                HourA = stoi(Hour);
                MinuteA = stoi(Minute);
                RocketNumberA = stoi(RocketNumber);
                EventTypeA = EventType;
            }
             
            if (EventType == "B")
            {
                DayB = stoi(Day);
                HourB = stoi(Hour);
                MinuteB = stoi(Minute);
                RocketNumberB = stoi(RocketNumber);
                EventTypeB = EventType;

                if (DayA == DayB)
                {
                    Result = Result + (HourB * 60 + MinuteB) - (HourA * 60 + MinuteA);
                }
                else
                {
                    Result = Result + (HourB * 60 + MinuteB) + 1440 - (HourA * 60 + MinuteA);
                }
            }

            if (EventType == "C")
            {
                DayC = stoi(Day);
                HourC = stoi(Hour);
                MinuteC = stoi(Minute);
                RocketNumberC = stoi(RocketNumber);
                EventTypeC = EventType;

                if (DayB == 0)
                {
                    if (DayA == DayC)
                    {
                        Result = Result + (HourC * 60 + MinuteC) - (HourA * 60 + MinuteA);
                    }
                    else
                    {
                        Result = Result + 1440 + (HourC * 60 + MinuteC) - (HourA * 60 + MinuteA);
                    }
                }
                else
                {
                    if (DayB == DayC)
                    {
                        Result = Result + (HourC * 60 + MinuteC) - (HourB * 60 + MinuteB);
                    }
                    else
                    {
                      
                        Result = Result + 1440 + (HourC * 60 + MinuteC) - (HourB * 60 + MinuteB);
                    }
                }
                DayB = 0;
            }

            if (EventType == "S")
            {
                DayS = stoi(Day);
                HourS = stoi(Hour);
                MinuteS = stoi(Minute);
                RocketNumberS = stoi(RocketNumber);
                EventTypeS = EventType;

                if (DayB == DayS)
                {
                    Result = Result + (HourS * 60 + MinuteS) - (HourB * 60 + MinuteB);
                }
                else
                {
                    Result = Result + (HourS * 60 + MinuteS) + 1440 - (HourB * 60 + MinuteB);
                }
                DayB = 0;
            }
            SetRocketNumber.erase(SetRocketNumber.begin());
        }

        ResultInt.push_front(Result);

        /* После того как посчитали время по одной ракете, переписываем сроки из set, с разными номерами ракет,
           снова в начальный set, и проходим новый цикл по следующему номеру ракеты. И так пока начальный set
           не окажется пустым. */

        while (!OtherData.empty())
        {
            for (It = OtherData.begin(); It != OtherData.end(); It++)
            {
                Iter = *OtherData.begin();

                SetData.insert(Iter);
            }
            OtherData.erase(OtherData.begin());
        }
    }
   
   /* Записываем результаты в лист в обратном порядке, затем из листа записываем в строку, стираем первый пробел, и выводим. */

    ResultIntCount = ResultInt.size();

    for (int i = 0; i < ResultIntCount; i++)
    {
        for (It3 = ResultInt.begin(); It3 != ResultInt.end(); It3++)
        {
            Iter3 = *ResultInt.begin();

        }
      
        ResultStr = to_string(Iter3);
        FinalResult = FinalResult + " " + ResultStr;
        ResultInt.erase(ResultInt.begin());
    }

    FinalResult.erase(0, 1);

    cout << FinalResult << endl;

    return 0;
}