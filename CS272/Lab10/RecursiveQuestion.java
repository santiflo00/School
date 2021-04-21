package lab10;

public class RecursiveQuestion {
	
	//1. Fibonacci Binary Recursion
	public static int FibBinaryRecursive(int k) {
		if(k <= 1) return k;
		return FibBinaryRecursive(k-1) + FibBinaryRecursive(k-2);
	}// of FibBinaryRecursive
	
	//2.Towers of Hanoi
	public static void toh(int src, int dest, int temp, int n) {
		if(n == 1) move(src,dest);
		else {
			toh(src, temp, dest, n-1);
			move(src, dest);
			toh(temp, dest, src, n-1);
		}// else
	}// of toh
	
	private static void move(int src, int dest) {
		System.out.println("Move from peg " +src + " to peg " + dest);
	}

	//3. Show call levels
	public static String showCallLevel(int L, int curl) {
		String space = " ";
		for(int i = 0; i < curl-1; i++) {
			space = space + " ";
		}
		System.out.println(space + "This is the "+ curl + " recursive call");
		if(L == 1) {return "";}
		else {
			  String output = showCallLevel(L - 1, curl + 1);
			  System.out.println(space + "This is the " + curl + " recursive call ");
			  return output;
		}
	}// showCallLevel
	
	//4. Binary Print
	public static void BinaryPrint(int n) {
	
		if(n == 0) {System.out.print("0"); return;}
		else {
			BinaryPrint(n/2);
			System.out.print(n % 2);
		}
	}
	//5. Pattern
	public static String Pattern(int x, int y) {
		String s = "", a = "";
		if(x == 0) return "*";
		else {
			if(x%2 == 1) {
				s = Pattern(x-1,y);
				System.out.println(s);
				return  s;
			}// of if
			else {
				s = Pattern(x-1,y-1);
				if(y%2 == 0) {
					for(int i = 0; i < y; i++) {
						a = a + "*";
					}
				}//if
				System.out.println(a);
				return  " "+s;
			}// of else
		}//outer else
	}//Pattern
	
	
	public static void main(String[] args) {
		//First 9 numbers of the fibbonacci sequence 1,1,2,3,5,8,13,21
		for(int i = 1; i < 9; i++)
			System.out.print(FibBinaryRecursive(i)+", ");
		System.out.println();
		
		
		toh(1,3,2, 3);  //move disks from peg 1 to 3 using the 2nd one as a temp with 3 disk
		System.out.println();
		
		BinaryPrint(4);//0100
		System.out.println();
		BinaryPrint(12);//1100
		System.out.println();
		
		showCallLevel(5,1); //Starting from level one to level 5
		System.out.println();
		
		Pattern(16,8);


	}// of main

}// of class
