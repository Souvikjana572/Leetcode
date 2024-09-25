class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        int count;
        TrieNode() {
            count = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };
    class Trie {
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
            }
        void insert(string s) {
            TrieNode* temp = root;
            for (int i = 0; i < s.size(); i++) {
                int index = s[i] - 'a';
                if (!temp->child[index]) {
                    temp->child[index] = new TrieNode();
                }
                temp = temp->child[index];
                temp->count += 1;
            }
        }
        int find(string s) {
            TrieNode* temp = root;
            int ans = 0;
            for (int i = 0; i < s.size(); i++) {
                int index = s[i] - 'a';
                if (!temp->child[index])
                    return ans;
                temp = temp->child[index];
                ans += temp->count;
            }
            return ans;
        }
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i]);
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            result.push_back(trie.find(words[i]));
        }
        return result;
    }
};
