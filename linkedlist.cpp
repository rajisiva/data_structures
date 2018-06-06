#include<iostream>
#include<cstdlib>
struct node{
	int data;
	node* next;
};
struct node* head;
struct node* tail;
void print(){
	node* temp = head;
	while(temp!=NULL){
		std::cout<<temp->data<<"\t";
		temp = temp->next;
	}
	std::cout<<std::endl;
}
void insert(int value){
	node* temp = (node *)malloc(sizeof(node));
	temp->data = value;
	if (head == NULL){
		temp->next = NULL;
		head = temp;	
		tail = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
	return;
}
void insertAtEnd(int value){
	node* temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->next = NULL;	
	if(head == NULL){
		head = temp;
	}
	else{
		node *temp1 = head;
		while(temp1->next !=NULL){
			temp1 = temp1->next;
		}
		temp1->next = temp;
		tail = temp;
	}
}
void insertAtPosition(int value,int pos){
	node* temp = (node *)malloc(sizeof(node));
	temp->data = value;
	if(pos == 1){
		temp->next = head;
		head = temp;
		return;
	}
	else if(pos>1){
		node* temp1 = head;
		for(int i=1;i<pos-1;i++){
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
		if(temp->next == NULL){
			tail = temp;
		}
	}
	else	
		std::cout<<"enter valid position"<<std::endl;
}

void removeHead(){
	if(head->next == NULL){
		
		head = NULL;
		free(head);
		return;
	}
	node * temp = head;
	temp = temp->next;
	free(head);
	head = temp;
	return;
}
void deleteValue(int value){
	node* temp = head;
	node * prev;
	while(temp->data!=value){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
	return;
}

void deleteAtPos(int pos){
	node* temp = head;
	node* prev;
	if(pos==1){
		head = NULL;
		free(head);
		return;
	}
	for(int i=1;i<pos;i++){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
	return;
}

void reversePrint(node *temp){
	if(temp == NULL) return;
	reversePrint(temp->next);
	std::cout<<temp->data<<"\t";
}

void reverseList(node *temp){
	if(temp->next == NULL){
		head = temp;
		return;
	}
	reverseList(temp->next);
	node *n = temp->next;
	n->next = temp;
	temp->next = NULL;
	tail = temp;
}

void mthNodeFromLast(int m){
	node* temp;
	node* temp1;
	temp = head;
	temp1 = head;
	for(int i=0;i<m;i++){
		temp = temp->next;
	}
	while(temp->next){
		temp = temp->next;
		temp1 = temp1->next;
	}
	std::cout<<std::endl<<temp1->data;
}

int main()
{
	int value;
	head = NULL;
	std::cout<<"enter a value";
	std::cin>>value;
	insert(value);
	insert(5);
	insert(10);
	insertAtEnd(15);
	insertAtEnd(20);
	insertAtEnd(25);
	insertAtPosition(30,7);
	insert(35);
	insertAtEnd(40);
	deleteValue(15);
	removeHead();
	deleteAtPos(3);
	print();
	std::cout<<std::endl<<"Tail pointer"<<tail->data;
	std::cout<<std::endl<<"Head Pointer"<<head->data<<std::endl;
	std::cout<<std::endl<<"ReversePrint\t"<<std::endl;
	reversePrint(head);
	std::cout<<std::endl<<"ReverseList\t"<<std::endl;
	reverseList(head);
	print();
	std::cout<<std::endl<<"Tail pointer"<<tail->data;
	std::cout<<std::endl<<"Head Pointer"<<head->data;
	mthNodeFromLast(5);
	return 0;
}
