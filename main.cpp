#include <iostream>
#define ARRAYLEN 10
#define ARRAY {231,88,11,4,9,909,0,8,19,100}
#define SHOWARRAY(X) for(int i=0;i<10;i++)std::cout<<(X)[i]<<std::endl;

struct node{
    int data=0;
    node* left= nullptr;
    node* right= nullptr;
};

int MergeSort(int *a,int len);

int QuickSort(int *a,int high);

int ShellSort(int *a ,int len);

node *list2BST(int *a,int len);

void shownode(node* root);

int HeapSort(int *a,int len);

int main() {

    std::cout << "------------------Merge Sort-----------------------" << std::endl;
    int aMerge[ARRAYLEN]ARRAY;
    MergeSort(aMerge,ARRAYLEN);
    SHOWARRAY(aMerge);

    std::cout << "------------------Quick Sort-----------------------" << std::endl;
    int aQuick[ARRAYLEN]ARRAY;
    QuickSort(aQuick,ARRAYLEN);
    SHOWARRAY(aQuick);

    std::cout << "------------------Shell Sort-----------------------" << std::endl;
    int aShell[ARRAYLEN]ARRAY;
    ShellSort(aShell,ARRAYLEN);
    SHOWARRAY(aShell);
    //int aaaa[10]{231,88,11,4,9,909,0,8,19,100};
    //shownode(list2BST(aaa,10));
    std::cout << "------------------Heap Sort-----------------------" << std::endl;
    int aHeap[ARRAYLEN]ARRAY;
    HeapSort(aHeap,ARRAYLEN);
    SHOWARRAY(aHeap);
    return 0;
}
