
import java.util.Scanner;

class Node{
	int carlen;
	Node next;
	
	public Node(int carlen) {
		this.carlen=carlen;
		this.next = null;
		
	}
}
class Queue{
	
	Node top;
	Node rear;
	
	public Queue() {
		this.top=null;
		this.rear=null;
	}
	
	public void deQueue() {//done
		//retira do inicio da fila (top)
		this.top = this.top.next;
		if(this.top == null)
			this.rear=null;
		
	}
	
	public void enqueue(int carlen) {//done
		//coloca no fim da fila (rear)
		Node aux = new Node(carlen);
		if(this.top==null) {
			this.top = this.rear = aux;
		}else {
			this.rear.next = aux;
			this.rear = aux;
			
		}
	}
	
	
}
public class Main {

	
	public static void main(String[] args) {
		
		
		
	}
}