
#ifndef GRAPTH_H
#define GRAPTH_H

#include <vector>
#include "Vertex.h"
#include "Edge.h"

/**
 * Szablon klasy MatrixGraph
 *
 * @param V Klasa z dodatkowymi informacjami o wierchołku, po której dziedziczy Vertex
 * @param E Klasa z dodatkowymi informacjami o krawędzi, po której dziedziczy Edge
 */
template<class V, class E>
class MatrixGraph
{
    private:
        /** @var g Wektor wierzchołków */
        vector<Vertex<V, E> > v;
        vector<vector<Edge<E > > > g;

        /** @var t Pamiętania aktualnego czasu przetwarzania przy dfs */
        int t;

        /**
         * Przeszukiwanie grafu w głąb, rekurencja
         *
         * @param v
         */
         /*
        void dfsR(int v)
        {
            g[v].setD(++this->t);

            for (auto it = g[v].begin(); it != g[v].end(); it++) {
                if (g[it->getV()].getS() == -1) {
                    g[it->getV()].setS(v);

                    this->dfsR(it->getV());
                }
            }

            g[v].setF(++this->t);
        }*/

    public:
        MatrixGraph(int n = 0) : g(n, vector<Edge<E > >(n)), v(n)
        {
        }

        /**
         * Dodawanie krawędzi skierowanej
         *
         * @param b
         * @param e
         * @param d
         */
        void edgeD(int b, int e, E d = E())
        {
            g[b][e].=Edge<E>(d, e);
        }
         /**
         * Dodawanie wierzcholka
         *
         * @param b
         * @param v
         */
        void vertice(int b, V vertice)
        {
           v[b] = vertice;
        }
        /**
         * Dodawanie krawędzi nieskierowanej
         *
         * @param b
         * @param e
         * @param d
         */
        void edgeU(int b, int e, E d = E())
        {
            g[b][e].=Edge<E>(d, e);
            g[e][b].=Edge<E>(d, b);
        }

        /**
         * Przeszukiwanie grafu wszerz.
         *
         * Wierzchołek musi zawierać dodatkowe informacje:\n
         * int t - odległość wierzchołka od źródła wyszukiwania\n
         * int s - nr wierzchołka, z którego prowadzi znaleziona, najkrótsza trasa
         *
         * @param s
         */
        void bfs(int s)
        {
            for (auto it = g.begin(); it != g.end(); it++) {
                it->setT(-1);
                it->setS(-1);
            }

            g[s].setT(0);

            int qu[SIZE(g)], b, e;

            qu[b = e = 0] = s;

            while (b <= e) {
                s = qu[b++];

                for (auto it = g[s].begin(); it != g[s].end(); it++) {
                    if (g[it->getV()].getT() == -1) {
                        g[qu[++e] = it->getV()].setT(g[s].getT() + 1);
                        g[it->getV()].setS(s);
                    }
                }
            }
        }

        /**
         * Przeszukiwanie grafu w głąb
         *
         * Wierzchołek musi zawierać dodatkowe informacje:\n
         * int d - czas wejścia do wierzchołka\n
         * int f - czas wyjścia z wierzchołka\n
         * int s - nr wierzchołka, z którego prowadzi znaleziona, najkrótsza trasa
         *
         * @param e
         */
        void dfs(int e = -1)
        {
            this->t = -1;

            int b = 0;

            e == -1 ? e = SIZE(this->g) - 1 : b = e;

            for (int x = 0; x < SIZE(this->g); x++) {
                this->g[x].setD(-1);
                this->g[x].setF(-1);
                this->g[x].setS(-1);
            }

            for (int x = b; x <= e; x++) {
                if (this->g[x].getS() == -1) {
                    this->dfsR(x);
                }
            }
        }

        //region Getters & Setters

        /**
         * Pobierz g
         *
         * @return std::vector<Vertex<V, E>>
         */
        std::vector<Vertex<V, E> > getG()
        {
            return this->g;
        }

        //endregion
};

#endif // GRAPTH_H
