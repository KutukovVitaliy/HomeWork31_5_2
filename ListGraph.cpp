//
// Created by kvitadmin on 24.03.2022.
//

#include "ListGraph.h"
#include <iostream>


ListGraph::ListGraph(){
    graph = new std::vector<std::vector<int>>;
}

ListGraph::ListGraph(const ListGraph &lg) {
    graph = new std::vector<std::vector<int>>;
    *graph = *(lg.graph);
}

ListGraph& ListGraph::operator=(const ListGraph &lg) {
    if(this == &lg){
        return *this;
    }
    delete graph;
    graph = new std::vector<std::vector<int>>;
    *graph = *(lg.graph);
    return *this;
}
ListGraph::~ListGraph(){
    delete graph;
}

ListGraph::ListGraph(const IGraph& igraph){
    std::vector<int> tmpVector;
    for(int i = 0; i < igraph.VerticesCount(); ++i)
    {
        tmpVector.clear();
        igraph.GetNextVertices(i,tmpVector);
        graph->emplace_back(tmpVector);
    }
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(graph->size());
}

void ListGraph::AddEdge(int from, int to){
   if(from > graph->size()){
       std::cout << "Error!. Vertex number(from) too long!" << std::endl;
       return;
   }
   else if(from == graph->size()){
       std::vector<int> tmpVector{to};
       graph->emplace_back(tmpVector);
       return;
   }
   else
    graph->at(from).push_back(to);
}

void ListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const{
    vertices = graph->at(vertex);
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    std::vector<int> tmpVector;
    for(int i = 0; i < graph->size(); ++i){
        for(int j = 0; j < graph->at(i).size(); ++j){
            if(graph->at(i).at(j) == vertex){
                vertices.emplace_back(i);
            }
        }
    }
}

void operator<< (std::ostream& os, ListGraph& lg){
    std::vector<int> tmpVector;
    for(int i = 0; i < lg.VerticesCount(); ++i){
        tmpVector.clear();
        lg.GetNextVertices(i, tmpVector);
        for(auto& el : tmpVector){
            os << el << " ";
        }
        os << std::endl;
    }

}
