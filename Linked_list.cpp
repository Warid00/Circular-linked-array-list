using namespace std;
#include <iostream>
#include <stdexcept>
#include <vector>

struct Node{
    int value; Node *next; Node *prev;
    
    Node(int n){
        value = n; next = nullptr; prev = nullptr;
    }
};

class LinkedList{
    private:
        Node *head; Node *tail; int size;

        Node *get_node(int index){
        //helping takes index and returns a pointer to node
            int current_index = 0;
            Node *current = head;
            while (current != nullptr){
                if (current_index == index){
                    return current;
                }
                current = current -> next;
                current_index += 1;
            }
            throw out_of_range("IndexError: out of range");
        }

    public:
        LinkedList(){
            head = nullptr; tail = nullptr; size = 0;
        }

        int length(){
            return size;
        }

        void append(int value){
        // add integer to end of the list
            Node *new_node = new Node(value);
            if (head == nullptr){
                head = new_node;
                tail = head;
                size += 1;
                return;
            }
            else{
                tail -> next = new_node;
                new_node -> prev = tail;
                tail = new_node;
                size += 1;
            }
        }

        ~LinkedList(){
            Node *current = head;
            Node *next = head;
            while (current != nullptr){
                next = current -> next;
                delete current;
                current = next;
            }
        }

        void print(){
        //print out content in a list []
            cout << "[";
            Node *current = head;
            while(current -> next != nullptr){
                cout << current -> value << " ";
                current = current -> next;
            }
            cout << current -> value << "]" << endl;
        }

        int &operator[](int index){
            return get_node(index) -> value;
        }

        int pop(int index){
        //removing and returns the removed element
            Node* current =head;
            for (int k = 0; k < index; k++){
                current = current -> next;
            }
            return current -> value;
        }

        int pop(){
        //pop out the last element in list and return it
            return pop(size -1);
        }

        LinkedList(vector<int> vec){
            for (int k:vec){
                append(k);
            }
        }

        void insert(int val, int index){
        //insert a value in desired place
            Node* current = head;
            for (int k = 0; k < index; k++){
                current = current -> next;
            }
            Node* s = new Node(val);
            Node* x = current;
            Node* y = current -> prev;
            x -> prev = s;
            y -> next = s;
            s -> prev = y;
            s -> next = x;
            size += 1;
        }

        void remove(int index){
        //removes desired index
            Node* current = get_node(index);
            Node* tmp = get_node(index - 1);
            tmp -> next = current -> next;
            size -= 1;
        }
};

int main(){
    LinkedList a({1, 2, 3, 4});
    //example List
    a.print();
    //testing append
    a.append(5);
    a.print();
    //testing remove
    a.remove(1);
    a.print();
    //testing insert
    a.insert(1, 3);
    a.print();
    
    cout << "length = " << a.length() << endl;
    cout << "pop = " << a.pop() << endl;

    return 0;
}
