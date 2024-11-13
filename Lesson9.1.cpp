/*1. Написати шаблон функції для пошуку середнього арифметичного значення масиву.
2. Написати перевантажені шаблони функцій для знаходження коренів лінійного (a*x + b = 0) і 
квадратного (a*x2 + b*x + c = 0) рівнянь. Зауваження: у функції передаються коефіцієнти рівнянь.
3. Написати функцію, яка приймає як параметри дійсне число і кількість знаків після десяткового дробу, 
які мають залишитися. Завданням функції є округлення вищевказаного дійсного числа із заданою точністю.
4. Написати шаблонні функції і протестувати їх в основній програмі:
■ Знаходження максимального значення в одновимірному масиві;
■ Знаходження максимального значення у двовимірному масиві;
■ Знаходження максимального значення в тривимірному масиві.
5. Реалізуйте перевантажені функції для
■ Знаходження максимального значення двох цілих;
■ Знаходження максимального значення трьох цілих.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <iomanip>

#define Show(H)cout << H;
#define Default cout << "Ne virno vubranui variant!";
#define Vvod(H)cin >> H;

void Vubir_zadachi();
void Switch(int n);
void Random();
void Seredne_arefmetuchne();
template <typename T>
float Sablon_seredne_arefmetuchne(T Ar[], int n);

void Koreni_rivnan();
template<typename T> void Rivnanna(T A, T B);
template<typename T> void Rivnanna(T A, T B, T C);
template<typename T, typename T1> void Liniini(T A, T B, T1 A1, T1 B1);
template<typename T, typename T1> void Kvadratni(T A, T B, T C, T1 A1, T1 B1, T1 C1);
template<typename T>T Duskruminant(T A, T B, T C);

void Okryglenna();
template<typename T>void Znahodzenna_okruglenna(T A, int B);

void Max_znachenna_y_riznovumirnux_masuvax();
void Vubir_masuvy();
void Vubir_cilux_abo_ne_cilux_chisel();
template<typename T> void Switch_masuva(int A, int B);
/*1*/template<typename T>void Switch_vubora_chisel(int A, T Ar1[], int N);
/*1*/template<typename T>T Max(T Ar1[], int N);
/*1*/template<typename T>void Show_Max(T Ar1[], int N);
/*2*/template<typename T> void Switch_vubora_chisel(int A, T Ar2[][10], int Col, int Row);
/*2*/template<typename T>T Max(T Ar2[][10], int Col, int Row);
/*2*/template<typename T>void Show_Max(T Ar2[][10], int Col, int Row);
/*3*/template<typename T> void Switch_vubora_chisel(int A, T Ar3[][5][10], int N, int Col, int Row);
/*3*/template<typename T>T Max(T Ar3[][5][10], int N, int Col, int Row);
/*3*/template<typename T>void Show_Max(T Ar3[][5][10], int N, int Col, int Row);

void Randomnui_masuv(int Ar1[], int N);
void Randomnui_masuv(int Ar2[][10], int Col, int Row);
void Randomnui_masuv(int Ar3[][5][10], int N, int Col, int Row);

void Randomnui_masuv(double Ar1[], int N);
void Randomnui_masuv(double Ar2[][10], int Col, int Row);
void Randomnui_masuv(double Ar3[][5][10], int N, int Col, int Row);

template<typename T>void Show_masuv(T Ar1[], int N);
template<typename T>void Show_masuv(T Ar2[][10], int Col, int Row);
template<typename T>void Show_masuv(T Ar3[][5][10], int N, int Col, int Row);

void Max_znachenna_miz_chislamu();
void Vubir_kilkosti_znachen();
void Switch_dla_znachen(int A);
int Znaxodzenna_max_znachenna(int A, int B);
int Znaxodzenna_max_znachenna(int A, int B, int C);

using namespace std;
int main() {
	int a;
	Vubir_zadachi();
	Vvod(a);
	Switch(a);
	Show('\n');
}
void Vubir_kilkosti_znachen() {
	cout << "Oberite kilkist znachen: \n"
		<< "1. Maksumym miz dvoma znachennamu\n"
		<< "2 Maksumym miz troma znachennamu\n";
}
int Znaxodzenna_max_znachenna(int A, int B, int C) {
	if (A > B && A > C) {
		return A;
	}
	else if (A < B && B > C) {
		return B;
	}
	else if (C > A && C > B) {
		return C;
	}
}
int Znaxodzenna_max_znachenna(int A, int B) {
	if (A > B) {
		return A;
	}
	else return B;
}
void Switch_dla_znachen(int a) {
	int A = 0, B = 0, C = 0, Max = 0;
	switch (a) {
	case 1: {
		cout << "Vvedite dva znachenna: ";
		Vvod(A);
		Vvod(B);
		Max = Znaxodzenna_max_znachenna(A, B);
		Show(Max);
		Show('\n');
	}break;
	case 2: {
		cout << "Vvedite dva znachenna: ";
		Vvod(A);
		Vvod(B);
		Vvod(C);
		Max = Znaxodzenna_max_znachenna(A, B, C);
		Show(Max);
		Show('\n');
	}break;
	default:Default;
	}
}
void Max_znachenna_miz_chislamu() {
	/*5. Реалізуйте перевантажені функції для
      ■ Знаходження максимального значення двох цілих;
      ■ Знаходження максимального значення трьох цілих.*/
	int a;
	Vubir_kilkosti_znachen();
	Vvod(a);
	Switch_dla_znachen(a);
}
void Randomnui_masuv(int Ar2[][10], int Col, int Row) {
	Random();
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			Ar2[i][j] = rand() % 50 - 25;
		}
	}
}
void Randomnui_masuv(int Ar3[][5][10], int N, int Col, int Row) {
	Random();
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				Ar3[k][i][j] = rand() % 50 - 25;
			}
		}
	}
}
void Randomnui_masuv(double Ar1[], int N) {
	Random();
	for (int i = 0; i < N; i++) {
		Ar1[i] = (double)(rand() % 50 - 25) / (double)(rand() % 9 + 1);
	}
}
void Randomnui_masuv(double Ar2[][10], int Col, int Row) {
	Random();
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			Ar2[i][j] = (double)(rand() % 50 - 25) / (double)(rand() % 9 + 1);
		}
	}
}
void Randomnui_masuv(double Ar3[][5][10], int N, int Col, int Row) {
	Random();
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				Ar3[k][i][j] = (double)(rand() % 50 - 25) / (double)(rand() % 9 + 1);
			}
		}
	}
}
template<typename T>void Show_masuv(T Ar1[], int N) {
	for (int i = 0; i < N; i++) {
		Show(Ar1[i]);
		Show(' ');
	}
	Show('\n');
}
template<typename T>void Show_masuv(T Ar2[][10], int Col, int Row) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			Show(Ar2[i][j]);
			Show(' ');
		}
		Show('\n');
	}
	Show('\n');
}
template<typename T>void Show_masuv(T Ar3[][5][10], int N, int Col, int Row) {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				Show(Ar3[k][i][j]);
				Show(' ');
			}
			Show('\n');
		}
		Show('\n');
	}
	Show('\n');
}
/*3*/template<typename T>T Max(T Ar3[][5][10], int N, int Col, int Row) {
	T M = Ar3[0][0][0];
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				if (M < Ar3[k][i][j]) {
					M = Ar3[k][i][j];
				}
			}
		}
	}
	return M;
}
/*2*/template<typename T>T Max(T Ar2[][10], int Col, int Row) {
	T M = Ar2[0][0];
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			if (M < Ar2[i][j]) {
				M = Ar2[i][j];
			}
		}
	}
	return M;
}
/*1*/template<typename T>T Max(T Ar1[], int N) {
	T M = Ar1[0];
	for (int i = 0; i < N; i++) {
		if (M < Ar1[i]) {
			M = Ar1[i];
		}
	}
	return M;
}
/*3*/template<typename T>void Show_Max(T Ar3[][5][10], int N, int Col, int Row) {
	cout << "Maxsumalne znachenna masuvy: ";
	T max = Max(Ar3, N, Col, Row);
	Show(max);
	Show('\n');
}
/*2*/template<typename T>void Show_Max(T Ar2[][10], int Col, int Row) {
	cout << "Maxsumalne znachenna masuvy: ";
	T max = Max(Ar2, Col, Row);
	Show(max);
	Show('\n');
}
/*1*/template<typename T>void Show_Max(T Ar1[], int N) {
	cout << "Maxsumalne znachenna masuvy: ";
	T max = Max(Ar1, N);
	Show(max);
	Show('\n');
}
template<typename T>void Switch_masuva(int A, int B) {
	const int n = 3, col = 10, row = 5;
	T Arr1[n], Arr2[row][col], Arr3[n][row][col];
	switch (A) {
	case 1: {
		Switch_vubora_chisel(B, Arr1, n);
	} break;
	case 2: {
		Switch_vubora_chisel(B, Arr2, col, row);
	}break;
	case 3: {
		Switch_vubora_chisel(B, Arr3, n, col, row);
	}break;
	default:Default;
	}
	Show('\n');
}
/*3*/template<typename T> void Switch_vubora_chisel(int A, T Ar3[][5][10], int N, int Col, int Row) {
	Random();
	switch (A) {
	case 1: {
		Randomnui_masuv(Ar3, N, Col, Row);
		Show('\n');
		Show_masuv(Ar3, N, Col, Row);
		Show('\n');
		Show_Max(Ar3, N, Col, Row);
		Show('\n');
	}break;
	case 2: {
		Randomnui_masuv(Ar3, N, Col, Row);
		Show('\n');
		Show_masuv(Ar3, N, Col, Row);
		Show('\n');
		Show_Max(Ar3, N, Col, Row);
		Show('\n');
	}break;
	default:Default;
	}
	Show('\n');
}
/*2*/template<typename T> void Switch_vubora_chisel(int A, T Ar2[][10], int Col, int Row) {
	Random();
	switch (A) {
	case 1: {
		Randomnui_masuv(Ar2, Col, Row);
		Show('\n');
		Show_masuv(Ar2, Col, Row);
		Show('\n');
		Show_Max(Ar2, Col, Row);
		Show('\n');
	}break;
	case 2: {
		Randomnui_masuv(Ar2, Col, Row);
		Show('\n');
		Show_masuv(Ar2, Col, Row);
		Show('\n');
		Show_Max(Ar2, Col, Row);
		Show('\n');
	}break;
	default:Default;
	}
	Show('\n');
}
/*1*/template<typename T> void Switch_vubora_chisel(int A, T Ar1[], int N) {
		Random();
		Randomnui_masuv(Ar1, N);
		Show('\n');
		Show_masuv(Ar1, N);
		Show('\n');
		Show_Max(Ar1, N);
		Show('\n');
}

void Vubir_masuvy() {
	cout << "Oberite masuv:\n"
		<< "1. Odnovumirnui\n"
		<< "2. Dvovumirnui\n"
		<< "3. Truvumirnui\n";
}
void Vubir_cilux_abo_ne_cilux_chisel() {
	cout << "Oberite iakumu chuslamu byde zapovnenui masuv:\n"
		<< "1. Cili chusla\n"
		<< "2. Ne cili chisla\n";
}
void Max_znachenna_y_riznovumirnux_masuvax() {
	/*4. Написати шаблонні функції і протестувати їх в основній програмі:
      ■ Знаходження максимального значення в одновимірному масиві;
      ■ Знаходження максимального значення у двовимірному масиві;
      ■ Знаходження максимального значення в тривимірному масиві.*/
	int a, b;
	Vubir_masuvy();
	Vvod(a);
	Vubir_cilux_abo_ne_cilux_chisel();
	Vvod(b);
	if (b == 1) {
		Switch_masuva<int>(a, b);
		Show('\n');
	}
	else if (b == 2) {
		Switch_masuva<double>(a, b);
		Show('\n');
	}
}
template<typename T>void Znahodzenna_okruglenna(T A, int B) {
	T D = A;
	T R = 0;
	int K, S, P = A;
	int k = 1, n = 0;
	for (int i = 0; i <= B; i++) {
		D *= 10;
	}
	K = (int)D % 10;
	D /= 10;
	if (K >= 5) {
		D++;
	}
	for (int j = 0; j < B; j++) {
		S = (int)D % 10;
		D /= 10;
		R += (S * k);
		k *= 10;
	}
	cout << "Okruglene chislo: ";
	Show(P);
	Show('.');
	Show(R);
	//cout << setprecision(B) << fixed << A;
	Show('\n');
}
void Okryglenna() {
	/*3. Написати функцію, яка приймає як параметри дійсне число і кількість знаків після десяткового дробу, 
         які мають залишитися. Завданням функції є округлення вищевказаного дійсного числа із заданою точністю.*/
	int Zn;
	double Num;
	cout << "Okruglenna cilogo chusla\n"
		<< "Vvedite chislo ta tochnist okryglenna: ";
	Vvod(Num);
	Vvod(Zn);
	Znahodzenna_okruglenna(Num, Zn);
}
template<typename T> void Rivnanna(T A, T B) {
	cout << "Korin rivnanna: ";
	float x = (-1 * B) / A;
	Show(x);
	Show('\n');
	Show('\n');
}
template<typename T, typename T1> void Liniini(T A, T B, T1 A1, T1 B1) {
	cout << "Dla liniinogo rivnanna a*x + b = 0\n"
		<< "vvedite znachenna cilux zminnux a i b: ";
	Vvod(A);
	Vvod(B);
	Show('\n');
	if (A == 0 && B != 0) {
		cout << "Nemae koreniv rivnanna!";
		Show('\n');
		Show('\n');
	}
	else if (A == 0 && B == 0) {
		cout << "Korenem rivnanna moze bytu byd iake chislo!";
		Show('\n');
		Show('\n');
	}
	else {
		Rivnanna(A, B);
		Show('\n');
		Show('\n');
	}
	cout << "Dla liniinogo rivnanna a*x + b = 0\n"
		<< "vvedite znachenna ne cilux zminnux a i b: ";
	Vvod(A1);
	Vvod(B1);
	Show('\n');
	if (A1 == 0 && B1 != 0) {
		cout << "Nemae koreniv rivnanna!";
		Show('\n');
		Show('\n');
	}
	else if (A1 == 0 && B1 == 0) {
		cout << "Korenem rivnanna moze bytu byd iake chislo!";
		Show('\n');
		Show('\n');
	}
	else {
		Rivnanna(A1, B1);
		Show('\n');
		Show('\n');
	}
}
template<typename T>T Duskruminant(T A, T B, T C) {
	T D = (B * B) - 4 * A * C;
	return D;
}
template<typename T> void Rivnanna(T A, T B, T C) {
	T Dus = Duskruminant(A, B, C);
	T Izvl_kor = 0;
	for (int i = 2; i < Dus; i++) {
		if (Dus / i == i) {
			Izvl_kor = i;
			break;
		}
	}
	if (Dus < 0) {
		cout << "Nemae koreniv!";
		Show('\n');
		Show('\n');
	}
	else if (Dus == 0) {
		T X = (-1 * B) / (2 * A);
		cout << "Maemo odun koren: ";
		Show(X);
		Show('\n');
		Show('\n');
	}
	else if (Dus > 0) {
		T X1 = ((-1 * B) + Izvl_kor) / (2 * A);
		T X2 = ((-1 * B) - Izvl_kor) / (2 * A);
		cout << "Maemo dva korena: ";
		Show(X1);
		Show(' ');
		Show(X2);
		Show('\n');
		Show('\n');
	}
}
template<typename T, typename T1> void Kvadratni(T A, T B, T C, T1 A1, T1 B1, T1 C1){
	cout << "Dla kvadratnogo rivnanna a*x2 + b*x + c = 0\n"
		<< "Vvedite znachenna cilux zminnux a, b i c: ";
	Vvod(A);
	Vvod(B);
	Vvod(C);
	Show('\n');
	if (A == 0 && B != 0 && C != 0) {
		Rivnanna(B, C);
		Show('\n');
		Show('\n');
	}else if(A == 0 && B == 0 && C != 0) {
		cout << "Nemae koreniv rivnanna!";
		Show('\n');
		Show('\n');
	}else if (A == 0 && B == 0 && C == 0) {
		cout << "Korenem rivnanna moze bytu byd iake chislo!";
		Show('\n');
		Show('\n');
	}
	else if (A != 0 && B == 0 && C == 0) {
		cout << "Koren rivnanna: ";
		Show(0);
		Show('\n');
		Show('\n');
	}
	else if (A != 0 && B != 0 && C == 0) {
		cout << "Odun koren rivnanna: ";
		Show(0);
		Show('\n');
		cout << "Drugui koren rivnanna: ";
		Rivnanna(A, B);
		Show('\n');
		Show('\n');
	}
	else if (A != 0 && B == 0 && C != 0) {
		Rivnanna(A, C);
		Show('\n');
		Show('\n');
	}
	else {
		Rivnanna(A, B, C);
		Show('\n');
		Show('\n');
	}
		cout << "Dla kvadratnogo rivnanna a*x2 + b*x + c = 0\n"
			<< "Vvedite znachenna ne cilux zminnux a, b i c: ";
		Vvod(A1);
		Vvod(B1);
		Vvod(C1);
		Show('\n');
		if (A1 == 0 && B1 != 0 && C1 != 0) {
			Rivnanna(B1, C1);
			Show('\n');
			Show('\n');
		}
		else if (A1 == 0 && B1 == 0 && C1 != 0) {
			cout << "Nemae koreniv rivnanna!";
			Show('\n');
			Show('\n');
		}
		else if (A1 == 0 && B1 == 0 && C1 == 0) {
			cout << "Korenem rivnanna moze bytu byd iake chislo!";
			Show('\n');
			Show('\n');
		}
		else if (A1 != 0 && B1 == 0 && C1 == 0) {
			cout << "Koren rivnanna: ";
			Show(0);
			Show('\n');
			Show('\n');
		}
		else if (A1 != 0 && B1 != 0 && C1 == 0) {
			cout << "Odun koren rivnanna: ";
			Show(0);
			Show('\n');
			cout << "Drugui koren rivnanna: ";
			Rivnanna(A1, B1);
			Show('\n');
			Show('\n');
		}
		else if (A1 != 0 && B1 == 0 && C1 != 0) {
			Rivnanna(A1, C1);
			Show('\n');
			Show('\n');
		}
		else {
			Rivnanna(A1, B1, C1);
		}
}
void Koreni_rivnan() {
	//2. Написати перевантажені шаблони функцій для знаходження коренів лінійного (a*x + b = 0) і 
	//квадратного(a*x2 + b*x + c = 0) рівнянь.Зауваження: у функції передаються коефіцієнти рівнянь.
	int a = 0, b = 0, c = 0;
	float a1 = 0, b1 = 0, c1 = 0;
	Liniini(a, b, a1, b1);
	Kvadratni(a, b, c, a1, b1, c1);
}
void Vubir_zadachi() {
	cout << "Oberite zadachy:\n"
		<< "1. Seredne arefmetuchne\n"
		<< "2. Koreni rivnan\n"
		<< "3. Okryglenna\n"
		<< "4. Max znachenna y riznovumirnux masuvax\n"
		<< "5. Max znachenna miz chislamu\n";
}
void Switch(int n) {
	switch (n) {
	case 1: Seredne_arefmetuchne(); break;
	case 2: Koreni_rivnan(); break;
	case 3: Okryglenna(); break;
	case 4: Max_znachenna_y_riznovumirnux_masuvax(); break;
	case 5: Max_znachenna_miz_chislamu(); break;
	default:Default;
	}
}
void Random() {
	srand(time(NULL));
}
void Randomnui_masuv(int Ar[], int n) {
	Random();
	for (int i = 0; i < n; i++) {
		Ar[i] = rand() % 50 - 25;
	}
}
void Seredne_arefmetuchne() {
	//1. Написати шаблон функції для пошуку середнього арифметичного значення масиву.
	const int N = 20;
	int Arr[N];
	double Arr2[N];
	Randomnui_masuv(Arr, N);
	cout << "Masuv ciluh chisel:\n";
	Show_masuv(Arr, N);
	Show('\n');
	float SA = Sablon_seredne_arefmetuchne(Arr, N);
	cout << "Seredne arufmetuchne: ";
	Show(SA);
	Show('\n');
	Show('\n');
	Randomnui_masuv(Arr2, N);
	cout << "Masuv ne ciluh chisel:\n";
	Show_masuv(Arr2, N);
	Show('\n');
	float SA2 = Sablon_seredne_arefmetuchne(Arr2, N);
	cout << "Seredne arufmetuchne: ";
	Show(SA2);
	Show('\n');
}
template <typename T> float Sablon_seredne_arefmetuchne(T Ar[], int n) {
	T Sum = 0;
	for (int i = 0; i < n; i++) {
		Sum += Ar[i];
	}
	return (float)Sum / n;
}