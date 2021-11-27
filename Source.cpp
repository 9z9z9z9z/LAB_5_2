#include <iostream>
#include <windows.h>
#include <time.h>
//============================================================
void init(double** args, int lines, int posts) {
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < posts; j++)
			args[i][j] = (double)(rand()%1000 -500)/13;
}
//============================================================
double poisk_Max(double** args, int lines, int posts) {
	double Max = args[0][posts / 2];
	for (int i = 0; i < lines / 2; i++) {
		for (int j = posts / 2; j < posts; j++) {
			if (args[i][j] > Max) Max = args[i][j];
		}
	}
	return Max;
}
//============================================================
double poisk_Min(double** args, int lines, int posts) {
	double Min = args[lines / 2][0];
	for (int i = lines / 2; i < lines; i++) {
		for (int j = 0; j < posts / 2; j++) {
			if (args[i][j] < Min) Min = args[i][j];
		}
	}
	return Min;
}
//============================================================
void print(double** args, int lines, int posts) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < posts; j++) {
			if ((i < lines / 2) && (j > (posts / 2)-1) || (i > (lines / 2)-1) && (j < posts / 2)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				printf_s("%f\t", args[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else{
				printf_s("%f\t", args[i][j]);
			}
		}
		std::cout << std::endl;
	}
}
//===============================================================================
int main() {
	srand(time(0));
	int N = -1, M = -1;
	while (N < 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		std::cout << "Input number of lines, please" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cin >> N;
		system("cls");
	}
	while (M < 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "Input number of posts, please" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cin >> M;
		system("cls");
	}
	double** A = (double**)calloc(N, sizeof(double*));
	for (int i = 0; i < N; i++) A[i] = (double*)calloc(M, sizeof(double));
	int W[2];
	init(A, N, M);
	print(A, N, M);
	double Max = poisk_Max(A, N, M);
	double Min = poisk_Min(A, N, M);
	std::cout << "Maximum is:"  << Max <<std::endl;
	std::cout << "Minimum is:" << Min << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return 666;
}
