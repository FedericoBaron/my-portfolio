import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Balloon {
	public static void main(String[]args) {
		Scanner kb = new Scanner(System.in);
		
		//continues for multiple test cases until input = "0 0 0"
		while (kb.hasNext()) {
		      int n = kb.nextInt();
		      int a = kb.nextInt();
		      int b = kb.nextInt();
		      if ((n | a | b) == 0)
		        return;
		
		//sets teams to be a 2D array which contains all teams and their info
		int[][] teams = new int[n][3];

    //fills up 2D array
		for(int i = 0;i < n; i++) {
			teams[i][0] = kb.nextInt();
			teams[i][1] = kb.nextInt();
			teams[i][2] = kb.nextInt();
		}
		
		//custom sort that sorts it by highest distance between a and b
		int[]temp = new int[3];
		for(int i = 0;i < teams.length; i++) {
			for(int j = 0; j < teams.length-1;j++) {
				if(Math.abs(teams[j][1]-teams[j][2]) < Math.abs(teams[j+1][1]-teams[j+1][2])) {
					temp=teams[j];
					teams[j]=teams[j+1];
					teams[j+1]=temp;
				}
			}
		}
		
		//Calculates distance

    //d is distance
		int d = 0;

    //for loop for going through every team
		for(int i = 0; i < n; i++) {

      //checks which room is further
			if(teams[i][1]>teams[i][2]) {

        //adds to distance and subtracts balloons
				while(b>0 && teams[i][0]>0) {
					b--;
					d += teams[i][2]; 
					teams[i][0]--;
				}

        //makes room switch if necessary for that team and keeps adding distance and subtracting balloons
				while(teams[i][0]>0) {
					a--;
					d += teams[i][1];
					teams[i][0]--;
				}
			}

      //if room b is further it enters this else
			else {
        
        //adds to distance and subtracts balloons
				while(a>0 && teams[i][0]>0) {
					a--;
					d += teams[i][1];
					teams[i][0]--;
				}

        //switches room if necessary for that team and keeps adding to distance and subtracting balloons
				while(teams[i][0]>0) {
					b--;
					d += teams[i][2];
					teams[i][0]--;
				}
			}
		}
		
		//prints distance
		System.out.println(d);
		
		}
	}
}
