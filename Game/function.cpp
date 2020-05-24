#include<iostream>
#include<conio.h>
#include"Headerfunction.h"

using namespace std;

bool gameOver;
const int height = 25;																				//высота поля
const int width = 70;																				//ширина поля
int platformX, platformY, platform;																	//переменные координат платформы
int ballX, ballY, moveX, moveY;

void startGame() {																					//функция игры
	platformX = width / 2 - 3, platformY = height - 3, platform = 0;								//начальные координаты платформы 
	ballX = width / 2, ballY = 20, moveX = 0, moveY = 1;											//начальные координаты и направление движения мяча
	while (!gameOver) {
		draw();
		platformMove();
		ballMove();
	}
	system("cls");
	cout << "\t\t\tИгра окончена!\n\n";
	system("pause");
	gameOver = false;
}
void startMenu(int switcher) {																		//функция стартового меню
	while (true)
	{
		system("cls");
		switch (switcher)
		{
		case 1: {
			cout << "\n\n\n\n\t\t       << НОВАЯ ИГРА >>"
				<< "\n\n\n\n\t\t          ПРОДОЛЖИТЬ"
				<< "\n\n\n\n\t\t            ПОМОЩЬ"
				<< "\n\n\n\n\t\t          ЗАЛ СЛАВЫ"
				<< "\n\n\n\n\t\t            ВЫХОД";
			break;
		}
		case 2: {
			cout << "\n\n\n\n\t\t          НОВАЯ ИГРА  "
				<< "\n\n\n\n\t\t       << ПРОДОЛЖИТЬ >>"
				<< "\n\n\n\n\t\t            ПОМОЩЬ"
				<< "\n\n\n\n\t\t          ЗАЛ СЛАВЫ"
				<< "\n\n\n\n\t\t            ВЫХОД";
			break;
		}
		case 3: {
			cout << "\n\n\n\n\t\t          НОВАЯ ИГРА"
				<< "\n\n\n\n\t\t          ПРОДОЛЖИТЬ"
				<< "\n\n\n\n\t\t       <<   ПОМОЩЬ   >>"
				<< "\n\n\n\n\t\t          ЗАЛ СЛАВЫ"
				<< "\n\n\n\n\t\t            ВЫХОД";
			break;
		}
		case 4: {
			cout << "\n\n\n\n\t\t          НОВАЯ ИГРА"
				<< "\n\n\n\n\t\t          ПРОДОЛЖИТЬ"
				<< "\n\n\n\n\t\t            ПОМОЩЬ"
				<< "\n\n\n\n\t\t       << ЗАЛ СЛАВЫ  >>"
				<< "\n\n\n\n\t\t            ВЫХОД      ";
			break;
		}
		case 5: {
			cout << "\n\n\n\n\t\t          НОВАЯ ИГРА"
				<< "\n\n\n\n\t\t          ПРОДОЛЖИТЬ"
				<< "\n\n\n\n\t\t            ПОМОЩЬ"
				<< "\n\n\n\n\t\t          ЗАЛ СЛАВЫ"
				<< "\n\n\n\n\t\t       <<   ВЫХОД    >>";
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
void draw() {																						//функция отрисовки платформы и мяча
	system("cls");
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++)
		{
			if (j == platformX + platform && i == platformY && platform != 6) {						//отрисовка платформы
				cout << "=";
				platform++;
			}
			else if (j == ballX && i == ballY) cout << "o";											//отрисовка мяча
			else cout << " ";
		}
		cout << endl;
	}
	platform = 0;
}
void platformMove() {
	if (_kbhit())																					//проверка нажатия клавишь
	{
		switch (_getch()) {
		case (75):
			platformX -= 3;																			//перемещение платформы влево
			if (platformX < 0) {
				platformX = 0;
			}
			break;
		case (77):
			platformX += 3;																			//преемещение платформы вправо
			if (platformX > width - 6) {
				platformX = width - 6;
			}
			break;
		}
	}
}
void ballMove() {																					//функция перемещения мяча и платформы
	if (ballX >= platformX && ballX <= platformX + 3 && ballY == platformY - 1)						//при столкновении мяча с левой частью платформы мяч летит влево
		moveX = -1;																					//смена направления
	if (ballX >= platformX + 3 && ballX <= platformX + 6 && ballY == platformY - 1)					//при столкновении мяча с правой частью платформы мяч летит вправо
		moveX = 1;																					//смена направления
	if (ballX >= platformX && ballX <= platformX + 6 && ballY == platformY - 1 || ballY <= 0)		//при столкновении мяча с платформой и верхнем краем поля
		moveY = -moveY;																				//смена направления
	if (ballX <= 0 || ballX >= width)																//при столкновении с левым или правым краем поля
		moveX = -moveX;																				//смена направления 
	if (ballY > platformY)																			//условие проигрыша
		gameOver = true;
	ballX += moveX;																					//изменение координат X мяча 
	ballY += moveY;																					//изменение координат Y мяча
}
void help() {																						//функция описания игры

}
void topGamer() {																					//функция вывода лучших игроков

}