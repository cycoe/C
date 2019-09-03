#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>

void printMessage(void* ptr);
void printMessage3(void* ptr);

int main(int argc, char *argv[])
{
    int tmp1, tmp2;
    pthread_t t1, t2;
    char* m1 = "thread 1";
    char* m2 = "thread 2";
    void* retval;

    int ret1, ret2;
    ret1 = pthread_create(&t1, NULL, (void*) &printMessage, (void*) m1);
    ret2 = pthread_create(&t2, NULL, (void*) &printMessage3, (void*) m2);

    // 阻塞主线程，防止其在子线程完成之前退出
    tmp1 = pthread_join(t1, &retval);
    tmp2 = pthread_join(t2, &retval);
    return 0;
}

void printMessage(void* ptr) {
    int i = 0;
    for (; i < 10; i++) {
        printf("%s: %d\n", (char*) ptr, i);
        sleep(1);
    }
}

void printMessage3(void* ptr) {
    int i = 0;
    for (; i < 10; i++) {
        printf("%s: %d\n", (char*) ptr, i);
        sleep(3);
    }
}
