#include "utils/config.h"
#include "skiplist.h"
#include "message_queue.h"
#pragma once
class Compacter;
class Writer{
public:
    Writer(){}
    Writer(Compacter*);
    ~Writer();
	Message* searchMessage(const string&, const unsigned long long);
	void mayInsertMessage();
	MessageQueue* queue;
private:
    Compacter* compacter;
	SkipList* list;
};

