#include <map>
class Pipe { //Структура трубы
	static int id;
public:
	int d;
	int l;
	bool repair;
	Pipe AddPipe();
	void PrintPipe(const map <int, Pipe>&);
	void FixPipe(Pipe&);
	void DelPipe(map <int, Pipe>&);
	void FindandFixPipe(map <int, Pipe>&);
};