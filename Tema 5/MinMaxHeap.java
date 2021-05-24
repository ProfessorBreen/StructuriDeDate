import java.util.ArrayList;
import java.util.List;

public class MinMaxHeap<E extends Comparable<E>> {
  private static final int MAX_SIZE = 1024;
  private final E[] heap;
  private int size;

  public MinMaxHeap() {
    size = 0;
    heap = (E[]) new Comparable[MAX_SIZE];
  }

  public E getMin() {
    if (size == 0) {
      throw new UnsupportedOperationException();
    }

    return heap[0];
  }

  public E getMax() {
    if (size == 0) {
      throw new UnsupportedOperationException();
    }

    if (size == 1) {
      return heap[1];
    }
    if (size == 2) {
      return heap[2];
    }

    if (heap[2].compareTo(heap[3]) > 0) {
      return heap[2];
    }
    return heap[3];
  }

  public void insert(E element) {
    if (size == 0) {
      heap[1] = element;
      size++;
    } else {
      size++;
      heap[size] = element;
      pushUp(size);
    }
  }

  public void deleteMin() {
    if (size == 0) {
      throw new UnsupportedOperationException();
    }

    if (size == 1) {
      size--;
      return;
    }
    heap[1] = heap[size];
    size--;
    pushDown(1);
  }

  public void deleteMax() {
    if (size == 0) {
      throw new UnsupportedOperationException();
    }

    if (size == 1) {
      size--;
      return;
    }
    heap[1] = heap[size];
    size--;
    pushDown(getMaxPosition());
  }

  private void pushDown(int node) {
    if (2 * node > size) {
      return;
    }

    if (log2(node) % 2 == 1) {
      pushDownMin(node);
    } else {
      pushDownMax(node);
    }
  }

  private void pushUp(int node) {
    if (node != 1) {
      if (log2(node) % 2 == 1) {
        if (heap[node].compareTo(heap[node / 2]) > 0) {
          swapNodes(node, node / 2);
          pushUpMax(node / 2);
        } else {
          pushUpMin(node);
        }
      } else {
        if (heap[node].compareTo(heap[node / 2]) < 0) {
          swapNodes(node, node / 2);
          pushUpMin(node / 2);
        } else {
          pushUpMax(node);
        }
      }
    }
  }

  private int log2(int nr) {
    return (int) (Math.log(nr) / Math.log(2));
  }

  private void pushDownMin(int node) {
    if (2 * node <= size) {
      int smallestChild = getSmallestChild(node), smallestGrandchild = getSmallestGrandchild(node);
      if (smallestChild == smallestGrandchild) {
        if (heap[smallestChild].compareTo(heap[node]) < 0) {
          swapNodes(smallestChild, node);
        }
      } else {
        if (heap[smallestGrandchild].compareTo(heap[node]) < 0) {
          swapNodes(smallestGrandchild, node);
          if (heap[smallestGrandchild].compareTo(heap[smallestGrandchild / 2]) > 0) {
            swapNodes(smallestGrandchild, smallestGrandchild / 2);
          }
          pushDownMin(smallestGrandchild);
        }
      }
    }
  }

  private void pushDownMax(int node) {
    if (2 * node <= size) {
      int greatestChild = getGreatestChild(node), greatestGrandchild = getGreatestGrandchild(node);
      if (greatestChild == greatestGrandchild) {
        if (heap[greatestChild].compareTo(heap[node]) > 0) {
          swapNodes(greatestChild, node);
        }
      } else {
        if (heap[greatestGrandchild].compareTo(heap[node]) > 0) {
          swapNodes(greatestGrandchild, node);
          if (heap[greatestGrandchild].compareTo(heap[greatestGrandchild / 2]) < 0) {
            swapNodes(greatestGrandchild, greatestGrandchild / 2);
          }
          pushDownMax(greatestGrandchild);
        }
      }
    }
  }

  private void pushUpMin(int node) {
    if (node / 2 <= 1) {
      return;
    }
    if (heap[node].compareTo(heap[node / 4]) < 0) {
      swapNodes(node, node / 4);
      pushUpMin(node / 4);
    }
  }

  private void pushUpMax(int node) {
    if (node / 2 <= 1) {
      return;
    }
    if (heap[node].compareTo(heap[node / 4]) > 0) {
      swapNodes(node, node / 4);
      pushUpMax(node / 4);
    }
  }

  private int getMaxPosition() {
    if (size == 0) {
      throw new UnsupportedOperationException();
    }

    if (size == 1) {
      return 1;
    }
    if (size == 2) {
      return 2;
    }

    if (heap[2].compareTo(heap[3]) > 0) {
      return 2;
    }
    return 3;
  }

  private int getSmallestChild(int node) {
    int smallestChild = 2 * node;
    if (2 * node + 1 <= size) {
      if (heap[2 * node].compareTo(heap[2 * node + 1]) > 0) {
        smallestChild = 2 * node + 1;
      }
    }
    return smallestChild;
  }

  private int getSmallestGrandchild(int node) {
    int smallestGrandchild = getSmallestChild(node);
    if (2 * (2 * node) <= size) {
      if (heap[2 * (2 * node)].compareTo(heap[smallestGrandchild]) < 0) {
        smallestGrandchild = 2 * (2 * node);
      }
    }

    if (2 * (2 * node + 1) <= size) {
      if (heap[2 * (2 * node + 1)].compareTo(heap[smallestGrandchild]) < 0) {
        smallestGrandchild = 2 * (2 * node + 1);
      }
    }

    if (2 * (2 * node) + 1 <= size) {
      if (heap[2 * (2 * node) + 1].compareTo(heap[smallestGrandchild]) < 0) {
        smallestGrandchild = 2 * (2 * node) + 1;
      }
    }

    if (2 * (2 * node + 1) + 1 <= size) {
      if (heap[2 * (2 * node + 1) + 1].compareTo(heap[smallestGrandchild]) < 0) {
        smallestGrandchild = 2 * (2 * node + 1) + 1;
      }
    }

    return smallestGrandchild;
  }

  private int getGreatestChild(int node) {
    int greatestChild = 2 * node;
    if (2 * node + 1 <= size) {
      if (heap[2 * node].compareTo(heap[2 * node + 1]) > 0) {
        greatestChild = 2 * node + 1;
      }
    }
    return greatestChild;
  }

  private int getGreatestGrandchild(int node) {
    int greatestGrandchild = getGreatestChild(node);
    if (2 * (2 * node) <= size) {
      if (heap[2 * (2 * node)].compareTo(heap[greatestGrandchild]) > 0) {
        greatestGrandchild = 2 * (2 * node);
      }
    }

    if (2 * (2 * node + 1) <= size) {
      if (heap[2 * (2 * node + 1)].compareTo(heap[greatestGrandchild]) > 0) {
        greatestGrandchild = 2 * (2 * node + 1);
      }
    }

    if (2 * (2 * node) + 1 <= size) {
      if (heap[2 * (2 * node) + 1].compareTo(heap[greatestGrandchild]) > 0) {
        greatestGrandchild = 2 * (2 * node) + 1;
      }
    }

    if (2 * (2 * node + 1) + 1 <= size) {
      if (heap[2 * (2 * node + 1) + 1].compareTo(heap[greatestGrandchild]) > 0) {
        greatestGrandchild = 2 * (2 * node + 1) + 1;
      }
    }

    return greatestGrandchild;
  }

  private void swapNodes(int position1, int position2) {
    E temp = heap[position1];
    heap[position1] = heap[position2];
    heap[position2] = temp;
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= size / 2; i++) {
      sb.append("Node: ")
          .append(heap[i])
          .append(", Left child: ")
          .append(heap[2 * i])
          .append(", Right child: ")
          .append(heap[2 * i + 1])
          .append("\n");
    }
    return sb.toString();
  }

  public static void main(String[] args) {
    MinMaxHeap<Integer> myHeap = new MinMaxHeap<>();
    List<Integer> elementsToAdd =
        new ArrayList<>(List.of(8, 71, 41, 31, 10, 11, 16, 46, 51, 31, 21, 13));

    for (int elem : elementsToAdd) {
      myHeap.insert(elem);
    }

    System.out.println(myHeap);
  }
}
