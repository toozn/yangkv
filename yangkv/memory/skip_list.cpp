#include "skip_list.h"

SkipList::SkipList() {
	tmp_map.clear();
}

void SkipList::insertMessage(const Message* msg) {
	tmp_map[msg->key] = msg;
}
Message* SkipList::searchMessage(const string& key) {
	if (tmp_map.count(key)) {
		return tmp_map[key];
	}
	else {
		return nullptr;
	}
}
