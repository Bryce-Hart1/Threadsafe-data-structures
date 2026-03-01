#include<vector>
#include<mutex>
#include<memory>



namespace threadSafe{
    template <typename Type>


    class biTree{
        struct node{
            std::mutex nodeLock;
            Type value;
            std::unique_ptr<Type> left = nullptr;
            std::unique_ptr<Type> right = nullptr;
            std::size_t count = 0;
        };
        private:
            node root;
        public:
            biTree(Type rootValue){
                std::unique_lock<std::mutex> lock(root.nodeLock);
                root.value = rootValue;
            }
            ~biTree(){
                delete[] root;
            }

            void add(Type value){
                auto current = this->root;
                while(current.left != nullptr && current.right != nullptr){
                    break; //temp
                }
            }
            void center(){

            }
            bool find(){

            }

            std::vector<Type> orderedList(){

            }

            void remove(Type remove){

            }



            

            
    };
}