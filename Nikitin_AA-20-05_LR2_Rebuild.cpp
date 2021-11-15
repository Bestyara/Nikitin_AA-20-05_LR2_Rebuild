// try catch мусор в редактировании, проверить добавлена труба или нет
using namespace std;
#include <iostream>
#include <string>
#include "windows.h"
#include <fstream>
#include <map>
#include <vector>
#include <unordered_map>
#include "cs.h"
#include "pipe.h"

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
void Pipe::PrintPipe(const unordered_map <int, Pipe>& PipeMap) //Вывод данных о трубе
{
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {// https://stackoverflow.com/questions/14555751/how-to-iterate-over-a-c-stl-map-data-structure-using-the-auto-keyword
			cout << endl << "Труба: " << endl;
			cout << endl << "ID: " << i.first;
			cout << endl << "Длина трубы: " << i.second.l;
			cout << endl << "Диаметр трубы: " << i.second.d;
			cout << endl << "Труба в ремонте:(0 - Нет, 1 - Да): " << i.second.repair << endl;
		}
	}
	else
		cout << endl <<"Труба не была добавлена" << endl;
}

void CompressorStation::PrintCompressorstation(const unordered_map <int, CompressorStation>& CSMap) //Вывод данных о КС
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

void Pipe::DelPipe(unordered_map <int, Pipe>& PipeMap) {
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

void CompressorStation::DelStation(unordered_map <int, CompressorStation>& CSMap) {
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

void Pipe::FindandFixPipe(unordered_map <int, Pipe>& PipeMap) {//поиск и пакетное редактирование труб
	cout << endl << "Данные о трубах, которые находятся в ремонте: " << endl;
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
	while (PipeMap.count(ch) == 0 && ch != -1) {
		cout << "Ошибка при вводе данных, данные о трубе с данным ID не найдены, введите другое значение" << endl;
		ch = proverkavvoda();
	}
	while (ch != -1 && PipeMap.count(ch) != 0) {
		if (PipeMap[ch].repair == 0) {
			PipeMap[ch].repair = 1;
		}
		else {
			PipeMap[ch].repair = 0;
		}
		cout << endl << "Данные изменены" << endl;
		cout << endl << "Введите ID труб, данные о ремонте которых хотели бы изменить (для окончания ввода напишите -1):" << endl;
		ch = proverkavvoda();
		while (PipeMap.count(ch) == 0 && ch != -1) {
			cout << "Ошибка при вводе данных, данные о трубе с данным ID не найдены, введите другое значение" << endl;
			ch = proverkavvoda();
		}
	}
}

void CompressorStation::FindandFixStation(unordered_map <int, CompressorStation>& CSMap) {//поиск и пакетное редактирование КС
	cout << endl << "Поиск по какому параметру произвести?" << endl;
	cout << "1 - Название";
	cout << endl << "2 - Процент задейстованных цехов" << endl;
	int ch;
	ch = proverkavvoda();
	switch(ch){
		case 1: {//название
			cout << endl << "Введите название КС:" << endl;
			string str;
			cin.ignore(32767, '\n');
			getline(cin, str);
			cout << endl << "Результат поиска: ";
			for (auto& i : CSMap) {
				if (i.second.name == str) {
					cout << endl << "Компрессорная станция:" << endl;
					cout << endl << "ID: " << i.first << endl;
					cout << "Наименование: " << i.second.name << endl;
					cout << "Количество цехов: " << i.second.kol << endl;
					cout << "Количество цехов в работе: " << i.second.kolinwork << endl;
					cout << "Эффективность: " << i.second.effectiveness << endl;
				}
			}
			cout << endl << "Выберите действие (для выхода введите -1):";
			cout << endl << "1 - Изменить данные всех найденных КС";
			cout << endl << "2 - Выборочно изменить данные некоторых КС" << endl;
			int ch1;
			ch1 = proverkavvoda();
			switch (ch1) {
				case 1: {
					string str1;
					cout << "Введите новое название КС" << endl;
					cin.ignore(32767, '\n');
					getline(cin, str1);
					for (auto& i : CSMap) {
						if (i.second.name == str) {
							i.second.name = str1;
						}
					}
					cout << "Данные изменены" << endl;
					break;
				}
				case 2: {
					string str1;
					cout << "Введите новое название КС" << endl;
					cin.ignore(32767, '\n');
					getline(cin, str1);
					cout << endl << "Введите ID КС, название которой хотели бы изменить (для окончания ввода напишите -1):" << endl;
					ch1 = proverkavvoda();
					while (CSMap.count(ch1) == 0 && ch1 != -1) {
						cout << "Ошибка при вводе данных, данные о КС с данным ID не найдены, введите другое значение" << endl;
						ch1 = proverkavvoda();
					}
					while (ch1 != -1 && CSMap.count(ch1) != 0) {
						CSMap[ch1].name = str1;
						cout << endl << "Данные изменены" << endl;
						cout << endl << "Введите ID КС, название которой хотели бы изменить (для окончания ввода напишите -1):" << endl;
						ch1 = proverkavvoda();
						while (CSMap.count(ch1) == 0 && ch1 != -1) {
							cout << "Ошибка при вводе данных, данные о КС с данным ID не найдены, введите другое значение" << endl;
							ch1 = proverkavvoda();
						}
					}
					break;
				}
				default: {
					cout << "Ошибка при вводе данных";
					break;
				}
			}
			break;
		}
		case 2: {//процент задейстованных цехов
			cout << endl << "Введите минимальный процент задейстованных цехов: " << endl;
			int percent;
			cin >> percent;
			cout << endl << "Результат поиска: ";
			for (auto& i : CSMap) {
				if ((double(i.second.kolinwork) / double(i.second.kol) * 100) >= percent) {
					cout << endl << "Компрессорная станция:" << endl;
					cout << endl << "ID: " << i.first << endl;
					cout << "Наименование: " << i.second.name << endl;
					cout << "Количество цехов: " << i.second.kol << endl;
					cout << "Количество цехов в работе: " << i.second.kolinwork << endl;
					cout << "Эффективность: " << i.second.effectiveness << endl;
				}
			}
			cout << endl << "Выберите действие (для выхода введите -1):";
			cout << endl << "1 - Изменить данные всех найденных КС";
			cout << endl << "2 - Выборочно изменить данные некоторых КС" << endl;
			int num;
			num = proverkavvoda();
			switch (num) {
				case 1: {
					cout << "Введите у скольких цехов возобновить работу:" << endl;
					int kolvo;
					kolvo = proverkavvoda();
					for (auto& i : CSMap) {
						if (((double(i.second.kolinwork) / double(i.second.kol) * 100) >= percent) && (i.second.kolinwork+kolvo <= i.second.kol)) {
							i.second.kolinwork += kolvo;
							cout << "Данные КС с ID " << i.first << " изменены" << endl;
						}
						else if (i.second.kolinwork + kolvo > i.second.kol) {
							cout << "Ошибка при вводе числа, у КС с ID " << i.first << " значение не может быть изменено" << endl;
						}
					}
					break;
				}
				case 2: {
					cout << "Введите у скольких цехов возобновить работу:" << endl;
					int kolvo;
					kolvo = proverkavvoda();
					int ch1;
					cout << endl << "Введите ID КС, число рабочих цехов которой хотели бы изменить (для окончания ввода напишите -1):" << endl;
					ch1 = proverkavvoda();
					while (CSMap.count(ch1) == 0 && ch1 != -1) {
						cout << "Ошибка при вводе данных, данные о КС с данным ID не найдены, введите другое значение" << endl;
						ch1 = proverkavvoda();
					}
					while (ch1 != -1 && CSMap.count(ch1) != 0) {
						if (CSMap[ch1].kolinwork + kolvo <= CSMap[ch1].kol) {
							CSMap[ch1].kolinwork += kolvo;
							cout << "Данные КС с ID " << ch1 << " изменены" << endl;
							cout << endl << "Введите ID КС, число рабочих цехов которой хотели бы изменить (для окончания ввода напишите -1):" << endl;
							ch1 = proverkavvoda();
							while (CSMap.count(ch1) == 0 && ch1 != -1) {
								cout << "Ошибка при вводе данных, данные о КС с данным ID не найдены, введите другое значение" << endl;
								ch1 = proverkavvoda();
							}
						}
						else if (CSMap[ch1].kolinwork + kolvo > CSMap[ch1].kol) {
							cout << "Ошибка при вводе числа, у КС с ID " << ch1 << " значение не может быть изменено" << endl;
						}
					}
					break;
				}
				default: {
					cout << "Ошибка при вводе данных";
					break;
				}
			}
			break;
		}
		default: {
			cout << "Ошибка при вводе данных";
			break;
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
	cout << "10 - Найти трубы в ремонте и выполнить пакетное редактирование" << endl;
	cout << "11 - Найти КС по названию, проценту задействованных цехов и выполнить пакетное редактирование" << endl;
	cout << "0 - Выход" << endl << endl;
}

void Pipe::savefilepipe(const unordered_map <int, Pipe>& PipeMap, ofstream& filesave) {
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
}

void CompressorStation::savefilestation(const unordered_map <int, CompressorStation>& CSMap, ofstream& filesave) {
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

void Pipe::loadfilepipe(unordered_map <int, Pipe>& PipeMap, ifstream& fileload) {
	string str;
	Pipe p;
	while (!fileload.eof()) {
		getline(fileload, str);
		if (str == "Pipe") {
			int strid;
			getline(fileload, str);//считываем id
			strid = stoi(str);
			if (PipeMap.count(strid) != 0) {
				getline(fileload, str);//считываем диаметр
				PipeMap[strid].d = stoi(str);
				getline(fileload, str);//считываем длину
				PipeMap[strid].l = stoi(str);
			}
			else {
				getline(fileload, str);//считываем диаметр
				p.d = stoi(str);
				getline(fileload, str);//считываем длину
				p.l = stoi(str);
				PipeMap.insert(pair <int, Pipe>(strid, p));
			}
		}
		else if (str == "Compressor Station") {
			getline(fileload, str);
			getline(fileload, str);
			getline(fileload, str);
			getline(fileload, str);
			getline(fileload, str);
		}
	}
}

void CompressorStation::loadfilestation(unordered_map <int, CompressorStation>& CSMap, ifstream& fileload) {
	string str;
	CompressorStation cs;
	while (!fileload.eof()) {
		getline(fileload, str);
		if (str == "Pipe") {
			getline(fileload, str);
			getline(fileload, str);
			getline(fileload, str);
		}
		else if (str == "Compressor Station") {
			int strid;
			getline(fileload, str);//считываем id
			strid = stoi(str);
			if (CSMap.count(strid) != 0) {
				getline(fileload, str);//считываем название
				CSMap[strid].name = str;
				getline(fileload, str);//считываем кол-во цехов
				CSMap[strid].kol = stoi(str);
				getline(fileload, str);//считываем кол-во рабочих цехов
				CSMap[strid].kolinwork = stoi(str);
				getline(fileload, str);//считываем эффективность
				CSMap[strid].effectiveness = stoi(str);
			}
			else {
				getline(fileload, str);//считываем название
				cs.name = str;
				getline(fileload, str);//считываем кол-во цехов
				cs.kol = stoi(str);
				getline(fileload, str);//считываем кол-во рабочих цехов
				cs.kolinwork = stoi(str);
				getline(fileload, str);//считываем эффективность
				cs.effectiveness = stoi(str);
				CSMap.insert(pair <int, CompressorStation>(strid, cs));
			}
		}
	}
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
	int pipeid = 0, stationid = 0;
	int i = 0, j = 0;
	unordered_map <int, Pipe> PipeMap;
	unordered_map <int, CompressorStation> CSMap;
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
				if (PipeMap.count(i) != 0) {
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
				if (CSMap.count(j) != 0) {
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
				p.savefilepipe(PipeMap, filesave);
				cs.savefilestation(CSMap, filesave);
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
					p.loadfilepipe(PipeMap, fileload);
					fileload.close(); 
					ifstream fileload(filenam + ".txt");
					cs.loadfilestation(CSMap, fileload);
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
			case 11: {
				cs.FindandFixStation(CSMap);
				break;
			}
		}
		system("pause");
		system("cls");
	}
}