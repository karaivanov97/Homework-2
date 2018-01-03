#include <iostream>

using namespace std;

/*Задача 1
Имате предварително въведени стойности от естествени числа,
принадлежащи на интервала[10..99].числата са въведени в квадратна таблица
с размери 6 реда и 6 колони.Да се състави програма на C++,
чрез която се намира сумата на всички елементи от редовете с четни номера : 2, 4 и 6.
Програмата да извежда и сумата на всеки отделен ред.
Пример :
11, 12, 13, 14, 15, 16,
21, 22, 23, 24, 25, 26,
31, 32, 33, 34, 35, 36,
41, 42, 43, 44, 45, 46,
51, 52, 53, 54, 55, 56,
61, 62, 63, 64, 65, 66
Изход:
21, 22, 23, 24, 25, 26 сума 141
41, 42, 43, 44, 45, 46 сума 261
61, 62, 63, 64, 65, 66 сума 381
Сума на елементите 783
*/

const int MAX_ARRAY_SIZE =6;

int main()
{
	int total = 0;
	int arr[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] =
	{
	{11, 12, 13, 14, 15, 16},
	{21, 22, 23, 24, 25, 26},
	{31, 32, 33, 34, 35, 36},
	{41, 42, 43, 44, 45, 46},
	{51, 52, 53, 54, 55, 56},
	{61, 62, 63, 64, 65, 66}
	};
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
		int sumrow = 0;
		for (int j = 0; j < MAX_ARRAY_SIZE; j++) {

			if ((i + 1) % 2 == 0) {
				sumrow += arr[i][j];
			}
		}
		if (sumrow != 0) {
			cout << sumrow << endl;
			total += sumrow;
		}
	}
	cout << total;


	return 0;
}

#include <iostream>

using namespace std;

//Задача 2
//	Имате предварително въведени стойности от естествени числа,
//	принадлежащи на интервала[10..99].Числата са въведени в квадратна 
//	таблица с размери 6 реда и 6 колони.Да се състави програма на C++,
//	чрез която се намира сумата на всички елементи, чиято стойност е нечетно число.
//	Програмата да извежда формираните суми за всеки отделен ред на квадратната таблица, 
//	както и общата сума от тези елементи.Да се използва само един цикъл.
//	Пример:
//11, 12, 13, 14, 15, 16,
//	21, 22, 23, 24, 25, 26,
//	31, 32, 33, 34, 35, 36,
//	41, 42, 43, 44, 45, 46,
//	51, 52, 53, 54, 55, 56,
//	61, 62, 63, 64, 65, 66
//	Изход:
//11, , 13, , 15, , сума от елементите 39
//	21, , 23, , 25, , сума от елементите 69
//	31, , 33, , 35, , сума от елементите 99
//	41, , 43, , 45, , сума от елементите 129
//	51, , 53, , 55, , сума от елементите 159
//	61, , 63, , 65, , сума от елементите 189
//	Сума на елементите : 684
int main () {
int arr[6][6] = {
{ 11, 12, 13, 14, 15, 16 },
{ 21, 22, 23, 24, 25, 26 },
{ 31, 32, 33, 34, 35, 36 },
{ 41, 42, 43, 44, 45, 46 },
{ 51, 52, 53, 54, 55, 56 },
{ 61, 62, 63, 64, 65, 66 }
};

int sumodd = 0;
int total = 0;
for (int i = 0; i < 36; i++) {


	int current = arr[i / 6][i % 6];
	if (arr[i / 6][i % 6] % 2 != 0)
	{
		sumodd += arr[i / 6][i % 6];
	}


	if ((i + 1) % 6 == 0) {
		cout << sumodd << endl;
		total += sumodd;
		sumodd = 0;
	}
}
cout << total;

return 0;
}

#include <iostream>

using namespace std;


int main() {
	//Задача 3
	//	Същестуват два двумерни масива с предварително въведени стойности.
	//	Първият масив съдържа случайни естествени числа от интервала[0..22],
	//	а елементите на втория са само 1. И двата масива са с брой редове R и брой колони К
	//	- естествени числа от интервала[3..10].
	//	Резултатът от решението на тази задача се записва 
	//	в нов трети масив(със същите измерения като миналите два), 
	//	като[i, j] - тия елемент в този нов масив е равен на[i, j] - тия елемент
	//	от първия масив, умножен по сумата от елементите във втория масив
	//	.Да се състави програма(C++), чрез която се извеждат стойностите на елементите 
	//	и на трите двумерни масива.
	//	Пример:
	//I - ви масив :
	//11 17 4 10
	//	29 4 18 18
	//	22 14 5 5
	//	1 27 1 11
	//	25 2 27 6
	//	II - ри масив :
	//1 1 1 1
	//	1 1 1 1
	//	1 1 1 1
	//	1 1 1 1
	//	1 1 1 1
	//	Резултат : сума от от произведения :
	//220 340 80 200
	//	580 80 360 360
	//	440 280 100 100
	//	20 540 20 220
	//	500 40 540 120
	//
	const int K = 4;
	const int R = 5;
	
	int firstArr[R][K];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < K; j++) {
			cin >> firstArr[i][j];
		}
	}
	
	int secondArr[R][K];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < K; j++)
		{
			secondArr[i][j] = i;
		}
	}
	int sumSecond = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < K; j++)
		{
			sumSecond += secondArr[i][j];
		}
	}
	int resultArr[R][K];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < K; j++) {
			resultArr[i][j] = sumSecond*firstArr[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < K; j++) {
			cout << firstArr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < K; j++) {
			cout << secondArr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < K; j++) {
			cout << resultArr[i][j] << "  ";
		}
		cout << endl;
	}


	return 0;
}

	
//Задача 4
	//Да се състави програма, чрез която се въвеждат N[5..105]
	//двойки естествени дуцифрени числа.Всяка от двойките стойности представлява 
	//числител и знаменател на обикновена дроб и се записва като елементи на двумерен масив.
	//Програмата да изведе всяка от дробите и изчисли стойността й в проценти - цяло число.
	//Пример: N = 5
	//	Изход :
	//	17 / 82 = 20 %
	//	29 / 61 = 47 %
	//	12 / 60 = 20 %
	//	88 / 91 = 96 %
	//	73 / 19 = 384 %
	//
#include <iostream>

using namespace std;


int main() {
	

	 const int N = 5;

	if (N > 4 && N < 106) {
	int arr[N][2];
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < 2; j++) {
	cin >> arr[i][j];
	}
	//Moje i po sledniq nachin:
	//cout<<"Purvo chislo : ";
	//cin >> arr[i][0];
	//cout<<"Vtoro chislo : ";
	//cin >> arr[i][1];

	}
	for (int i = 0; i < N; i++) {
	int percent = arr[i][0]*100 / arr[i][1];
	cout << percent << '%' << endl;

	}
	}
	else {
	cout << "Opitai pak";
	}
	

	return 0;
}


//Задача 5
	//Да се състави програма(C++),
	//чрез която се въвежда естествено число N от интервала[1000 .. 1000 000].
	//Чрез функция да се провери дали въведеното число, но в 2 - ична бройна система съдържа
	//в записа си K и повече на брой последователни нули.
	//Пример:
	//N = 12345; K = 5
	//Изход:
	//11000000111001 - брой последователни нули 5
	
#include <iostream>
#include <cmath>

using namespace std;

long long int tobinary(int a) {
long long int result = 0;
for (int i = 0; a != 0; i++) {
result += (a % 2)*pow(10, i);
a /= 2;
}
return result;

}
bool broi(long long int binary, int K) {
int maxcounter = 0;
int currentcounter = 0;
while (binary) {
if (binary % 10 == 0) {
currentcounter++;
}
else if (binary % 10 == 1) {
if (currentcounter > maxcounter) {
maxcounter = currentcounter;
}
currentcounter = 0;
}
binary /= 10;
}
return maxcounter>=K;
}

int main() {
	int N,K;
	cin >> N >> K;
	cout << tobinary(N) << endl;
	cout << broi(tobinary(N), K);
	

	return 0;
}


	//Задача 6
	//Да се състави програма, чрез която се търсят първите 4 най - малки естествени числа,
	//отговарящи на съвкупността от следните условия : При делене на 2 има остатък 1,
	//при делене на 3 има остатък 2, при делене на 4 има остатък 3, при делене на 5 има остатък 4,
	//при делене на 6 има остатък 5, при делене на 7 има остатък 6, при делене на 8 има остатък 7,
	//при делене на 9 има остатък 8.
	//Пример за такова число : 2519
#include <iostream>


using namespace std;


int main() {

	int counter = 0;
	for (int i = 1; counter < 4; i++) {
	int current = 9 * i - 1;
	if (current % 9 == 8 && current % 8 == 7 && current % 7 == 6 && current % 6 == 5 && current % 5 == 4 && current % 4 == 3 && current % 3 == 2 && current % 2 == 1) {
	cout << current << endl;
	counter++;
	}
	}
	


	return 0;
}


	//Задача 7
	//Да се състави програма, чрез която се намира най - малкото естествено число,
	//което умножено по 18 дава число е еднакви цифри.

#include <iostream>

using namespace std;


bool same(int chislo) {
while (chislo) {
if (chislo / 10 == 0)
return true;
if (chislo % 10 != (chislo / 10) % 10) {
return false;
}
chislo /= 10;
}
return true;
}

int main() {
	
	for (int i = 1;; i++) {
	if (same(i * 18)) {
	cout << i;
	break;
	}
	}
	
	return 0;
}



	//Задача 8
	//Да се състави програма(C++), чрез която по въведено естествено число N от интервала[1..40]
	//се извежда стойността на съответния номер елемент от ред на Фибоначи.
	//Използвайте динамично оптимиране.
	//Пример:
	//20
	//Изход :
	//6765

#include <iostream>


using namespace std;


int main() {
	

	int n;
	cin >> n;
	do {
	cout << "Vuvedi chislo mejdu 1 i 40" << endl;
	cin >> n;
	} while (!(n > 0 && n < 41));
	int firstnum = 1;
	int secondnum = 1;
	for (int i = 2; i < n; i++) {
	int newnum = firstnum + secondnum;
	firstnum = secondnum;
	secondnum = newnum;
	}
	cout << secondnum << endl;
	
	return 0;
}


	//Задача 9
	//Да се състави програма, чрез която се въвежда естествено число от интервала[111..22222].
	//Програмата, чрез функция, проверява дали въведеното число e кратно на сбора от цифрите си.
	//Входни данни : естествено число N.
	//Пример :
	//N = 132
	//Изход :
	//дели се


#include <iostream>

using namespace std;


int sumdigits(int chisloto) {
int result = 0;
for (int i = 0; chisloto != 0; i++) {
result += chisloto % 10;
chisloto /= 10;
return result;
}
}
bool kratno(int proverka) {
if (proverka%sumdigits(proverka) == 0)
return true;
else
return false;
} 

int main() {
	
	int n;
	do {
	cout << "Vuvedi chislo mejdu 111 i 22222" << endl;
	cin >> n;
	} while (!(n > 110 && n < 22223));
	if (kratno(n))
	cout << "deli se" << endl;
	else
	{
	cout << "ne se deli";
	}
	
	return 0;
}

	
    	//Задача 10
	//През лятото е организиран семинар по екология.
	//Един от организаторите е фирма, собственик на хотелски комплес в ски курорт.
	//С цел качествено обслужване на клиентите,
	//хотелският комплекс се стреми към равномерно разпределение на гости по отделни стаи.
	//Да се състави програма, чрез която се въвеждат две естествени числа : N[40....10040] -
	//брой гости и K[10..20] - максимален капацитет на зала.
	//Програмата да осъществи равномерно разпределение на всички гости по отделни стаи стаи.
	//Пример :
	//N = 49 K = 15
	//Изход :
	//13 12 12 12

#include <iostream>

using namespace std;

int main() {
	
	int n, k;
	int min = 0;
	do {
		cout << "Za gosti mejdu 40 i 10040" << endl;
		cin >> n;
	} while (!(n > 39 && n < 10041));
	do {
		cout << "Za zala mejdu 10 i 20" << endl;
		cin >> k;
	} while (!(k > 9 && k < 21));
	for (int i = 0;; i++) {
		if ((i*k - n) > 0) {
			min = i;
			break;
		}
	}

	return 0;
}
	
