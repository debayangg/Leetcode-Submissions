class LRUCache {
public:
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_key;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (map_key.find(key) == map_key.end()) {
            return -1;
        }

        // Move the accessed element to the front of the list
        auto it = map_key[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        map_key[key] = cache.begin();
        
        return value;
    }
    
    void put(int key, int value) {
        if (map_key.find(key) != map_key.end()) {
            // If the key is already present, update the value and move it to the front
            auto it = map_key[key];
            cache.erase(it);
            cache.push_front({key, value});
            map_key[key] = cache.begin();
        } else {
            // If the cache is at capacity, remove the least recently used item
            if (cache.size() == cap) {
                auto last_element = cache.back();
                map_key.erase(last_element.first);
                cache.pop_back();
            }

            // Insert the new element at the front of the list
            cache.push_front({key, value});
            map_key[key] = cache.begin();
        }
    }
};
