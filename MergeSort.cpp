#include <cstdlib>
#include <iostream>
#include <cstring>

//
// Created by xidian on 18-7-4.
//
void insert(int *l,int llen,int *r,int rlen){
    int *tmp=(int *)malloc(sizeof(int)*(rlen+llen));
    for(int i=0,j=0,k=0;i<llen || j<rlen;){
        if(i==llen){
            for(;j<rlen;j++){
                tmp[k++]=r[j];
                //std::cout<<tmp[k-1]<<std::endl;
            }
            //
            memcpy(l,tmp,(llen+rlen)*sizeof(int));
            free(tmp);
            return ;
        }
        if(j==rlen){
            for(;i<llen;i++){
                tmp[k++]=l[i];
                //std::cout<<tmp[k-1]<<std::endl;
            }
            //
            memcpy(l,tmp,(llen+rlen)*sizeof(int));
            free(tmp);
            return ;
        }
        if(l[i]<=r[j]){
            tmp[k++]=l[i++];
            //std::cout<<tmp[k-1]<<std::endl;
        }else{
            tmp[k++]=r[j++];
            //std::cout<<tmp[k-1]<<std::endl;
        }
    }
}

int MergeSort(int *a,int len){

    if(len==1){return 1;}
    if(len==2){
        if(a[0]>a[1]){
            int tmp=a[0];
            a[0]=a[1];
            a[1]=tmp;
        }
        return 1;
    }else{
        int *left=a;
        int *right=a+len/2;
        MergeSort(left,len/2);
        MergeSort(right,len-len/2);
        insert(left,len/2,right,len-len/2);
        return 0;
    }

}