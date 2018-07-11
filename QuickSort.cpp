//
// Created by xidian on 18-7-4.
//

#include <iostream>
int swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int QuickOnce(int *a,int low,int high){

    int watch=low;
    int l=low+1;
    int r=high;
    char dir='r';
    while(1){
        if(l==r){
            if(dir=='l' && a[l]>a[watch]){
                swap(&a[l],&a[watch]);
                watch=l;
                break;
            }
            if(dir=='r' && a[1]<a[watch]){
                swap(&a[r],&a[watch]);
                watch=r;
                break;
            }
            break;
        }
        switch(dir){
            case 'r':if(a[r]>=a[watch]) {
                        r--;
                        continue;
                        }else{
                        swap(&a[r],&a[watch]);
                        watch=r;
                        r--;
                        dir='l';
                        }
                        break;
            case 'l':if(a[l]<=a[watch]) {
                        l++;
                        continue;
                        }else{
                        swap(&a[l],&a[watch]);
                        watch=l;
                        l++;
                        dir='r';
                        }
                        break;
        }


    }
    std::cout<<"------------left:\t";
    for(int i=low;i<watch;i++)
        std::cout<<a[i]<<" ";
    std::cout<<"\n------mid:"<<a[watch]<<std::endl;
    std::cout<<"------------right:\t";
    for(int i=watch+1;i<=high;i++)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl<<std::endl;
    return watch;
}
int QuickSortIter(int *a,int low,int high){
    if(high-low<2){return 0;}
    int mid = QuickOnce(a,low,high);
    QuickSortIter(a,low,mid-1);
    QuickSortIter(a,mid+1,high);

    return 0;
}
int QuickSort(int *a,int len){
    return QuickSortIter(a,0,len-1);
}