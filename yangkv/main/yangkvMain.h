#include "utils/env.h"
#include "utils/hash_helper.h"
#pragma once

class Writer;
class Compacter;
class WriterConfig;
class YangkvMain {
public:
	YangkvMain();
	~YangkvMain();
    void Init();
	void setKey(const string&, const string&, bool flag = 0);
	void delKey(const string&);
	string getValue(const string&);
	Writer* getWriter(int);
    void Stop();

private:
	unsigned long long idx;
	Env* env;
    static const int kMaxWriter = 4;
    static const int kSeedForWriter = 37;
	Writer* writer[kMaxWriter];
	Compacter* compacter;
    WriterConfig* arg[kMaxWriter];
};

void* workerRound(void*);
