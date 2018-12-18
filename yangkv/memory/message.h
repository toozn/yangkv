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
