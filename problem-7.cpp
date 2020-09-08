//
/*
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, 
and an encoded message, 
count the number of ways it can be decoded.

For example, the message '111' would give 3, 
since it could be decoded as 'aaa', 'ka', and 'ak'.


My solution is not really time efficient.

For input size of 10, it takes around 25 miliseconds,
For input size of 20, it takes around 2500 miliseconds,
For input size of 30, it takes around 250000 miliseconds,
*/
//

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

std::string generateInput(int len);
int findCombinations(std::string input);
int decodable(std::string s);

int main(){

    std::string input = generateInput(10);
    /********************************************************************************************/
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    findCombinations(input);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Size: "<<input.length() << ": "<< duration << " miliseconds" << std::endl;
    /********************************************************************************************/
    return 0;
}

int findCombinations(std::string input){
    int size = input.length();

    if(size == 1 && input.at(0) != '0'){
        return decodable(input);
    }
    if(size == 2){ 
        if(input.at(0) == '0'){
            return decodable(input);
        }
        return decodable(input) + 1;
    }
    else{
        std::string substr1 = input.substr(0,1);
        std::string substr2 = input.substr(0,2);
        std::string substr3 = input.substr(1,input.length() -1);
        std::string substr4 = input.substr(2,input.length() -1);
        return decodable(substr1) *
                findCombinations(substr3) +
                decodable(substr2) *
                findCombinations(substr4);
    }

}

int decodable(std::string s){
    if(s[0] == '0') return 0;
    int num = stoi(s);
    if(num<=26) return 1;
    return 0;
}
std::string generateInput(int len){
    srand((unsigned)(time(0)));
    std::string input = "";
    input += std::to_string(rand()%10+1);
    while(len > 1){
        std::string generated  = std::to_string((rand()%10));
        len-= generated.size();
        input += generated;
    }
    return input;
}
