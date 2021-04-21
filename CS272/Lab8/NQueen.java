package Lab8;

public class NQueen {
	
	public static void solve(int N) {
		ArraylistStack<Integer> S = new ArraylistStack<Integer>();
		int rowid = (S.size() +1);
		int colid = 0;
		int qpos = 0;
		
		while(S.size() < N) {
			colid = 1;
			qpos = 1;
			while(colid <= N) {
				if(checkConflict(colid, S)== true) {
					colid++;
				}
				else {
					S.push(colid);
					break;
				}
				
			}// of while
		//Need to backtrack
		}// of while
	}// of solve
	
	public static boolean checkConflict(int Qpos, ArraylistStack<Integer> s) {
		if(Qpos == s.top() || Qpos == s.top()-1 || Qpos == s.top()+1 ) {return false; }
		
		return true;
	}//of
	
	
	
	public static void main(String[] args) {
		solve(5);

	}//of main

}// of class
