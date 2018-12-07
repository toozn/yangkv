#include <bits/stdc++.h>
using namespace std;

class Config{
public:
	Config(){}
	static const int kWriterNum = 8;
};

class WriterConfig{
public:
    WriterConfig(){}
    WriterConfig(bool flag, int id, void* instance_) {
        stopFLAG = flag;
        instance = instance_;
        workerId = id;
    }
    void* instance;
    bool stopFLAG;
    int workerId;
};
