#include "yangkvMain.h"

class Singleton {
public:
    static YangkvMain* get() {
        pthread_once(&_p_once, &Singleton::_new);
        return _instance;
    }

    DISALLOW_COPY_AND_ASSIGN(Singleton);

private:
    Singleton();

    ~Singleton();

    /// @brief Construct the singleton instance
    static void _new() {
        _instance = new YangkvMain();
    }

    /// @brief  Destruct the singleton instance
    /// @note Only work with gcc
    static void _delete() {
    }

    static pthread_once_t _p_once;      ///< Initialization once control
    static YangkvMain* _instance;    ///< The singleton instance
}singleton;
