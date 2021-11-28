#pragma once

#include <string>
#include <map>

class CompressorStation { //Структура КС	
//private:
public:
	static int MaxId;
	CompressorStation();
	std::string name;
	int kol;
	int kolinwork;
	double effectiveness;
	CompressorStation AddStation();//////////!!!!!!!!!!!!!!!!!!!!
	//void PrintCompressorstation(const unordered_map <int, CompressorStation>&);
	friend ostream& operator<< (ostream&, const unordered_map <int, CompressorStation>&);
	void FixStation();
	void DelStation(unordered_map <int, CompressorStation>&);
	void FindandFixStation(unordered_map <int, CompressorStation>&);
	void savefilestation(const unordered_map <int, CompressorStation>&, ofstream&);
	void loadfilestation(unordered_map <int, CompressorStation>&, ifstream&);
};