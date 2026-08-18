class TimeMap {
    unordered_map<string, vector<pair<int,string>>> git;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(git.find(key)!=git.end()){
            git[key].push_back({timestamp,value});
        }
        else{
            git[key]={{timestamp,value}};
        }
    }
    
    string get(string key, int timestamp) {
        if(git.find(key)==git.end()) return "";
        int n=git[key].size();
        int st=0;
        int end=n-1;
        string res="";
        while(st<=end){
            int mid=st+(end-st)/2;
            int time=git[key][mid].first;
            if(time<=timestamp){
                res=git[key][mid].second;
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return res;
    }
};
