#include <map>

using namespace std;

class Pipe { //����� �����
public:
	static int id;
	int d;
	int l;
	bool repair;
	Pipe();//�����������
	friend istream& operator>> (istream&, Pipe& p);//���������� �����
	friend ostream& operator<< (ostream&, const unordered_map <int, Pipe>&);//���������� ������
	void FixPipe(unordered_map <int, Pipe>&, int&);
	void DelPipe(unordered_map <int, Pipe>&);
	void FindandFixPipe(unordered_map<int, Pipe>&);
	void savefilepipe(const unordered_map <int, Pipe>&, ofstream&);
	void loadfilepipe(unordered_map <int, Pipe>&, ifstream&);
};