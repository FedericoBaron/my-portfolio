// Federico Baron 
// COP3330 Fall 2019
// NID: fe960661

import java.util.Arrays;
public class Strands
{
    public static void straightAndNarrow(String str)
    {
        // checks if str is null or if its length is 0 and prints "Pshh!" if so
        if (str == null || str.length() == 0)
        {
            System.out.println("Pshh!");
            return;
        }

        // get the length of the string
        int len = str.length();

        // iterate through the string substrings
        for (int i = 0; i < len; i++)
        {
            // if its a space don't print it 
            if (str.substring(i,i+1).equals(" "))
                System.out.println();
            // if its not a space print it 
            else
                System.out.println("  " + str.substring(i, i+1));
        }
    }

    public static void straightAndNarrow(String str, int n)
    {
        // checks if str is null or if its length is 0 and prints "Pshh!" if so
        if (str == null || str.length() == 0)
        {
            System.out.println("Pshh!");
            return;
        }

        // get the length of the string 
        int len = str.length();

        // iterate through the string substrings
        for (int i = 0; i < len; i++)
        {
            // if it's a space just print a new line 
            if (str.substring(i,i+1).equals(" "))
                System.out.println();
            // otherwise print n spaces and then print the letter
            else
            {
                for (int j = 0; j < n; j++)
                    System.out.print(" ");
                System.out.println(str.substring(i, i+1));
            }
        }
    }

    public static void meanderingPath(String str)
    {
        // checks if str is null or if its length is 0 and prints "Pshh!" if so
        if (str == null || str.length() == 0)
        {
            System.out.println("Pshh!");
            return;
        }
        
        // save the path of spaces
        int[] path = {2, 2, 2, 3, 4, 5, 5, 5, 4, 3};

        // save the length of the string 
        int len = str.length();

        // first letter needs 3 spaces instead of following path
        if (str.length() >= 1)
            System.out.println("   " + str.substring(0, 1));

        // rest of letters follow the meandering path
        for (int i = 1; i < len; i++)
        {
            // if its a space just print a new line
            if (str.substring(i,i+1).equals(" "))
                System.out.println();
            // otherwise print as many spaces as are needed and the character at i 
            else
            {
                for (int j = 0; j < path[i%path.length]; j++)
                {
                    System.out.print(" ");
                }
                System.out.println(str.substring(i,i+1));
            }
        }
    }

    public static void classicRapunzel(String[] strings)
    {

        // check for empty or null
        if (strings == null || strings.length == 0)
        {
            System.out.println("Pshh!");
            return;
        }
        
        // length of strings array 
        int len = strings.length;

        // meandering path to follow 
        int[] path = {2, 2, 2, 3, 4, 5, 5, 5, 4, 3};

        // char array to save the lines of output
        char[] chars = new char[len * 3 + path[5]];

        // fills up the chars array with space characters
        Arrays.fill(chars, ' ');
        int loc = 0;

        // save length of longest string
        int maxi = 0;
        for (int i = 0; i < len; i++)
        {
            maxi = Math.max(maxi, strings[i].length());
        }
        
        // go through first line do 3 spaces for first char and 2 for the rest
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                loc = loc + 3;
            }
            else
            {
                loc = loc + 2;
            }
            if (strings[i].length() > 0)
                chars[loc] = strings[i].charAt(0);
            loc++;
            
        }
        
        // print all the characters saved from the first line 
        printChars(chars);

        // go through each line
        for (int line = 1; line < maxi; line++)
        {
            Arrays.fill(chars, ' ');
            loc = 0;
            // go through each string 
            for (int i = 0; i < len; i++)
            {
                // if i is 0 it means that its the first char and we need to follow the path
                if (i == 0)
                {
                    loc = loc + path[line%path.length];
                }
                // otherwise we just add 2 more spaces
                else
                    loc = loc + 2;
                // if str len is greater than line it means we still have chars to print 
                if(strings[i].length() > line)
                {
                    chars[loc] = strings[i].charAt(line);
                }
                // increase loc to account for the char added 
                loc++;
            }
            
            // print the line that was formed inside chars
            printChars(chars);
        }

    }

    public static void steamyMocha(String [] strings)
    {
        // check for empty or null
        if (strings == null || strings.length == 0)
        {
            System.out.println("Pshh!");
            return;
        }
        
        int len = strings.length;
        int[] path = {2, 2, 2, 3, 4, 5, 5, 5, 4, 3};
        char[] chars = new char[len * 3 + path[5]];
        Arrays.fill(chars, ' ');
        int loc = 0;

        int maxi = 0;

        for (int i = 0; i < len; i++)
        {
            maxi = Math.max(maxi, strings[i].length());
        }
        
        // go through first line
        for (int i = 0; i < len; i++)
        {
            // special case first is 3 spaces -not meandering path-
            if (i == 0)
            {
                loc = loc + 3;
            }
            // every char after has 2 spaces
            else
            {
                loc = loc + 2;
            }
            // add char after the spaces as long as it's even
            if(strings[i].length() > 0 && i % 2 == 0)
                chars[loc] = strings[i].charAt(0);
            loc++;
            
        }

        printChars(chars);

        // go through each line
        for (int line = 1; line < maxi + 1; line++)
        {
            // reset chars to all spaces for each line of output
            Arrays.fill(chars, ' ');

            //reset location to 0 for each line of output
            loc = 0;

            // go through each string 
            for (int i = 0; i < len; i++)
            {
                // first case follows meandering path
                if (i == 0)
                {
                    loc = loc + path[line%path.length];
                }
                // the rest of the chars just have 2 spaces
                else
                    loc = loc + 2;
                // if it's even then we print
                if (strings[i].length() > line && i % 2 == 0)
                {
                    chars[loc] = strings[i].charAt(line);
                }
                // if it's odd we print previous one 
                else if (strings[i].length() > line - 1 && i % 2 == 1)
                    chars[loc] = strings[i].charAt(line - 1);
                loc++;
            }
            printChars(chars);
        }
    }

    public static void cascadingWaterfall(String [] strings)
    {
        // check for empty or null
        if (strings == null || strings.length == 0)
        {
            System.out.println("Pshh!");
            return;
        }
        
        // length of strings array 
        int len = strings.length;

        // meandering path to follow
        int[] path = {2, 2, 2, 3, 4, 5, 5, 5, 4, 3};

        // array of chars for each line of output
        char[] chars = new char[len * 3 + path[5]];

        // fill it up with spaces
        Arrays.fill(chars, ' ');

        int loc = 0;

        // find the longest string and save its length in maxi 
        int maxi = 0;
        for (int i = 0; i < len; i++)
        {
            maxi = Math.max(maxi, strings[i].length());
        }
        
        // we already know that only one character will be printed so we do that 
        loc = loc + 3;
        if (strings[0].length() > 0)
            chars[loc] = strings[0].charAt(0);
        loc++;

        printChars(chars);

        // go through each line
        for (int line = 1; line < maxi + len; line++)
        {
            Arrays.fill(chars, ' ');
            loc = 0;
            // go through each string 
            for (int i = 0; i < len; i++)
            {
                if (i == 0)
                {
                    loc = loc + path[line % path.length];
                }
                else
                    loc = loc + 2;
                if (strings[i].length() > line - i && line - i >= 0)
                {
                    chars[loc] = strings[i].charAt(line - i);
                }
                loc++;
            }
            // this means there are definitely characters
            if (line <= maxi - len)
                printChars(chars);
            // otherwise check if line is empty
            else
                for (int j = 0; j < chars.length; j++)
                    if (chars[j] != ' ' && line > maxi - len)
                    {
                        printChars(chars);
                        break;
                    }
        }
    }

    // prints all the chars without extra spaces at the end 
    public static void printChars(char[] chars)
    {
        int last = -1;
        for (int i = 0; i < chars.length; i++)
        {
            if (chars[i] != ' ')
                last = i;
        }
        
        if (last != -1)
            for (int i = 0; i < last+1; i++)
            {
                System.out.print(chars[i]);
            }
        
        // make new line at the end
        System.out.println();
    }

    // returns how difficult the assignment was from 1.0 to 5.0
    public static double difficultyRating()
    {
        return 2.0;
    }
    
    // returns how many hours were spent on the assignment 
    public static double hoursSpent()
    {
        return 5.0;
    }
}




