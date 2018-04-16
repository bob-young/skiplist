#include<iostream>
#define MAX 100 
using namespace std;

template<typename T>
class skiplist
{
private:
	//inner class
	class node{
		public:
		T data;
		node* next=NULL;
		node* down=NULL;
		int level;
		
			node(T val,int level){
				this->data=val;
				this->level=level;
				this->next=NULL;
			}
	};
	//params
	node* start[MAX];
	int depth=0;
	int len=0;
	//functions
	void init(int len,T array[],int level=0){
		this->start[level]=new node(array[0],level);
		node* tmp=this->start[level];
		int i=1;
		while(i<len){
			node* now=new node(array[i],level);
			tmp->next=now;
			tmp=now;
			i++;
		}
	}
	
	void build_up(int level){
		//last head
		node* last=this->start[level-1];
		//head
		this->start[level]=new node(this->start[0]->data,level);
		node* tmp=this->start[level];
		tmp->down=last;
		if(last->next==NULL || last->next->next==NULL){
			return;
		}
		last=last->next->next;
		//down link
		while(last!=NULL && last->next!=NULL){
			node* now=new node(last->data,level);
			now->down=last;
			tmp->next=now;
			tmp=now;
			last=last->next->next;
		}
	}
	int get_base(node* pos){
		//down to level 0
		node* tmp=pos;
		while(tmp->down!=NULL){
			tmp=tmp->down;
		}
		//from start[0] to tmp
		int i=0;
		node* stmp=start[0];
		for(;;i++){
			if(stmp==tmp){//find
				return i;
			}
			if(stmp==NULL){//not find
				return -1;
			}
			stmp=stmp->next;
		}
		
	}
	int search_level(node** begin,T val){
		node* tmp=*begin;
		while(tmp!=NULL){
			cout<<tmp->data<<":"<<endl;
			if(tmp->data==val){
				return get_base(tmp);
			}
			if(tmp->next==NULL){
				cout<<"NULL";
				{
					if(tmp->down==NULL){
						return -2;
					}
					cout<<tmp->down->data;
					*begin=tmp->down;
					return -1;
				}
			}
			if(tmp->data<val && tmp->next->data<=val){
				tmp=tmp->next;
				continue;
			}
			if(tmp->data<val && tmp->next->data>val){
				if(tmp->down==NULL){
					return -2;
				}else{
					*begin=tmp->down;
					return -1;
				}
			}
		}
	}
public:
	skiplist(){
		cout<<"0 element init"<<endl;
	}
	skiplist(int len,T array[]){
		this->len=len;
		cout<<len<<" element init"<<endl;
		while((len>>=1)>0){
			this->depth++;
		}
		cout<<this->depth<<" depth"<<endl;
		//build original list
		init(this->len,array);
		//build upper level
		for(int i=1;i<(this->depth);i++){
			build_up(i);
		}
			
	}
	int search(T val){
		
		node* begin=start[depth-1];
		if(val<begin->data){
			cout<<"too small"<<endl;
			return -1;
		}
		int flag=0;
		for(int i=0;i<depth;i++){
			cout<<"search loop "<<i<<endl;
			flag=search_level(&begin,val);
			//getchar();
			if(flag>=0){
				return flag;
			}else if(flag==-2){
				cout<<"not found"<<endl;
				return -1;
			}
		}
	}
	int length(){
		return this->len;
	}
	int get_depth(){
		return this->depth;
	}
	
	//test
	void show_data(int level){
		cout<<&(this->start[level])<<"now in level "<<level<<endl;
		node* tmp=this->start[level];
		while(tmp!=NULL){
			cout<<tmp->data<<"\t";
			tmp=tmp->next;
		}
		cout<<endl;
	}
};
int main(){
	int ar[10]={1,2,3,4,5,6,7,8,9,10};
	skiplist<int> *a= new skiplist<int>(10,ar);
	a->show_data(0);
	a->show_data(1);
	a->show_data(2);
	a->show_data(3);
	
	for(int i=0;i<10;i++)
		cout<<"result i="<<a->search(i)<<endl;
	//cout<<"result:"<<a->search(6)<<endl;
	getchar();
	return 0;
} 
