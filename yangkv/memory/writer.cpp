#include "writer.h"
#include "compacter.h"

class compacter;

Writer::Writer(Compacter* compacter) {
    list_ = new SkipList();
    compacter_ = compacter;
    queue_ = new MessageQueue();
}

Writer::~Writer() {
    delete list_;
}

void Writer::mayInsertMessage() {
    while (queue_->isEmpty() == false) {
        auto msg = queue_->getFront();
        list_->insert(msg);
        queue_->pop();
        printf("Success Insert! KEY:%s VALUE:%s ID:%lld\n", msg->key.c_str(), msg->value.c_str(), msg->id);
        if (list_->size() >= kMaxListSize) {
            compacter_->pushList(list_);
            list_ = new SkipList();
        }
    }
}

Message* Writer::searchMessage(const string& key, const unsigned long long idx) {
    return list_->search(key, idx);
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
