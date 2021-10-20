// struct Node{
//         Node *childs;
//         bool isEnd;
//         Node(){
//             Node *childs= new Node;
//             isEnd=false;
//         }
//     };
// class Trie {
// public:
    
//     Trie() {
        
//     }
    
//     void insert(string word) {
//         Node *curr=word;
//         for(int i=0;i<words.size();i++){
//             char ch= word[i];
//             if(curr->childs[ch-'a'] == NULL){
//                 curr->childs[ch-'a'] = new Node;
//             }
//             curr = curr->childs[ch-'a'];
//         }
//         curr->isEnd = true;
//     }
    
//     bool search(string word) {
//         Node *curr= word;
//         for(int i=0;i<word.size();i++){
//             char ch = word[i];
//             if(curr->childs[ch-'a'] == NULL) return false;
//             curr = curr->childs[ch-'a'];
//         }
//         return isEnd;
//     }
    
//     bool startsWith(string prefix) {
//         Node *curr = root;
//         for(int i=0;i<prefix.size();i++){
//             char ch= prefix[i];
            
//             if(curr->childs[ch-'a'] == NULL){
//                 return false;
//             }
//             curr = curr->childs[ch-'a'];
//         }
//         return true;
//     }
// };

// /**
//  * Your Trie object will be instantiated and called as such:
//  * Trie* obj = new Trie();
//  * obj->insert(word);
//  * bool param_2 = obj->search(word);
//  * bool param_3 = obj->startsWith(prefix);
//  */

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode(): isWord(false) {
        for (auto &a : child) a = nullptr;
    }
    ~ TrieNode() {
        for (auto a : child) delete a;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~ Trie() {
        delete root;
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->child[c - 'a']) {
                cur->child[c - 'a'] = new TrieNode();
            }
            cur = cur->child[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->child[c - 'a']) {
                return false;
            } 
            cur = cur->child[c - 'a'];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->child[c - 'a']) {
                return false;
            }
            cur = cur->child[c - 'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */