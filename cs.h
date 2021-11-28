#pragma once

#include <string>
#include <map>

using namespace std;

class CompressorStation { //����� ��	
public:
	static int id;
	string name;
	int kol;
	int kolinwork;
	double effectiveness;
	CompressorStation();//�����������
	friend istream& operator>> (istream&, CompressorStation& cs);//���������� �����
	friend ostream& operator<< (ostream&, const unordered_map <int, CompressorStation>&);//���������� ������
	void FixStation(unordered_map <int, CompressorStation>&, int&);
	void DelStation(unordered_map <int, CompressorStation>&);
	void FindandFixStation(unordered_map <int, CompressorStation>&);
	void savefilestation(const unordered_map <int, CompressorStation>&, ofstream&);
	void loadfilestation(unordered_map <int, CompressorStation>&, ifstream&);
};