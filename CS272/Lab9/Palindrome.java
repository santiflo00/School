package lab9;
import Lab8.LinkStack;
import java.util.Scanner;

public class Palindrome {

	public static void main(String[] args) {
		String p;
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter a phrase to test if it is a word-by-word palindrome or not: ");
		p = scan.nextLine();
		scan.close();
		System.out.println(isPalindrome(p));
	}// main
	
	public static boolean isPalindrome(String st) {
		LinkedQueue<String> pqueue = new LinkedQueue<String>();
		LinkStack<String> pstack = new LinkStack<String>();
		String add = "";
		boolean ans = true;
		int length = st.length();
		for(int i = 0; i < length; i++) {
			if(st.charAt(i) == ' ' || st.charAt(i) == ',' || st.charAt(i) == '?' || st.charAt(i) == '!' || st.charAt(i) == '.' || i == length-1) {
				pqueue.enqueue(add);
				pstack.push(add);
				add = "";
			}// of if
			else {
				add = add + st.charAt(i);
			}//else if
		}//for
		int size = pqueue.size();
		for(int i = 0; i < size; i++) {
			if(pqueue.front() != pstack.top()) {
				ans = false;
				break;
			}//if
			else {
				pqueue.dequeue();
				pstack.pop();
			}//else
		}//for
		return ans;
		
	}// isPalindrome

}// class
