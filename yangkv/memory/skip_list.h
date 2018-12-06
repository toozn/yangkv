#include "message_queue.h"
class MessageQueue;
class Message;

class SkipList {
public:
	SkipList();
	void insertMessage(Message* msg);
	Message* searchMessage(const string& key);
	MessageQueue* queue;
private:
	map<string, Message*>tmp_map;	
};
