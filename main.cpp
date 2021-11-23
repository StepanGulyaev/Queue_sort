#include "Queue.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <chrono>


using namespace std::chrono;



void fill_vector(std::vector<int> &random_numbers)
    {
    int smallest = -10000;
    int biggest = 10000;
    for (size_t i = 0; i < random_numbers.size(); i++)
        {
        int random_number = smallest + rand() % (biggest - smallest);
        random_numbers[i] = random_number;
        }
    }


int main()
    { 
    Queue myQueue;
    size_t size = 0;
    std::vector<int> random_numbers(size);

    while (size < 3000)
        {
        size+=300;
        random_numbers.resize(size);

        std::cout<< "Number of sorted elements: " << size << " ";
        fill_vector(random_numbers);
        myQueue.push(random_numbers);
        random_numbers.clear();

        myQueue.clear_N_op();
        time_point<system_clock> start, end;
        start = system_clock::now();
        myQueue.sort();
        end = system_clock::now();
        duration<double> seconds = end - start;

        std:: cout << "Sort time:" << seconds.count() << " ";
        std:: cout << "Number of operations:" << myQueue.N_op << std::endl;

        myQueue.clear_N_op();
        myQueue.clear();
        }
    }
