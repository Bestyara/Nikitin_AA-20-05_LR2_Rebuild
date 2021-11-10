// try catch мусор в редактировании, проверить добавлена труба или нет
using namespace std;
#include <iostream>
#include <string>
#include "windows.h"
#include <fstream>
#include <map>
#include <vector>
#include "cs.h"
#include "pipe.h"

//class Pipe { //Структура трубы
//public:
//	int id;
//	int d;
//	int l;
//	bool repair;
//	Pipe AddPipe();
//	void PrintPipe(const map <int, Pipe>&);
//	void FixPipe(Pipe&);
//	void DelPipe(map <int, Pipe>&);
//	void FindandFixPipe(map <int, Pipe>&);
//};

//class CompressorStation { //Структура КС
//public:
//	int id;
//	string name;
//	int kol;
//	int kolinwork;
//	int effectiveness;
//	CompressorStation AddStation();
//	void PrintCompressorstation(const map <int, CompressorStation>&);
//	void FixStation(CompressorStation&);
//	void DelStation(map <int, CompressorStation>&);
//};

int proverkavvoda() {
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

Pipe Pipe::AddPipe(){ //Добавление трубы
	Pipe p; // { 0, 1420, 200, };
	cout << "Введите диаметр трубы: ";
	p.d = proverkavvoda();
	cout << "Введите длину трубы: ";
	p.l = proverkavvoda();
	p.repair = 0;
	return p;
}
CompressorStation CompressorStation::AddStation() { //Добавление КС
	CompressorStation cs;
	cout << "Введите наименование: ";
	cin.ignore(32767, '\n');//https://ravesli.com/urok-57-vvedenie-v-std-string/
	getline(cin, cs.name);
	cout << "Количество цехов: ";
	cs.kol = proverkavvoda();
	cout << "Количество цехов в работе: ";
	cs.kolinwork = proverkavvoda();
	while ((cs.kolinwork < 1) || (cs.kolinwork > cs.kol)) {
		cout << "Ошибка ввода, введите другое значение" << endl;
		cs.kolinwork = proverkavvoda();
	}
	cout << "Эффективность: ";
	cs.effectiveness = proverkavvoda();
	return cs;
}
void Pipe::PrintPipe(const map <int, Pipe>& PipeMap) //Вывод данных о трубе
{
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {// https://stackoverflow.com/questions/14555751/how-to-iterate-over-a-c-stl-map-data-structure-using-the-auto-keyword
			cout << endl << "Труба";
			cout << endl << "ID: " << i.first;
			cout << endl << "Длина трубы: " << i.second.l;
			cout << endl << "Диаметр трубы: " << i.second.d;
			cout << endl << "Труба в ремонте:(0 - Нет, 1 - Да): " << i.second.repair << endl;
		}
	}
	else
		cout << endl <<"Труба не была добавлена" << endl;
}

void CompressorStation::PrintCompressorstation(const map <int, CompressorStation>& CSMap) //Вывод данных о КС
{
	if (CSMap.size() != 0) {
		for (auto& i : CSMap) {// https://stackoverflow.com/questions/14555751/how-to-iterate-over-a-c-stl-map-data-structure-using-the-auto-keyword
				cout << endl << "Компрессорная станция:" << endl;
				cout << endl << "ID: " << i.first << endl;
				cout << "Наименование: " << i.second.name << endl;
				cout << "Количество цехов: " << i.second.kol << endl;
				cout << "Количество цехов в работе: " << i.second.kolinwork << endl;
				cout << "Эффективность: " << i.second.effectiveness << endl;
			}
	}
	else
		cout << endl << "КС не была добавлена" << endl;
}

void Pipe::FixPipe(Pipe& p) { //Редактирование данных трубы
	p.repair = !p.repair;
	if (p.repair == 0) {
		cout << "Теперь труба не в ремонте" << endl;
	}
	if (p.repair == 1) {
		cout << "Теперь труба в ремонте" << endl;
	}
}

void CompressorStation::FixStation(CompressorStation& cs) { //Редактирование данных о КС
	int num;
	cout << "Введите что нужно сделать (возобновить работу цехов, остановить работу цехов)" << endl;
	cout << "1 - Возобновить работу цехов " << endl;
	cout << "2 - Остановить работу цехов " << endl << endl;
	cin >> num;
	int kolvo;
	switch (num) {
	case 1: {
		cout << "У скольких цехов нужно возобновить работу: ";
		kolvo = proverkavvoda();
		while (cs.kolinwork + kolvo > cs.kol) {
			cout << "Ошибка ввода, введите другое значение" << endl;
			kolvo = proverkavvoda();
		}
		cs.kolinwork = cs.kolinwork + kolvo;
		break;
	}
	case 2: {
		cout << "У скольких цехов нужно остановить работу: ";
		kolvo = proverkavvoda();
		while (cs.kolinwork - kolvo < 0) {
			cout << "Ошибка ввода, введите другое значение" << endl;
			kolvo = proverkavvoda();
		}
		cs.kolinwork = cs.kolinwork - kolvo;
		break;
	}
	default:
		cout << endl << "Ошибка при вводе значения";
		break;
	}
}

void Pipe::DelPipe(map <int, Pipe>& PipeMap) {
	cout << endl << "Введите ID трубы, данные о которой нужно удалить (для окончания ввода напишите -1)" << endl;
	int ch = proverkavvoda();
	if (PipeMap.count(ch) != 0) {
		while (ch != -1 && PipeMap.count(ch) != 0) {
			PipeMap.erase(PipeMap.find(ch));
			cout << endl << "Введите ID трубы, данные о которой нужно удалить (для окончания ввода напишите -1)" << endl;
			ch = proverkavvoda();
		}
	}
	else {
		cout << endl << "Ошибка при вводе ID" << endl;
	}
}

void CompressorStation::DelStation(map <int, CompressorStation>& CSMap) {
	cout << endl << "Введите ID КС, данные о которой нужно удалить (для окончания ввода напишите -1)" << endl;
	int ch = proverkavvoda();
	if (CSMap.count(ch) != 0) {
		while (ch != -1 && CSMap.count(ch) != 0) {
		CSMap.erase(CSMap.find(ch));
		cout << endl << "Введите ID КС, данные о которой нужно удалить (для окончания ввода напишите -1)" << endl;
		ch = proverkavvoda();
		}
	}
	else {
		cout << endl << "Ошибка при вводе ID" << endl;
	}
}

void Pipe::FindandFixPipe(map <int, Pipe>& PipeMap) {
	cout << endl << "Данные о трубах, которые находятся в ремонте" << endl;
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {
			if (i.second.repair == 1) {
				cout << endl << "Труба";
				cout << endl << "ID: " << i.first;
				cout << endl << "Длина трубы: " << i.second.l;
				cout << endl << "Диаметр трубы: " << i.second.d;
				cout << endl << "Труба в ремонте:(0 - Нет, 1 - Да): " << i.second.repair << endl;
			}
		}
	}
	cout << endl << "Введите ID труб, данные о ремонте которых хотели бы изменить (для окончания ввода напишите -1):" << endl;
	int ch; 
	ch = proverkavvoda();
	while (ch >= PipeMap.size()) {
		cout << "Ошибка при вводе данных, введите другое значение" << endl;
		ch = proverkavvoda();
	}
	while (ch != -1 && ch < PipeMap.size()) {
		if (PipeMap[ch].repair == 0) {
			PipeMap[ch].repair = 1;
		}
		else {
			PipeMap[ch].repair = 0;
		}
		cout << endl << "Данные изменены" << endl;
		cout << endl << "Введите ID труб, данные о ремонте которых хотели бы изменить (для окончания ввода напишите -1):" << endl;
		ch = proverkavvoda();
		while (ch >= PipeMap.size()) {
			cout << "Ошибка при вводе данных, введите другое значение" << endl;
			ch = proverkavvoda();
		}
	}
}
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
	cout << "0 - Выход" << endl << endl;
}

void savefilepipe(const map <int, Pipe>& PipeMap, ofstream& filesave) {
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {
			filesave << "Труба:" << endl;
			filesave << i.first << endl;
			filesave << i.second.l << endl;
			filesave << i.second.d << endl;
			filesave << i.second.repair << endl;
		}
	}
	else
		filesave << "Нет данных о трубах" << endl;
	/*if (CSMap.size() != 0) {
		for (auto& i : CSMap) {
			filesave << "Компрессорная станция:" << endl;
			filesave << i.first << endl;
			filesave << i.second.name << endl;
			filesave << i.second.kol << endl;
			filesave << i.second.kolinwork << endl;
			filesave << i.second.effectiveness << endl;
		}
	}
	else
		filesave << "Нет данных о КС" << endl;*/
}

void savefilestation(const map <int, CompressorStation>& CSMap, ofstream& filesave) {
	if (CSMap.size() != 0) {
		for (auto& i : CSMap) {
			filesave << "Компрессорная станция:" << endl;
			filesave << i.first << endl;
			filesave << i.second.name << endl;
			filesave << i.second.kol << endl;
			filesave << i.second.kolinwork << endl;
			filesave << i.second.effectiveness << endl;
		}
	}
	else
		filesave << "Нет данных о КС" << endl;
}

void loadfilepipe(Pipe& p, CompressorStation& cs, ifstream& fileload) {
	string str;
	getline(fileload, str);
	if (str == "Труба:") {
		getline(fileload, str);
		p.d = stoi(str);
		getline(fileload, str);
		p.l = stoi(str);
	}
	getline(fileload, str);
	if (str == "Компрессорная станция:") {
		getline(fileload, str);
		cs.name = str;
		getline(fileload, str);
		cs.kol = stoi(str);
		getline(fileload, str);
		cs.kolinwork = stoi(str);
		getline(fileload, str);
		cs.effectiveness = stoi(str);
	}
}
void proverkamenu(const int& menu) {
	if ((menu > 9) || (menu < 0)) {
		cout << "Введите другое число" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int menu = 1;
	int pipeid = 0, stationid = 0;
	int i = 0, j = 0;
	map<int, Pipe> PipeMap;
	map<int, CompressorStation> CSMap;
	Pipe p;
	CompressorStation cs;
	while (menu != 0) {
		mainmenu();
		menu = proverkavvoda();
		proverkamenu(menu);
		switch (menu) {
			case 1: {
				PipeMap.insert(pair <int, Pipe>(pipeid, p.AddPipe()));
				pipeid++;
				break;
			}
			case 2: {
				CSMap.insert(pair <int, CompressorStation>(stationid, cs.AddStation()));
				stationid++;
				break;
			}
			case 3: {
				p.PrintPipe(PipeMap);
				cs.PrintCompressorstation(CSMap);
				break;
			}
			case 4: {
				cout << endl << "Введите ID трубы для редактирования: ";
				i = proverkavvoda();
				if (i < PipeMap.size()) {
					p.FixPipe(PipeMap[i]);
				}
				else {
					cout << "Введите другое значение" << endl;
				}
				break;
			}
			case 5: {
				cout << endl << "Введите ID КС для редактирования: ";
				j = proverkavvoda();
				if (j < CSMap.size()) {
					cs.FixStation(CSMap[j]);
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
					cout << "Файл  для считывания информации не был создан" << endl;
				}
				else {
					loadfilepipe(p, cs, fileload);
					fileload.close();
				}
				break;
			}
			case 8: {
				p.DelPipe(PipeMap);
				break;
			}
			case 9: {
				cs.DelStation(CSMap);
				break;
			}
			case 10: {
				p.FindandFixPipe(PipeMap);
				break;
			}
		}
		system("pause");
		system("cls");
	}
}