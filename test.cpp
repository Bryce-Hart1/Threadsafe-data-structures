#include "tsVector.hpp"
#include <vector>

#include "tsQueue.hpp"
#include <queue>

#include "tsStack.hpp"
#include <stack>

#include <unordered_map>
#include "tsHashmap.hpp"

#include <functional>
#include <algorithm>

using i32 = u_int32_t;
using i16 = u_int16_t;
using i8 = int8_t;
using size_t = std::size_t;
using string = std::string;




/**
 * @attention testing of the non tree structures - hashmap, queue, stack, and vec
 * @details runs through all possible functions from each, non multithreaded. This is due to 
 * the possible end times of each thread could destroy orignal order, meaning that testing order that 
 * each operation is finishing is not important. This is subject to changes as I expand this project.
 * 
 * 
 * 
 */

void vecPushBack(threadsafe::vec<i16> x, i16 i){
    x.pushBack(i);
}


//test pushback, clear, shrink to fit and at features and compare the outputs to std::vector
bool Vector_testOne(threadsafe::vec<i16>& x, std::vector<i16>& y){
    threadsafe::vec<int> name;
    
    const int oneM = 1000000;
    int n = 0; //number pushed into both
    for(int i = 0; i < oneM; i++){
        std::thread t(vecPushBack, std::ref(x), n);
        t.join();
        n++;
    }
    if(x.size() != y.size()){
        return false;
    }else{
        for(int i = 0; i < oneM; i++){
            if(x.at(i) != y.at(i)){
                return false;
            }
        }
    }
    x.clear();
    y.clear();
    x.pushBack(3);
    y.push_back(3);
    x.shrinkToFit();
    y.shrink_to_fit();
    if(x.size() != y.size()){
        return false;
    }
}

//testing itr methods
bool Vector_testTwo(threadsafe::vec<i16>& x, std::vector<i16>& y){
    threadsafe::vec<i16> tempA; 
    std::vector<i16> tempB;
    tempA.pushBack(4);
    tempB.push_back(4);
    tempA.pushBack(9);
    tempB.push_back(9);
    tempA.pushBack(1);
    tempB.push_back(1);
    std::sort(tempA.startItr(), tempA.endItr());
    std::sort(tempB.begin(), tempB.end());
}





bool testVector(){
    using namespace std;
    string p = "In testVector: ";
    threadsafe::vec<i16> tsVector;
    vector<i16> vector;
    cout << "size of vector " << sizeof(vector);
    cout << "size of tsVector" << sizeof(tsVector);
    if(!Vector_testOne(tsVector, vector)){
        cout << p <<  "Failed Testone" << endl;
    }
    if(!Vector_testTwo(tsVector, vector)){
        cout << p << "Failed TestTwo" << endl;
    }
    

}






bool testQueue(){
    std::queue<i16> x;
    threadsafe::queue<i16> y;
    
}




bool testStack(){
    std::stack<i16> x;
    threadsafe::stack<i16> y;

}


bool testMap(){
    std::unordered_map<char, i16> x;
    threadsafe::hashmap<char, i16> y;
    

}











int main(){
    if(testVector()){
        std::cout << "All Vector tests passed" << std::endl;
    }
    if(testQueue()){
        std::cout << "All Vector tests passed" << std::endl;
    }
    if(testStack()){
        std::cout << "All Stack tests passed" << std::endl;
    }
}