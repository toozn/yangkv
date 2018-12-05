#include "utils/env.h"
#include "memory/skip_list.h"
class YangkvMain {
public:
	YangkvMain();
	~YangkvMain();
	void setKey(const string&, const string&);
	void delKey(const string&);
	string getValue(const string&);
	MessageQueue* getQueue(int);

private:
	unsigned long long idx;
	Env* env;
	SkipList* act_list[10];
	vector<SkipList>frozen_list;
};