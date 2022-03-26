//
// Created by kvitadmin on 24.03.2022.
//

#ifndef HOMEWORK31_5_2_MATRIXGRAPH_H
#define HOMEWORK31_5_2_MATRIXGRAPH_H
#include <vector>
#include "IGraph.h"
#include <ostream>

class MatrixGraph : public IGraph {
private:
    std::vector<std::vector<int>> *graph;
public:
    MatrixGraph();
    MatrixGraph(const MatrixGraph& mg);
    ~MatrixGraph() override;
    MatrixGraph& operator= (const MatrixGraph& mg);
    explicit MatrixGraph(const IGraph& igraph);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    friend void operator<< (std::ostream& os, MatrixGraph& mg);
};



#endif //HOMEWORK31_5_2_MATRIXGRAPH_H
