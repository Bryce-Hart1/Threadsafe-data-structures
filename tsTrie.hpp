#include <memory>
#include <string>
#include <mutex>




namespace threadSafe{

    struct node{
        char value;
        std::mutex mtx;
        bool isEndPoint;
    };

class Trie{
    private:
        std::unique_ptr<node> root;
        std::atomic<std::size_t> v_nodeCount;
        std::atomic<std::size_t> wordCount;

        void setEndPointTrue(){
        std::lock_guard<std::mutex> lock(mtx);
        this->isEndPoint = true;
        }


//default constructor gets called on root
Trie(){
    root.get()->value = '*';
    root.get()->isEndPoint = true;
}

//gets called on all children
Trie(std::string intial){

}
//increment the count for this endNode
void increment() {
    if(this->getIsEndPoint()){
    std::lock_guard<std::mutex> lock(mtx);
    ++count;
    }
}

unsigned getCount(){
    std::lock_guard<std::mutex> lock(mtx);
    return this->count;
}

char getValue(){
    return this->value;
}

//endpoint just means that it is a word/phrase that needs saved



bool getIsEndPoint(){
    return this->isEndPoint;
}


//returns a node at requested position, if not returns nullptr
atomicNode* findChildNode(char value){
    std::lock_guard<std::mutex> lock(mtx);
    for(auto& child : children){
        if(child->value == value){
            return child.get();
        }
    }
    return nullptr;
}

unsigned int getChildCount() const{
    std::lock_guard<std::mutex> lock(mtx);
    return children.size();
}


//adds entire word
void add(std::string word){
    atomicNode* current = this;
    
    for(size_t i = 0; i < word.length(); i++){
        char ch = word[i];
        if(NO_CAPITALS_FLAG){
            ch = toLower(ch);
        }
        
        std::lock_guard<std::mutex> lock(current->mtx); //lock current
        
        atomicNode* thisChild = nullptr;
        
        for(auto& c : current->children){
            if(c->value == ch){
                thisChild = c.get();
                break;
            }
        }
        
        if(thisChild == nullptr){
            current->children.emplace_back(std::make_unique<atomicNode>(ch));
            thisChild = current->children.back().get();

        }
        
        current = thisChild;
    }
    
    //these need to be outside any lock since they acquire their own locks anyway
    current->setEndPointTrue();
    current->increment();
}

//print everything but root, and only if it is an endpoint
void saveSet(std::string prefix, std::vector<std::string>& allwords){
    if(this->isEndPoint && !this->isRoot){
        allwords.push_back(prefix);
    }
    for(auto& child : children){ //for all children
        child->saveSet(prefix + child->value, allwords);
    }
}
/*
void printTofile(std::string predef, std::vector<std::string>& words){
    std::ofstream output(predef);
    if(!output.is_open()){
        print::Debug("Error in numberList::printToFile: could not open file.");
        return;
    }
    print::Debug("Amount of words to print to file: " + std::to_string(words.size()));
    size_t counter = 0;
    std::string prev = "";
    for(auto& word : words){
        if(prev == word){
            prev = word;
            counter++;
        }else{ //else, we print the current amount we have (could be one ) and reset counter and update previous
            output << word << ":" << std::to_string(counter) << std::endl;
            prev = word;
            counter = 1; //because if we reset again then we need to show that at least one instance was shown
        }
    }
}
*/
};


}