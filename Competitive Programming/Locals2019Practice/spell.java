import java.util.Scanner;

public class spell {
	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		int d = kb.nextInt();
		kb.nextLine();
		String[] words = new String[d];
		for(int i = 0; i < d; i++)
		{
			words[i] = kb.nextLine();
		}
		int n = kb.nextInt();
		kb.nextLine();
		for(int i = 0; i < n; i++)
		{
			boolean flag = false;
			boolean flag2 = false;
			String entry = kb.nextLine();
			System.out.println(entry);
			for(int j = 0; j < words.length; j++)
				if(checkIfSame(entry, words[j]))
				{
					System.out.println("CORRECT");
					flag = true;
				}
			if(!flag)
				for(int j = 0; j < words.length; j++)
				{
					if(omitted(words[j], entry))
					{
						System.out.println("ONE LETTER OMITTED FROM " + words[j]);
						flag2 = true;
					}
					else if(extra(words[j], entry))
					{
						System.out.println("ONE LETTER ADDED TO " + words[j]);
						flag2 = true;
					}
					else if(mistype(words[j],entry))
					{
						System.out.println("ONE LETTER DIFFERENT FROM " + words[j]);
						flag2 = true;
					}
					else if(transp(words[j],entry))
					{
						System.out.println("TWO LETTERS TRANSPOSED IN " + words[j]);
						flag2 = true;
					}
				}
			if(!flag && !flag2)
				System.out.println("UNKNOWN");
			System.out.println();
		}
	}
	public static boolean checkIfSame(String word, String entry)
	{
		if(word.equals(entry))
			return true;
		return false;
	}
	public static boolean omitted(String word, String entry)
	{
		if(word.length() != entry.length()+1)
			return false;

		char[] wordL = word.toCharArray();
		
		for(int i = 0; i < entry.length(); i++)
		{
			for(int j = 0; j < word.length(); j++)
			{

				if((entry.substring(0,i+1) + wordL[j]).equals(word))
					return true;
				if((entry.substring(0,i) + wordL[j] + entry.substring(i)).equals(word))
					return true;
			}
		}
		return false;
	}

	public static boolean extra(String word, String entry)
	{
		if(word.length()!=entry.length()-1)
			return false;
		
		if(entry.substring(0,entry.length()-1).equals(word))
			return true;

		for(int i = 0; i < entry.length()-1; i++)
		{
			if((entry.substring(0,i)+entry.substring(i+1)).equals(word))
				return true;
		}
		return false;
	}
	
	public static boolean mistype(String word, String entry)
	{
		int sameCount = 0;
		if(word.length()!=entry.length())
			return false;
		for(int i = 0; i < word.length(); i++)
		{
			if(word.substring(i, i+1).equals(entry.substring(i,i+1)))
				sameCount++;
		}
		if(sameCount == word.length()-1)
			return true;
		return false;
	}
	public static boolean transp(String word, String entry)
	{
		if(word.length() != entry.length())
			return false;

		

		
		for(int i = 0; i < word.length()-1; i++)
		{
			char[] entry2 = word.toCharArray();
			char temp = word.charAt(i);
			char temp2 = word.charAt(i+1);
			entry2[i] = temp2;
			entry2[i+1] = temp;
			String s = new String(entry2);
			if(s.equals(entry))
				return true;
 		}
		return false;
	}
}
