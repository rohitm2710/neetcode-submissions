class PrefixTree {
private:
    class TrieNode {
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

public:

    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(curr->children[c-'a']==nullptr){
                curr->children[c-'a']=new TrieNode();
            }
            curr=curr->children[c-'a'];
        }
        curr->endofWord=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(curr->children[c-'a']==nullptr){
                return false;
            }
            curr=curr->children[c-'a'];
        }
        return curr->endofWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char c:prefix){
            if(curr->children[c-'a']==nullptr){
                return false;
            }
            curr=curr->children[c-'a'];
        }
        return true;
    }
};
