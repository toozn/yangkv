#include "message.h"
#pragma once
using namespace std;

class MessageQueue {
public:
	MessageQueue();
    ~MessageQueue();
	void push(Message*);
	Message* getFront();
    void pop();
	bool isFull();
	bool isEmpty();
    Message* search(const string&, const unsigned long long);
private:
	static const int kQueueSize = 64;
	Message* queue_[kQueueSize];
	unsigned long long w_ptr, r_ptr;
	mutex lock_;
};
