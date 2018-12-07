#include "message_queue.h"
#include "utils/config.h"

class SkipList {
public:
	SkipList();
    void Init();
    ~SkipList();
	Message* searchMessage(const string&, const unsigned long long);
	void mayInsertMessage();
	MessageQueue* queue;
private:
    void insertMessage(Message*);
	map<string, Message*>tmp_map;	
};

