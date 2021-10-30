#include "Queue.h"
#include <iostream>
#include <vector>
#include <stdexcept>

Queue::Queue()
    {
    size = 0;
    std::vector<int> array;
    }

Queue::Queue(Queue* myQueue_adress)
    {
    size = myQueue_adress->size;
    if (size)
        {
        for (size_t i = 0; i < size; i++)
            {
            array.push_back(myQueue_adress->array[i]);
            }
        }
    }

Queue::~Queue()
    {
    array.clear();
    }

void Queue::push(const int el)
    {
    array.push_back(el);
    size++;
    }

void Queue::push(const std::vector<int> newValues)
    {
    for(size_t i = 0; i < newValues.size(); i++)
        {
        push(newValues[i]);
        }
    }

int Queue::pop()
    {
    if (is_not_empty())
        {
        int first_el = array[0];
        for (size_t i = 0; i < size - 1; i++)
            {
            array[i] = array[i+1];
            }
        size--;
        array.resize(size);
        return first_el;
        }
    else
        {
        return 0;
        }
    }


int Queue::is_not_empty()
    {
    if(!size)
        {
        throw std::runtime_error("Queue is empty!");
        return 0;
        }
    return 1;
    }

int Queue::check_pos_exist(unsigned int pos)
    {
    if (pos > size)
        {
        throw std::runtime_error("Value of pos[" + std::to_string(pos) + "] bigger than queue size[" + std::to_string(size) + "]!");
        return 0;
        }
    return 1;
    }

void Queue::clear()
    {
    if (is_not_empty())
        {
        array.clear();
        size = 0;
        }
    }

void Queue::clear(size_t pos)
    {
    if ( (is_not_empty() ) && (check_pos_exist(pos)) )
        {
        for (size_t i = 0 ; i < pos; i++)
            {
            array.erase(array.begin()+i);
            size--;
            }
        }
    }

void Queue::set(const int newValue,size_t pos)
    {
    if ( (is_not_empty() ) && (check_pos_exist(pos) ))
        {
        for (size_t i = 0; i < size; i++)
            {
            if ( i == pos )
                {
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
        int result = 0;
        for (size_t i = 0; i < size; i++)
            {
            if ( i == pos )
                {
                result = pop();
                push(result);
                }
            else
                {
                push(pop());
                }
            }
        return result;
        }
    }


int& Queue:: operator[] (unsigned int index)
    {
    if ( (is_not_empty() ) && (check_pos_exist(index) ))
        {
        int& adress_el = array[0];
        for (size_t i = 0; i < index; i++)
            {
            adress_el = (array[i]);
            push(get(i));
            }
        return adress_el;
        }
    }

void Queue:: sort()
    {
    int temp, item; 
    for (int i = 1; i < size; i++)
        {
        temp = get(i); 
        item = i-1; 
        while(item >= 0 && get(item) > temp)
            {
            set(get(item),item + 1); 
            set(temp,item);
            item--;
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

