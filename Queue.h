#ifndef LINEARSTRUCTURES_QUEUE_H
#define LINEARSTRUCTURES_QUEUE_H

#include <vector>

class Queue
    {
    private:
        std::vector<int> array; 

        int is_not_empty(); // check if queue is empty
        int check_pos_exist(unsigned int pos); // check position on existence 

    public:
        size_t size;
        unsigned long long int N_op;
        
        Queue(); //Constructor
        Queue(Queue* myQueue_adress); // copy original queue
        ~Queue(); //Destructor

        void push(const int el); // add element
        void push(const std::vector<int> newValues); // add few elements
        int peek(); // return value of the first element 
        int pop(); // delete first element and return it's value
        void clear(); // delete all elements from array
        void clear(size_t pos); // delete all elements before the certain position ()
        void clear_N_op(); //clear operation counter 

        int get(size_t pos); // get value from element on n-position
        void set(const int newValue,size_t pos); // set new value to element on n-position
        
        int& operator[] (unsigned int index); // overload the "[]"

        void sort(); //insertion sort of queue

        void print(); // print the queue
    };

#endif
