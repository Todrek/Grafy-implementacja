#ifndef GRAPTH_H
#define GRAPTH_H

#include <vector>

#include "Vertex.h"
#include "Edge.h"

/**
 * Szablon klasy Grapth
 *
 * @param class V Klasa z dodatkowymi informacjami o wierchołku, po której dziedziczy Vertex
 * @param class E Klasa z dodatkowymi informacjami o krawędzi, po której dziedziczy Edge
 */
template<class V, class E>
class Grapth
{
    private:
        /** @var std::vector<Vertex<V, E> > g Wektor wierzchołków */
        std::vector<Vertex<V, E> > g;

    public:
        Grapth(int n = 0) : g(n)
        {
        }

        /**
         * Dodawanie krawędzi skierowanej
         *
         * @param int b
         * @param int e
         * @param E d
         */
        void edgeD(int b, int e, E d = E())
        {
            g[b].PB(Edge<E>(d, e));
        }

        /**
         * Dodawanie krawędzi nieskierowanej
         *
         * @param int b
         * @param int e
         * @param E d
         */
        void edgeU(int b, int e, E d = E())
        {
            g[b].PB(Edge<E>(d, e));
            g[e].PB(Edge<E>(d, b));
        }

        /**
         * Przeszukiwanie grafu wszerz.
         *
         * Wierzchołek musi zawierać dodatkowe informacje:\n
         * int t - odległość wierzchołka od źródła wyszukiwania\n
         * int s - nr wierzchołka, z którego prowadzi znaleziona, najkrótsza trasa
         *
         * @param int s
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
