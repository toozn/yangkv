#include "writer.h"

Writer::Writer(Compacter* compacter_) {
    list = new SkipList();
    compacter = compacter_;
    queue = new MessageQueue();
}

Writer::~Writer() {
    delete list;
}

void Writer::mayInsertMessage() {
    while (queue->isEmpty() == false) {
        auto msg = queue->getFront();
        list->insert(msg);
        queue->pop();
        printf("Success Insert! KEY:%s VALUE:%s ID:%lld\n", msg->key.c_str(), msg->value.c_str(), msg->id);
    }
}

Message* Writer::searchMessage(const string& key, const unsigned long long idx) {
    return list->search(key, idx);
}

void* workRound(void* arg_) {
    pthread_detach(pthread_self());
    auto arg = (WriterConfig*)arg_;
    auto writer = (Writer*)arg->instance;
    while (arg->stopFLAG == false) {
        writer->mayInsertMessage();
    }
    printf("Writer Quit!\n");
    return 0;
}
