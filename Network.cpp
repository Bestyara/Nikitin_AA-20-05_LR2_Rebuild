#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Network.h"

using namespace std;

int proverkavvodaint();

double proverkavvodadouble();

void Network::AddPipe() {
	Pipe::id++;
	if (PipeMap.count(Pipe::getid()) == 0) {
		PipeMap.insert(pair <int, Pipe>(Pipe::getid(), Pipe()));//getnextid
		cin >> PipeMap[Pipe::getid()];
	}
}

void Network::AddStation() {
	CompressorStation::id++;
	if (CSMap.count(CompressorStation::getid()) == 0) {
		CSMap.insert(pair <int, CompressorStation>(CompressorStation::getid(), CompressorStation()));
		cin >> CSMap[CompressorStation::getid()];
	}
}

void Network::DelPipe() {
	cout << endl << "������� ID �����, ������ � ������� ����� ������� (��� ��������� ����� �������� -1)" << endl;
	int ch = proverkavvodaint();
	if (PipeMap.count(ch) != 0) {
		while (ch != -1 && PipeMap.count(ch) != 0) {
			PipeMap.erase(PipeMap.find(ch));
			cout << endl << "������� ID �����, ������ � ������� ����� ������� (��� ��������� ����� �������� -1)" << endl;
			ch = proverkavvodaint();
		}
	}
	else {
		cout << endl << "������ � ����� � ����� ID ���, ���������� ������ ������ ID" << endl;
	}
}

void Network::DelStation() {
	cout << endl << "������� ID ��, ������ � ������� ����� ������� (��� ��������� ����� �������� -1)" << endl;
	int ch = proverkavvodaint();
	if (CSMap.count(ch) != 0) {
		while (ch != -1 && CSMap.count(ch) != 0) {
			CSMap.erase(CSMap.find(ch));
			cout << endl << "������� ID ��, ������ � ������� ����� ������� (��� ��������� ����� �������� -1)" << endl;
			ch = proverkavvodaint();
		}
	}
	else {
		cout << endl << "������ � �� � ����� ID ���, ���������� ������ ������ ID" << endl;
	}
}

void Network::FindandFixPipe() {//����� � �������� �������������� ����
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
	cout << endl << "������ � ������, ������� �� ��������� � �������: " << endl;
	if (PipeMap.size() != 0) {
		for (auto& i : PipeMap) {
			if (i.second.repair == 0) {
				cout << endl << "�����";
				cout << endl << "ID: " << i.first;
				cout << endl << "����� �����: " << i.second.l;
				cout << endl << "������� �����: " << i.second.d;
				cout << endl << "����� � �������:(0 - ���, 1 - ��): " << i.second.repair << endl;
			}
		}
	}
	cout << endl << "������� ID ����, ������ � ������� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
	int ch = proverkavvodaint();
	while (PipeMap.count(ch) == 0 && ch != -1) {
		cout << "������ ��� ����� ������, ������ � ����� � ������ ID �� �������, ������� ������ ��������" << endl;
		ch = proverkavvodaint();
	}
	while (ch != -1 && PipeMap.count(ch) != 0) {
		cout << ch;
		if (PipeMap[ch].repair == 0) {
			PipeMap[ch].repair = 1;
		}
		else {
			PipeMap[ch].repair = 0;
		}
		cout << endl << "������ ��������" << endl;
		cout << endl << "������� ID ����, ������ � ������� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
		ch = proverkavvodaint();
		while (PipeMap.count(ch) == 0 && ch != -1) {
			cout << "������ ��� ����� ������, ������ � ����� � ������ ID �� �������, ������� ������ ��������" << endl;
			ch = proverkavvodaint();
		}
	}
}

void Network::FindandFixStation() {//����� � �������� �������������� ��
	cout << endl << "����� �� ������ ��������� ����������?" << endl;
	cout << "1 - ��������";
	cout << endl << "2 - ������� �������������� �����" << endl;
	int ch = proverkavvodaint();
	switch (ch) {
	case 1: {//��������
		cout << endl << "������� �������� ��:" << endl;
		string str;
		cin.ignore(32767, '\n');
		getline(cin, str);
		cout << endl << "��������� ������ �� ��������: ";
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
		int ch1 = proverkavvodaint();
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
			ch1 = proverkavvodaint();
			while (CSMap.count(ch1) == 0 && ch1 != -1) {
				cout << "������ ��� ����� ������, ������ � �� � ������ ID �� �������, ������� ������ ��������" << endl;
				ch1 = proverkavvodaint();
			}
			while (ch1 != -1 && CSMap.count(ch1) != 0) {
				CSMap[ch1].name = str1;
				cout << endl << "������ ��������" << endl;
				cout << endl << "������� ID ��, �������� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
				ch1 = proverkavvodaint();
				while (CSMap.count(ch1) == 0 && ch1 != -1) {
					cout << "������ ��� ����� ������, ������ � �� � ������ ID �� �������, ������� ������ ��������" << endl;
					ch1 = proverkavvodaint();
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
		cout << endl << "��������� ������ (������ ��������): ";
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
		cout << endl << "��������� ������ (������ ��������): ";
		for (auto& i : CSMap) {
			if ((double(i.second.kolinwork) / double(i.second.kol) * 100) < percent) {
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
		int num = proverkavvodaint();
		switch (num) {
		case 1: {
			cout << "������� � �������� ����� ����������� ������:" << endl;
			int kolvo = proverkavvodaint();
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
			int kolvo = proverkavvodaint();
			cout << endl << "������� ID ��, ����� ������� ����� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
			int ch1 = proverkavvodaint();
			while (CSMap.count(ch1) == 0 && ch1 != -1) {
				cout << "������ ��� ����� ������, ������ � �� � ������ ID �� �������, ������� ������ ��������" << endl;
				ch1 = proverkavvodaint();
			}
			while (ch1 != -1 && CSMap.count(ch1) != 0) {
				if (CSMap[ch1].kolinwork + kolvo <= CSMap[ch1].kol) {
					CSMap[ch1].kolinwork += kolvo;
					cout << "������ �� � ID " << ch1 << " ��������" << endl;
					cout << endl << "������� ID ��, ����� ������� ����� ������� ������ �� �������� (��� ��������� ����� �������� -1):" << endl;
					ch1 = proverkavvodaint();
					while (CSMap.count(ch1) == 0 && ch1 != -1) {
						cout << "������ ��� ����� ������, ������ � �� � ������ ID �� �������, ������� ������ ��������" << endl;
						ch1 = proverkavvodaint();
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

void Network::savefile(ofstream& filesave) {
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

void Network::loadfile(ifstream& fileload) {
	string str;
	Pipe p;
	CompressorStation cs;
	while (!fileload.eof()) {
		getline(fileload, str);
		if (str == "Pipe") {
			int strid;
			getline(fileload, str);//��������� id
			strid = stoi(str);
			/*if (PipeMap.size() != 0) {
				for (auto& i : PipeMap) {
					if (i.first > Pipe::id)
						Pipe::id = i.first;
				}
			}*/
			if (Pipe::id < strid)
				Pipe::id = strid;
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
			int strid;
			getline(fileload, str);//��������� id
			strid = stoi(str);
			if (CompressorStation::id < strid)
				CompressorStation::id = strid;
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

