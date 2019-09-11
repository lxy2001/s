#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}
List Read(){
    struct LNode *p1,*p2,*head;
    int n=0;
    int c=0;
    p1=p2=(struct LNode*)malloc(sizeof(struct LNode));
    while(c==0){
        n++;
        if(n==1){
            scanf("%d",&p1->Data);
            if(p1->Data==-1){
                break;
            }
            else{
                head=p1;
                p2=p1;
            }
        }
        else{
            p1=(struct LNode*)malloc(sizeof(struct LNode));
            scanf("%d",&p1->Data);
            if(p1->Data==-1){
                break;
            }
            else{
                p2->Next=p1;
                p2=p1;
            }
        }
    }
    p2->Next=NULL;
    return (head);
}
ElementType FindKth( List L, int K ){
    struct LNode *p1,*p2;
    p1=L;
    p2=L;
    int n=0;
    int t=0;
    while(p2!=NULL){
        n++;
        p2=p2->Next;
    }
    if(K>n||K<0){
        t=-1;
    }
    else{
        for(int i=1;i<=K;i++){
            if(i==K){
                t=p1->Data;
                break;
            }
            p1=p1->Next;
        }
    }
    return t;
}


