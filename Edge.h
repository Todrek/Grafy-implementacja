#ifndef EDGE_H
#define EDGE_H

/**
 * Szablon klasy Edge
 *
 * @param class E Klasa z dodatkowymi informacjami o krawędzi
 */
template<class E>
class Edge : E
{
    private:
        /** @var int v Nr wierzchołka, od którego prowadzi krawędź */
        int v;

    public:
        Edge(E e, int v) : E(e)
        {
            this->v = v;
        }
};

#endif // EDGE_H
