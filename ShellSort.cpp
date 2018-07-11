//
// Created by xidian on 18-7-5.
//
extern int swap(int *a,int *b);
int shellOnce(int *a,int len,int pace){
    for(int i=pace;i<len;i++){
        for(int j=i-pace;j>=0;j-=pace){
            if(a[j]>a[j+pace]){
                swap(&a[j],&a[j+pace]);
            } else{ break;}

        }
    }
}

int ShellSort(int *a ,int len){
    int pace=len/2;
    for(int i=pace;i>0;i/=2){
        shellOnce(a,len,i);
    }
}