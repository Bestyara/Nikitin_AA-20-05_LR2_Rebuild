#include <string>
#include <map>
class CompressorStation { //��������� ��	
private:
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
	void FindandFixStation(map <int, CompressorStation>&);
	void savefilestation(const map <int, CompressorStation>&, ofstream&);
};