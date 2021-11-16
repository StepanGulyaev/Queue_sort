#include "Queue.h"
#include <iostream>
#include <vector>
#include <stdexcept>

Queue::Queue()
    {
    size = 0;  N_op++;
    std::vector<int> array;  N_op++;
    }

Queue::Queue(Queue* myQueue_adress)
    {
    size = myQueue_adress->size; N_op+=2;
    if (size)
        {
        N_op++;
        N_op+=2;
        for (size_t i = 0; i < size; i++)
            {
            N_op+=3;
            array.push_back(myQueue_adress->array[i]); N_op+=4;
            }
        }
    }

Queue::~Queue()
    {
    array.clear(); N_op+=size;
    }

void Queue::push(const int el)
    {
    array.push_back(el);N_op+=2;
    size++; N_op+=2;
    }

void Queue::push(const std::vector<int> newValues)
    {
    N_op+=2;
    for(size_t i = 0; i < newValues.size(); i++)
        {
        N_op+=3;
        push(newValues[i]); N_op++;
        }
    }


int Queue::peek()
    {
    return array[0]; N_op++;
    }

int Queue::pop()
    {
    if (is_not_empty())
        {
        N_op++;
        int first_el = peek(); N_op+=2;
        array.erase(array.begin()); N_op+=2;
        size--; N_op+=2;
        return first_el; 
        }
    else
        {
        N_op++;
        return 0;
        }
    }


int Queue::is_not_empty()
    {
    if(!size)
        {
        N_op++;
        throw std::runtime_error("Queue is empty!");
        return 0;
        }
    return 1;
    }

int Queue::check_pos_exist(unsigned int pos)
    {
    if (pos > size)
        {
        N_op++;
        throw std::runtime_error("Value of pos[" + std::to_string(pos) + "] bigger than queue size[" + std::to_string(size) + "]!");
        return 0;
        }
    return 1;
    }

void Queue::clear()
    {
    if (is_not_empty())
        {
        N_op++;
        array.clear();
        size = 0; N_op++;
        }
    }

void Queue::clear(size_t pos)
    {
    if ( (is_not_empty() ) && (check_pos_exist(pos)) )
        {
        N_op++;
        N_op+=2;
        for (size_t i = 0 ; i < pos; i++)
            {
            N_op+=3;
            pop(); 
            }
        }
    }

void Queue:: clear_N_op ()
    {
    N_op = 0;
    }

void Queue::set(const int newValue,size_t pos)
    {
    if ( (is_not_empty() ) && (check_pos_exist(pos) ))
        {
        N_op++;
        N_op+=2;
        for (size_t i = 0; i < size; i++)
            {
            N_op+=3;
            if ( i == pos )
                {
                N_op++;
                pop(); 
                push(newValue);
                }
            else
                {
                push(pop());
                }
            }
        }
    }

int Queue::get(size_t pos)
    {
    if ( (is_not_empty() ) && (check_pos_exist(pos) ))
        {
        N_op++;
        Queue copyQueue(this); N_op++;
        int result = 0; N_op+=2;
        N_op+=2;
        for (size_t i = 0; i <= pos; i++)
            {
            N_op+=3;
            result = copyQueue.pop(); N_op++;
            }
        return result;
        }
    else 
        {
        N_op++;
        return 0;
        }
    }

int& Queue:: operator[] (unsigned int index)
    {
    is_not_empty();
    check_pos_exist(index); 
    Queue copyQueue(this);
    int& adress_el = copyQueue.array[0];
    for (size_t i = 0; i < size; i++)
        {
        if ( i == index)
            {
            adress_el = copyQueue.array[i];
            push(pop());
            }
        else
            {
            push(pop());
            }
        }
    return adress_el;
    }
    
void Queue:: sort()
    {
    int temp, item; N_op+=2;
    N_op+=2;
    for (int i = 1; i < size; i++)
        {
        N_op+=3;
        temp = get(i); N_op++; 
        item = i-1; N_op+=2 ; 
        while(item >= 0 && get(item) > temp)
            {
            N_op+=3;
            set(get(item),item + 1); 
            set(temp,item);
            item--; N_op+=2;
            }
        }
    }

void Queue::print()
    {
    for (size_t i = 0; i <size; i++)
        {
        std::cout << array[i] << "  "; 
        }
    }

