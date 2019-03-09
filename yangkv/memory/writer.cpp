#include "writer.h"
#include "compacter.h"

class compacter;

Writer::Writer(Compacter* compacter) {
    list_ = new SkipList();
    compacter_ = compacter;
    queue_ = new MessageQueue();
    pthread_rwlock_init(&rwlock_, NULL);
}

Writer::~Writer() {
    delete list_;
}

void Writer::mayInsertMessage() {
    while (queue_->isEmpty() == false) {
        pthread_rwlock_wrlock(&rwlock_);
        auto msg = queue_->getFront();
        list_->insert(msg);
        queue_->pop();
        //printf("Success Insert! KEY:%s VALUE:%s ID:%lld\n", msg->key.c_str(), msg->value.c_str(), msg->id);
        if (list_->size() >= kMaxListSize) {
            cout << "???" << endl;
            compacter_->pushList(list_);
            list_ = new SkipList();
        }
        pthread_rwlock_unlock(&rwlock_);
    }
}

Message* Writer::searchMessage(const string& key, const unsigned long long idx) {
    pthread_rwlock_rdlock(&rwlock_);
    auto msg = new Message(key, "", idx, false);
    Status s = list_->get(*msg);
    pthread_rwlock_unlock(&rwlock_);
    return msg;
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
