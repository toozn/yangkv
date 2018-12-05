#include "utils/config.h"
#include "message_queue.h"
#include "utils/bloomfilter.h"
#include "utils/pointcache.h"
using namespace std;

class Client{
public:
	void Init();
	string Get(const string&);
	void Set(const string&, const string&);
	void Delete(const string&);
private:
	Reader* 
	static const int kWorkThreadNum = 8;
	static const unsigned long long kEntrySeed = 10007;
	message_queue* queue[kWorkThreadNum];
	unsigned long long idx;
	BloomFilter bm;
	PointCache pcache;
};