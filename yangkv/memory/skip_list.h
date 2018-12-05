#include "message.h"
class SkipList {
public:
	SkipList();
	void insertMessage(const Message* msg);
	Message* searchMessage(const string& key);
	MessageQueue* queue;
private:
	map<string, Message*>tmp_map;
	
};