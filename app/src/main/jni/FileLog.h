//
// Created by Admin on 2019/7/16.
//

#ifndef JNIDEMO_FILELOG_H
#define JNIDEMO_FILELOG_H

#include <string.h>
#include "Defines.h"

class FileLog {
public:
    FileLog();

    void init(std::string path);

    static void e(const char *message, ...) __attribute__((format (printf, 1, 2)));

    static void w(const char *message, ...) __attribute__((format (printf, 1, 2)));

    static void d(const char *message, ...) __attribute__((format (printf, 1, 2)));

    static void i(const char *message, ...) __attribute__((format (printf, 1, 2)));

    static FileLog &getInstance();

private:
    FILE *logFile = nullptr;
    pthread_mutex_t mutex;

};

#define DEBUG_E FileLog::getInstance().e
#define DEBUG_W FileLog::getInstance().w
#define DEBUG_D FileLog::getInstance().d
#define DEBUG_I FileLog::getInstance().i
#endif //JNIDEMO_FILELOG_H
