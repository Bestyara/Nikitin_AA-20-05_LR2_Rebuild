#include <string>
#include <map>
class CompressorStation { //Структура КС	
private:
	static int id;
public:
	string name;
	int kol;
	int kolinwork;
	int effectiveness;
	CompressorStation AddStation();
	//void PrintCompressorstation(const unordered_map <int, CompressorStation>&);
	friend ostream& operator<< (ostream&, const unordered_map <int, CompressorStation>&);
	void FixStation(CompressorStation&);
	void DelStation(unordered_map <int, CompressorStation>&);
	void FindandFixStation(unordered_map <int, CompressorStation>&);
	void savefilestation(const unordered_map <int, CompressorStation>&, ofstream&);
	void loadfilestation(unordered_map <int, CompressorStation>&, ifstream&);
};