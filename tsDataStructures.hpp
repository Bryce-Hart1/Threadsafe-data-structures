#pragma once
#include <mutex>
#include <exception>
#include <thread>



/** @attention locations of all data structures
 * vec (vector) line 24 - 83
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
        T* _Data;
        std::size_t _Size;
        std::size_t _Capacity;
        std::size_t StartIndex;
        std::size_t EndIndex;
        std::mutex _mutex;
        vec(){
            
        }
        /*passing intial size allows for vec size to be set to this*/
        vec(size_t intial){
            _Capacity = intial;
        }

        void appendTo(std::size_t ){

        }
        /** @brief a better named erase() from std::vector
         * moves down elements at that position
         * 
         */
        void eraseAt(std::size_t iteratorPosition){
            try{
                if(iteratorPosition <= EndIndex && iteratorPosition >= StartIndex){

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


        
        void remove(std::size_t startIndex, std::size_t endIndex){

        }

        /**
         * @brief simular to shrink to fit for vector. Changes so the array 
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

    };



}