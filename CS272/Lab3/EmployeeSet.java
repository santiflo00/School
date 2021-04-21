package Lab3;

import java.io.*;

//TODO need to finish addOrdered method, and main method for test functions

public class EmployeeSet {

	private Employee[] data;
	private int items;
	
	public EmployeeSet() {
		final int INITIAL_SIZE = 10;
		items = 0;
		data = new Employee[INITIAL_SIZE];
	}// of employee
	
	public EmployeeSet(Object obj) {
		if(obj == null) return;
		if(obj instanceof EmployeeSet) {
			EmployeeSet copy = (EmployeeSet)obj;
			items = copy.items;
			data = new Employee[items];
			for(int i = 0; i < items; i++) {
				data[i] = copy.data[i];
			}// of for loop
		}// of if 
	}// of copy constructor
	
	public int size() {   // method to return number of elements 
		return items;
	}// of size
	
	public int capacity() {  // method to return capacity of collection
		return data.length;
	}// of capacity
	
	public void add(Employee a) {   //adds an employee object to first available space in array

		if(items == data.length) {
			ensureCapacity((items*2));
		}// of if
		data[items] = a;
		items++;
		
	}// of add
	
	public boolean contains(Employee a) {
		if(a == null) return false;
		for(int i = 0; i < items; i++) {
			if(a == data[i]) {
				return true;
			}// of if
		}// of for
		return false;
	}// of contains
	
	public boolean remove(int eno) {
		for(int i = 0; i < data.length; i++) {
			if(i == items) { return false; }
			else if(data[i].getNum() == eno) {
				items--;
				data[i] = data[items];
				return true;
			}// of else if
		}// of for
		return false;
	}//of remove
	
	private void ensureCapacity(int minimumCapacity) {  // double array when it is full
		
		Employee[] bigger;
		
		if(data.length < minimumCapacity) {
			bigger = new Employee[minimumCapacity];
			System.arraycopy(data, 0, bigger, 0, items);
			data = bigger;
		}// of if
		
	}// of ensureCapacity
	
	public void addOrdered(Employee a) { //Sorts data using bubble sort then adds the new object by calling add method      
		if(a == null) return;
		boolean sorted = false;
		int temp;
		while(!sorted) {
			sorted = true;
			for(int i = 0; i < items-1; i++) {
				if(data[i].getNum() > data[i+1].getNum()) {
					temp = data[i].getNum();
					data[i].setNum(data[i+1].getNum());
					data[i+1].setNum(temp);
					sorted = false;
				}// of if
			}// of for
		}// of while
		add(a);
	}// of addOrdered
	
	
	public static void main(String[] args) {
		// TODO Read in csv file
		EmployeeSet data1 = new EmployeeSet();
		
		Employee emp1 = new Employee("Flores, Santiago", 3824, 19, "NM", 2578);
		
		System.out.println(data1.size());
		System.out.println(data1.capacity());
		data1.add(emp1);                          //add emp1 to data1
		System.out.println(data1.contains(emp1)); //test to see if add and contains works returns true
		System.out.println(data1.size());
		System.out.println();
		
		EmployeeSet data2 = new EmployeeSet();
		//Hard coded test cases
		Employee e1 = new Employee("Dickinson, Geoff", 7852, 35, "MA", 2180);
		Employee e2 = new Employee("DiNocco, Lily", 4856, 39, "CA", 2351);
		Employee e3 = new Employee("Dobrin, Denisa", 1234, 31, "WA", 2125);
		Employee e4 = new Employee("Eaton, Marianne", 8987, 26, "NM", 2343);
		Employee e5 = new Employee("Engdahl, Jean", 3145, 43, "CO", 2026);
		Employee e6 = new Employee("England, Rex", 4555, 39, "EN", 2045);
		Employee e7 = new Employee("Estremera, Miguel", 3214, 34, "DI",2129);
		Employee e8 = new Employee("Evensen, April", 7915, 28, "HI",2458);
		Employee e9 = new Employee("Ferguson, Susan", 4456, 62, "LN", 1789);
		Employee e10 = new Employee("Fernandes, Nilson", 7701, 28, "NS", 2132);
		
		data2.add(e1);
		data2.add(e2);
		data2.add(e3);
		data2.add(e4);
		data2.add(e5);
		data2.add(e6);
		data2.add(e7);
		data2.add(e8);
		data2.add(e9);
		data2.add(e10);
		
//		EmployeeSet data3 = new EmployeeSet(data2);  
		
		System.out.println(data2.size());             //Size returns 10(num of elements)
		System.out.println(data2.capacity());         //return 10 (inital array size)
		System.out.println(data2.contains(e3));       //return true
		System.out.println(data2.contains(emp1));     //return false
		data2.remove(4456);                           //remove e9
		System.out.println(data2.size());             //Size returns 9 
		System.out.println(data2.contains(e9));       //return false e9 was removed
		
		System.out.println();
		data2.add(e9);
		data2.add(emp1);
		System.out.println(data2.size());           //size becomes 11
		System.out.println(data2.capacity());       //Capacity is double from 10 to 20
		System.out.println(data2.contains(emp1));	//return true
		
		System.out.println();
		Employee e11 = new Employee("jakfl;as", 1561, 20,"SF", 0 );
		data2.addOrdered(e11);
		System.out.println(data2.size());
		System.out.println(data2.contains(e11));
		
		System.out.println();
		
		
		EmployeeSet data4 = new EmployeeSet();
		String line = "";
		String comma = ",";
		int count = 0;
		int i = 0;
		
		// read csv file
		try {
			FileReader fr = new FileReader("core_dataset.csv");
			BufferedReader br = new BufferedReader(fr);
			while((line = br.readLine()) != null) {
				
				if (count == 0) { // skips the first line
					count++;
				}// of if
				else {	
				
			String[] employees = line.split(comma); //separate by each comma and store in array employees
			
				if(employees.length > 0) {
					Employee e = new Employee(employees[0] + ", " + employees[1], Integer.parseInt(employees[2]), Integer.parseInt(employees[3]),"NM", 0);
					data4.add(e);
						
				}// of if
				}// of else
				line = br.readLine();
			}// of while
		
		br.close();
		}// of try
		catch(FileNotFoundException ex) {
			System.out.println("Unable to open file 'core_dataset.csv' ");
		}// of catch
		catch(IOException ex) {
		System.out.println("Error reading file 'core_dataset.csv' ");
		}// of catch
		
		System.out.println(data4.capacity());
		System.out.println(data4.size());
		
	}// of main

}// of class
