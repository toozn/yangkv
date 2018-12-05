#include "entry.h"

Entry::Entry() {
	idx = 0;
}

string Entry::GetKey(const string& key) {
	//query in bloomfilter
	if(bm.Query(key) == false) {
		return "";
	}
	//query in pointcache
	string tmp = pcache.Query(key);
	if (tmp != "") {
		return tmp;
	}

	unsigned long long hashval = 1;
	for (const char ch: key) {
		hashval = (hashval + ch) * kEntrySeed;
	}
	thread_id = hashval % kWorkThreadNum;

	tmp = SeekInQueue(key);
	if (tmp != "" || tmp == Deleted) {
		return tmp;
	}

	tmp = SeekInActiveList(key);
	if (tmp != "" || ) {
		return tmp;
	}

}