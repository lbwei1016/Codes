#include <queue>
#include <vector>
#define QUEUE
#define VECTOR

// no error detection
class TopoIterator {
    public:
        // number of vertices and adjacency list of graph
        TopoIterator(int _v, std::vector<int> _graph[]) {
            iterator = 0;
            V = _v;
            G.resize(V);
            for (int i=0; i<V; ++i) {
                G[i] = _graph[i];
            }
            sort();
        }

        void sort() {
            std::queue<int> que;
            std::vector<int> indeg(V);

            for (auto &vec: G) {
                for (auto &u: vec) {
                    ++indeg[u];
                }
            }

            for (int u=0; u<V; ++u) {
                if (indeg[u] == 0) {
                    que.push(u);
                    sorted_seq.push_back(u);
                }
            }

            while (que.size()) {
                int v = que.front(); que.pop();
                for (auto &u: G[v]) {
                    if (--indeg[u] == 0) {
                        que.push(u);
                        sorted_seq.push_back(u);
                    }
                }
            }
        }
        // return the id of current node
        int at() const  {
            return sorted_seq[iterator];
        }
        // move forward for one step (cyclic)
        void advance() {
            (++iterator) %= V;
        }
        // return the whole sorted sequence
        std::vector<int> get_all() const {
            return sorted_seq;
        }

    private:
        int V, iterator;
        std::vector<std::vector<int> > G;
        std::vector<int> sorted_seq;
};