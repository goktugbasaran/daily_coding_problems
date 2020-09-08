//
/*
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>   
#include <unordered_set>
#include <algorithm>
#include <bits/stdc++.h> 
#define SIZE 1000000

bool pair_exists_vec(int k, std::vector<int> array);
bool pair_exists_set(int k,std::vector<int>array);
std::vector<int> generate_random_array(int size);
int main(){
    srand((unsigned)(time(0)));
    int k = rand()%SIZE +1;

    std::vector<int> array = generate_random_array(SIZE);

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    pair_exists_set(k,array);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Set: " << duration << std::endl;
   
    t1 = std::chrono::high_resolution_clock::now();
    pair_exists_vec(k,array);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Vec: " << duration << std::endl;

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
bool pair_exists_set(int k,std::vector<int> array){
    std::unordered_set<int> complements;
    for (int val : array){
        if(complements.find(val) != complements.end()){
            return true;
        }
        complements.insert(k-val);
    }
    return false;
}
bool pair_exists_vec(int k, std::vector<int> array){
    sort(array.begin(),array.end());
    int i =0;
    int j = array.size()-1;
    while(i != j){
        int sum = array[i] + array[j];
        if(sum> k){
            j--;
        }
        else if(sum < k){
            i++;
        }
        else{
            return true;
        }
    }
    return false;
}
