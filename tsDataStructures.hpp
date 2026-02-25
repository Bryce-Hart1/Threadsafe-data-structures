#pragma once
#include <mutex>
#include <exception>
#include <thread>
#include <iostream>
#include <random>
#include <cstddef>


/** @attention locations of all data structures
 * vec (vector) line 24 - 83
 * 
 * 
 */

class outOfBoundsException : public std::exception{
    std::string errorMsg;
    public:
    outOfBoundsException(std::string message) : errorMsg(std::move(message)){}
    const char* what() const noexcept override {return errorMsg.c_str(); }
};


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
        T* _Data;
        std::size_t _Size; //also our end iterator
        std::size_t _Capacity;
        std::size_t _StartIndex;
        std::mutex _SizeMutex;
        
        //checks if index is in range
        bool checkIndex(size_t index){
            if(index >= _StartIndex && index <= _Size){
                return true;
            }
            return false;
        }
        void moveDown(size_t ){

        }
        std::size_t getRandom(std::size_t startInd, std::size_t endInd){
                std::random_device rd;
                std::mt19937_64 gen(rd());
                std::uniform_int_distribution<std::size_t> distrib(startInd, endInd);
                std::size_t random_size = distrib(gen);
                return random_size;
        }



        public: 
        vec(){
            
        }
        /*passing intial size allows for vec size to be set to this*/
        vec(size_t intial){
            _Capacity = intial;
        }
        ~vec(){

        }


        void appendTo(std::size_t indexToAppend){
            try{
                if(indexToAppend)
            }
        }

        std::size_t endItr(){
            return _Size();
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
        
        void popBack(){
            std::unique_lock
            this->_Size--;
        }

        void pushBack(T value){
            if(_Size == _Capacity+1){
                //create new
            }
        }


        void remove(std::size_t IndexToRemove){

        }

        void remove(std::size_t startIndex, std::size_t endIndex){

        }

        /**
         * @brief simular to shrink to fit for vector. Changes so the array takes up exactly the size in memory
         */
        void shrinkToFit(){
            this->_Capacity = this->_Size;
        }

        /**
         * @brief sorts list starting at startIndex, and ending at EndIndex
         * 
         */
        void sort(std::size_t startIndex, std::size_t endIndex){

        }
        // returns starting position
        std::size_t startItr(){

        }

        void swap(){
            
        }

    };



}