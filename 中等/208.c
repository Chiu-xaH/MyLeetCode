#define ALPHABET_SIZE 26

typedef struct Trie {
    bool isEnd;   
    struct Trie* children[ALPHABET_SIZE];
} Trie;


Trie* trieCreate() {
    Trie* node = (Trie*)malloc(sizeof(Trie));
    node->isEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void trieInsert(Trie* obj, char* word) {
    Trie* cur = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (cur->children[idx] == NULL) {
            cur->children[idx] = trieCreate();
        }
        cur = cur->children[idx];
    }
    cur->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* cur = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (cur->children[idx] == NULL) {
            return false;
        }
        cur = cur->children[idx];
    }
    return cur->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* cur = obj;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int idx = prefix[i] - 'a';
        if (cur->children[idx] == NULL) {
            return false;
        }
        cur = cur->children[idx];
    }
    return true;
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        trieFree(obj->children[i]);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/