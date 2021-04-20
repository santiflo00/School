package lab2;

public class Employee {
	
	String name;
	int num;
	int age;
	String state;
	int zip;
	int[] advisor = new int[3];
	
	public Employee() {
		name = null;
		num = 0;
		age = 0;
		state = null;
		zip = 0;
		advisor[0] = 0;
		advisor[1] = 0;
		advisor[2] = 0;
		
	}// of constructor employee
	
	public Employee(String nm, int number, int a, String st, int z) {
		name = nm;
		num = number;
		age = a;
		state = st;
		zip = z;
	}// of 5 argument constructor
	
	public Employee(Object obj) {
		if(obj == null) return;
		if(obj instanceof Employee) {
			Employee e = (Employee)obj;
			name = new String(e.name);
			num = e.num;
			age = e.age;
			state = new String(e.state);
			zip = e.zip;
			advisor = e.advisor;
			
		}// of if
	}// of copy constructor
	
	// Get and Set methods
	public String getName() {
		return name;
	}// of getName
	public void setName(String employeeName) {
		name = employeeName;
	}// of setName
	
	public int getNum() {
		return num;
	}// of getNum
	public void setNum(int number) {
		num = number;
	}// of setNum
	
	public int getAge() {
		return age;
	}// of getAge
	public void setAge(int a) {
		age = a;
	}// of setAge
	
	public String getState() {
		return state;
	}// of getState
	public void setState(String st) {
		state = st;
	}// of setState
	
	public int getZip() {
		return zip;
	}// of getZip
	public void setZip(int zp) {
		zip = zp;
	}// of setZip
	public void getAdvisors() {
		for(int i = 0; i < 3; i++) {
			System.out.print(advisor[i] + " ");
		}// of for
	}// of getAdvisors
	
	public void setAdvisors(int a1, int a2, int a3) {
		advisor[0] = a1;
		advisor[1] = a2;
		advisor[2] = a3;
	}
	public String toString() {
		return (name + ", " + num + ", " + age + ", " + state + ", " + zip + ", " + advisor);
	}// of toString 
	
	public boolean equals(Object obj) {
		if (obj instanceof Employee) {
			Employee candidate = (Employee)obj;
			return (candidate.num == num);
		}
		else { return false; }
	}// of equals
	
	public static int[] getAllAdvisors(Employee e1, Employee e2) {
		int[] same = new int[3];
		int k = 0;
		if (e1 == null || e2 == null) {
			return null;
		}
		else {
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					if(e1.advisor[i] == e2.advisor[j]) {
						same[k] = k;
						System.out.println(same[k]);
						k++;
					}// of if
				}// of inner for
			}// of outer for
			
		//System.out.println(same[0] + " " + same[1] + " k" + same[2]);	
		return same;
		}// of else
	}// of getAllAdvisors
	

	public static void main(String[] args) {
		
		Employee emp1 = new Employee();      // test using no argument constructor
		//call for all set functions
		emp1.setName("Santiago");
		emp1.setNum(3824);
		emp1.setAge(19);
		emp1.setState("NM");
		emp1.setZip(838290);
		emp1.setAdvisors(22,  3, 4);
		
		//Test for set and get functions
		System.out.println(emp1.getName());
		System.out.println(emp1.getNum());
		System.out.println(emp1.getAge());
		System.out.println(emp1.getState());
		System.out.println(emp1.getZip());
		emp1.getAdvisors();
		
		System.out.println();
		
		Employee emp2 = new Employee(emp1); //emp2 is a copy of emp1 to test copy constructor
		//test to see if the object(emp1) was copied to emp2
		System.out.println(emp2.getName());
		System.out.println(emp2.getNum());
		System.out.println(emp2.getAge());
		System.out.println(emp2.getState());
		System.out.println(emp2.getZip());
		emp2.getAdvisors();
		
		System.out.println();
//		//test for getAllAdvisors
		//int[] values = getAllAdvisors(emp1, emp2);
//		for(int i = 0; i < values.length; i++) {
//			System.out.print(values[i] + " ");
//		}// of for
		
		emp2.setAdvisors(4, 32, 9);
		
		System.out.println();
		//test for getAllAdvisors
	// int[] values = getAllAdvisors(emp1, emp2);
//		for(int i = 0; i < values.length; i++) {
//			System.out.print(values[i] + " ");
//		}// of for

		getAllAdvisors(emp1, emp2);
	}// of main

}// of class

//lab2
//Santiago Flores
//Thu 9/5/2019 7:39 AM
