#include <iostream>
using namespace std;

template<class T>
class node{
	public:
		T info;
		node *next;
		node(T val){
			info = val;
			next = NULL;
		}

};	

template<class T>
class queue{
	private:
		node<T> *front, *back;

	public:
		queue(){front=back=NULL;}
		bool empty(){
			return back==NULL and front==NULL;
		}

		void push(T val){
			node<T> *aux = new node<T>(val);

			if(front==NULL){
				front=back=aux;
			}else{
				back->next = aux;
				back = aux;
			}
		}

		void pop(){
			//		if(empty()) return;//if not commented, there will be an error if pop on empty queue

			front = front->next;

			if(front==NULL) back = front;
		}

		T top(){
			return front->info;
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
