//
// Created by xidian on 18-7-11.
//
#include <iostream>
extern int swap(int *a,int *b);

void buildHeapBig(int *a,int len){
    for(int i=len-1;i>=0;i--){
        if(a[(i-1)/2]<a[i]){
            swap(&a[(i-1)/2],&a[i]);
        }
    }
}

void rebuild(int *a,int len){
    swap(&a[0],&a[len-1]);
    int tmp=0;
    while(tmp<len-1){
        if(tmp*2+1>=len-1 && tmp*2+2>len-1){break;}
        if(tmp*2+1==len-2){
            if (a[tmp] < a[tmp * 2 + 1]) {//left swap
                swap(&a[tmp], &a[tmp * 2 + 1]);
            }
            break;
        }
        if(a[tmp*2+1]>=a[tmp*2+2]) {//left greater
            if (a[tmp] < a[tmp * 2 + 1]) {//left swap
                swap(&a[tmp], &a[tmp * 2 + 1]);
                tmp = tmp * 2 + 1;
                continue;
            }
        } else {//right greater
            if (a[tmp] < a[tmp * 2 + 2]) {//right
                swap(&a[tmp], &a[tmp * 2 + 2]);
                tmp = tmp * 2 + 2;
                continue;
            }
        }
        break;
    }
    //buildHeapBig();
}

int HeapSort(int *a,int len){
    buildHeapBig(a,len);
    //for(int i=0;i<10;i++)std::cout<<(a)[i]<<std::endl;

    for(int i=len;i>1;i--){
        rebuild(a,i);
    }
}