import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Main {
    public static void main(String[] args) {
        ResizingArrayQueueOfStrings stack = new ResizingArrayQueueOfStrings();
        while(!StdIn.isEmpty()){
            String s = StdIn.readString();
            if(s.equals("-")) StdOut.print(stack.dequeue());
            else stack.enqueue(s);
        }
    }
}
