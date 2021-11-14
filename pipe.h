#include <map>
class Pipe { //Структура трубы
private:
	static int id;
	int d;
	int l;
	bool repair;
public:
	Pipe AddPipe();
	void PrintPipe(const map <int, Pipe>&);
	void FixPipe(Pipe&);
	void DelPipe(map <int, Pipe>&);
	void FindandFixPipe(map <int, Pipe>&);
	void savefilepipe(const map <int, Pipe>&, ofstream&);
};