#pragma once

#include <string>
#include <map>

using namespace std;

class CompressorStation { //класс КС	
public:
	static int id;
	string name;
	int kol;
	int kolinwork;
	double effectiveness;
	CompressorStation();//конструктор
	friend istream& operator>> (istream&, CompressorStation& cs);//перегрузка ввода
	friend ostream& operator<< (ostream&, const unordered_map <int, CompressorStation>&);//перегрузка вывода
	void FixStation(unordered_map <int, CompressorStation>&, int&);
	void DelStation(unordered_map <int, CompressorStation>&);
	void FindandFixStation(unordered_map <int, CompressorStation>&);
	void savefilestation(const unordered_map <int, CompressorStation>&, ofstream&);
	void loadfilestation(unordered_map <int, CompressorStation>&, ifstream&);
};