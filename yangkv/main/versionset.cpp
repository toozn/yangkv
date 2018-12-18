#include "versionset.h"
void Version::ref(){
    ref_++;
}
void Version::unref(){
    assert(this != &set_->dummyVersion_);
    ref_--;
    if (ref_ == 0) {
        for (auto it: maintainList_) {
            delete it;
        }
        nxt_->pre_ = pre_;
        pre_->nxt_ = nxt_;
        delete this;
    }
}
