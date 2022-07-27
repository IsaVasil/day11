#include <stdio.h>
int main(int args,char *argp[]){
FILE* f=fopen(argp[1],"r");
if(f==NULL){
    perror("could not open file");
    return 0;
}
int cur_sym;
fseek(f,0,SEEK_END);
int symbol_count =ftell(f);
int cur_sym;
fseek(f,symbol_count/2,SEEK_SET);

while((cur_sym=fgetc(f))!=EOF){
    cur_sym=fgetc(f);
    if(cur_sym == EOF ){
        break;
    }
    printf("%c",cur_sym);
    fclose(f);
}
cur_sym=fgetc(f);
printf("%c",cur_sym);
printf("%ld",ftell(f));
fclose(f);
    return 0;
}