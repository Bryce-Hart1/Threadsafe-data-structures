#pragma once

#include<mutex>
#include <thread>
#include <iostream>
#include <random>
#include <cstddef>

#include "exceptions.hpp"

/** @attention complete vector implemenation
 * My goal with this project is to provide a completely safe multithreaded vector implemenation with all functions mostly from scratch
 * tip for later use throw std::out_of_range("index out of range");
 *
 * 
 */


namespace threadsafe{
    template <typename T>
    /** @class vec
    * threadsafe vector implementation
    * 
    *
    *
    */
    class vec{
        private:
        T* v_Data;
        std::size_t v_Size; //also our end iterator
        std::size_t v_Capacity;
        std::size_t v_StartIndex;
        std::mutex v_SizeMutex;
        std::mutex v_elementMutex;
        
        //checks if index is in range
        bool checkIndex(size_t index){
            if(index >= v_StartIndex && index <= v_Size){
                return true;
            }
            return false;
        }

        T* returnCopy(std::size_t newSize){
            T* newBlock = new T[newSize]; 
                for (size_t i = 0; i < v_Size; i++){
                    newBlock[i] = v_Data[i];
                }
                delete[] v_Data; 
        }

        /**
         * @brief private member that moves 
         */
        void moveLeft(size_t startFrom){
            std::unique_lock<std::mutex> v_Mutex;
            //it will erase this front element, that is the startFrom index.
            for(int i = startFrom; i < this->endItr-1; i++){
                v_data[i] = v_data[i+1]
            }
        }
        //gets random in start to end index. This greatly reduces chance of worst case runtime for quicksort
        std::size_t getRandom(std::size_t startInd, std::size_t endInd){
                std::random_device rd;
                std::mt19937_64 gen(rd());
                std::uniform_int_distribution<std::size_t> distrib(startInd, endInd);
                std::size_t random_size = distrib(gen);
                return random_size;
        }
        void parition(){

        }

        void quickSort(){

        }


        public: 
        vec() : v_Data(new T[2]), v_Size(0) v_Capacity(2), v_StartIndex(0){}
        /*passing intial size allows for vec size to be set to this*/
        vec(std::size_t capacity) : v_Data(new T[capacity]), v_Size(0), v_Capacity(2), v_StartIndex(0){}

        ~vec(){
            delete[] T* v_Data;


        }


        void appendTo(std::size_t indexToAppend){
            try{
                if(checkIndex(indexToAppend)){
                }
            }
        }

        T at(std::size_t indexAt){
            try{
                if(checkIndex(indexAt)){
                    return v_Data[indexAt];
                }
            }catch(const std::exception &e){
                std::cerr << e << '\n';
            }
            
        }

        std::size_t capacity(){
            return this->v_Capacity;
        }


        std::size_t endItr(){
            return v_Size();
        }

        /** @brief a better named erase() from std::vector
         * moves down elements at that position
         * 
         */
        void eraseAt(std::size_t iteratorPosition){
            try{
                if(checkIndex(iteratorPosition)){

                }
                throw new std::exception();
            }catch(const std::exception &e){
                
            }
        }

        /**
         * returns front element
         */
        T frontElement(){
            try{
                if(size() != 0){
                    return data[v_StartIndex];
                }else{
                    throw new //range exception
                }
            }catch(const std::exception &e){

            }
        }


        bool isEmpty(){
            if(v_Size == 0){
                return true;
            }
            return false;
        }
        
        //remove last element
        void popBack(){
            std::unique_lock<std::mutex> lock(v_Mutex);
            this->_Size--;
        }


        void pushBack(T value){
            std::unique_lock<std::mutex> lock(v_Mutex);
            if(v_Size == v_Capacity+1){
                size_t allocateNewSize = (v_Capacity * 2);
                v_Data = returnCopy();   
                v_Capacity = allocateNewSize;                
            }
            v_Data[v_Size] = value;
        }

        //removes from the index provided
        void remove(std::size_t IndexToRemove){
            std::unique_lock<std::mutex> v_Mutex;
            
        }
        //removes from all indexes from start to finish
        void remove(std::size_t startIndex, std::size_t endIndex){
            
        }

        void resize(std::size_t resizeToSize){
            std::unique_lock<v_Mutex> lock;
            v_Capacity = resizeToSize;
        }

        /**
         * @brief simular to shrink to fit for vector. Changes so the array takes up exactly the size in memory
         */
        void shrinkToFit(){
            std::unique_lock<std::mutex> lock(v_Mutex);
            this->_Capacity = this->_Size;
        }

        std::size_t size(){
            std::unique_lock<std::mutex> lock(v_Mutex);
            return this->v_Size;
        }

        /**
         * @brief sorts list starting at startIndex, and ending at EndIndex
         * 
         */
        void sort(std::size_t startIndex, std::size_t endIndex){

        }

        void sort(std::size_t startIndex, std::size_t endIndex, std::function<T(T, T)> function){

        }

        // returns starting position
        std::size_t startItr(){
            return this->v_StartIndex;
        }

        
        void swap(T &dataA, T &dataB){
            std::unique_lock<std::mutex> lock(v_Mutex);
            T temp = dataA;
            dataA = dataB;
            dataB = temp;
        }

    };



}