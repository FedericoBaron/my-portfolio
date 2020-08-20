// Federico Baron 
// COP3330 Fall 2019
// NID: fe960661

public class Garland
{
    // Reference to the top-left node in this garland.
    private Node head;  
    // Reference to the top-right node in this garland
    private Node tail;
    // The number of strings currently in this garland.
    private int size;
    
    
    public static Node stringToLinkedList(String s)
    {
        // checks if the string is null to return null if so
        if (s == null)
            return null;
        
        // if length is 0 also return null
        int len = s.length();
        if (len == 0)
        {
                return null;
        }

        // otherwise go through with turning the string into a linked list

        // create new linked list
        Node headNode = new Node(s.charAt(0));

        // start with count being 1 since we already are putting the charAt(0)
        int count = 1;

        // dummy node to go through the list
        Node garlyGarl = headNode;

        // go through the whole string and put it into linked list
        while (count < len)
        {
                garlyGarl.down = new Node(s.charAt(count));
                garlyGarl = garlyGarl.down;
                count++;
        }

        // return the head;
        return headNode;
    }

    // turns a linked list into a String 
    public static String linkedListToString(Node head)
    {
        // gets the length of the list
        int len = getListLength(head);

        // makes char array the size of the length of the list
        char[] garlyString = new char[len];

        // start count at 0 to go through every item
        int count = 0;

        // go through until char[] is full
        while (count < len)
        {
            garlyString[count] = head.data;
            head = head.down;
            count++;
        }

        // returns the char[] as a string 
        return String.valueOf(garlyString);
    }

    // parameterless constructor
    Garland()
    {

    }

    // constructor with parameters
    Garland(String [] strings)
    {
        int len = strings.length;
        for (int i = 0; i < len; i++)
        {
            addString(strings[i]);
        }
    }

    // get head
    public Node head()
    {
        return head;
    }

    // get size
    public int size()
    {
        return size;
    }

    // adds string that is passed to the garland
    public void addString(String s)
    {
        if (s == null || s.length() == 0)
        {
            return;
        }
        size++;

        if (tail == null)
        {
            tail = stringToLinkedList(s);
            head = tail;
            return;
        }

        tail.next = stringToLinkedList(s);
        tail = tail.next;
        

    }

    // gets the node at the passed index
    public Node getNode(int index)
    {
            if (!validIndex(index))
            {
                return null;
            }
            int count = 0;
            Node dummy = head;
            while (count != index)
            {
                dummy = dummy.next;
                count++;
            }
            return dummy;
    }

    // gets the string at the passed index
    public String getString(int index)
    {
        Node dummy = getNode(index);
        int count = 0;

        // use a char array to make it faster 
        char[] arr = new char[getListLength(dummy)];

        // as long as it's not null keep increasing count, addings chars, and going down the garland
        while (dummy != null)
        {
            arr[count] = dummy.data;
            count++;
            dummy = dummy.down;
        }
        return String.valueOf(arr);
    }

    // removed the string at the passed index
    public boolean removeString(int index)
    {
        // check if index is valid
        if (!validIndex(index))
        {
            return false;
        }

        // check if index is 0
        if (index == 0)
        {
            head = head.next;
            size--;
            return true;
        }

        // otherwise do a standard removal
        Node dummy = head;
        for (int i = 0; i < index-1; i++)
        {
                dummy = dummy.next;
        }

        // find the one at the index and skip it by changing where the previous one's next points to
        dummy.next = dummy.next.next;
        size--;
        return true;
    }

    // prints the string at the given index
    public boolean printString(int index)
    {   
        // check if index is valid
        if (!validIndex(index))
        {
            System.out.println("(invalid index)");               
            return false;
        }
        
        // go through each garland until the index'th one is found 
        Node dummy = head;
        for (int i = 0; i < index; i++)
        {
            dummy = dummy.next;
        }
        printString(dummy);
        return true;
    }

    // prints every string
    public void printStrings()
    {
        // if the size is 0 then there are no strings
        if (size == 0)
        {
            System.out.println("(empty list)");
            return;
        }

        // otherwise while the index is valid keep printing all the strings sequentially
        int index = 0;
        while (validIndex(index))
        {
            printString(index);
            index++;
        }

    }

    // gets the length of a garland
    private static int getListLength(Node head)
    {

        // counts the length by going until head is null
        int count = 0;
        while (head != null)
        {
            count++;
            head = head.down;
        }

        // returns how many times head wasn't null which is the length
        return count;
    }

    // gets whether the index is valid for the garland
    private boolean validIndex(int index)
    {
            if (index >= size || index < 0)
                return false;
            return true;
    }

    private void printString(Node head)
    {
        // if the head is null you have to print it
        if (head == null)
        {
            System.out.println("(null)");
            return;
        }

        // otherwise keep printing each character until head is null
        while (head != null)
        {
            System.out.print(head.data);
            head = head.down;
        }
        System.out.println();   
    }

    public static double difficultyRating()
    {
        return 2.0;
    }

    public static double hoursSpent()
    {
        return 2.5;
    }

}
