#include "tsVector.hpp"


#include <shared_mutex>



/**
 * @attention a threadsafe queue
 * Requires import of threadsafe vector
 */
template <typename T>
using vec = threadsafe::vec<T>;


namespace threadsafe{

        template <typename T> class queue{
        friend class vec<T>;
        
        private:
            vec<T> _queue;
            std::atomic<std::size_t> _front;
            std::atomic<std::size_t> _back;

        void clear(){
            this->_queue.clear();
        }

        T front(){
            return vec.at(_front);            
        }

        void pop(){
            _front.fetch_add(1);
        }

        void push(T val){
            _queue.pushBack(val)
        }


    };





}