import java.util.ArrayList;
import java.util.List;

public class MaxHeap<E extends Comparable<E>> {
  private static final int MAX_SIZE = 1024;
  private final E[] heap;
  private int size;

  public MaxHeap() {
    size = 0;
    heap = (E[]) new Comparable[MAX_SIZE];
  }

  public E getMax() {
    if (size > 0) {
      E result = heap[0];
      heap[0] = heap[size - 1];
      size--;
      fixHeap(0);
      return result;
    }
    return null;
  }

  public E peek() {
    if (size > 0) {
      return heap[0];
    }
    return null;
  }

  public void add(E element) {
    heap[size] = element;
    int currentNode = size;
    int parent = (currentNode - 1) / 2;
    while (parent >= 0 && heap[currentNode].compareTo(heap[parent]) > 0) {
      swapNodes(currentNode, parent);

      currentNode = parent;
      parent = (currentNode - 1) / 2;
    }

    size++;
  }

  public int getSize() {
    return size;
  }

  private void swapNodes(int position1, int position2) {
    E temp = heap[position1];
    heap[position1] = heap[position2];
    heap[position2] = temp;
  }

  private void fixHeap(int root) {
    if (root < size / 2) {
      int child1 = 2 * root + 1;
      int child2 = child1 + 1;

      int cmp1 = heap[root].compareTo(heap[child1]);
      int cmp2 = heap[root].compareTo(heap[child2]);
      int cmp3 = heap[child1].compareTo(heap[child2]);

      if (cmp1 < 0 || cmp2 < 0) {
        if (cmp3 > 0) {
          swapNodes(root, child1);
          fixHeap(child1);
        } else {
          swapNodes(root, child2);
          fixHeap(child2);
        }
      }
    }
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < size / 2; i++) {
      sb.append("Node: ")
          .append(heap[i])
          .append(", Left child: ")
          .append(heap[2 * i + 1])
          .append(", Right child: ")
          .append(heap[2 * i + 2])
          .append("\n");
    }
    return sb.toString();
  }

  public static void main(String[] args) {
    MaxHeap<String> myHeap = new MaxHeap<>();
    List<String> elementsToAdd = new ArrayList<>(List.of("bca", "abc", "dzz", "dzx", "rig", "oof", "bdd", "fgh", "cde"));

    for (String elem : elementsToAdd) {
      myHeap.add(elem);
    }

    System.out.println(myHeap);
  }
}
