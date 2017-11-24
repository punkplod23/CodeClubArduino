import java.util.Scanner;

public class Questions_2 {

	public static void main(String[] args){
		
	Scanner in = new Scanner(System.in);                             
    
	//Question 1 - login
	System.out.print("What is your name?");
    System.out.println("");
    String strName = in.next();

    if (strName.equalsIgnoreCase("Phil")){
      	System.out.println("Hello " + strName);
        
	}   	        
    else {
    	System.out.println("Go away!");
    	System.exit(0);
    }
     
    //Question 2
      	System.out.println("Are you feeling ok? (Y/N)");
      	String strResponse = in.next();      	
      	question(strResponse);
      	        		   
	}      
	
		
	public static void question(String answer){
		if (answer.equalsIgnoreCase("Y")){
		System.out.println("Great!");
		}
		else{
			System.out.println("no....really..your answer is no????");
		}		
	}		
}
