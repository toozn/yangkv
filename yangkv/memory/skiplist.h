#include "message.h"
#include "utils/status.h"
#pragma once

class SkipList {
public:
    SkipList(){
        id_ = 0;
        list_.clear();
    };
    void insert(Message* msg) {
        if (list_.size() == 0) {
            id_ = msg->id;
        }
        list_[msg->key] = msg;
    }
    Status get(Message& msg) {
        if (list_.count(msg.key) == 0) {
            return Status::NotFound();
        }
        msg = *list_[msg.key];
        return Status::OK();
    }
    unsigned long long getId() {
        return id_;
    }
    unsigned int size() {
        return list_.size();
    }
private:
    unsigned long long id_;
    map<string, Message*>list_;
};
