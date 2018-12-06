#include "singleton.h"

int main() {
    auto db = Singleton::get();
    printf("Hello world\n");
}
