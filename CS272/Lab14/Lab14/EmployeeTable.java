package Lab14;

public class EmployeeTable {
	int size;
	Object[] keys;
	Object[] data;
	boolean[] used;
	
	public EmployeeTable() {
		size = 0;
		keys = new Object[701];
		data = new Object[701];
		used = new boolean[701];
		for(int i = 0; i < used.length;i++) {used[i] = false;}//initialize all values to false as the table is empty
	}//constructor
	
	public void put(Employee e) {
		int index = hash(e.getNum());
		while(used[index] == true) {index++;}//loop for the first available free space
		data[index] = e;
		keys[index] = e.getNum();
		used[index] = true;
		size++;
		System.out.println("Employee '"+ e.getName()+ "' has been entered with index "+index);
	}//put
	
	public boolean remove(int emp_no) {
		int index = hash(emp_no);
		int s = search(emp_no);
		if(s==-1)return false;
		System.out.println("Employee '" +data[index]+ "' is being removed");
		keys[index] = null;
		data[index] = null;
		used[index] = false;
		size--;
		return true;
	}//remove
	
	public int search(int emp_no) {
		int index = hash(emp_no);
		int i = 0;
		while(i < keys.length && used[index]==true) {
			if((int)keys[index] == emp_no)return index;
			i++;
			index++;
		}//while
		return -1;
	}//search
	
	private int hash(Object emp_no) {
		return Math.abs(emp_no.hashCode()%keys.length);
	}//hash
	
	public static void main(String args[]) {
		EmployeeTable empTable = new EmployeeTable();
		Employee emp1 = new Employee();
		System.out.println("Size of hash table: "+empTable.size+"\n");
		emp1.setName("Santiago");
		emp1.setNum(154945261);
		empTable.put(emp1);
		System.out.println("Search for index of emp1: "+empTable.search(emp1.getNum())+"\n");
		System.out.println("Size of hash table: "+empTable.size+"\n");
		
		Employee emp2 = new Employee();
		emp2.setName("emp2");
		emp2.setNum(1211131311);
		empTable.put(emp2);
		System.out.println("Search for index of emp2: "+empTable.search(emp2.getNum())+"\n");
		
		Employee emp3 = new Employee();
		emp3.setName("emp3");
		emp3.setNum(44644564);
		empTable.put(emp3);
		System.out.println("Search for index of emp3: "+empTable.search(emp3.getNum())+"\n");
		
		Employee emp4 = new Employee();
		emp4.setName("emp4");
		emp4.setNum(987312);
		empTable.put(emp4);
		System.out.println("Search for index of emp4: "+empTable.search(emp4.getNum())+"\n");
		
		Employee emp5 = new Employee();
		emp5.setName("emp5");
		emp5.setNum(123456789);
		empTable.put(emp5);
		System.out.println("Search for index of emp5: "+empTable.search(emp5.getNum())+"\n");
		System.out.println("Size of hash table: "+empTable.size+"\n");
		
		empTable.remove(emp2.getNum());
		System.out.println("\nSize of hash table: "+empTable.size);
		
		System.out.println(empTable.remove(489));//employee num that does not exist return false
		System.out.println("Size of hash table: "+empTable.size+"\n");//table stays same size
		
		Employee emp6 = new Employee();
		//employee to test collision occurrences
		emp6.setName("emp6");
		emp6.setNum(875);//same hash number as emp5
		empTable.put(emp6);
		System.out.println("Search for index of emp6: "+empTable.search(emp6.getNum())+"\n");//index is 1 more than index of emp5
		System.out.println("Size of hash table: "+empTable.size+"\n");
		
		
		
	}// main
}//class
