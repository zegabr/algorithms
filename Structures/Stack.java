import java.util.Scanner;
class Node{
	char data;
	Node next;
	public Node(char data) {
		this.data=data;
		this.next=null;
	}
}
class Stack{
	Node top;
	public Stack() {
		this.top=null;
	}
	public void push(char data) {
		Node aux = new Node(data);
		if(this.top==null)//pilha vazia
			this.top=aux;
		else {
			aux.next=this.top;
			this.top=aux;
		}	
	}
	public void pop() {
		if(this.top==null)
			return;
		else {
			this.top=this.top.next;
		}
	}
	public String printStack() {//for test purposes
		String s="";
		Node aux = this.top;
		if(aux==null)
			return "vazio";
		while(aux!=null) {
			s=s+" "+aux.data;
			aux=aux.next;
		}
		return s;
	}
}
public class Main {
	public static void main(String[] args) {
		Stack teste = new Stack();
		teste.push('1');
		teste.push('2');
		teste.push('3');
		teste.pop();
		teste.pop();
		teste.push('4');
        System.out.println(teste.printStack());	
	}
}