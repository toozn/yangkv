#include "message.h"

Message::Message(const string& key_, const string& value_, const unsigned long long id_) {
	key = key_, value = value_, id = id_;
}