#include<iostream>
#include<locale>
#include<Windows.h>
#include "Headerfunction.h"

using namespace std;

																		//переменные координат и направление движени€ м€ча

int main() {
	setlocale(LC_ALL, "rus");
	system("mode con cols=70 lines=25");															//установка размера окна
	system("title Game");
	system("color 0A");																				//установка цвета шрифта
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);													//получение дескриптора консольного окна
	CONSOLE_CURSOR_INFO cursor = { 100,false };														//сокрытие курсора
	SetConsoleCursorInfo(hCons, &cursor);
	startMenu(1);
	return 0;
}
