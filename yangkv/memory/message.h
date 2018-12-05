#include <bits/stdc++.h>
using namespace std;

struct Message{
public:
	Message() {}
	Message(const string&, const string&, const unsigned long long);
	string key;
	string value;
	unsigned long long id;
};