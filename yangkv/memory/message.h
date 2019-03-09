#include <bits/stdc++.h>
#pragma once
using namespace std;

struct Message{
public:
	Message() {}
	Message(const string&, const string&, const unsigned long long, bool);
    void Debug();
	string key;
	string value;
    bool del_flag;
	unsigned long long id;
};

Message::Message(const string& key_, const string& value_, const unsigned long long id_, bool flag) {
	key = key_, value = value_, id = id_, del_flag = flag;
}

void Message::Debug() {
    printf("KEY= %s, VALUE= %s, ID= %lld\n", key.c_str(), value.c_str(), id);
}
