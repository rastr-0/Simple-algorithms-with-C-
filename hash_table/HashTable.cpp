#include <iostream>
#include <list>
#include <string>

class HashTable{
private:
    static const int hash_groups = 10;
    std::list<std::pair<int, std::string>> table[hash_groups];
public:
    void insert_item(const int key, const std::string value){
        int hash_value = hash_function(key);
        auto& cell = table[hash_value];
        auto begin_itr = std::begin(cell);
        bool key_exists = false;
        for (; begin_itr != std::end(cell); begin_itr++){
            if (begin_itr->first == key){
                begin_itr->second = value;
                key_exists = true;
                std::cout << "Key exists, values was replaced" << std::endl;
                break;
            }
        }
        if (!key_exists){
            std::cout << "Key was inserted" << std::endl;
            cell.emplace_back(key, value);
        }
    }
    void remove_item(const int key){
        int hash_value = hash_function(key);
        auto& cell = table[hash_value];
        auto begin_itr = std::begin(cell);
        bool key_exists = false;
        for (; begin_itr != std::end(cell); begin_itr++){
            if (begin_itr->first == key){
                begin_itr = cell.erase(begin_itr);
                key_exists = true;
                std::cout << "Key exists, values was erased" << std::endl;
                break;
            }
        }
        if (!key_exists)
            std::cout << "Key doesn't exists" << std::endl;
    }
    bool is_empty() const{
        int sum = 0;
        for (int i = 0; i < hash_groups; i++){
            sum += table[i].size();
            if (sum > 0)
                return false;
        }
        return true;
    }
    const int hash_function(const int key){
        // distribute numbers by last value of number:
        // 101 => 1; 607 => 7
        return key % hash_groups;
    }
    std::string search_table(const int key);
    void print(){
        for (int i = 0; i < hash_groups; i++){
            if (table[i].size() == 0)
                continue;
            auto begin_itr = table[i].begin();
            std::cout << i << " cell" << std::endl;
            for (;begin_itr != table[i].end(); begin_itr++){
                std::cout << "Key: " << begin_itr->first << " Value: " << begin_itr->second << std::endl;
            }
            std::cout << "- - -" << std::endl;
        }
    }
};
int main(){
    
}
