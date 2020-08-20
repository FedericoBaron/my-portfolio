import java.util.Scanner;

public class bulk {
	public static void main(String [] args)
	{
		Scanner kb = new Scanner(System.in);
		int x = kb.nextInt();
		int y = kb.nextInt();
		System.out.println(y*x-((x-1)*2));
	}
}
