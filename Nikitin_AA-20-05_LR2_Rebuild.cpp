﻿// try catch мусор в редактировании, проверить добавлена труба или нет
#include <iostream>
#include <string>
#include "windows.h"
#include <fstream>
#include <unordered_map>
#include "cs.h"
#include "pipe.h"
#include "Network.h"

using namespace std;

int proverkavvodaint() {
	int a;
	while (true) {
		cin >> a;
		if (cin.fail() || a < -1) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введите другое значение" << endl;
		}
		else
			return a;
	}
}

double proverkavvodadouble() {// перегрузка функций
	double a;
	while (true) {
		cin >> a;
		if (cin.fail() || a < -1) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введите другое значение" << endl;
		}
		else
			return a;
	}
}

int Pipe::id = 0;

int CompressorStation::id = 0;

void mainmenu() {
	cout << "Введите одно из представленных чисел" << endl;
	cout << "1 - Добавить трубу" << endl;
	cout << "2 - Добавить КС" << endl;
	cout << "3 - Просмотр всех объектов" << endl;
	cout << "4 - Редактировать трубу" << endl;
	cout << "5 - Редактировать КС" << endl;
	cout << "6 - Сохранить" << endl;
	cout << "7 - Загрузить" << endl;
	cout << "8 - Удалить данные о трубах" << endl;
	cout << "9 - Удалить данные о КС" << endl;
	cout << "10 - Найти трубы в ремонте и выполнить пакетное редактирование/удаление" << endl;
	cout << "11 - Найти КС по названию, проценту задействованных цехов и выполнить пакетное редактирование" << endl;
	cout << "0 - Выход" << endl << endl;
}

void proverkamenu(const int& menu) {
	if ((menu > 11) || (menu < 0)) {
		cout << "Введите другое число" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian"); 
	Network seti;
	int menu = 1;
	while (menu != 0) {
		mainmenu();
		menu = proverkavvodaint();
		proverkamenu(menu);
		switch (menu) {
			case 1: {
				//if (seti.PipeMap.count(Pipe::getid()) == 0) {
				//	seti.PipeMap.insert(pair <int, Pipe>(Pipe::getid(), Pipe()));//getnextid
				//	cin >> seti.PipeMap[Pipe::getid()];
				//}
				//else
				//	cout << "Труба с таким ID уже присутствует, ID увеличено попробуйте добавить трубу снова" << endl;
				//Pipe::id++;
				seti.AddPipe();
				break;
			}
			case 2: {
				/*if (seti.CSMap.count(CompressorStation::getid()) == 0) {
					seti.CSMap.insert(pair <int, CompressorStation>(CompressorStation::getid(), CompressorStation()));
					cin >> seti.CSMap[CompressorStation::getid()];
				}
				else
					cout << "КС с таким ID уже присутствует, ID увеличено попробуйте добавить КС снова" << endl;
				CompressorStation::id++;*/
				seti.AddStation();
				break;
			}
			case 3: {
				cout << seti.PipeMap;
				cout << seti.CSMap;
				break;
			}
			case 4: {

				cout << endl << "Введите ID трубы для редактирования: ";
				int i = proverkavvodaint();//!!!!!!!!!!!!!!!!
				if (seti.PipeMap.count(i) != 0) {
					seti.PipeMap[i].FixPipe();
				}
				else {
					cout << "Введите другое значение" << endl;
				}
				break;
			}
			case 5: {
				cout << endl << "Введите ID КС для редактирования: ";
				int j = proverkavvodaint();
				if (seti.CSMap.count(j) != 0) {
					seti.CSMap[j].FixStation();
				}
				else {
					cout << "Введите другое значение" << endl;
				}
				break;
			}
			case 6: {
				cout << endl << "Введите название файла: " << endl;
				string filenam;
				cin.ignore(32767, '\n');//https://ravesli.com/urok-57-vvedenie-v-std-string/
				getline(cin, filenam);
				ofstream filesave(filenam + ".txt");//!!!!!!!!!!!!!!!!!!!!!!
				if (filesave.fail()) {
					cout << "Файл для считывания информации не был создан" << endl;
				}
				else {
					seti.savefile(filesave);
					filesave.close();
				}
				break;
			}
			case 7: {
				Pipe::id = 0;
				CompressorStation::id = 0;
				cout << endl << "Введите название файла: " << endl;
				string filenam;
				cin.ignore(32767, '\n');//https://ravesli.com/urok-57-vvedenie-v-std-string/
				getline(cin, filenam);
				ifstream fileload(filenam + ".txt");//!!!!!!!!!!!!!!!!
				if (fileload.fail()) {
					cout << "Файл для считывания информации не был создан" << endl;
				}
				else {
					seti.loadfile(fileload);
					fileload.close();
				}
				break;
			}
			case 8: {
				seti.DelPipe();
				break;
			}
			case 9: {
				seti.DelStation();
				break;
			}
			case 10: {
				seti.FindandFixPipe();
				break;
			}
			case 11: {
				seti.FindandFixStation();
				break;
			}
		}
		system("pause");
		system("cls");
	}
}

