class NumberContainers {
public:
    unordered_map<int,int> indNum;
    unordered_map<int,set<int>> minNum;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        minNum[indNum[index]].erase(index);
        indNum[index]=number;
        minNum[number].insert(index);
    }
    
    int find(int number) {
        if(minNum[number].size())
        return *(minNum[number].begin());
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */