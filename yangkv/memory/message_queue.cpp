#include "message_queue.h"
#include <unistd.h>

MessageQueue::MessageQueue() {
	w_ptr = 0;
	r_ptr = 0;
}

void MessageQueue::push(Message* msg) {
	lock_guard<mutex> lock(lock_);
	while(w_ptr - r_ptr <= kQueueSize) {
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
