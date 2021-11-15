#include <map>
class Pipe { //Структура трубы
private:
	static int id;
public:
	int d;
	int l;
	bool repair;
	Pipe AddPipe();
	void PrintPipe(const unordered_map <int, Pipe>&);
	void FixPipe(Pipe&);
	void DelPipe(unordered_map <int, Pipe>&);
	void FindandFixPipe(unordered_map<int, Pipe>&);
	void savefilepipe(const unordered_map <int, Pipe>&, ofstream&);
	void loadfilepipe(unordered_map <int, Pipe>&, ifstream&);
};