//
/*
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. The array can contain
duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/
//

#include <iostream>
#include <vector>
#include <chrono>

std::vector<int> generate_random_array(int size);
void print_vector(std::vector<int> &vec);
int linearTime_linearSpace(std::vector<int> input);

int main(){


    std::vector<int> input;
    
    input.push_back(1);
    input.push_back(2);
    input.push_back(0);
    
   /********************************************************************************************/
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::cout << linearTime_linearSpace(input) << std::endl;
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Linear time, linear complexity: " <<duration <<" microseconds"<<std::endl;
    /********************************************************************************************/

    return 0;
}

int linearTime_linearSpace(std::vector<int> input){

    int maxPositive = 0;
    for (int num :input){
        if(num>0 && num>maxPositive) maxPositive=num;
    }

    int array[maxPositive];
    for(int num: input){
        array[num] = 1;
    }
    for(int i = 0;i<maxPositive;i++){
        if(array[i] - array[i+1] == 1){
            return i+1;
        }
        if(array[i] - array[i+1] == -1){
            return i;
        }
    }
    return maxPositive+1;
 }








std::vector<int> generate_random_array(int size){
    srand((unsigned)(time(0)));
    int k = rand()%size +1;
    std::vector<int> array;
    for (int i = 0; i < size; i++){
        array.push_back(rand()%size/100);
    }
    return array;
}

void print_vector(std::vector<int> &vec){
    for(int num: vec){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
