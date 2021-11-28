using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "cs.h"

int proverkavvoda(int a);

double proverkavvoda(double a);

CompressorStation::CompressorStation()
{
	this->name = "";
	this->kol = 0;
	this->kolinwork = 0;
	this->effectiveness = 0;
}

istream& operator>> (istream& in, CompressorStation& cs) {
	cout << "Введите наименование: ";
	in.ignore(32767, '\n');//https://ravesli.com/urok-57-vvedenie-v-std-string/
	getline(in, cs.name);
	cout << "Количество цехов: ";
	cs.kol = proverkavvoda(cs.kol);
	cout << "Количество цехов в работе: ";
	cs.kolinwork = proverkavvoda(cs.kolinwork);
	while ((cs.kolinwork < 1) || (cs.kolinwork > cs.kol)) {
		cout << "Ошибка ввода, введите другое значение" << endl;
		cs.kolinwork = proverkavvoda(cs.kolinwork);
	}
	cout << "Эффективность: ";
	cs.effectiveness = proverkavvoda(cs.effectiveness);
	return in;
}
ostream& operator<< (ostream& out, const unordered_map <int, CompressorStation>& CSMap) {
	if (CSMap.size() != 0) {
		for (auto& i : CSMap) {// https://stackoverflow.com/questions/14555751/how-to-iterate-over-a-c-stl-map-data-structure-using-the-auto-keyword
			out << endl << "Компрессорная станция:" << endl;
			out << endl << "ID: " << i.first << endl;
			out << "Наименование: " << i.second.name << endl;
			out << "Количество цехов: " << i.second.kol << endl;
			out << "Количество цехов в работе: " << i.second.kolinwork << endl;
			out << "Эффективность: " << i.second.effectiveness << endl;
		}
	}
	else
		out << endl << "КС не была добавлена" << endl;
	return out;
}
void FixStation(unordered_map <int, CompressorStation>& CSMap,int& j) { //Редактирование данных о КС
	cout << "Введите что нужно сделать (возобновить работу цехов, остановить работу цехов)" << endl;
	cout << "1 - Возобновить работу цехов " << endl;
	cout << "2 - Остановить работу цехов " << endl << endl;
	int kol = -2;
	kol = proverkavvoda(kol);
	switch (kol) {
	case 1: {
		cout << "У скольких цехов нужно возобновить работу: ";
		int kolvo = -2;
		kolvo = proverkavvoda(kolvo);
		while (CSMap[j].kolinwork + kolvo > kol) {
			cout << "Ошибка ввода, введите другое значение" << endl;
			kolvo = proverkavvoda(kolvo);
		}
		CSMap[j].kolinwork += kolvo;
		break;
	}
	case 2: {
		cout << "У скольких цехов нужно остановить работу: ";
		int kolvo = 0;
		kolvo = proverkavvoda(kolvo);
		while (CSMap[j].kolinwork - kolvo < 0) {
			cout << "Ошибка ввода, введите другое значение" << endl;
			kolvo = proverkavvoda(kolvo);
		}
		CSMap[j].kolinwork -= kolvo;
		break;
	}
	default:
		cout << endl << "Ошибка при вводе значения";
		break;
	}
}

void DelStation(unordered_map <int, CompressorStation>& CSMap) {
	cout << endl << "Введите ID КС, данные о которой нужно удалить (для окончания ввода напишите -1)" << endl;
	int ch = -2;
	ch = proverkavvoda(ch);
	if (CSMap.count(ch) != 0) {
		while (ch != -1 && CSMap.count(ch) != 0) {
			CSMap.erase(CSMap.find(ch));
			cout << endl << "Введите ID КС, данные о которой нужно удалить (для окончания ввода напишите -1)" << endl;
			ch = proverkavvoda(ch);
		}
	}
	else {
		cout << endl << "Ошибка при вводе ID" << endl;
	}
}

void FindandFixStation(unordered_map <int, CompressorStation>& CSMap) {//поиск и пакетное редактирование КС
	cout << endl << "Поиск по какому параметру произвести?" << endl;
	cout << "1 - Название";
	cout << endl << "2 - Процент задейстованных цехов" << endl;
	int ch = -2;
	ch = proverkavvoda(ch);
	switch (ch) {
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
		int ch1 = -2;
		ch1 = proverkavvoda(ch1);
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
			ch1 = proverkavvoda(ch1);
			while (CSMap.count(ch1) == 0 && ch1 != -1) {
				cout << "Ошибка при вводе данных, данные о КС с данным ID не найдены, введите другое значение" << endl;
				ch1 = proverkavvoda(ch1);
			}
			while (ch1 != -1 && CSMap.count(ch1) != 0) {
				CSMap[ch1].name = str1;
				cout << endl << "Данные изменены" << endl;
				cout << endl << "Введите ID КС, название которой хотели бы изменить (для окончания ввода напишите -1):" << endl;
				ch1 = proverkavvoda(ch1);
				while (CSMap.count(ch1) == 0 && ch1 != -1) {
					cout << "Ошибка при вводе данных, данные о КС с данным ID не найдены, введите другое значение" << endl;
					ch1 = proverkavvoda(ch1);
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
		int num = -2;
		num = proverkavvoda(num);
		switch (num) {
		case 1: {
			cout << "Введите у скольких цехов возобновить работу:" << endl;
			int kolvo = -2;
			kolvo = proverkavvoda(kolvo);
			for (auto& i : CSMap) {
				if (((double(i.second.kolinwork) / double(i.second.kol) * 100) >= percent) && (i.second.kolinwork + kolvo <= i.second.kol)) {
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
			int kolvo = -2;
			kolvo = proverkavvoda(kolvo);
			cout << endl << "Введите ID КС, число рабочих цехов которой хотели бы изменить (для окончания ввода напишите -1):" << endl;
			int ch1 = -2;
			ch1 = proverkavvoda(ch1);
			while (CSMap.count(ch1) == 0 && ch1 != -1) {
				cout << "Ошибка при вводе данных, данные о КС с данным ID не найдены, введите другое значение" << endl;
				ch1 = proverkavvoda(ch1);
			}
			while (ch1 != -1 && CSMap.count(ch1) != 0) {
				if (CSMap[ch1].kolinwork + kolvo <= CSMap[ch1].kol) {
					CSMap[ch1].kolinwork += kolvo;
					cout << "Данные КС с ID " << ch1 << " изменены" << endl;
					cout << endl << "Введите ID КС, число рабочих цехов которой хотели бы изменить (для окончания ввода напишите -1):" << endl;
					ch1 = proverkavvoda(ch1);
					while (CSMap.count(ch1) == 0 && ch1 != -1) {
						cout << "Ошибка при вводе данных, данные о КС с данным ID не найдены, введите другое значение" << endl;
						ch1 = proverkavvoda(ch1);
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

void savefilestation(const unordered_map <int, CompressorStation>& CSMap, ofstream& filesave) {
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

void loadfilestation(unordered_map <int, CompressorStation>& CSMap, ifstream& fileload) {
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