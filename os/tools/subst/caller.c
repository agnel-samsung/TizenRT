#include "subst.h"
#include <stdio.h>

void f(int c) {
    putchar(c);
} 

int main() {

    void *handle = subst_load("pretty-st.json", "debug.log");

    char *s = "<A>%d<B>%d<C>%s<D>%f<E>\n";

    char *p = s;
    while(*p) {
        subst_decode(handle, *p, f);
        ++p;
    }
    subst_unload(handle);
    return 0;
}
