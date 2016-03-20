#ifndef GRAPTH_H
#define GRAPTH_H

#include <vector>

#include "Vertex.h"
#include "Edge.h"

/**
 * Klasa Grapth
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
        void edgeD(int b, int e, E d)
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
        void edgeU(int b, int e, E d)
        {
            g[b].PB(Edge<E>(d, e));
            g[e].PB(Edge<E>(d, b));
        }
};

#endif // GRAPTH_H
