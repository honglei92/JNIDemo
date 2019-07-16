LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE   := ndkdemotest-jni
LOCAL_CPPFLAGS := -Wall -std=c++11 -DANDROID -finline-functions -ffast-math -Os -fno-strict-aliasing -O3 -frtti -D__STDC_LIMIT_MACROS

LOCAL_SRC_FILES += \
./ndkdemotest.cpp\
./FileLog.cpp

LOCAL_LDLIBS :=-llog


include $(BUILD_SHARED_LIBRARY)

