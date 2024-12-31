#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
typedef struct Node1{
    int m;
    struct Node1 *next;
}node1;
node1 *top1 = NULL;
int count1 = 0;
void push_list1(int num){
    node1 *n = malloc(sizeof(node1));
    n->next = top1;
    top1 = n;
    n->m = num;
    count1++;
}
int pop_list1(){
    int num;
    node1 *n;
    n = top1;
    top1 = top1->next;
    num = n->m;
    free(n);
    count1--;
    return num;
}
void displaylist1(){
    int check;
    node1 *c;
    for (int i = 1; i <= count1; i++){
        c = top1;
        check = count1;
        while (check!=i){
            c = c->next;
            check--;
        }
        printf("%d ",c->m);
    }
}
int main(){
    char arr[] = "ABCD^+*EF^GH/*-";
    int a,b,c,d,f,g;
    printf("Enter A,B,C,D,G and H separated by space: ");
    scanf("%d%d%d%d",&a,&b,&c,&d,&f,&g);
    printf("%-10s%-10s%s\n","Step","Symbol","Stack");
    for (int i=0;i<strlen(arr);i++){
        if (isalpha(arr[i])){
            int x;
            if (arr[i]=='A')
                x = a;
            else if (arr[i]=='B')
                x = b;
            else if (arr[i]=='C')
                x = c;
            else if (arr[i]=='D')
                x = d;
            push_list1(x);
        }
        else{
            int y = pop_list1();
            int x = pop_list1();
            if (arr[i]=='+')
                push_list1(x+y);
            else if (arr[i]=='-')
                push_list1(x-y);
            else if (arr[i]=='*')
                push_list1(x*y);
            else if (arr[i]=='/')
                push_list1(x/y);
            else if (arr[i]=='^')
                push_list1((int)pow(x,y));
            else if (arr[i]=='%')
                push_list1(x%y);
        }
        printf("%-10d%-10c",i+1,arr[i]);
        displaylist1(); 
        printf("\n");
    }
}