//
// Created by Lebron Sn on 2017/2/6.
//
#include "bs.h"
JNIEXPORT jint JNICALL
Java_com_example_lebronsn_bsdiffpatch_MainActivity_patch
        (JNIEnv *env, jobject instance, jstring oldpath_, jstring newpath_,jstring patch_) {
    const char* argv[4];
    argv[0] = "bspatch";
    argv[1] = (*env)->GetStringUTFChars(env,oldpath_, 0);
    argv[2] = (*env)->GetStringUTFChars(env,newpath_, 0);
    argv[3] = (*env)->GetStringUTFChars(env, patch_, 0);
    mypatch(4,argv);
    (*env)->ReleaseStringUTFChars(env,oldpath_, argv[1]);
    (*env)->ReleaseStringUTFChars(env,newpath_, argv[2]);
    (*env)->ReleaseStringUTFChars(env,patch_,argv[3]);
//    free(argv);
    return 0;
}

JNIEXPORT jint JNICALL
Java_com_example_lebronsn_bsdiffpatch_MainActivity_diff
        (JNIEnv *env, jobject instance, jstring oldpath_, jstring newpath_, jstring patch_) {
    const char* argv[4];
    argv[0] = "bsdiff";
    argv[1] = (*env)->GetStringUTFChars(env,oldpath_, 0);
    argv[2] = (*env)->GetStringUTFChars(env,newpath_, 0);
    argv[3] = (*env)->GetStringUTFChars(env, patch_, 0);
    mydiff(4,argv);
    (*env)->ReleaseStringUTFChars(env,oldpath_, argv[1]);
    (*env)->ReleaseStringUTFChars(env,newpath_, argv[2]);
    (*env)->ReleaseStringUTFChars(env,patch_,argv[3]);
//    free(argv[0]);
//    free(argv);
    return 0;
}