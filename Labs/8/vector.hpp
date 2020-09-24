#include <stdlib.h>
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;

template <class T>

class vector {
    private:
        T *v;
        int s;
        int cap;
    public:
        vector(){
            s=0;
            v=NULL;
        }

        void set_s(int new_s){
            s = new_s;
        }

        ~vector(){
            delete [] v;
        }

        int size() {
            return s;
        }

        void push_back(T ele) {
            if(s < cap){
                T *temp;
                temp = new T[++s];
                for(int i=0; i<s-1; i++)
                    temp[i]=v[i];
                delete [] v;
                v=temp;
                v[s-1]=ele;
            }
            else{
                cout << "Cannot push value onto memory that is out of the capacity." << endl;
            }
        }

        vector(vector<T> &other){
            cap = other.cap;
            v = new T[other.s];
            for(int i = 0; i < other.s; i++){
                v[i] = other.v[i]; 
            }
            s = other.s;

            ////v = other.v;
        }

        void operator=(vector<T> &other){
            delete [] v;
            v = new T[other.s];
            for(int i = 0; i < other.s; i++){
                v[i] = other.v[i]; 
            }
            ////v = other.v;
            s = other.s;
        }

        T operator[](int index){
            if(index >= s){
                throw std::out_of_range("That index is out of range.");
            }else{
                return v[index];
            }
        }

        T at(int index){
            if(index > s){
                throw std::out_of_range("That index is out of range.");
            }else{
                return v[index];
                ////cout << "Valid index." << endl;
            }
        }

        vector(int capacity){
            s=0;
            v=NULL;
            cap = capacity;
        }

        void resize(int new_size){
            cap = new_size;
        }


};