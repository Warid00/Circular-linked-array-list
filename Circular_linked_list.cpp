using namespace std;
#include <vector>
#include <iostream>
#include <stdexcept>

struct Node{
    int value; Node *next; Node *prev;
    
    Node(int n){
        value = n; next = nullptr; prev = nullptr;
    }
};

class CircLinkedList{
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
        CircLinkedList(){
            head = nullptr; tail = nullptr; size = 0;
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

        int &operator[](int index){
            return get_node(index) -> value;
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

        CircLinkedList(int n){
            head = nullptr;
            tail = nullptr;
            for (int k = 1; k <= n; k++){
                append(k);
            }
        }

        vector<int> josephus_sequence(int k){
            vector<int> jos;
            Node* x = head;
            Node* y = tail;
            while (x -> next != x){
                for (int k = 1; k < 1; k++){
                    y = x;
                    x = x -> next;
                }
                jos.push_back(x -> value);
                y -> next = x -> next;
                delete x;
                x = y -> next;
                size -= 1;
            }
            jos.push_back(x -> value);
            delete x;
            return jos;    
        }
};

int last_man_standing(int n, int k){
    CircLinkedList z(n);
    vector<int> jos = z.josephus_sequence(k);
    return jos[n-1];
}

int main(){
    CircLinkedList clist;
    clist.append(0);
    clist.append(2);
    clist.append(4);
    clist.print();
    cout << last_man_standing(67, 7) << endl;
    return 0;
}
