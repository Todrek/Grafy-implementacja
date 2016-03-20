#ifndef EDGE_H
#define EDGE_H

/**
 * Szablon klasy Edge
 *
 * @param class E Klasa z dodatkowymi informacjami o krawędzi
 */
template<class E>
class Edge : public E
{
    private:
        /** @var int v Nr wierzchołka, do którego prowadzi krawędź */
        int v;

    public:
        Edge(E e, int v) : E(e)
        {
            this->v = v;
        }

        //region Getters & Setters

        /**
         * Pobierz v
         *
         * @return int
         */
        int getV()
        {
            return this->v;
        }

        //endregion
};

#endif // EDGE_H
