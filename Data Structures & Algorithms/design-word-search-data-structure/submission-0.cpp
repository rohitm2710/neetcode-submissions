class WordDictionary {
private:

    class TrieNode{
        public:
        bool endofWord;
        TrieNode* children[26];

        TrieNode(){
            endofWord=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };

    TrieNode* root;

    bool dfs(const string& word,int index,TrieNode* curr){
        if(!curr) return false;
        if(index==word.size()) return curr->endofWord;

        char c=word[index];

        if(c=='.'){
            for(int i=0;i<26;i++){
                if(curr->children[i]&&dfs(word,index+1,curr->children[i])){
                    return true;
                }
            }
            return false;
        }
        else{
            int Cindex = c-'a';
            if(!curr->children[Cindex]) return false;
            return dfs(word,index+1,curr->children[Cindex]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
        for(char c:word){
            int index = c-'a';
            if(!curr->children[index]){
                curr->children[index]=new TrieNode();
            }
            curr=curr->children[index];
        }
        curr->endofWord=true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};
