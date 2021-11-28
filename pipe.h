#pragma once

#include <map>

class Pipe { //Структура трубы
public:
	static int id;
	int d;
	int l;
	bool repair;
	Pipe();
	Pipe AddPipe();
	//void PrintPipe(const unordered_map <int, Pipe>&);
	friend ostream& operator<< (ostream&, const unordered_map <int, Pipe>&);
	void FixPipe(Pipe&);
	void DelPipe(unordered_map <int, Pipe>&);
	void FindandFixPipe(unordered_map<int, Pipe>&);
	void savefilepipe(const unordered_map <int, Pipe>&, ofstream&);
	void loadfilepipe(unordered_map <int, Pipe>&, ifstream&);
};