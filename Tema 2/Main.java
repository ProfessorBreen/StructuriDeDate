import java.io.*;
import java.util.Scanner;

public class Main {
  private static class Pair {
    int first;
    int second;

    public Pair(int first, int second) {
      this.first = first;
      this.second = second;
    }
  }

  private static class Node {
    Pair val;
    Node prev;
    Node next;

    public Node(int val1, int val2) {
      this.val = new Pair(val1, val2);
      prev = next = null;
    }
  }

  private static class Deque {
    private Node front;
    private Node back;
    private int size;

    public Deque() {
      front = back = null;
      size = 0;
    }

    public boolean isEmpty() {
      return size == 0;
    }

    public void pushFront(int val1, int val2) {
      size++;
      Node node = new Node(val1, val2);
      if (front == null) {
        front = back = node;
      } else {
        node.next = front;
        front.prev = node;
        front = node;
      }
    }

    public void pushBack(int val, int val2) {
      size++;
      Node node = new Node(val, val2);
      if (back == null) {
        front = back = node;
      } else {
        node.prev = back;
        back.next = node;
        back = node;
      }
    }

    public void popFront() {
      size--;
      Node temp = front;
      front = front.next;
      if (front == null) {
        back = null;
      } else {
        front.prev = null;
      }
    }

    public void popBack() {
      size--;
      Node temp = back;
      back = back.prev;
      if (back == null) {
        front = null;
      } else {
        back.next = null;
      }
    }

    public Pair getFront() {
      return front.val;
    }

    public Pair getBack() {
      return back.val;
    }
  }

  public static void main(String[] args) throws IOException {
    File inputFile = new File("deque.in");
    File outputFile = new File("deque.out");
    FileInputStream inputStream = new FileInputStream(inputFile);
    FileOutputStream outputStream = new FileOutputStream(outputFile);

    int[] v = new int[5000005];
    Scanner scanner = new Scanner(inputStream);
    PrintWriter writer = new PrintWriter(outputStream);
    int n = scanner.nextInt(), m = scanner.nextInt();
    long s = 0;
    for (int i = 1; i <= n; i++) {
      int x = scanner.nextInt();
      v[i] = x;
    }
    Deque q = new Deque();
    for (int i = 1; i <= n; i++) {
      while (!q.isEmpty() && q.getFront().first >= v[i]) {
        q.popFront();
      }
      q.pushFront(v[i], i);
      if (i >= m) {
        if (i - q.getBack().second + 1 > m) {
          q.popBack();
        }
        s += q.getBack().first;
      }
    }
    writer.println(s);
    writer.close();
    outputStream.close();
  }
}
