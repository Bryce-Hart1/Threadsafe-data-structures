#include "tsVector.hpp"
#include <vector>

#include "tsQueue.hpp"
#include <queue>

//#include "tsStack.hpp"
#include <stack>

#include <unordered_map>
//#include "tsHashmap.hpp"

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
 */


//used a variadic template to ignore other arguments from std vector
template<template <typename...> class Container, typename Type, typename... Args>
void printContainer(const Container<Type, Args...>& c) {
    std::cout << "[";
    for (size_t i = 0; i < c.size(); i++) {
        std::cout << c.at(i) << ", ";
    }
    std::cout << "]";
}

void vecPushBack(threadsafe::vec<i16>& x, i16 i){
    
}

//show size dif
bool Vector_testOne(threadsafe::vec<i16>& x, std::vector<i16>& y){
    std::cout << "Size of threadsafe: " << sizeof(x) << std::endl;
    std::cout << "Size of vector: " << sizeof(y) << std::endl;
    return true;
}

//visualize 
bool Vector_testTwo(const threadsafe::vec<i16>& x, const std::vector<i16>& y){
    printContainer(x);
    printContainer(y);
}



//tests popBack
bool Vector_testThree(threadsafe::vec<i16>& x, std::vector<i16>& y){
    for(int i = 0; i < 10; i++){
        x.pushBack(i);
        y.push_back(i);
    }
    x.popBack();
    y.pop_back();
    x.popBack();
    y.pop_back();
    if(x.size() != y.size()){
        return false;
    }
    x.clear();
    y.clear();
    return true;
}

// tests at
bool Vector_testFour(threadsafe::vec<i16>& x, std::vector<i16>& y){
    for(i16 i = 0; i < 100; i++){
        x.pushBack(i * 2);
        y.push_back(i * 2);
    }
    for(int i = 0; i < 100; i++){
        if(x.at(i) != y.at(i)){
            return false;
        }
    }
    x.clear();
    y.clear();
    return true;
}

//tests replace
bool Vector_testFive(threadsafe::vec<i16>& x, std::vector<i16>& y){
    for(i16 i = 0; i < 10; i++){
        x.pushBack(i);
        y.push_back(i);
    }
    x.replace(99, 5);
    y[5] = 99;
    if(x.at(5) != y.at(5)){
        return false;
    }
    x.clear();
    y.clear();
    return true;
}

//tests isEmpty before and after pushing
bool Vector_testSix(threadsafe::vec<i16>& x, std::vector<i16>& y){
    if(!x.isEmpty() || !y.empty()){
        return false;
    }
    x.pushBack(1);
    y.push_back(1);
    if(x.isEmpty() || y.empty()){
        return false;
    }
    x.clear();
    y.clear();
    return true;
}

//tests capacity grows
bool Vector_testSeven(threadsafe::vec<i16>& x, std::vector<i16>& y){
    size_t initialCapacity = x.capacity();
    for(i16 i = 0; i < 50; i++){
        x.pushBack(i);
        y.push_back(i);
    }
    if(x.capacity() <= initialCapacity){
        return false;
    }
    if(x.size() != y.size()){
        return false;
    }
    x.clear();
    y.clear();
    return true;
}

// tests multithreaded pushBack produces correct final size

bool Vector_testEight(threadsafe::vec<i16>& x, std::vector<i16>& y){
    const int numThreads = 100;
    std::vector<std::thread> threads;
    for(int i = 0; i < numThreads; i++){
        threads.emplace_back(vecPushBack, std::ref(x), (i16)i);
    }
    for(auto& t : threads){
        t.join();
    }
    // all pushBacks must have completed
    if(x.size() != numThreads){
        return false;
    }
    x.clear();
    y.clear();
    return true;
}

// tests clear() resets size to 0 but vec remains usable
bool Vector_testNine(threadsafe::vec<i16>& x, std::vector<i16>& y){
    for(i16 i = 0; i < 20; i++){
        x.pushBack(i);
        y.push_back(i);
    }
    x.clear();
    y.clear();
    if(x.size() != 0 || y.size() != 0){
        return false;
    }
    // should still be usable after clear
    x.pushBack(42);
    y.push_back(42);
    if(x.at(0) != y.at(0)){
        return false;
    }
    x.clear();
    y.clear();
    return true;
}

// tests frontElement() and endElement() match first and last pushBack
bool Vector_testTen(threadsafe::vec<i16>& x, std::vector<i16>& y){
    for(i16 i = 1; i <= 5; i++){
        x.pushBack(i);
        y.push_back(i);
    }
    if(x.frontElement() != y.front()){
        return false;
    }
    if(x.endElement() != y.back()){
        return false;
    }
    x.clear();
    y.clear();
    return true;
}


bool testVector(){
    using namespace std;
    string p = "In testVector: ";
    threadsafe::vec<i16> tsVector;
    vector<i16> stdVector;

    if(!Vector_testOne(tsVector, stdVector))   cout << p << "Failed TestOne"   << endl;
    if(!Vector_testTwo(tsVector, stdVector))   cout << p << "Failed TestTwo"   << endl;
    if(!Vector_testThree(tsVector, stdVector)) cout << p << "Failed TestThree" << endl;
    if(!Vector_testFour(tsVector, stdVector))  cout << p << "Failed TestFour"  << endl;
    if(!Vector_testFive(tsVector, stdVector))  cout << p << "Failed TestFive"  << endl;
    if(!Vector_testSix(tsVector, stdVector))   cout << p << "Failed TestSix"   << endl;
    if(!Vector_testSeven(tsVector, stdVector)) cout << p << "Failed TestSeven" << endl;
    if(!Vector_testEight(tsVector, stdVector)) cout << p << "Failed TestEight" << endl;
    if(!Vector_testNine(tsVector, stdVector))  cout << p << "Failed TestNine"  << endl;
    if(!Vector_testTen(tsVector, stdVector))   cout << p << "Failed TestTen"   << endl;
    return true;
}






bool testQueue(){
    std::queue<i16> x;
    threadsafe::queue<i16> y;
    
}




bool testStack(){
    std::stack<i16> x;
    //threadsafe::stack<i16> y;

}


bool testMap(){
    std::unordered_map<char, i16> x;
    //threadsafe::hashmap<char, i16> y;
    

}











int main(){
    if(testVector()){
        std::cout << "All Vector tests passed" << std::endl;
    }

    /*
    if(testQueue()){
        std::cout << "All Queue tests passed" << std::endl;
    }
    if(testStack()){
        std::cout << "All Stack tests passed" << std::endl;
    }

    */
}