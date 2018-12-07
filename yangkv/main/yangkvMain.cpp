#include "yangkvMain.h"
#include <unistd.h>
void* writerRound(void* arg_) {
    pthread_detach(pthread_self());
    auto arg = (WriterConfig*) arg_;
    auto writer = (SkipList*)arg->instance;
    int id = arg->workerId;
    printf("Worker id: %d begin to work\n", id);
    while (arg->stopFLAG == false) {
        writer->mayInsertMessage();
    }
    printf("Quit Writer %d!\n", id);
    return 0;
}
YangkvMain::YangkvMain(){}

void YangkvMain::Init() {
    idx = 0;
    for (int id = 0; id < kMaxWriter; id++) {
        act_list[id] = new SkipList(compacter);
        arg[id] = WriterConfig(0, id, (void*)act_list[id]);
        pthread_t tid;
        pthread_create(&tid, NULL, writerRound, (void*)&arg[id]);
    }
    compacter = new Compacter();
}

void YangkvMain::setKey(const string& key, const string& value, bool del_flag) {
	auto id = idx++;
    int writer = strHash(key, kSeedForWriter) % kMaxWriter;
    auto queue = act_list[writer]->queue;
    assert(queue != nullptr);
    auto msg = new Message(key, value, id, del_flag);
	if (queue->IsFull() == false) {
		queue->push(msg);
        return;
	}
    else {
        sleep(1);
        assert(queue->IsFull() == false);
        queue->push(msg);
    }
}

void YangkvMain::delKey(const string& key) {
	setKey(key, "", true);
}

string YangkvMain::getValue(const string& key) {
    auto id = idx;
    int writer = strHash(key, kSeedForWriter) % kMaxWriter;
    auto msg = act_list[writer]->queue->search(key, id);
    if (msg != nullptr) {
        if (msg->del_flag == true) {
            return "IsEmpty";
        }
        return msg->value;
    }
    printf("%s %d\n", key.c_str(), __LINE__);
    msg = act_list[writer]->searchMessage(key, id);
    if (msg == nullptr || msg->del_flag == true) {
        return "IsEmpty";
    }
    return msg->value;
}

SkipList* YangkvMain::getList(int idx) {
    assert (idx < 8);
    return act_list[idx];
}

void YangkvMain::Stop() {
    for (int id = 0; id < kMaxWriter; id++) {
        arg[id].stopFLAG = true;
    }
}

