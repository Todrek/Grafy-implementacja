#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define LL long long
#define SIZE(x) (int) x.size()
#define PB(x) push_back(x)

template<class E>
class Edge : public E
{
    private:
        int v;

    public:
        Edge(E e, int v) : E(e)
        {
            this->v = v;
        }

        int getV()
        {
            return this->v;
        }
};

template<class V, class E>
class Vertex : public V, public std::vector<Edge<E> >
{
    //
};

template<class V, class E>
class Graph
{
   private:
       std::vector<Vertex<V, E> > g;
       int t;

   public:
       Graph(int n = 0) : g(n)
       {
       }

       void edgeD(int b, int e, E d = E())
       {
           g[b].PB(Edge<E>(d, e));
       }

       int bfs(int s, int m)
       {
           int r = 0;

           for (auto it = g.begin(); it != g.end(); it++) {
               it->setT(-1);
               it->setS(-1);
           }

           g[s].setT(0);

           int qu[SIZE(g)], b = 0, e = 0;

           qu[0] = s;

           while (b <= e) {
               int k = qu[b++];

               for (auto it = g[k].begin(); it != g[k].end(); it++) {
                   if (g[it->getV()].getT() == -1) {
                       qu[++e] = it->getV();
                       g[it->getV()].setT(g[k].getT() + 1);
                       g[it->getV()].setS(k);
                   }

                   if (g[k].getS() == s && it->getV() == m) {
                       r++;
                   }
               }
           }

           return r;
       }
};

class Empty
{
};

class Ver
{
    private:
        int t, s;

    public:
        void setT(int t)
        {
            this->t = t;
        }

        int getT()
        {
            return this->t;
        }

        void setS(int s)
        {
            this->s = s;
        }

        int getS()
        {
            return this->s;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n, x;
    cin >> t;

    while (t --> 0) {
        cin >> n;

        Graph<Ver, Empty> g(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                cin >> x;

                if (x) {
                    g.edgeD(i, j);
                }
            }
        }

        bool err = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                cin >> x;

                if (g.bfs(i, j) != x) {
                    cout << "NIE\n";
                    err = true;
                    break;
                }
            }

            if (err) {
                break;
            }
        }

        if (!err) {
            cout << "TAK\n";
        }
    }

    return 0;
}
