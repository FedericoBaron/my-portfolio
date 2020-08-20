public class Bonfire
{
    public static int getThirdLargest(int[] array)
    {

        // check if the array has less than 3 integers and if so we can't find the third largest
        if (array.length < 3)
        {   
            return Integer.MIN_VALUE;
        }

        // initialize 2 integers that hold the location of 2 largest numbers in the array
        int loc = -1;
        int loc2 = -1;
        int loc3 = -1;
        
        // initialize largest to be the lowest integer in Java
        int largest = Integer.MIN_VALUE;

        // go through array and find largest
        for (int i = 0; i < array.length; i++)
        {
            // if position i of array is larger than largest then it's the new largest 
            if (array[i] > largest)
            {
                largest = array[i];
                loc = i;
            }
        }

        largest = Integer.MIN_VALUE;

        // go through array and find 2nd largest
        for (int i = 0; i < array.length; i++)
        {
            // if position i of array is larger than largest and was not previously found then it's the new largest
            if (array[i] > largest && i != loc)
            {
                largest = array[i];
                loc2 = i;
            }
        }

        largest = Integer.MIN_VALUE;

        // go through array and find 3rd largest
        for (int i = 0; i < array.length; i++)
        {

            // if position i of array is larger than largest and was not previously found then it's the new largest
            if (array[i] > largest && i != loc && i != loc2)
            {
                largest = array[i];
                loc3 = i;
            }
        }

        // return the 3rd largest element
        return array[loc3];
    }

    public static void printThirdLargest(int[] array)
    {
        System.out.println(getThirdLargest(array));
    }

    public static boolean isRotation(int[] array1, int[] array2)
    {

        // checks if they're the same length, if they're not then it is not a rotation
        if (array1.length != array2.length)
        {
            return false;
        }

        // nested for loop to find locations where array1 and array2 are equal
        for (int i = 0; i < array1.length; i++)
        {
            for (int j = 0; j < array1.length; j++)
            {

                // finds when they're equal
                if (array1[i] == array2[j])
                {

                    // initialize boolean which checks if they're all equal
                    boolean isEqual = true;

                    // goes through the length of the array to see if all values are equal with the rotation
                    for (int k = 0; k < array1.length; k++)
                    {
                        if (array1[(i+k)%array2.length] != array2[(j+k)%array1.length])
                            isEqual = false;
                    }

                    // if isEqual is true then it is a rotation
                    if (isEqual == true)
                        return true;
                }
            }
        }

        return true;
        
    }
    
    public static int[] generateNthRotation(int[] array, int n)
    {
        // if the array is empty there's not much we can do 
        if (array.length == 0)
            return array;

        // if n is negative we need to turn it into a number we can process
        if (n < 0)
            n = array.length + n;
        
        // creates new array to hold the rotated array 
        int[] rotatedArray = new int[array.length];

        // puts every element in its rotated location
        for (int i = 0; i < array.length; i++)
        {
            rotatedArray[(i + n) % array.length] = array[i];
        }

        // returns the new array that contains rotated elements
        return rotatedArray;
    }

    public static void printRibbon(int n, int width)
    {
        // char containing what char has to be printed in this case
        char symChar = '@';
        
        // prints upper boundary
        doBox(width);

        // goes through width to add '@' or 'o' as well as '|' and " "
        for(int j = 0; j < width; j++)
        {   
            // prints left boundary
            System.out.print("|");
            symChar = '@';

            // prints spaces that are needed at the beginning 
            for(int i = 0; i < j; i++)
            {
                System.out.print(" ");
            }

            for(int k = 1; k < width - j + 1; k++)
            {
                // prints the character
                System.out.print(symChar);
                
                // determines whether the character should remain the same or not
                if(k % n == 0)
                {
                     if(symChar == '@')
                         symChar = 'o';
                     else
                        symChar = '@';
                }
                
                // prints spaces that are needed at the end
                while(k >= n * 3 && k < width - j)
                {
                    System.out.print(" ");
                    k++;
                }
            }
            
            // prints right boundary
            System.out.println("|");
        }

        // prints lower boundary
        doBox(width);
    }

    // it prints the upper and lower boundary of the ribbon walls
    public static void doBox(int width)
    {
        System.out.print("+");

        for (int i = 0; i < width; i++)
        {
            System.out.print("-");
        }

        System.out.print("+");

        System.out.println();
    }

    // returns how difficult the assignment was from 1.0 to 5.0
    public static double difficultyRating()
    {
        return 1.3;
    }

    // returns how many hours were spent on the assignment 
    public static double hoursSpent()
    {
        return 2.5;
    }
}