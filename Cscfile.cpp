using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "cs.h"

int proverkavvodaint();

double proverkavvodadouble();

CompressorStation::CompressorStation()
{
	this->name = "";
	this->kol = 0;
	this->kolinwork = 0;
	this->effectiveness = 0;
}

istream& operator>> (istream& in, CompressorStation& cs) {
	cout << "������� ������������: ";
	in.ignore(32767, '\n');//https://ravesli.com/urok-57-vvedenie-v-std-string/
	getline(in, cs.name);
	cout << "���������� �����: ";
	cs.kol = proverkavvodaint();
	cout << "���������� ����� � ������: ";
	cs.kolinwork = proverkavvodaint();
	while ((cs.kolinwork < 1) || (cs.kolinwork > cs.kol)) {
		cout << "������ �����, ������� ������ ��������" << endl;
		cs.kolinwork = proverkavvodaint();
	}
	cout << "�������������: ";
	cs.effectiveness = proverkavvodadouble();
	return in;
}
ostream& operator<< (ostream& out, const unordered_map <int, CompressorStation>& CSMap) {
	if (CSMap.size() != 0) {
		for (auto& i : CSMap) {
			out << endl << "������������� �������:" << endl;
			out << endl << "ID: " << i.first << endl;
			out << "������������: " << i.second.name << endl;
			out << "���������� �����: " << i.second.kol << endl;
			out << "���������� ����� � ������: " << i.second.kolinwork << endl;
			out << "�������������: " << i.second.effectiveness << endl;
		}
	}
	else
		out << endl << "�� �� ���� ���������" << endl;
	return out;
}
void CompressorStation::FixStation() { //�������������� ������ � ��
	cout << "������� ��� ����� ������� (����������� ������ �����, ���������� ������ �����)" << endl;
	cout << "1 - ����������� ������ ����� " << endl;
	cout << "2 - ���������� ������ ����� " << endl << endl;
	kol = proverkavvodaint();
	switch (kol) {
	case 1: {
		cout << "� �������� ����� ����� ����������� ������: ";
		int kolvo = proverkavvodaint();
		while (kolinwork + kolvo > kol) {
			cout << "������ �����, ������� ������ ��������" << endl;
			kolvo = proverkavvodaint();
		}
		kolinwork += kolvo;
		break;
	}
	case 2: {
		cout << "� �������� ����� ����� ���������� ������: ";
		int kolvo = proverkavvodaint();
		while (kolinwork - kolvo < 0) {
			cout << "������ �����, ������� ������ ��������" << endl;
			kolvo = proverkavvodaint();
		}
		kolinwork -= kolvo;
		break;
	}
	default:
		cout << endl << "������ ��� ����� ��������";
		break;
	}
}

int CompressorStation::getid() {
	return id;
}