#include "compacter.h"
#include "utils/config.h"

class SkipList {
public:
    SkipList(){}
    SkipList(Compacter*);
    ~SkipList();
	Message* searchMessage(const string&, const unsigned long long);
	void mayInsertMessage();
	MessageQueue* queue;
private:
    Compacter* compacter;
    void insertMessage(Message*);
	map<string, Message*>tmp_map;	
};

