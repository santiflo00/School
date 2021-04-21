// Santiago Flores
// Lab1

import java.io.*;

public class  EmployeeFile0p {
	
	static String[] array = new String[302]; // Global string array used to transfer needed data to write to new file
	
	
	public static void main(String[] args) {
		
		read("core_dataset.csv");
		write("young_employee.csv");
		
		
	}// of main
	
	
	
	public static void read(String fname) {
		
		String line = "";
		String comma = ",";
		int count = 0;
		int i = 0;
		
		
		try {
			FileReader fileReader = new FileReader(fname);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			
			while ((line = bufferedReader.readLine()) != null) {   
				
				if (count == 0) { // skips the first line
					count++;
					array[i] = line;  //store the first line at array[0]
					i++;
				}// of if
				else {	
					
				String[] employees = line.split(comma); //separate by each comma and store in array employees
				
					if(employees.length > 0) {
						if (Integer.parseInt(employees[6]) <= 30) {   //parse string at age into an int and find employees under 30
					
							//System.out.println(employees[0] + "," + employees[1] + "  " + employees[2] + " " + employees[3] + " " + employees[4] + " " + employees[5] + " " + employees[6] + " " + employees[7]);
							array[i] = (employees[0] + "," + employees[1] + "  " + employees[2] + " " + employees[3] + " " + employees[4] + " " + employees[5] + " " + employees[6] + " " + employees[7]);
							i++;
						}// of if
					}// of if
				}// of else
				
				line = bufferedReader.readLine();
				
				
	
			}// of while
		
			bufferedReader.close();
		}// of try
		catch(FileNotFoundException ex) {
				System.out.println("Unable to open file '" + fname + "' ");
			}// of catch
		catch(IOException ex) {
			System.out.println("Error reading file '" + fname + "'");
		}// of catch
	}// of read
	
	public static void write(String fname) {
		
		
		
		try {
			
			File file = new File(fname);
			
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			int i = 0;
			while (array[i] != null) {   // loop until end of the file
				bw.write(array[i] + "\n"); 
			i++;
			}// of while
			
			bw.close();  // close file
			fw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}// of catch
		
		System.out.println("Finish writing to file");
	}// of write
	
	
}// of class