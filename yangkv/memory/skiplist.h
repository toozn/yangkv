#include "message.h"
#pragma once

class SkipList {
public:
    SkipList(){
        id_ = 0;
        list.clear();
    };
    void insert(Message* msg) {
        if (list.size() == 0) {
            id_ = msg->id;
        }
        list[msg->key] = msg;
    }
    Message* search(const string& key, const unsigned long long idx) {
        if (list.count(key) == 0) {
            return nullptr;
        }
        if (list[key]->del_flag == true) {
            return nullptr;
        }
        return list[key];
    }
    unsigned long long getId() {
        return id_;
    }
private:
    unsigned long long id_;
    map<string, Message*>list;
};
