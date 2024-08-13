#include <bits/stdc++.h>
using namespace std;

template <class T>
class MinHeap
{
    /*
    Min Heap properties
    1. Complete binary tree (CBT)
    2. Heap order property, i.e., for every node n
        - n < left child
        - n < right child
    */
public:
    vector<T> min_heap_vector;
    int min_heap_size;

    MinHeap()
    {
        this->min_heap_size = 0;
    }

    void insert(T data)
    {
        // Push in min heap vector
        this->min_heap_vector.push_back(data);
        this->min_heap_size++;

        // Restructure min heap
        int curr_idx = this->min_heap_size - 1;
        int parent_idx = (curr_idx - 1)/2;
        while (
            (this->min_heap_vector[curr_idx] < this->min_heap_vector[parent_idx])
            &&
            (curr_idx > 0)
        )
        {
            swap(
                this->min_heap_vector[curr_idx],
                this->min_heap_vector[parent_idx]
            );
            curr_idx = parent_idx;
            parent_idx = (curr_idx - 1)/2;
        }
    }

    T pop_min()
    {
        if (this->min_heap_size > 0)
        {
            T min_element = this->min_heap_vector[0];
            // Swap first and last element
            int last_idx = this->min_heap_size - 1;
            swap(
                this->min_heap_vector[0],
                this->min_heap_vector[last_idx]
            );

            // Remove last element
            this->min_heap_vector.pop_back();
            this->min_heap_size--;

            // Restructure min heap
            int root_idx = 0;
            int left_child_idx = 2*root_idx + 1;
            int right_child_idx = 2*root_idx + 2;

            while (true)
            {
                int next_min_idx = 0;
                // If both left and right child exist
                if (left_child_idx<this->min_heap_size && right_child_idx<this->min_heap_size)
                {
                    if (
                        this->min_heap_vector[left_child_idx] < this->min_heap_vector[root_idx]
                        &&
                        this->min_heap_vector[right_child_idx] < this->min_heap_vector[root_idx]
                    )
                    {
                        if (
                            this->min_heap_vector[left_child_idx] <= this->min_heap_vector[right_child_idx]
                        )
                        {
                            next_min_idx = left_child_idx;
                        }
                        else
                        {
                            next_min_idx = right_child_idx;
                        }
                    }
                    else if (
                        this->min_heap_vector[left_child_idx] < this->min_heap_vector[root_idx]
                    )
                    {
                        next_min_idx = left_child_idx;
                    }
                    else
                    {
                        next_min_idx = right_child_idx;
                    }
                }
                // If only left child exists
                else if (left_child_idx<this->min_heap_size)
                {
                    next_min_idx = left_child_idx;
                }
                // If only right child exists
                else if (right_child_idx<this->min_heap_size)
                {
                    next_min_idx = right_child_idx;
                }
                else
                {
                    break;
                }

                if (
                    this->min_heap_vector[root_idx] > this->min_heap_vector[next_min_idx]
                )
                {
                    swap(
                        this->min_heap_vector[root_idx],
                        this->min_heap_vector[next_min_idx]
                    );
                    root_idx = next_min_idx;
                    left_child_idx = 2*root_idx + 1;
                    right_child_idx = 2*root_idx + 2;
                }
                else
                {
                    break;
                }
            }
            return min_element;
        }
        return 0;
    }

    T get_min()
    {
        if (this->min_heap_size > 0)
        {
            return this->min_heap_vector[0];
        }
        return 0;
    }

    void display_heap()
    {
        for (int i=0; i<this->min_heap_size; i++)
        {
            cout << this->min_heap_vector[i] << " ";
        }
        cout << endl;
    }
};


template <class T>
class PriorityQ
{
public:
    MinHeap<T> min_heap;

    void push(T data)
    {
        this->min_heap.insert(data);
    }
    T pop()
    {
        return this->min_heap.pop_min();
    }
    T front()
    {
        return this->min_heap.get_min();
    }
    int size()
    {
        return this->min_heap.min_heap_size;
    }
    void display_storage()
    {
        this->min_heap.display_heap();
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    PriorityQ<int> pq1;
    pq1.push(12);
    pq1.push(6);
    pq1.push(5);
    pq1.push(100);
    pq1.push(1);
    pq1.push(9);
    pq1.push(0);
    pq1.push(14);

    cout << "pq size = " << pq1.size() << endl;
    pq1.display_storage();

    int x;
    x = pq1.pop();
    cout << "Popped " << x << ", pq size = " << pq1.size() << endl;
    pq1.display_storage();
    x = pq1.pop();
    cout << "Popped " << x << ", pq size = " << pq1.size() << endl;
    pq1.display_storage();

    int y = pq1.front();
    cout << "Front " << y << ", pq size = " << pq1.size() << endl;
    pq1.display_storage();

    cout << "\n\n------------------\n\n";

    PriorityQ<int> pq2;
    pq2.push(100);
    pq2.push(10);
    pq2.push(15);
    pq2.push(4);
    pq2.push(17);
    pq2.push(21);
    pq2.push(67);

    cout << pq2.size() << endl;
    cout << pq2.front() << endl;

    while (pq2.size()>0)
    {
        pq2.display_storage();
        cout << "Size =   " << pq2.size() << endl;
        cout << "Min  =   " << pq2.front() << endl;

        int k = pq2.pop();
        cout << "Popped = " << k << endl;
        cout << "\n";
    }

    return 0;
}