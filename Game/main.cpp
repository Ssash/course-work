#include<iostream>
#include<locale>
#include<Windows.h>
#include "Headerfunction.h"

using namespace std;
																		//���������� ��������� � ����������� �������� ����
int main() {
	setlocale(LC_ALL, "rus");
	system("mode con cols=70 lines=25");															//��������� ������� ����
	system("title Game");
	system("color 0A");																				//��������� ����� ������
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);													//��������� ����������� ����������� ����
	CONSOLE_CURSOR_INFO cursor = { 100,false };														
	SetConsoleCursorInfo(hCons, &cursor);
	startMenu(1);
	return 0;
}
