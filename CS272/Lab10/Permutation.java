package lab10;
import java.util.Arrays;

public class Permutation {
	
	    private static void swap(int[] a, int x, int y) {
	        int temp = a[x];
	        a[x] = a[y];
	        a[y] = temp;
	    }
	    public static void permute(int[] a) {
	        permute(a, 0, a.length-1);
	    }

	    private static void permute(int[] a, int first, int last) {
	        if (first == last) System.out.println(Arrays.toString(a));
	        else {
	            for (int i = first; i <= last; i++) {
	                swap(a, first, i);
	                permute(a, first + 1, last);
	                swap(a, first, i);
	            }//for
	            
	        }//else
	        
	    }//of permute

	    public static void main(String[] args) {
	    	int[] test1 = new int[]{1}; //test with length 1
	    	permute(test1);
	    	System.out.println();
	    	
	    	int[] test2 = new int[] {212, 59};//Test with length 2
	        permute(test2);
	    	System.out.println();
	    	
	        int[] test3 = new int[]{23, 432 , 6, 5, 32};// test with length 5
	        permute(test3);
	        System.out.println();
	        
	        int[] test4 = new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//test with length 10
	        permute(test4);

	    }// of main


}// class
