#include "message.h"
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
    Message* search(const string& key, const unsigned long long idx) {
        if (list_.count(key) == 0) {
            return nullptr;
        }
        if (list_[key]->del_flag == true) {
            return nullptr;
        }
        return list_[key];
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
