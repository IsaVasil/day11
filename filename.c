#include <stdio.h>
int main (int argc,char **argp){
FILE* f1=fopen(argp[1],"r");
int cur_sym;
int word_counter,res=0;
char *word=argp[2];
while((cur_sym=fgetc(f1))!=EOF){
    if(cur_sym!=word[word_counter]){
        word_counter=0;
    }
    if(cur_sym==word[word_counter]){
        word_counter++;
    }
    if (word[word_counter]=='\0'){
        res++;
        word_counter=0;
    }
    //fprintf(stdout,"%c",cur_sym);
   
}
//fputs("hello my name is kaloqn",f1);
fclose(f1);

    return 0;
}