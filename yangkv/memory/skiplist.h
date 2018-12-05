#include "message_queue.h"

class SkipList {
public:
	void SkipList();
	void insertMessage(const message* msg);
	Message* searchMessage(const string& key);
	typename MessageQueue* queue;
private:
	map<string, message*>tmp_map;
	
};