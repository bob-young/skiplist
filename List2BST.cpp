//
// Created by xidian on 18-7-5.
//

#include <cstdlib>
#include <iostream>

struct node{
    int data=0;
    node* left= nullptr;
    node* right= nullptr;
};

node* buildBST(int *a,int len){
    if(len==0){ return NULL;}
    node* root=(node*)malloc(sizeof(node));
    root->data=a[len/2];
    if(len==1){
        return root;
    }
    root->left=buildBST(a,len/2);
    root->right=buildBST(a+len/2+1,len-len/2-1);
    return root;
}

node *list2BST(int *a,int len){
    return buildBST(a,len);
}

void shownode(node* root){
    std::cout<<root->data<<std::endl;
    if(root->left!=NULL)
        shownode(root->left);
    else
        std::cout<<"NULL"<<std::endl;

    if(root->right!=NULL)
        shownode(root->right);
    else
        std::cout<<"NULL"<<std::endl;
}