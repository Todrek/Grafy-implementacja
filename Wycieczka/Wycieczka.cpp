#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../Graph.h"

#define LL long long
#define SIZE(x) (int) x.size()
#define PB(x) push_back(x)

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

        // ...

        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                cin >> x;

                // ...
            }
        }
    }

    return 0;
}
