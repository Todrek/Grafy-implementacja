#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "Edge.h"

/**
 * Klasa Vertex
 *
 * @param class V Klasa z dodatkowymi informacjami o wierchołku
 * @param class E Klasa z dodatkowymi informacjami o krawędzi, po której dziedziczy Edge
 */
template<class V, class E>
class Vertex : V, public std::vector<Edge<E> >
{
    //
};

#endif // VERTEX_H