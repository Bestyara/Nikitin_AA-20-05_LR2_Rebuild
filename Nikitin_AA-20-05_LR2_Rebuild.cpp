// try catch мусор в редактировании, проверить добавлена труба или нет
using namespace std;
#include <iostream>
#include <string>
#include "windows.h"
#include <fstream>
#include <vector>
#include <unordered_map>
#include "cs.h"
#include "pipe.h"

int proverkavvoda(int a) {
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

double proverkavvoda(double a) {// перегрузка функций
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

void DelPipe(unordered_map <int, Pipe>& PipeMap);

void FindandFixPipe(unordered_map <int, Pipe>& PipeMap);

void savefilepipe(const unordered_map <int, Pipe>& PipeMap, ofstream& filesave);

void loadfilepipe(unordered_map <int, Pipe>& PipeMap, ifstream& fileload);

void DelStation(unordered_map <int, CompressorStation>& CSMap);

void FindandFixStation(unordered_map <int, CompressorStation>& CSMap);

void savefilestation(const unordered_map <int, CompressorStation>& CSMap, ofstream& filesave);

void loadfilestation(unordered_map <int, CompressorStation>& CSMap, ifstream& fileload);

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
	cout << "10 - Найти трубы в ремонте и выполнить пакетное редактирование" << endl;
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
	int menu = 1;
	unordered_map <int, Pipe> PipeMap;
	unordered_map <int, CompressorStation> CSMap;
	while (menu != 0) {
		mainmenu();
		menu = proverkavvoda(menu);
		proverkamenu(menu);
		switch (menu) {
			case 1: {
				PipeMap.insert(pair <int, Pipe>(Pipe::id, Pipe()));
				cin >> PipeMap[Pipe::id];
				Pipe::id++;
				break;
			}
			case 2: {
				CSMap.insert(pair <int, CompressorStation>(CompressorStation::id, CompressorStation()));
				cin >> CSMap[CompressorStation::id];
				CompressorStation::id++;
				break;
			}
			case 3: {
				cout << PipeMap;
				cout << CSMap;
				break;
			}
			case 4: {
				int i = -2;
				cout << endl << "Введите ID трубы для редактирования: ";
				i = proverkavvoda(i);
				if (PipeMap.count(i) != 0) {
					PipeMap[i].FixPipe(PipeMap,i);
				}
				else {
					cout << "Введите другое значение" << endl;
				}
				break;
			}
			case 5: {
				int j = -2;
				cout << endl << "Введите ID КС для редактирования: ";
				j = proverkavvoda(j);
				if (CSMap.count(j) != 0) {
					CSMap[j].FixStation(CSMap,j);
				}
				else {
					cout << "Введите другое значение" << endl;
				}
				break;
			}
			case 6: {
				cout << endl << "Введите название файла: " << endl;
				string filenam;
				cin >> filenam;
				ofstream filesave(filenam + ".txt");
				savefilepipe(PipeMap, filesave);
				savefilestation(CSMap, filesave);
				filesave.close();
				break;
			}
			case 7: {
				cout << endl << "Введите название файла: " << endl;
				string filenam;
				cin >> filenam;
				ifstream fileload(filenam + ".txt");
				if (fileload.fail()) {
					cout << "Файл для считывания информации не был создан" << endl;
				}
				else {
					loadfilepipe(PipeMap, fileload);
					fileload.close(); 
					ifstream fileload(filenam + ".txt");
					loadfilestation(CSMap, fileload);
					fileload.close();
				}
				break;
			}
			case 8: {
				DelPipe(PipeMap);
				break;
			}
			case 9: {
				DelStation(CSMap);
				break;
			}
			case 10: {
				FindandFixPipe(PipeMap);
				break;
			}
			case 11: {
				FindandFixStation(CSMap);
				break;
			}
		}
		system("pause");
		system("cls");
	}
}

