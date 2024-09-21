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

        void insert(int n) {
            string s = to_string(n);
            TrieNode* node = root;

            for (int i = 0; i < s.size(); i++) {
                int index = s[i] - '0';
                
                if (node->child[index] == NULL) {
                    node->child[index] = new TrieNode();
                }

                node = node->child[index];
            }
        }

        void find(TrieNode* node, int currNumber, vector<int>& result) {
            if (!node) return;

            if (currNumber > 0) {
                result.push_back(currNumber);
            }

            for (int i = 0; i < 10; i++) {
                if (node->child[i]) {
                    find(node->child[i], currNumber * 10 + i, result);
                }
            }
        }
    };

    vector<int> lexicalOrder(int n) {
        Trie trie;
        for (int i = 1; i <= n; i++) {
            trie.insert(i);
        }
        vector<int> result;
        trie.find(trie.root, 0, result);
        return result;
    }
};
