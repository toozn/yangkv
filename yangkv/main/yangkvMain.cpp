#include "yangkvMain.h"

YangkvMain::YangkvMain(){}

void YangkvMain::setKey(const string& key, const string& value) {
	idx++;
    MessageQueue* queue = act_list[0]->queue;
    auto msg = new Message(key, value, idx);
	if (queue->IsFull() == false) {
		queue->push(msg);
	}
}

void YangkvMain::delKey(const string& key) {
	setKey(key, "");
}

string YangkvMain::getValue(const string& key) {
    return "233";
//    auto queue = act_list[0]->queue;
//	if (queue->IsFull() == false) {
//		//act_list[0]->queue->push(Message(key));
//	}
}

SkipList* YangkvMain::getList(int idx) {
    assert (idx < 8);
    return act_list[idx];
}
