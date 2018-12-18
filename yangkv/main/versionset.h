#include "memory/writer.h"
#include "memory/compacter.h"
#include "versionedit.h"
class VersionSet;
class yangkvMain;
class VersionEdit;
class Version{
public:
    Version(){}
    Version(VersionSet* set) {
        set_ = set;
    }
    void ref();
    void unref();
    Version* nxt_;
    Version* pre_;
private:
    VersionSet* set_;
    int ref_;
    set<SkipList*>maintainList_;
};

class VersionSet{
public:
    VersionSet(){
        dummyVersion_ = Version();
        current_ = &dummyVersion_;
    }
    void applyEdit(VersionEdit* edit) {
        auto v = new Version(this);
        //TODO
    }
    Version* current_;
    Version dummyVersion_;
    yangkvMain* db_;
};
