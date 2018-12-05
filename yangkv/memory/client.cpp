#include "entry.h"

Client::Init() {
	idx = 0;
	bm.Init();
	pcache.Init();
}

string Client::Get(const string& key) {
	//query in bloomfilter
	if(bm.Query(key) == false) {
		return "";
	}
	//query in pointcache
	string tmp = pcache.Query(key);
	if (tmp != "" || tmp == "DELETED") {
		return tmp;
	}

	unsigned long long hashval = 1;
	for (const char ch: key) {
		hashval = (hashval + ch) * kEntrySeed;
	}
	int thread_id = hashval % kWorkThreadNum;

	tmp = SeekInQueue(key, thread_id);
	if (tmp != "" || tmp == "DELETED") {
		return tmp;
	}

	tmp = SeekInActiveList(key, thread_id);
	if (tmp != "" || tmp == "DELETED") {
		return tmp;
	}

	tmp = SeekInFrozenList(key, thread_id);
	if (tmp != "" || tmp == "DELETED") {
		return tmp;
	}

	tmp = SeekInLSMTree(key);
	if (tmp != "" || tmp == "DELETED") {
		return tmp;
	}

	return "";
}

void Client::Set(const string& key, const string& value) {

	unsigned long long hashval = 1;
	for (const char ch: key) {
		hashval = (hashval + ch) * kEntrySeed;
	}
	thread_id = hashval % kWorkThreadNum;
	int cnt = 0;
	while (queue[thread_id]->IsFull()) {
		usleep(1000);
		cnt++;
		assert(cnt <= 1000);
	}
	queue[thread_id]->push(Message(key, value, ++idx));
}

void Client::Delete(const string& key) {
	Set(key, "DELETED");
}