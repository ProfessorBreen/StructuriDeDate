#include <fstream>

using namespace std;

struct node
{
    pair<int, int> val;
    node *prev{}, *next{};

    static node *createNode(pair<int, int> val)
    {
        node *newNode = new node;
        newNode->prev = newNode->next = nullptr;
        newNode->val = val;
        return newNode;
    }
};

class deq
{
    node *front;
    node *back;
    int sz;
public:
    deq()
    {
        front = back = nullptr;
        sz = 0;
    }

    bool isEmpty() const
    {
        return sz == 0;
    }

    void pushFront(pair<int, int> val)
    {
        node *newNode = node::createNode(val);
        if (front == nullptr)
            back = front = newNode;
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        sz++;
    }

    void pushBack(pair<int, int> val)
    {
        node *newNode = node::createNode(val);
        if (back == nullptr)
            front = back = newNode;
        else
        {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        sz++;
    }

    void popFront()
    {
        node *temp = front;
        front = front->next;
        if (front == nullptr)
            back = nullptr;
        else
            front->prev = nullptr;
        sz--;
    }

    void popBack()
    {
        node *temp = back;
        back = back->prev;
        if (back == nullptr)
            front = nullptr;
        else
            back->next = nullptr;
        sz--;
    }

    pair<int, int> getFront()
    {
        return front->val;
    }

    pair<int, int> getBack()
    {
        return back->val;
    }
};

int v[5000005];

int main()
{
    ifstream in("deque.in");
    ofstream out("deque.out");
    int n, k, i;
    long long s = 0;
    in >> n >> k;
    for (i = 1; i <= n; i++)
        in >> v[i];
    deq q;
    for (i = 1; i <= n; i++)
    {
        while (!q.isEmpty() && q.getBack().first >= v[i])
            q.popBack();
        q.pushBack(make_pair(v[i], i));
        if (i >= k)
        {
            if (i - q.getFront().second + 1 > k)
                q.popFront();
            s = s + q.getFront().first;
        }
    }
    out << s;
    return 0;
}
