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
	cout << "������� ������� �����: ";
	p.d = proverkavvoda(p.d);
	cout << "������� ����� �����: ";
	p.l = proverkavvoda(p.l);
	p.repair = 0;
	return in;
}

ostream& operator<< (ostream& out, const unordered_map <int, Pipe>& PipeMap) {
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {// https://stackoverflow.com/questions/14555751/how-to-iterate-over-a-c-stl-map-data-structure-using-the-auto-keyword
			out << endl << "�����: " << endl;
			out << endl << "ID: " << i.first;
			out << endl << "����� �����: " << i.second.l;
			out << endl << "������� �����: " << i.second.d;
			out << endl << "����� � �������:(0 - ���, 1 - ��): " << i.second.repair << endl;
		}
	}
	else
		out << endl << "����� �� ���� ���������" << endl;
	return out;
}

void Pipe::FixPipe(unordered_map <int, Pipe>& PipeMap, int& ind) { //�������������� ������ �����
	PipeMap[ind].repair = !PipeMap[ind].repair;
	if (PipeMap[ind].repair == 0) {
		cout << "������ ����� �� � �������" << endl;
	}
	if (PipeMap[ind].repair == 1) {
		cout << "������ ����� � �������" << endl;
	}
}

void DelPipe(unordered_map <int, Pipe>& PipeMap) {
	cout << endl << "������� ID �����, ������ � ������� ����� ������� (��� ��������� ����� �������� -1)" << endl;
	int ch = -2;
	ch = proverkavvoda(ch);
	if (PipeMap.count(ch) != 0) {
		while (ch != -1 && PipeMap.count(ch) != 0) {
			PipeMap.erase(PipeMap.find(ch));
			cout << endl << "������� ID �����, ������ � ������� ����� ������� (��� ��������� ����� �������� -1)" << endl;
			ch = proverkavvoda(ch);
		}
	}
	else {
		cout << endl << "������ ��� ����� ID" << endl;
	}
}

void FindandFixPipe(unordered_map <int, Pipe>& PipeMap) {//����� � �������� �������������� ����
	cout << endl << "������ � ������, ������� ��������� � �������: " << endl;
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {
			if (i.second.repair == 1) {
				cout << endl << "�����";
				cout << endl << "ID: " << i.first;
				cout << endl << "����� �����: " << i.second.l;
				cout << endl << "������� �����: " << i.second.d;
				cout << endl << "����� � �������:(0 - ���, 1 - ��): " << i.second.repair << endl;
			}
		}
	}
	cout << endl << "������� ID ����, ������ � ������� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
	int ch = -2;
	ch = proverkavvoda(ch);
	while (PipeMap.count(ch) == 0 && ch != -1) {
		cout << "������ ��� ����� ������, ������ � ����� � ������ ID �� �������, ������� ������ ��������" << endl;
		ch = proverkavvoda(ch);
	}
	while (ch != -1 && PipeMap.count(ch) != 0) {
		if (PipeMap[ch].repair == 0) {
			PipeMap[ch].repair = 1;
		}
		else {
			PipeMap[ch].repair = 0;
		}
		cout << endl << "������ ��������" << endl;
		cout << endl << "������� ID ����, ������ � ������� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
		ch = proverkavvoda(ch);
		while (PipeMap.count(ch) == 0 && ch != -1) {
			cout << "������ ��� ����� ������, ������ � ����� � ������ ID �� �������, ������� ������ ��������" << endl;
			ch = proverkavvoda(ch);
		}
	}
}

void savefilepipe(const unordered_map <int, Pipe>& PipeMap, ofstream& filesave) {
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {
			filesave << "�����:" << endl;
			filesave << i.first << endl;
			filesave << i.second.l << endl;
			filesave << i.second.d << endl;
			filesave << i.second.repair << endl;
		}
	}
	else
		filesave << "��� ������ � ������" << endl;
}

void loadfilepipe(unordered_map <int, Pipe>& PipeMap, ifstream& fileload) {
	string str;
	Pipe p;
	while (!fileload.eof()) {
		getline(fileload, str);
		if (str == "Pipe") {
			int strid;
			getline(fileload, str);//��������� id
			strid = stoi(str);
			if (PipeMap.count(strid) != 0) {
				getline(fileload, str);//��������� �������
				PipeMap[strid].d = stoi(str);
				getline(fileload, str);//��������� �����
				PipeMap[strid].l = stoi(str);
			}
			else {
				getline(fileload, str);//��������� �������
				p.d = stoi(str);
				getline(fileload, str);//��������� �����
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