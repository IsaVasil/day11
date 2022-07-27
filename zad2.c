#include <stdio.h>

int main(){

    FILE* f=fopen("Hello_world","a");
fputc('h',f);
fputc('e',f);
fputc('l',f);
fputc('l',f);
fputc('o',f);
fputs("hello asd",f);
fclose(f);
    return 0;
}