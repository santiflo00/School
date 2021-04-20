package Lab14;
import java.util.*;
import java.io.*;

public class hash {

	public static void main(String[] args) {
		HashMap<Integer, Employee> hMap = new HashMap<Integer,Employee>();
		Employee e = new Employee();
		
		//read data from csv file and put employees into hMap
		String line = "";
		String comma = ",";
		int count = 0;

		try {
			FileReader fileReader = new FileReader("/home/sflores/projects/eclipse-workspace/CS272/Lab14/core_dataset.csv");//path may be different
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			
			while ((line = bufferedReader.readLine()) != null) {   
				
				if (count == 0)count++;//skips first line
				
				else {		
					e = new Employee();
					String[] employees = line.split(comma); //separate by each comma and store in array employees
					e.setName(employees[0]+", " +employees[1]);
					e.setNum(Integer.parseInt(employees[2]));
					e.setState(employees[3]);
					e.setZip(Integer.parseInt(employees[4]));
					e.setAge(Integer.parseInt(employees[6]));
					hMap.put(e.getNum(),e);
					System.out.println("Employee "+e.getName()+ " has been placed in hash");
				}//else
			}//while
			bufferedReader.close();
		}//try
		catch(FileNotFoundException ex) {
				System.out.println("Unable to open file");
		}
		catch(IOException ex) {
			System.out.println("Error reading file");
		}
		System.out.println("Done reading file\n");
		
		System.out.println("Size of hash after adding employees: " +hMap.size());
		
		//Remove employees
		hMap.remove(1112030816);
		System.out.println("Size of hash after removing 1112030816: " +hMap.size());
		hMap.remove(1111030148);
		System.out.println("Size of hash after removing 1111030148: " +hMap.size());
		hMap.remove(602000312);
		System.out.println("Size of hash after removing 602000312: " +hMap.size()+"\n");
		
		Employee e1 = new Employee();
		//Finding employees
		e1 = hMap.get(1501072093);
		System.out.println("Employee 1501072093: "+e1);
		System.out.println("Size of hash: " +hMap.size());
		
		//Is null since employee was removed
		e1 = hMap.get(1111030148);
		System.out.println("Employee 1111030148: "+ e1);
		System.out.println("Size of hash: " +hMap.size());
		
	}//main

}//class
