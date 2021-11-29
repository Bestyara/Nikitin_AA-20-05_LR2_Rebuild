using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "pipe.h"

int proverkavvoda(int a);

double proverkavvoda(double a);

Pipe::Pipe()
{
	this->d = 0;
	this->l = 0;
	this->repair = 0;
}

istream& operator>> (istream& in, Pipe& p){
	cout << "Введите диаметр трубы: ";
	p.d = proverkavvoda(p.d);
	cout << "Введите длину трубы: ";
	p.l = proverkavvoda(p.l);
	p.repair = 0;
	return in;
}

ostream& operator<< (ostream& out, const unordered_map <int, Pipe>& PipeMap) {
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {// https://stackoverflow.com/questions/14555751/how-to-iterate-over-a-c-stl-map-data-structure-using-the-auto-keyword
			out << endl << "Труба: " << endl;
			out << endl << "ID: " << i.first;
			out << endl << "Длина трубы: " << i.second.l;
			out << endl << "Диаметр трубы: " << i.second.d;
			out << endl << "Труба в ремонте:(0 - Нет, 1 - Да): " << i.second.repair << endl;
		}
	}
	else
		out << endl << "Труба не была добавлена" << endl;
	return out;
}

void Pipe::FixPipe(unordered_map <int, Pipe>& PipeMap, int& ind) { //Редактирование данных трубы
	PipeMap[ind].repair = !PipeMap[ind].repair;
	if (PipeMap[ind].repair == 0) {
		cout << "Теперь труба не в ремонте" << endl;
	}
	if (PipeMap[ind].repair == 1) {
		cout << "Теперь труба в ремонте" << endl;
	}
}

void DelPipe(unordered_map <int, Pipe>& PipeMap) {
	cout << endl << "Введите ID трубы, данные о которой нужно удалить (для окончания ввода напишите -1)" << endl;
	int ch = -2;
	ch = proverkavvoda(ch);
	if (PipeMap.count(ch) != 0) {
		while (ch != -1 && PipeMap.count(ch) != 0) {
			PipeMap.erase(PipeMap.find(ch));
			cout << endl << "Введите ID трубы, данные о которой нужно удалить (для окончания ввода напишите -1)" << endl;
			ch = proverkavvoda(ch);
		}
	}
	else {
		cout << endl << "Ошибка при вводе ID" << endl;
	}
}

void FindandFixPipe(unordered_map <int, Pipe>& PipeMap) {//поиск и пакетное редактирование труб
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
	int ch = -2;
	ch = proverkavvoda(ch);
	while (PipeMap.count(ch) == 0 && ch != -1) {
		cout << "Ошибка при вводе данных, данные о трубе с данным ID не найдены, введите другое значение" << endl;
		ch = proverkavvoda(ch);
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
		ch = proverkavvoda(ch);
		while (PipeMap.count(ch) == 0 && ch != -1) {
			cout << "Ошибка при вводе данных, данные о трубе с данным ID не найдены, введите другое значение" << endl;
			ch = proverkavvoda(ch);
		}
	}
}

void savefilepipe(const unordered_map <int, Pipe>& PipeMap, ofstream& filesave) {
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

void loadfilepipe(unordered_map <int, Pipe>& PipeMap, ifstream& fileload) {
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