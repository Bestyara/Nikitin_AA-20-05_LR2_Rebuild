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
	cout << "������� ������������: ";
	in.ignore(32767, '\n');//https://ravesli.com/urok-57-vvedenie-v-std-string/
	getline(in, cs.name);
	cout << "���������� �����: ";
	cs.kol = proverkavvoda(cs.kol);
	cout << "���������� ����� � ������: ";
	cs.kolinwork = proverkavvoda(cs.kolinwork);
	while ((cs.kolinwork < 1) || (cs.kolinwork > cs.kol)) {
		cout << "������ �����, ������� ������ ��������" << endl;
		cs.kolinwork = proverkavvoda(cs.kolinwork);
	}
	cout << "�������������: ";
	cs.effectiveness = proverkavvoda(cs.effectiveness);
	return in;
}
ostream& operator<< (ostream& out, const unordered_map <int, CompressorStation>& CSMap) {
	if (CSMap.size() != 0) {
		for (auto& i : CSMap) {// https://stackoverflow.com/questions/14555751/how-to-iterate-over-a-c-stl-map-data-structure-using-the-auto-keyword
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
void FixStation(unordered_map <int, CompressorStation>& CSMap,int& j) { //�������������� ������ � ��
	cout << "������� ��� ����� ������� (����������� ������ �����, ���������� ������ �����)" << endl;
	cout << "1 - ����������� ������ ����� " << endl;
	cout << "2 - ���������� ������ ����� " << endl << endl;
	int kol = -2;
	kol = proverkavvoda(kol);
	switch (kol) {
	case 1: {
		cout << "� �������� ����� ����� ����������� ������: ";
		int kolvo = -2;
		kolvo = proverkavvoda(kolvo);
		while (CSMap[j].kolinwork + kolvo > kol) {
			cout << "������ �����, ������� ������ ��������" << endl;
			kolvo = proverkavvoda(kolvo);
		}
		CSMap[j].kolinwork += kolvo;
		break;
	}
	case 2: {
		cout << "� �������� ����� ����� ���������� ������: ";
		int kolvo = 0;
		kolvo = proverkavvoda(kolvo);
		while (CSMap[j].kolinwork - kolvo < 0) {
			cout << "������ �����, ������� ������ ��������" << endl;
			kolvo = proverkavvoda(kolvo);
		}
		CSMap[j].kolinwork -= kolvo;
		break;
	}
	default:
		cout << endl << "������ ��� ����� ��������";
		break;
	}
}

void DelStation(unordered_map <int, CompressorStation>& CSMap) {
	cout << endl << "������� ID ��, ������ � ������� ����� ������� (��� ��������� ����� �������� -1)" << endl;
	int ch = -2;
	ch = proverkavvoda(ch);
	if (CSMap.count(ch) != 0) {
		while (ch != -1 && CSMap.count(ch) != 0) {
			CSMap.erase(CSMap.find(ch));
			cout << endl << "������� ID ��, ������ � ������� ����� ������� (��� ��������� ����� �������� -1)" << endl;
			ch = proverkavvoda(ch);
		}
	}
	else {
		cout << endl << "������ ��� ����� ID" << endl;
	}
}

void FindandFixStation(unordered_map <int, CompressorStation>& CSMap) {//����� � �������� �������������� ��
	cout << endl << "����� �� ������ ��������� ����������?" << endl;
	cout << "1 - ��������";
	cout << endl << "2 - ������� �������������� �����" << endl;
	int ch = -2;
	ch = proverkavvoda(ch);
	switch (ch) {
	case 1: {//��������
		cout << endl << "������� �������� ��:" << endl;
		string str;
		cin.ignore(32767, '\n');
		getline(cin, str);
		cout << endl << "��������� ������: ";
		for (auto& i : CSMap) {
			if (i.second.name == str) {
				cout << endl << "������������� �������:" << endl;
				cout << endl << "ID: " << i.first << endl;
				cout << "������������: " << i.second.name << endl;
				cout << "���������� �����: " << i.second.kol << endl;
				cout << "���������� ����� � ������: " << i.second.kolinwork << endl;
				cout << "�������������: " << i.second.effectiveness << endl;
			}
		}
		cout << endl << "�������� �������� (��� ������ ������� -1):";
		cout << endl << "1 - �������� ������ ���� ��������� ��";
		cout << endl << "2 - ��������� �������� ������ ��������� ��" << endl;
		int ch1 = -2;
		ch1 = proverkavvoda(ch1);
		switch (ch1) {
		case 1: {
			string str1;
			cout << "������� ����� �������� ��" << endl;
			cin.ignore(32767, '\n');
			getline(cin, str1);
			for (auto& i : CSMap) {
				if (i.second.name == str) {
					i.second.name = str1;
				}
			}
			cout << "������ ��������" << endl;
			break;
		}
		case 2: {
			string str1;
			cout << "������� ����� �������� ��" << endl;
			cin.ignore(32767, '\n');
			getline(cin, str1);
			cout << endl << "������� ID ��, �������� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
			ch1 = proverkavvoda(ch1);
			while (CSMap.count(ch1) == 0 && ch1 != -1) {
				cout << "������ ��� ����� ������, ������ � �� � ������ ID �� �������, ������� ������ ��������" << endl;
				ch1 = proverkavvoda(ch1);
			}
			while (ch1 != -1 && CSMap.count(ch1) != 0) {
				CSMap[ch1].name = str1;
				cout << endl << "������ ��������" << endl;
				cout << endl << "������� ID ��, �������� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
				ch1 = proverkavvoda(ch1);
				while (CSMap.count(ch1) == 0 && ch1 != -1) {
					cout << "������ ��� ����� ������, ������ � �� � ������ ID �� �������, ������� ������ ��������" << endl;
					ch1 = proverkavvoda(ch1);
				}
			}
			break;
		}
		default: {
			cout << "������ ��� ����� ������";
			break;
		}
		}
		break;
	}
	case 2: {//������� �������������� �����
		cout << endl << "������� ����������� ������� �������������� �����: " << endl;
		int percent;
		cin >> percent;
		cout << endl << "��������� ������: ";
		for (auto& i : CSMap) {
			if ((double(i.second.kolinwork) / double(i.second.kol) * 100) >= percent) {
				cout << endl << "������������� �������:" << endl;
				cout << endl << "ID: " << i.first << endl;
				cout << "������������: " << i.second.name << endl;
				cout << "���������� �����: " << i.second.kol << endl;
				cout << "���������� ����� � ������: " << i.second.kolinwork << endl;
				cout << "�������������: " << i.second.effectiveness << endl;
			}
		}
		cout << endl << "�������� �������� (��� ������ ������� -1):";
		cout << endl << "1 - �������� ������ ���� ��������� ��";
		cout << endl << "2 - ��������� �������� ������ ��������� ��" << endl;
		int num = -2;
		num = proverkavvoda(num);
		switch (num) {
		case 1: {
			cout << "������� � �������� ����� ����������� ������:" << endl;
			int kolvo = -2;
			kolvo = proverkavvoda(kolvo);
			for (auto& i : CSMap) {
				if (((double(i.second.kolinwork) / double(i.second.kol) * 100) >= percent) && (i.second.kolinwork + kolvo <= i.second.kol)) {
					i.second.kolinwork += kolvo;
					cout << "������ �� � ID " << i.first << " ��������" << endl;
				}
				else if (i.second.kolinwork + kolvo > i.second.kol) {
					cout << "������ ��� ����� �����, � �� � ID " << i.first << " �������� �� ����� ���� ��������" << endl;
				}
			}
			break;
		}
		case 2: {
			cout << "������� � �������� ����� ����������� ������:" << endl;
			int kolvo = -2;
			kolvo = proverkavvoda(kolvo);
			cout << endl << "������� ID ��, ����� ������� ����� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
			int ch1 = -2;
			ch1 = proverkavvoda(ch1);
			while (CSMap.count(ch1) == 0 && ch1 != -1) {
				cout << "������ ��� ����� ������, ������ � �� � ������ ID �� �������, ������� ������ ��������" << endl;
				ch1 = proverkavvoda(ch1);
			}
			while (ch1 != -1 && CSMap.count(ch1) != 0) {
				if (CSMap[ch1].kolinwork + kolvo <= CSMap[ch1].kol) {
					CSMap[ch1].kolinwork += kolvo;
					cout << "������ �� � ID " << ch1 << " ��������" << endl;
					cout << endl << "������� ID ��, ����� ������� ����� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
					ch1 = proverkavvoda(ch1);
					while (CSMap.count(ch1) == 0 && ch1 != -1) {
						cout << "������ ��� ����� ������, ������ � �� � ������ ID �� �������, ������� ������ ��������" << endl;
						ch1 = proverkavvoda(ch1);
					}
				}
				else if (CSMap[ch1].kolinwork + kolvo > CSMap[ch1].kol) {
					cout << "������ ��� ����� �����, � �� � ID " << ch1 << " �������� �� ����� ���� ��������" << endl;
				}
			}
			break;
		}
		default: {
			cout << "������ ��� ����� ������";
			break;
		}
		}
		break;
	}
	default: {
		cout << "������ ��� ����� ������";
		break;
	}
	}
}

void savefilestation(const unordered_map <int, CompressorStation>& CSMap, ofstream& filesave) {
	if (CSMap.size() != 0) {
		for (auto& i : CSMap) {
			filesave << "������������� �������:" << endl;
			filesave << i.first << endl;
			filesave << i.second.name << endl;
			filesave << i.second.kol << endl;
			filesave << i.second.kolinwork << endl;
			filesave << i.second.effectiveness << endl;
		}
	}
	else
		filesave << "��� ������ � ��" << endl;
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
			getline(fileload, str);//��������� id
			strid = stoi(str);
			if (CSMap.count(strid) != 0) {
				getline(fileload, str);//��������� ��������
				CSMap[strid].name = str;
				getline(fileload, str);//��������� ���-�� �����
				CSMap[strid].kol = stoi(str);
				getline(fileload, str);//��������� ���-�� ������� �����
				CSMap[strid].kolinwork = stoi(str);
				getline(fileload, str);//��������� �������������
				CSMap[strid].effectiveness = stoi(str);
			}
			else {
				getline(fileload, str);//��������� ��������
				cs.name = str;
				getline(fileload, str);//��������� ���-�� �����
				cs.kol = stoi(str);
				getline(fileload, str);//��������� ���-�� ������� �����
				cs.kolinwork = stoi(str);
				getline(fileload, str);//��������� �������������
				cs.effectiveness = stoi(str);
				CSMap.insert(pair <int, CompressorStation>(strid, cs));
			}
		}
	}
}