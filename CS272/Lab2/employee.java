

//lab2
//Santiago Flores
// 9/6/2019
//CS 272


package lab2;

public class employee {

	String name;
	int num;
	int age;
	String state;
	int zip;
	int[] advisor = new int[3];

	public employee() {

		name = null;
		num = 0;
		age = 0;
		state = null;
		zip = 0;
		advisor[0] = 0;
		advisor[1] = 0;
		advisor[2] = 0;

	}// of constructor employee

	public employee(Object obj) {

		if(obj == null) return;
		if(obj instanceof employee) {
			employee e = (employee)obj;
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
		System.out.println();
	}// of getAdvisors
	public void setAdvisors(int a1, int a2, int a3) {
		advisor[0] = a1;
		advisor[1] = a2;
		advisor[2] = a3;
	}// of setAdvisors
	
	public String toString() {
		return (name + ", " + num + ", " + age + ", " + state + ", " + zip + ", " + "advisors(" + advisor[0] + ", " + advisor[1] + ", " + advisor[2] + ")");
	}// of toString 

	public boolean equals(Object obj) {
		if (obj instanceof employee) {
			employee candidate = (employee)obj;
			return (candidate.num == num);
		}// of if
		else { return false; }
	}// of equals

	public static int[] getAllAdvisors(employee e1, employee e2) {
		int[] same = new int[3];
		int k = 0;
		if (e1 == null || e2 == null) {
			return null;
		}// of if
		else {
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					if(e1.advisor[i] == e2.advisor[j]) {
						same[k] = e1.advisor[i];
						k++;
					}// of if
				}// of inner for
			}// of outer for
		return same;
		}// of else
	}// of getAllAdvisors

	
	public static void main(String[] args) {

		employee emp1 = new employee();      // test using no argument constructor
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
		System.out.println(emp1.toString());

		System.out.println();

		employee emp2 = new employee(emp1); //emp2 is a copy of emp1 to test copy constructor
		//test to see if the object(emp1) was copied to emp2
		System.out.println(emp2.getName());
		System.out.println(emp2.getNum());
		System.out.println(emp2.getAge());
		System.out.println(emp2.getState());
		System.out.println(emp2.getZip());
		emp2.getAdvisors();
		System.out.println(emp2.toString());

		System.out.println();

		//test for getAllAdvisors           should get all values since arrays are the same
		int[] values = getAllAdvisors(emp1, emp2);
		for(int i = 0; i < values.length; i++) {
			System.out.print(values[i] + " ");
		}// of for
		
		System.out.println();
		
		
        //create new object and set advisors to see if getAllAdvisors gets correct values and for equals method
		employee emp3 = new employee();
		emp3.setAdvisors(3, 399, 28);
		emp3.getAdvisors();
		emp3.setNum(6767);
		
		//Should only return number 3
	    values = getAllAdvisors(emp1, emp3);
		for(int i = 0; i < values.length; i++) {
			System.out.print(values[i] + " ");
		}// of for
		System.out.println();
		
		System.out.println(emp1.equals(emp2));  //Should return true 
		System.out.println(emp3.equals(emp1));  //should return false


	}// of main
}// of class



