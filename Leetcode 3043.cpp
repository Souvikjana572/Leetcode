class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[10];
        TrieNode() {
            for (int i = 0; i < 10; i++) {
                child[i] = NULL;
            }
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode* node = root;
            for (char ch : word) {
                int index = ch - '0';
                if (node->child[index] == NULL) {
                    node->child[index] = new TrieNode();
                }
                node = node->child[index];
            }
        }

        int search(string word) {
            TrieNode* node = root;
            int s = 0;
            for (char ch : word) {
                int index = ch - '0';
                if (node->child[index] ==NULL) {
                    return s;
                }
                node = node->child[index];
                s++;
            }
            return s;
        }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* souvik = new Trie();
        for (int num : arr1) {
            souvik->insert(to_string(num));
        }
        int ans = 0;
        for (int num : arr2) {
            ans = max(ans, souvik->search(to_string(num)));
        }
        return ans;
    }
};
