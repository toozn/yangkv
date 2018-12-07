#include "singleton.h"
#include <unistd.h>

int main() {
    auto db = Singleton::get();
    db->Init();
    sleep(1);
    db->setKey("123", "456");
    db->setKey("456", "111");
    sleep(1);
    printf("value is %s\n", db->getValue("123").c_str());
    printf("value is %s\n", db->getValue("456").c_str());
    printf("value is %s\n", db->getValue("789").c_str());
    db->delKey("123");
    sleep(1);
    printf("value is %s\n", db->getValue("123").c_str());
    db->Stop();
    sleep(1);
    printf("DB stoped\n");
}
