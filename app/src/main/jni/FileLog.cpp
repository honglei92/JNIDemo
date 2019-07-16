//
// Created by Admin on 2019/7/16.
//

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "FileLog.h"
#include <android/log.h>

FileLog &FileLog::getInstance() {
    static FileLog instance;
    return instance;
}

void FileLog::init(std::string path) {
    pthread_mutex_lock(&mutex);
    if (path.size() > 0 && logFile == nullptr) {
        logFile = fopen(path.c_str(), "w");
    }

}

FileLog::FileLog() {
    pthread_mutex_init(&mutex, NULL);
}

void FileLog::e(const char *message, ...) {
    va_list argptr;
    va_start(argptr, message);
    timer_t t = reinterpret_cast<timer_t>(time(0));
    struct tm *now = localtime(reinterpret_cast<const time_t *>(&t));
    __android_log_vprint(ANDROID_LOG_ERROR, "ndkdemotest", message, argptr);
    va_end(argptr);
    va_start(argptr, message);

    FILE *logFile = getInstance().logFile;
    if (logFile) {
        fprintf(logFile, "%d-%d %02d:%02d:%02d error: ", now->tm_mon + 1, now->tm_mday,
                now->tm_hour,
                now->tm_min, now->tm_sec);
        vfprintf(logFile, message, argptr);
        fprintf(logFile, "\n");
        fflush(logFile);
    }
    va_end(argptr);
}

void FileLog::w(const char *message, ...) {
    va_list argptr;
    va_start(argptr, message);
    timer_t t = reinterpret_cast<timer_t>(time(0));
    struct tm *now = localtime(reinterpret_cast<const time_t *>(&t));
    __android_log_vprint(ANDROID_LOG_WARN, "ndkdemotest", message, argptr);
    va_end(argptr);
    va_start(argptr, message);

    FILE *logFile = getInstance().logFile;
    if (logFile) {
        fprintf(logFile, "%d-%d %02d:%02d:%02d error: ", now->tm_mon + 1, now->tm_mday,
                now->tm_hour,
                now->tm_min, now->tm_sec);
        vfprintf(logFile, message, argptr);
        fprintf(logFile, "\n");
        fflush(logFile);
    }
    va_end(argptr);

}

void FileLog::d(const char *message, ...) {
    va_list argptr;
    va_start(argptr, message);
    timer_t t = reinterpret_cast<timer_t>(time(0));
    struct tm *now = localtime(reinterpret_cast<const time_t *>(&t));
    __android_log_vprint(ANDROID_LOG_DEBUG, "ndkdemotest", message, argptr);
    va_end(argptr);
    va_start(argptr, message);

    FILE *logFile = getInstance().logFile;
    if (logFile) {
        fprintf(logFile, "%d-%d %02d:%02d:%02d error: ", now->tm_mon + 1, now->tm_mday,
                now->tm_hour,
                now->tm_min, now->tm_sec);
        vfprintf(logFile, message, argptr);
        fprintf(logFile, "\n");
        fflush(logFile);
    }
    va_end(argptr);

}

void FileLog::i(const char *message, ...) {
    va_list argptr;
    va_start(argptr, message);
    timer_t t = reinterpret_cast<timer_t>(time(0));
    struct tm *now = localtime(reinterpret_cast<const time_t *>(&t));
    __android_log_vprint(ANDROID_LOG_INFO, "ndkdemotest", message, argptr);
    va_end(argptr);
    va_start(argptr, message);

    FILE *logFile = getInstance().logFile;
    if (logFile) {
        fprintf(logFile, "%d-%d %02d:%02d:%02d error: ", now->tm_mon + 1, now->tm_mday,
                now->tm_hour,
                now->tm_min, now->tm_sec);
        vfprintf(logFile, message, argptr);
        fprintf(logFile, "\n");
        fflush(logFile);
    }
    va_end(argptr);
}
