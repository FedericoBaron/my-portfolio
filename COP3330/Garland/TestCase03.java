// Sean Szumlanski
// COP 3330, Fall 2019

// ========================
// Garland: TestCase03.java
// ========================
// A small test of the stringToLinkedList() method.


public class TestCase03
{
	public static void main(String [] args)
	{
		Node head = Garland.stringToLinkedList("");
		System.out.println(head == null ? "Hooray!" : "oh no :(");
	}
}
