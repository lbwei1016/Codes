/*
***Trie*** (見 ./Algorithm/String/ac-algorithm.cpp)
    Description:
        每個節點皆儲存一整個字元集，若兩字串有相同的前綴，則他們擁有部分的共同祖先。
        類似於編排字典的方式，減低了檢索單字的困難度。 Trie 可以想作是多層次的索引表。
        優點是速度飛快，缺點是耗費記憶體。
    空間複雜度：O(|∑| x ∑L)；|∑|：字元集大小，L：字串長度
    增加、刪除字串時間複雜度：O(L)
*/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *alp[26]; // 字元集，26 為字元集大小
    int id; 

    TrieNode() {
        memset(alp, 0, sizeof(alp));
        id = 0;
    }
    // 新增
    void add(char *s, TrieNode *root, int cnt) {
        TrieNode *p = root;
        for(int t; *s; ++s) {
            t = *s-'a';
            // 不斷向下開拓節點
            if(!p->alp[t]) p->alp[t] = new TrieNode();
            p = p->alp[t];
        }
        p->id = cnt; // 字串尾
    }
    // 查詢
    int query(char *s, TrieNode *root) {
        TrieNode *p = root;
        for(int t; *s; ++s) {
            t = *s - 'a'; 
            // 在當前位置並沒有這個字元
            if(!p->alp[t]) return -1;
            p = p->alp[t];
        }
        // 若 id = 0，代表該字串未獨立出現過，只是某字串的子字串
        if(p->id) return p->id;
        else return -1;
    }
    // 移除指定字串
    int remove(char *s, TrieNode *root) {
        TrieNode *p = root;
        for(int t; *s; ++s) {
            t = *s - 'a';
            if(!p->alp[t]) return -1;
            p = p->alp[t];
        }
        if(p->id) {
            p->id = 0;
            return 1;
        }
        return -1;
    }
    // 遞迴釋出空間
    void clear(TrieNode *p) {
        for(int i=0; i<26; ++i) {
            if(p->alp[i])
                clear(p->alp[i]);
        }
        delete p;
    }
    // 逐一印出所有字串 (lexicographically)
    void traverse(TrieNode *p, char *s, int d) {
        if(p->id) {
            printf("no: %d -- %s\n", p->id, s-d);
            return;
        }
        for(int i=0; i<26; ++i) {
            if(p->alp[i]) {
                *s = i + 'a';
                traverse(p->alp[i], s+1, d+1);
            }
        }
    }
};

int main() {
    char s[25];
    int n, cnt, op;
    printf("How many strings?\n");
    while(scanf("%d", &n) == 1) {
        if(!n) break;
        cnt = 1;
        TrieNode *root = new TrieNode();
        while(n--) {
            printf("Input a string and an action:\n");
            scanf("%s%d", s, &op);
            if(op == 1) {
                int stat = root->remove(s, root);
                if(stat < 0) puts("Not found!");
                else puts("Removed successfully!");
                continue;
            }
            int q = root->query(s, root);
            // 找不到該字串
            if(q < 0) {
                // 加入
                root->add(s, root, cnt);
                printf("New! %d\n", cnt++);
            }
            else printf("Old! %d\n", q); // 曾經在第幾順位出現過
        }
        char tmp[25] = {0};
        root->traverse(root, tmp, 0);
        // 清空記憶體 !!!
        root->clear(root);
        printf("How many strings?\n");
    }
    return 0;
}