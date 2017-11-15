import java.util.Scanner;

public class Questions {

	public static void main(String[] args){
		
	Scanner in = new Scanner(System.in);                             
    
	//Question 1
	System.out.print("What is your name?");
    System.out.println("");
    String strName = in.next();

    //Question 2
    if (strName.equalsIgnoreCase("Phil")){
      	System.out.println("Hello " + strName);
        
	}   	        
    else {
    	System.out.println("Go away!");
    	System.exit(0);
    }
     
    //Question 3
      	System.out.println("Are you feeling ok? (Y/N)");
      	String strResponse = in.next();
      	if (strResponse.equalsIgnoreCase("Y")){
    	System.out.println("Glad to hear it");    	
    }
    else {
    	System.out.println("sorry to hear that, maybe talking to me will cheer you up");
    }
          		   
	}        			
}
