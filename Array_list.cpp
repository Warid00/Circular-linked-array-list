using namespace std;
#include <iostream>
#include <vector>
#include <stdexcept>

class ArrayList{
    private:
        int *data; int capacity;

        void resize() {
        //resising a new array and deleting old array
            capacity *= 2;
            int *tmp = new int[capacity];
            for (int k = 0; k < size; k++){
                tmp[k] = data[k];
            }
            delete[] data;
            data = tmp;
        }

    public:
        int size;
        
        int length(){
            return size;
        }

        ArrayList(){
            size = 0; capacity = 1;
            data = new int[capacity];
        }
        ArrayList(vector<int> vec){
            size = 0; capacity = 1;
            data = new int[capacity];
            for (int i:vec){
                append(i);
            }
        }

        ~ArrayList() {
            delete[] data;
        }

        void append(int n) {
        // add integer to end of the list
            if (size >= capacity){
                resize();
            }
            data[size] = n;
            size += 1;
        }

        int& operator[](int k){
            if (k >= size){
                return data[k];
            }
            else{
                throw out_of_range("indexError");
            }
        }

        void print(){
        //print out content in a list []
            cout << "[";
            for (int k = 0; k < size - 1; k++){
                cout << data[k];
                cout << ",";
            }
            cout << data[size - 1] << "]" << endl;
        }

        void insert(int val, int index){
        //insert a value in desired place
            int *tmp = new int[capacity];
                for (int k = 0; k < index; k++){
                    tmp[k] = data[k];
                }
                tmp[index] = val;
                size += 1;
                for (int k = index + 1; k < size; k++){
                    tmp[k] = data[k - 1];
                }
            delete[] data;
            data = tmp;
        }

        void remove(int index){
        //removes desired index
            if (index > size){
                throw out_of_range("indexError");
            }
            else{
                int *tmp = new int[capacity];
                for (int k = 0; k < index; k++){
                    tmp[i] = data[i];
                }
                size -= 1;
                for (int k = index; k < size; k++){
                    tmp[k] = data[k + 1];
                }
            
                delete[] data;
                data = tmp;
                if (size < 0.25*capacity){
                    shrink_to_fit();
                }            
            }
        }

        int pop(int index){
        //removing and returns the removed element
            int poppa = data[index];
            remove(index);
            return poppa;
        }

        int pop(){
        //pop out the last element in list and return it
            int poppa = data[size - 1];
            remove(size - 1);
            return poppa;
        }

        void shrink_to_fit(){
        //redusing capacity to the smallest capacity
            if (size*2 < capacity){
                capacity /= 2;
                int *tmp = new int [capacity];
                for (int k = 0; k < size; k++){
                    tmp[k] = data[k];
                }
                delete[] data;
                data = tmp;
            }
            else{
                cout << "capacity is good enough" << endl;
            }
        }
};

bool is_prime(int n){
//using a for loop to find primes
    for(int k = 2; k < n; k++){
        if(n%k == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ArrayList prime;
    for (int k = 0; k < 20; k++){
        if (is_prime(k) == true){
            prime.append(k);
        }
    }
    //example List
    prime.print();
    //testing append
    prime.append(27);
    prime.print();
    //testing remove
    prime.remove(6);
    prime.print();
    //testing shrink to fit
    prime.shrink_to_fit();
    prime.print();
    //testing insert
    prime.insert(420, 2);
    prime.print();
    
    cout << "pop = " << prime.pop() << endl;
    cout << "length = " << prime.length() << endl;
}
