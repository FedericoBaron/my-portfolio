import java.util.Scanner;

public class stopping {
	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		int total = kb.nextInt();
		int total2 = 1;
		int stops = 0;
		int gas = kb.nextInt();
		int food = kb.nextInt();
		while(total2<total)
		{
			if(total2 % gas == 0 && total2 % food == 0)
			{
				stops++;
			}
			else if(total2 % gas == 0)
			{
				stops++;
			}
			else if(total2 % food == 0)
			{
				stops++;
			}
			total2++;
		}
		System.out.println(stops);
	}
}
