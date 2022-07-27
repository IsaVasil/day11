#include <stdio.h>
#include<string.h>
#include<time.h>
#include <stdlib.h>
#include<math.h>
typedef struct Product{
    unsigned int id;
    float price;
    unsigned short sales_count;
    char name[10];
}Product;
char *name_list[]={
"product1",
"product2",
"product3",
"product4",
"product5"
};
void init_random_product( Product *p){
static int id_counter=0;
p->id=id_counter++;
p->price=150+rand()%(20025 - 150)/100;
p->sales_count=rand()%1000;
strcpy(p->name,name_list[rand()%5]);
}
void print_product(Product *p){
    printf("revenue:%f id:%d,price:%f,sales:%d,name:%s\n",p->price*p->sales_count,p->id,p->price,p->sales_count,p->name);
    
}
int comp_product(const void *p1,const void *p2){
    const Product *prod1=p1,*prod2=p2;
    double sales_dif=prod1->price*prod1->sales_count-prod2->price*prod2->sales_count;
    if(fabs(sales_dif)>0.01){
        return sales_dif*100;
    }
    int cmp_result = strcmp(prod1->name,prod2->name);
    if(cmp_result !=0){
        return cmp_result;
    }
   // return sales_dif*100;
   return prod1->id - prod2->id;
}
int main(){


    Product *product_list;
    product_list=malloc(30*sizeof(Product));
    if(!product_list){
        perror("error");
        return -1;
    }
product_list[0].sales_count=0;
    product_list[0].price=0;
    product_list[1].sales_count=0;
    product_list[2].price=0;
 //srand(time(0));
 for(int i =0;i<30;i++){
    init_random_product(product_list + i);
 }
   //printf("%lu",sizeof(Product));
  qsort(product_list,30,sizeof(Product),comp_product);
  for(int i=0;i<30;i++){
    print_product(product_list + i);
  }
    
free(product_list);

    return 0;
}