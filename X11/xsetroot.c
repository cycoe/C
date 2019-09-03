#include <stdio.h>
#include <X11/Xlib.h>

int main(int argc, char *argv[])
{
    Display* dpy = XOpenDisplay(NULL);
    char* status = "test";
    XStoreName(dpy, DefaultRootWindow(dpy), status);
    XFlush(dpy);
    return 0;
}
