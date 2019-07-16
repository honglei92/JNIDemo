package com.example.jnidemo.jni;

public class NDKTools {
    static {
        System.loadLibrary("ndkdemotest-jni");
    }

    public String s = "shubiao";

    public native String accessFiled();

    public static native String getStringFromNDK();
}
