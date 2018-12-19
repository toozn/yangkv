#include "yangkvMain.h"
#include "memory/writer.h"
#include "memory/compacter.h"
#include <unistd.h>
void* writerRound(void* arg_) {
    pthread_detach(pthread_self());
    auto arg = (WriterConfig*) arg_;
    auto writer = arg->instance;
    int id = arg->writerId;
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
        writer[id] = new Writer(compacter);
        arg[id] = new WriterConfig(0, id, writer[id]);
        pthread_t tid;
        pthread_create(&tid, NULL, writerRound, (void*)arg[id]);
    }
    compacter = new Compacter();
}

void YangkvMain::setKey(const string& key, const string& value, bool del_flag) {
	auto id = idx++;
    int writerID = strHash(key, kSeedForWriter) % kMaxWriter;
    auto queue = writer[writerID]->queue_;
    assert(queue != nullptr);
    auto msg = new Message(key, value, id, del_flag);
	if (queue->isFull() == false) {
		queue->push(msg);
        return;
	}
    else {
        sleep(1);
        assert(queue->isFull() == false);
        queue->push(msg);
    }
}

void YangkvMain::delKey(const string& key) {
	setKey(key, "", true);
}

string YangkvMain::getValue(const string& key) {
    auto id = idx;
    int writerID = strHash(key, kSeedForWriter) % kMaxWriter;
    auto msg = writer[writerID]->queue_->search(key, id);
    if (msg != nullptr) {
        if (msg->del_flag == true) {
            return "IsEmpty";
        }
        return msg->value;
    }
    printf("%s %d\n", key.c_str(), __LINE__);
    msg = writer[writerID]->searchMessage(key, id);
    if (msg == nullptr || msg->del_flag == true) {
        return "IsEmpty";
    }
    return msg->value;
}


void YangkvMain::Stop() {
    for (int id = 0; id < kMaxWriter; id++) {
        arg[id]->stopFLAG = true;
    }
}

