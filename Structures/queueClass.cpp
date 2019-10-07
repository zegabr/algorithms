#include <iostream>
using namespace std;

template<class T>
class node{
	public:
		T info;
		node *next;
		node(T val){
			this->info = val;
			this->next = NULL;
		}

};	

template<class T>
class queue{
	private:
		node<T> *front, *back;

	public:
		queue(){front=back=NULL;}
		bool empty(){
			return this->back==NULL and this->front==NULL;
		}

		void push(T val){
			node<T> *aux = new node<T>(val);

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

		T top(){
			return this->front->info;
		}

};


int32_t main(){
	queue<int> q;
	cout<<"is empty? "<<q.empty()<<endl;
	q.push(10);

	q.push(1);
	q.push(5);

	cout<<q.top()<<endl;
//return 0;
q.pop();
	cout<<q.top()<<endl;

	q.pop();
	cout<<q.top()<<endl;

	q.pop();
//	q->pop();
	return 0;
}
