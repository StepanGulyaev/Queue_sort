#include "Queue.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>



void fill_vector(std::vector<int> &random_numbers)
    {
    int smallest, biggest;
    std:: cout << "Set range of values" << std::endl;
    std:: cout << "Enter the smallest possible value: ";
    std:: cin >> smallest;
    std:: cout << "And the biggest one: ";
    std:: cin >> biggest;
    for (size_t i = 0; i < random_numbers.size(); i++)
        {
        int random_number = smallest + rand() % biggest;
        random_numbers[i] = random_number;
        }
    }

int main()
    { 
    Queue myQueue;

    size_t size;

    std:: cout << "How many numbers you want to sort?" << std::endl;
    std:: cin >> size;
    std::vector<int> random_numbers(size);
    fill_vector(random_numbers);

    myQueue.push(random_numbers);
    myQueue.print();

    std:: cout << std::endl;
    Queue copyQueue(&myQueue);
    copyQueue.sort();
    copyQueue.print();
    }