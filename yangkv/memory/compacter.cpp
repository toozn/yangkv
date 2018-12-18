#include "compacter.h"
#include <unistd.h>
using List = map<string, Message*>;
void* Compacter::compactRound(void* arg_) {
    auto arg = (CompacterConfig*)arg_;
    while (arg->stopFLAG == false) {
        mayCompactList();
        usleep(5000);
    }
    return 0;
}

void Compacter::pushList(List* list) {
    lock_guard<mutex>lock(lock_);
    lists[list_idx].push_back(list);
    if (lists[list_idx].size() >= kMaxFrozenListSize && compactFLAG == false) {
        list_idx = 1 - list_idx;
        compactFLAG = true;
    }
}

void Compacter::mayCompactList() {
    if (compactFLAG == true) {
        List temp;
        int sz = lists[1 - list_idx].size();
        for (int i = sz - 1; i >= 0; i--) {
            temp.insert(lists[1 - list_idx][i]->begin(), lists[1 - list_idx][i]->end());
        }
        //set_->CreateNewVersion();
        //dumpToTable(temp);
    }        
    else {
        return;
    }
}
