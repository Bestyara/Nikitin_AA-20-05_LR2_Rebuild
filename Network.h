#pragma once
#include <unordered_map>
#include "pipe.h"
#include "cs.h"

using namespace std;

class Network {
public:
	unordered_map <int, Pipe> PipeMap;
	unordered_map <int, CompressorStation> CSMap;

	void AddPipe();
	void AddStation();
	void DelPipe();
	void DelStation();
	void FindandFixPipe();
	void FindandFixStation();
	void savefile(ofstream&);
	void loadfile(ifstream&);
	//void loadfilestation(ifstream&);
};
