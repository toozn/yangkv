#include "utils/env.h"
#include "memory/skip_list.h"
#include "utils/hash_helper.h"

class SkipList;

class YangkvMain {
public:
	YangkvMain();
	~YangkvMain();
    void Init();
	void setKey(const string&, const string&, bool flag = 0);
	void delKey(const string&);
	string getValue(const string&);
	SkipList* getList(int);
    void Stop();

private:
	unsigned long long idx;
	Env* env;
    static const int kMaxWriter = 4;
    static const int kSeedForWriter = 37;
	SkipList* act_list[kMaxWriter];
	Compacter* compacter;
    WriterConfig arg[kMaxWriter];
};

void* workerRound(void*);
