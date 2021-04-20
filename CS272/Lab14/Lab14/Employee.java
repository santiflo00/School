package Lab14;

public class Employee {

	private String name;
	private int num;
	private int age;
	private String state;
	private int zip;
	private int[] advisor = new int[3];

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
		if (obj == null) throw new IllegalArgumentException("Object is null");
		if (obj instanceof Employee) {
			Employee candidate = (Employee)obj;
			return (candidate.num == num);
		}// of if
		else { return false; }
	}// of equals

	public static int[] getAllAdvisors(Employee e1, Employee e2) {
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
}//class