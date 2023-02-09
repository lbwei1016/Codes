/*
***String*** -- Aho–Corasick algorithm
    Description:
        Given a text "t" and 'n' strings "si", each with a value "ki".
        For each 'i', output the length of the shortest substring of "t" such that 
        "si" is matched exactly "ki" times; if this is impossible, output -1.
    Solution:
        We can solve the easier problem first:
            Given a text "t" and 'n' strings "si". 
            For each 'i', output the number of times that "si" is matched in "t".
        Then, we only need to record the position of each match for every string ("pos[]"). 
        With this information, we can calculate the aksed minimum length. (The last
        'for' loop.)
---------------------------------------------------------------------------------------------------------------
AC algorithm:
    Capability:
        Match multiple strings, say "s1' to "sn", with "a target text 't'" efficiently (simultaneously).
    Details:
        To begin with, build a "trie" with the given 'n' strings (The trie is built from the 'n' strings, not
        the target text!). Before going further, let's first make some definitions.

        Definition (suffix link):
            The suffix link of a node "v" points to a node "u" such that "v" and "u"
            has the longest common suffix, where "v" != "u".

        Definition (nodes' attributes):
            - v.link: The node pointed by "v's" suffix link. 
            - v.next[c]: If the transition of "c" is feasible at "v", "v.next[c] = u", otherwise -1.
            - v.trans[c]: The actual transition of "c" at "v". (to be elaborated more later).
        
        We can see that if "v.next[c] != -1", then "v.trans[c] == v.next[c]". What if "v.next[c] == -1"? Once
        a further matching is not possible, we should go back to a state that has the most potential for future
        matchings, i.e., the one pointed by the suffix link of "v"! This way, the loss of characters is 
        minimized since the common suffix is the longest. Thus, "v.trans[c] = v.link.trans[c]". Here comes the
        question: How to efficiently compute all suffix links? Suppose "v.link" is known, then for "u = v.trans[c]",
        "u.link" is simply "v.link.trans[c]"! Since the depth of "u" must be greater than "v", "v.link" must 
        have been calculated before "u.link", through BFS; moreover, the depth of "v" must also be greater 
        than "v.link". Hence, if we let the links of the root and all of its descendant point to root, as a starting
        point, by induction, we can compute all the suffix links in linear time. To sum up:
            - v.trans[c] = v.next[c],       if "v.next[c] != -1",
                         = v.link.trans[c], if "v.next[c] == -1".
            - u.link     = v.link.trans[c], where "u = v.trans[c] != -1".
        
        There is a problem remaining. Suppose we are at "v". No matter "v" is a match or not, the substrings of
        "v" may be matched. Thus we need to jump through suffix links until the root is reached, examining whether a
        match exists for each jump. This takes total O(n * |t|) time, where 'n' is the number of nodes. To improve, 
        we let "v.exit_link" point to the matched node nearest to "v". Jumping through exit links only takes
        O(|t| + |ans|), where "|ans|" is the total number of successful matches.

        The procedure of mathcing is as follows:
            [0.] Set the current state "v" at the root of the trie.
            [1.] Read in a character from "t", which is 'c'. If 'c' is '\0', terminate.
            [2.] Transition to "v.trans[c]". 
            [3.] Jump through exit links until root is reached. If "v.id = -1", a string is matched.
            [4.] Go to [1.].
    Complexity analysis:
        Space: O(|∑| * n)
        Time: 
            add_string(): O(sum of |si|)
            construct(): O(|∑| * n)
            match() + exit_link(): O(|t| + |ans|)
        (n: number of nodes; ∑: alphabet set)
    Reference:
        https://cp-algorithms.com/string/aho_corasick.html#find-all-strings-from-a-given-set-in-a-text
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 26; // size of alphabet
struct Node {
    int next[K]; // whether there is a child (if no, "next[i] = -1")
    int link = -1; // the proper suffix link (to the string with whom has the longest common suffix, excluding itself)
    int exit_link = -1; // link to the nearest matched string
    int trans[K]; // actual transition (if not computed yet, "trans[i] = -1")
    int id = -1; // if "id" != -1, then the current node is the string numbered "id"

    Node() {
        memset(next, -1, sizeof(next));
        memset(trans, -1, sizeof(trans));
    }
};

vector<Node> tr(1);

int n;
string text, str[N];
vector<int> ask(N);
vector<int> pos[N]; // positions of the last character of matched strings

void add_string(const string &s, int id) {
    int v = 0;
    for (char ch: s) {
        int c = ch - 'a';
        if (tr[v].next[c] == -1) {
            tr[v].next[c] = tr.size();
            tr[v].trans[c] = tr[v].next[c];
            tr.emplace_back();
        }
        v = tr[v].next[c];
    }
    tr[v].id = id;
}

void construct() {
    queue<int> que;
    que.push(0);
    tr[0].link = 0;
    for (int i = 0; i < K; ++i) {
        if (tr[0].trans[i] == -1) 
            tr[0].trans[i] = 0;
    }
    while (que.size()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < K; ++i) {
            int u = tr[v].next[i];
            if (u == -1) 
                tr[v].trans[i] = tr[tr[v].link].trans[i];
            else {
                if (v == 0) tr[u].link = 0;
                else
                    tr[u].link = tr[tr[v].link].trans[i];
                que.push(u);
            }
        }
    }
}

// exit link
int exit_link(int v, int at) {
    if (v == 0) return 0;
    if (tr[v].exit_link != -1) 
        exit_link(tr[v].exit_link, at);
    else 
        tr[v].exit_link = exit_link(tr[v].link, at);
    int id = tr[v].id;
    if (id != -1) {
        pos[id].push_back(at);
        return v;
    }
    else return tr[v].exit_link;
}

void match() {
    int v = 0;
    for (int i = 0; i < text.size(); ++i) {
        int c = text[i] - 'a';
        int to = tr[v].trans[c];
        exit_link(to, i);
        v = to;
    }
}

int main() {
    cin >> text >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ask[i] >> str[i];
        add_string(str[i], i);
    }
    construct();
    match();
    for (int i = 0; i < n; ++i) {
        if (pos[i].size() < ask[i]) {
            cout << "-1\n";
            continue;
        }

        int len = 1e9 + 7;
        auto st = pos[i].begin(), ed = pos[i].begin() + ask[i] - 1;
        while (ed != pos[i].end()) {
            len = min(len, int(*ed - *st + str[i].size()));
            st++; ed++;
        }
        cout << len << '\n';
    }
    return 0;
}