#include "yangkvMain.h"

void YangkvMain::setKey(const string& key, const string& value) {
	idx++;
	if (act_list[0]->queue->full() == false) {
		act_list[0]->queue->push(Message(key, value, idx));
	}
}

void YangkvMain::delKey(const string& key) {
	setKey(key, "");
}

void YangkvMain::getKey(const string& key) {
	if (act_list[0]->queue->IsFull() == false) {
		//act_list[0]->queue->push(Message(key));
	}
}