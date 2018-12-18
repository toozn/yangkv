#include "message_queue.h"
#include "utils/config.h"
#pragma once
using List = map<string, Message*>;
using namespace std;

class yangkvMain;

class Compacter {
public:
    Compacter(){
        list_idx = 0;
        lists[0].clear(), lists[1].clear();
    }
    ~Compacter(){}
    void pushList(List*);
    void* compactRound(void*);
    void mayCompactList();
private:
    static const int kMaxFrozenListSize = 10;
    vector<List*>lists[2];
    yangkvMain* main_;
    int list_idx;
    bool compactFLAG;
    mutex lock_;
};
