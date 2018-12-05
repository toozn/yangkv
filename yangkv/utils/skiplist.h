#include "listnode.h"
using namespace std;

class SkipList{
public:
	void Init();
	void Insert(const Message&);
	string Query(const string&);
private:
	listnode* head;
}