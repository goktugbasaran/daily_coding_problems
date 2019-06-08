#include <iostream>
#include <vector>
#include <chrono>


// problem:
// given an array of integers, find the *first* *positive* integer that is missing.
// eg: [3,2,4,-2,-3,-5,-1]
// sorted = [-5,-3,-2,-1,2,3,4]
// 1 is missing
// eg: [1,2,0]
// 3 is missing.    

std::vector<int> generate_random_array(int size);
void print_vector(std::vector<int> &vec);
int linearTime_linearSpace(std::vector<int> input);

int main(){


    std::vector<int> input;// = generate_random_array(1000);
    
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

    // O(n) time
    int maxPositive = 0;
    for (int num :input){
        if(num>0 && num>maxPositive) maxPositive=num;
    }

    // O(n-x) space == O(n) 
    int array[maxPositive];
    for(int num: input){
        array[num] = 1;
    }
    // O(n) time
    for(int i = 0;i<maxPositive;i++){
        if(array[i] - array[i+1] == 1){
            return i+1;
        }
        if(array[i] - array[i+1] == -1){
            return i;
        }
    }
    // if not found until the end of the list, it means the maxNumber+1 is missing
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
