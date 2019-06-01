#include <iostream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h> 

// problem:
// given an integer unsorted array of size k
// return an array that contains at index i the multiple
// of the numbers other than the i'th number in the original array
// ex. arr ={1,2,3,4}
// ret = {24,12,8,6}
// With divison allowed
// With division not allowed.

std::vector<int> generate_random_array(int size);

std::vector<int> problem2WithDivision(std::vector<int> &input);
std::vector<int> problem2WithWalking(std::vector<int> &input);
std::vector<int> problem2WithLog(std::vector<int> &input);

void print_vector(std::vector<int> &vec){
    for(int num: vec){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main(){
    
    std::vector<int> array =  generate_random_array(1000000);

    /********************************************************************************************/
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::vector<int> result = problem2WithDivision(array);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "With Division: " <<duration << std::endl;
    /********************************************************************************************/

    /********************************************************************************************/
    t1 = std::chrono::high_resolution_clock::now();
    std::vector<int> result2 = problem2WithWalking(array);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "With Walking: " <<duration << std::endl;
    /********************************************************************************************/

    /********************************************************************************************/
    t1 = std::chrono::high_resolution_clock::now();
    std::vector<int> result3 = problem2WithLog(array);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "With Log: " <<duration << std::endl;
    /********************************************************************************************/
    return 0;
}
std::vector<int> generate_random_array(int size){
    srand((unsigned)(time(0)));
    int k = rand()%size +1;
    std::vector<int> array;
    for (int i = 0; i < size; i++){
        array.push_back(rand()%size + rand()%k);
        while(array[i] == 0){
            array[i] = rand()%size + rand()%k;
        }
    }
    return array;
}
std::vector<int> problem2WithDivision(std::vector<int> &input){
    // complexity is O(n)
    int total = 1;
    for(int num : input){
        total*=num;
    }
    std::vector<int> result;
    for(int num: input){
        result.push_back(total/num);
    }
    return result;
}
std::vector<int> problem2WithWalking(std::vector<int> &input){
    // complexity is still O(n)
    std::vector<int> result(input.size(),1);
    int prev_mult = 1;
    int forw_mult = 1;
    int i = 1;
    int j = input.size()-2;
    for (;i<input.size();i++,j--){
        prev_mult *= input[i-1];
        forw_mult *= input[j+1];
        result[j] *= forw_mult;
        result[i] *= prev_mult;
    }
    return result;
}
std::vector<int> problem2WithLog(std::vector<int> &input){
    // this is a walkaround division since
    // log subtraction is technically division.

    // assuming log(n) and pow(n,10) time complexities are O(1)
    // total time complexity is O(n)
    // space complexity is also O(n)
    double sum = 0;
    double multAtIndex;
    std::vector<int> result;
    for(int num : input){
        sum += log10(num);
    }
    for(int num : input){
        result.push_back(pow(10,sum - log10(num)));
    }
    return result;
}