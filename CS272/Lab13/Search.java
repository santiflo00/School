package lab13;

public class Search {

	public static int binarySearch(int[] A, int e) {
		int ans;
		ans = binarySearch(A, 0, A.length-1, e);
		return ans;
	}//binarySearch
	
	private static int binarySearch(int[] A, int start, int end, int e) {
		int mid;
		if(end < start)return -1;
		mid = (start+end)/2;
		
		if(A[mid] == e) //number is found return position
			return mid;
		
		else if(e < A[mid]) //number is not found and lower less than mid value
			return binarySearch(A, start, mid-1, e);
		
		else  //number is not found and is larger than mid value
			return binarySearch(A, mid+1, end, e);
		
	}//binary search
	
	public static void main(String[] args) {
		int[] test3 = new int[] {7,18,54,92,420,689};
		System.out.println(binarySearch(test3, 420));//returns 4(position of 420)
		System.out.println(binarySearch(test3, 12));//return -1 element does not exist in array
		System.out.println(binarySearch(test3, 7));//return 0
		System.out.println(binarySearch(test3, 689));//return 5
		System.out.println(binarySearch(test3, 920));//return -1
		
	}//main

}//class
