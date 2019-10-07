#include <iostream>
using namespace std;

class node{
	public:
		int info;
		node *next;
		node(int info){
			this->info = info;
			this->next = NULL;
		}

};	

class queue{
	private:
		node *front, *back;

	public:
		bool empty(){
			return this->back==NULL and this->front==NULL;
		}

		void push(int info){
			node *aux = new node(info);

			if(front==NULL){
				this->front=this->back=aux;
			}else{
				this->back->next = aux;
				this->back = aux;
			}
		}

		void pop(){
			//		if(this->empty()) return;//if not commented, there will be an error if pop on empty queue

			this->front = this->front->next;

			if(this->front==NULL) this->back = this->front;
		}

		int top(){
			return this->front->info;
		}

};


int32_t main(){
	queue *q = new queue();
	cout<<"is empty? "<<q->empty()<<endl;
	q->push(10);

	q->push(1);
	q->push(5);

	cout<<q->top()<<endl;
	q->pop();
	cout<<q->top()<<endl;

	q->pop();
	cout<<q->top()<<endl;

	q->pop();
//	q->pop();
	return 0;
}
