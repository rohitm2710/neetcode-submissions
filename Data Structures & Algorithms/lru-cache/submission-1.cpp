class LRUCache {
private:
    int curr=0;
    int space;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> lru;
public:
    LRUCache(int capacity) {
        space=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        auto it=cache[key];
        int val=it->second;
        lru.erase(it);
        lru.push_front({key,val});
        cache[key]=lru.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            lru.erase(cache[key]);
            lru.push_front({key,value});
            cache[key]=lru.begin();
            return;
        }
        if(curr==space){
            auto ev=lru.back();
            cache.erase(ev.first);
            lru.pop_back();
            lru.push_front({key,value});
            cache[key]=lru.begin();
        }
        else{
            lru.push_front({key,value});
            cache[key]=lru.begin();
            curr++;
        }
    }
};
