#ifndef LINEARSTRUCTURES_QUEUE_H
#define LINEARSTRUCTURES_QUEUE_H

#include <vector>

class Queue
    {
    private:
        size_t size;
        std::vector<int> array;

        int is_not_empty(); // check if queue is empty
        int check_pos_exist(unsigned int pos); // check position on existence 

    public:
        Queue(); //Constructor
        Queue(Queue* myQueue_adress); // copy original queue
        ~Queue(); //Destructor

        void push(const int el); // add element
        void push(const std::vector<int> newValues); // add few elements
        int pop(); // delete first element and return it's value
        void clear();
        void clear(size_t pos);

        void set(const int newValue,size_t pos); // set new value to element on first position
        int get(size_t pos); // get new value from element on n-position

        int& operator[] (unsigned int index); // overload the "[]"

        void sort(); //sort

        void print();
    };

#endif