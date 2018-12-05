#include "message.h"
using namespace std;

class MessageQueue {
public:
	MessageQueue();
	void push(const Message&);
	Message pop();
	bool IsFull();
	bool IsEmpty();
private:
	static const int kQueueSize = 128;
	Message queue_[kQueueSize];
	unsigned long long w_ptr, r_ptr;
	mutex lock_;
};