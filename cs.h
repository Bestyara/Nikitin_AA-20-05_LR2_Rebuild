#include <string>
#include <map>
class CompressorStation { //Структура КС	
	static int id;
public:
	string name;
	int kol;
	int kolinwork;
	int effectiveness;
	CompressorStation AddStation();
	void PrintCompressorstation(const map <int, CompressorStation>&);
	void FixStation(CompressorStation&);
	void DelStation(map <int, CompressorStation>&);
};