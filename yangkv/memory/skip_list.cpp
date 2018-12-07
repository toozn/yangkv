#include "skip_list.h"

class Message;

SkipList::SkipList(Compacter* compacter_) {
    tmp_map.clear();
    compacter = compacter_;
    queue = new MessageQueue();
}

SkipList::~SkipList() {
    for (auto it = tmp_map.begin(); it != tmp_map.end(); it++) {
        delete it->second;
    }
    tmp_map.clear();
    delete queue;
}

void SkipList::mayInsertMessage() {
    while (queue->IsEmpty() == false) {
        auto msg = queue->pop();
        insertMessage(msg);
        printf("Success Insert! KEY:%s VALUE:%s ID:%lld\n", msg->key.c_str(), msg->value.c_str(), msg->id);
    }
}

void SkipList::insertMessage(Message* msg) {
	tmp_map[msg->key] = msg;
}
Message* SkipList::searchMessage(const string& key, const unsigned long long idx) {
    printf("key: %s\n", key.c_str());
	if (tmp_map.count(key) && tmp_map[key]->id <= idx) {
		return tmp_map[key];
	}
	else {
		return nullptr;
	}
}

void* workRound(void* arg_) {
    pthread_detach(pthread_self());
    auto arg = (WriterConfig*)arg_;
    auto writer = (SkipList*)arg->instance;
    while (arg->stopFLAG == false) {
        writer->mayInsertMessage();
    }
    printf("Writer Quit!\n");
    return 0;
}
