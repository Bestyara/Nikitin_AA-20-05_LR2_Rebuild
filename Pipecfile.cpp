using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "pipe.h"

int proverkavvodaint();

double proverkavvodadouble();

Pipe::Pipe()
{
	this->d = 0;
	this->l = 0;
	this->repair = 0;
}

istream& operator>> (istream& in, Pipe& p){
	cout << "������� ������� �����: ";
	p.d = proverkavvodaint();
	cout << "������� ����� �����: ";
	p.l = proverkavvodaint();
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

void Pipe::FixPipe() { //�������������� ������ �����
	repair = !repair;
	if (repair == 0) {
		cout << "������ ����� �� � �������" << endl;
	}
	if (repair == 1) {
		cout << "������ ����� � �������" << endl;
	}
}

int Pipe::getid() {
	return id;
}