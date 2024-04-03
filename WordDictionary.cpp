#include <unordered_map>
#include <string>

class Node {
public:
    unordered_map<char, Node*> children;
    bool isEnd = false;
};

class WordDictionary {
private:
    Node *root;

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node *current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new Node();
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        return searchHelper(root, 0, word);
    }

    bool searchHelper(Node *current, int i, string word){
        if (i == word.size()) {
            return current->isEnd;
        }

        else if (word[i] == '.') {
            for (const auto& pair : current->children) {
                if (searchHelper(pair.second, i+1, word)) {
                    return true;
                }
            }
            return false;
        }

        else if (current->children.find(word[i]) == current->children.end()) {
            return false;
        }

        return searchHelper(current->children[word[i]], i+1, word);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
