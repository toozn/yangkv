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
    //msg->Debug();
	while(w_ptr - r_ptr >= kQueueSize) usleep(5);
	queue_[w_ptr % kQueueSize] = msg;
	w_ptr++;
}

void MessageQueue::pop() {
	assert(w_ptr > r_ptr);
	r_ptr++;
}

Message* MessageQueue::getFront() {
    assert(w_ptr > r_ptr);
    return queue_[r_ptr % kQueueSize];
}

bool MessageQueue::isFull() {
	return (w_ptr - r_ptr == kQueueSize);
}

bool MessageQueue::isEmpty() {
	return (w_ptr == r_ptr);
}

Message* MessageQueue::search(const string& key, const unsigned long long idx) {
    unsigned long long begin = w_ptr - 1;
    unsigned long long end = r_ptr;
    for (unsigned long long i = begin; i >= end; i--) {
        auto msg = queue_[i % kQueueSize];
        if (key == msg->key && idx <= msg->id) {
            return msg;
        }
    }
    return nullptr;
}
