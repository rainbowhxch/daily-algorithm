#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <stack>

using namespace std;

class Trie {
private:
    struct Node {
        char c;
        unordered_map<char, Node *> children;
        int end;
        Node(char c) {
            this->c = c;
            this->end = 0;
        }
    };
    Node *root;
    vector<string> words;

public:
    Trie() {
        root = new Node('0');
    }

    void set_words(vector<string> words) {
        this->words = words;
    }

    void insert(string word, int index) {
        Node *cur = root;
        for (auto c : word) {
			if (cur->children.find(c) == cur->children.end())
				cur->children[c] = new Node(c);
            cur = cur->children[c];
        }
        cur->end = index;
    }

    string bfs() {
        string ans = "";
        stack<Node *> s;
        s.push(root);
        while (!s.empty()) {
            Node *tmp = s.top();
            s.pop();
			cout << tmp->end << endl;
            if (tmp->end > 0 || tmp == root) {
                if (tmp != root) {
                    string word = words[tmp->end-1];
                    if (word.size() > ans.size()
                     || (word.size() == ans.size() && word < ans))
                        ans = word;
                }

				for (auto i : tmp->children) {
                    s.push(i.second);
					cout << i.first << endl;
				}
            }
        }

        return ans;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        int index = 0;
        for (auto w : words) {
            trie.insert(w, ++index);
        }

        trie.set_words(words);
        return trie.bfs();
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> v = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
	s.longestWord(v);

	return 0;
}
