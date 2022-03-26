//
// Created by kvitadmin on 24.03.2022.
//

#ifndef HOMEWORK31_5_2_LISTGRAPH_H
#define HOMEWORK31_5_2_LISTGRAPH_H

#include "IGraph.h"
#include <vector>
#include <ostream>
#include <map>

class ListGraph : public IGraph{
private:
    std::map<int, std::vector<int>> *graph;
    int maxVertexNumber;
public:
    ListGraph();
    ListGraph(const ListGraph& lg);
    ListGraph& operator= (const ListGraph& lg);
    ~ListGraph() override;
    explicit ListGraph(const IGraph& igraph);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override ;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override ;

};

void operator<< (std::ostream& os, ListGraph& lg);


#endif //HOMEWORK31_5_2_LISTGRAPH_H
