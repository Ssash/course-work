#include<iostream>
#include<conio.h>
#include"Headerfunction.h"

using namespace std;

bool gameOver;
const int height = 25;																				//������ ����
const int width = 70;																				//������ ����
int platformX, platformY, platform;																	//���������� ��������� ���������
int ballX, ballY, moveX, moveY;

void startGame() {																					//������� ����
	platformX = width / 2 - 3, platformY = height - 3, platform = 0;								//��������� ���������� ��������� 
	ballX = width / 2, ballY = 20, moveX = 0, moveY = 1;											//��������� ���������� � ����������� �������� ����
	while (!gameOver) {
		draw();
		platformMove();
		ballMove();
	}
	system("cls");
	cout << "\t\t\t���� ��������!\n\n";
	system("pause");
	gameOver = false;
}
void startMenu(int switcher) {																		//������� ���������� ����
	while (true)
	{
		system("cls");
		switch (switcher)
		{
		case 1: {
			cout << "\n\n\n\n\t\t       << ����� ���� >>"
				<< "\n\n\n\n\t\t          ����������"
				<< "\n\n\n\n\t\t            ������"
				<< "\n\n\n\n\t\t          ��� �����"
				<< "\n\n\n\n\t\t            �����";
			break;
		}
		case 2: {
			cout << "\n\n\n\n\t\t          ����� ����  "
				<< "\n\n\n\n\t\t       << ���������� >>"
				<< "\n\n\n\n\t\t            ������"
				<< "\n\n\n\n\t\t          ��� �����"
				<< "\n\n\n\n\t\t            �����";
			break;
		}
		case 3: {
			cout << "\n\n\n\n\t\t          ����� ����"
				<< "\n\n\n\n\t\t          ����������"
				<< "\n\n\n\n\t\t       <<   ������   >>"
				<< "\n\n\n\n\t\t          ��� �����"
				<< "\n\n\n\n\t\t            �����";
			break;
		}
		case 4: {
			cout << "\n\n\n\n\t\t          ����� ����"
				<< "\n\n\n\n\t\t          ����������"
				<< "\n\n\n\n\t\t            ������"
				<< "\n\n\n\n\t\t       << ��� �����  >>"
				<< "\n\n\n\n\t\t            �����      ";
			break;
		}
		case 5: {
			cout << "\n\n\n\n\t\t          ����� ����"
				<< "\n\n\n\n\t\t          ����������"
				<< "\n\n\n\n\t\t            ������"
				<< "\n\n\n\n\t\t          ��� �����"
				<< "\n\n\n\n\t\t       <<   �����    >>";
			break;
		}
		}
		switcher = inputMenu(switcher);
	}
}
int inputMenu(int inputValue) {
	int key = _getch();
	if (key == 224) key = _getch();
	if (key == 72)
		if (inputValue != 1) startMenu(inputValue - 1);
		else startMenu(5);
	if (key == 80)
		if (inputValue != 5)
			startMenu(inputValue + 1);
		else startMenu(1);
	if (key == 13 || key == 32) {
		if (inputValue == 1)startGame();
		if (inputValue == 2)startGame();
		if (inputValue == 3)help();
		if (inputValue == 4)topGamer();
		if (inputValue == 5)_exit(0);

	}
	return inputValue;
}
void draw() {																						//������� ��������� ��������� � ����
	system("cls");
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++)
		{
			if (j == platformX + platform && i == platformY && platform != 6) {						//��������� ���������
				cout << "=";
				platform++;
			}
			else if (j == ballX && i == ballY) cout << "o";											//��������� ����
			else cout << " ";
		}
		cout << endl;
	}
	platform = 0;
}
void platformMove() {
	if (_kbhit())																					//�������� ������� �������
	{
		switch (_getch()) {
		case (75):
			platformX -= 3;																			//����������� ��������� �����
			if (platformX < 0) {
				platformX = 0;
			}
			break;
		case (77):
			platformX += 3;																			//����������� ��������� ������
			if (platformX > width - 6) {
				platformX = width - 6;
			}
			break;
		}
	}
}
void ballMove() {																					//������� ����������� ���� � ���������
	if (ballX >= platformX && ballX <= platformX + 3 && ballY == platformY - 1)						//��� ������������ ���� � ����� ������ ��������� ��� ����� �����
		moveX = -1;																					//����� �����������
	if (ballX >= platformX + 3 && ballX <= platformX + 6 && ballY == platformY - 1)					//��� ������������ ���� � ������ ������ ��������� ��� ����� ������
		moveX = 1;																					//����� �����������
	if (ballX >= platformX && ballX <= platformX + 6 && ballY == platformY - 1 || ballY <= 0)		//��� ������������ ���� � ���������� � ������� ����� ����
		moveY = -moveY;																				//����� �����������
	if (ballX <= 0 || ballX >= width)																//��� ������������ � ����� ��� ������ ����� ����
		moveX = -moveX;																				//����� ����������� 
	if (ballY > platformY)																			//������� ���������
		gameOver = true;
	ballX += moveX;																					//��������� ��������� X ���� 
	ballY += moveY;																					//��������� ��������� Y ����
}
void help() {																						//������� �������� ����

}
void topGamer() {																					//������� ������ ������ �������

}