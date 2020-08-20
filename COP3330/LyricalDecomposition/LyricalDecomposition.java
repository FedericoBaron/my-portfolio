// Federico Baron 
// COP3330 Fall 2019
// NID: fe960661

public class LyricalDecomposition{

    // calls all methods in order to print all the lyrics
    public static void printLyrics()
    {
        verse1();
        System.out.println();
        verse2();
        System.out.println();
        verse3();
        System.out.println();
        verse4();
        System.out.println();
        verse5();
        System.out.println();
        verse6();
    }

    public static void verse1()
    {
        // prints what is unique to the verse 1
        System.out.println("There was an old woman who swallowed a fly.");
        
        // calls a method that prints what is repeated from verse 1 in other verses
        verse1Repeated();
    }
    
    public static void verse1Repeated()
    {
        System.out.println("I don't know why she swallowed that fly;");
        System.out.println("Perhaps she'll die.");
    }

    public static void verse2()
    {  
        // prints what is unique to the verse 2
        System.out.println("There was an old woman who swallowed a spider,");
        System.out.println("That wriggled and iggled and jiggled inside her!");

        // calls a method that prints what is repeated from verse 2 in other verses
        verse2Repeated();
    }

    public static void verse2Repeated()
    {
        System.out.println("She swallowed the spider to catch the fly.");

        // calls verse1Repeated() to repeat what gets repeated from verse 1
        verse1Repeated();
    }

    public static void verse3()
    {
        // prints what is unique to verse 3
        System.out.println("There was an old woman who swallowed a bird.");
        System.out.println("How absurd, to swallow a bird!");

        // calls a method that prints what is repeated from verse 3 in other verses
        verse3Repeated();
    }

    public static void verse3Repeated()
    {
        System.out.println("She swallowed the bird to catch the spider;");

        // calls verse2Repeated() to repeat what gets repeated from verse 2
        verse2Repeated();
    }

    public static void verse4()
    {
        // prints what is unique to verse 4
        System.out.println("There was an old woman who swallowed a cat.");
        System.out.println("Imagine that, to swallow a cat!");

        // calls a method that prints what is repeated from verse 4 in other verses
        verse4Repeated();
        
    }

    public static void verse4Repeated()
    {
        System.out.println("She swallowed the cat to catch the bird;");

        // calls verse3Repeated() to repeat what gets repeated from verse 3
        verse3Repeated();
    }

    public static void verse5()
    {
        // prints what is unique to verse 5
        System.out.println("There was an old woman who swallowed a dog.");
        System.out.println("What a hog, to swallow a dog!");

        // calls a method that prints what is repeated from verse 5 in other verses
        verse5Repeated();
    }

    public static void verse5Repeated()
    {
        System.out.println("She swallowed the dog to catch the cat;");

        // calls verse4Repeated() to repeated what gets repeated from verse 4
        verse4Repeated();
    }

    public static void verse6()
    {
        // prints the last verse which is just these two lines
        System.out.println("There was an old woman who swallowed a horse.");
        System.out.println("She died, of course!");
    }

    // returns how difficult the assignment was from 1.0 to 5.0
    public static double difficultyRating()
    {
        return 1.0;
    }

    // returns how many hours were spent on the assignment 
    public static double hoursSpent()
    {
        return 1.0;
    }

}