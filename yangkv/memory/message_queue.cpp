#include "message_queue.h"
#include <unistd.h>

MessageQueue::MessageQueue() {
	w_ptr = 1;
	r_ptr = 1;
}

MessageQueue::~MessageQueue() {
    unsigned long long begin = r_ptr;
    unsigned long long end = w_ptr - 1;
    for (unsigned long long i = begin; i <= end; i++) {
        int pos = i % kQueueSize;
        delete queue_[pos];
    }
}

void MessageQueue::push(Message* msg) {
	lock_guard<mutex> lock(lock_);
    msg->Debug();
	while(w_ptr - r_ptr >= kQueueSize) {
		usleep(5000);
	}
	queue_[w_ptr % kQueueSize] = msg;
	w_ptr++;
}

Message* MessageQueue::pop() {
	assert(w_ptr > r_ptr);
	Message* tmp = queue_[r_ptr % kQueueSize];
	r_ptr++;
	return tmp;
}

bool MessageQueue::IsFull() {
	return (w_ptr - r_ptr == kQueueSize);
}

bool MessageQueue::IsEmpty() {
	return (w_ptr == r_ptr);
}

Message* MessageQueue::search(const string& key, const unsigned long long idx) {
    unsigned long long begin = r_ptr;
    unsigned long long end = w_ptr - 1;
    for (unsigned long long i = begin; i <= end; i++) {
        int pos = i % kQueueSize;
        if (queue_[pos]->key == key && queue_[pos]->id <= idx) {
            return queue_[pos];
        }
    }
    return nullptr;
}
