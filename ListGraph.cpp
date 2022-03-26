//
// Created by kvitadmin on 24.03.2022.
//

#include "ListGraph.h"
#include <iostream>


ListGraph::ListGraph(){
    graph = new std::map<int, std::vector<int>>;
    maxVertexNumber = 0;
}

ListGraph::ListGraph(const ListGraph &lg) {
    graph = new std::map<int, std::vector<int>>;
    *graph = *(lg.graph);
    maxVertexNumber = lg.maxVertexNumber;
}

ListGraph& ListGraph::operator=(const ListGraph &lg) {
    if(this == &lg){
        return *this;
    }
    delete graph;
    graph = new std::map<int, std::vector<int>>;
    *graph = *(lg.graph);
    maxVertexNumber = lg.maxVertexNumber;
    return *this;
}
ListGraph::~ListGraph(){
    delete graph;
}

ListGraph::ListGraph(const IGraph& igraph){
    graph = new std::map<int, std::vector<int>>;
    std::vector<int> tmpVector;
    maxVertexNumber = igraph.VerticesCount();
    for(int i = 0; i < maxVertexNumber; ++i)
    {
        tmpVector.clear();
        igraph.GetNextVertices(i,tmpVector);
        graph->emplace(std::make_pair(i, tmpVector));
    }
}

int ListGraph::VerticesCount() const {
    return maxVertexNumber;
}

void ListGraph::AddEdge(int from, int to){
    if(from == to){
        std::cout << "Error! from = to!" << std::endl;
        return;
    }
    if(from > maxVertexNumber){
       maxVertexNumber = from + 1;
   }
    if(to > maxVertexNumber){
        maxVertexNumber = to + 1;
    }
   if(graph->find(from) != graph->end()){
       graph->at(from).emplace_back(to);
       return;
   }
   else

       graph->emplace(std::make_pair(from,std::vector<int>(1,to)));
}

void ListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const{
    if(graph->find(vertex) != graph->end()) {
        vertices = graph->at(vertex);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    std::map<int, std::vector<int>>::iterator it;
    for(it = graph->begin(); it != graph->end(); ++it){
        for(auto& el : it->second){
            if(el == vertex){
                vertices.emplace_back(it->first);
            }
        }
    }
}

void operator<< (std::ostream& os, ListGraph& lg){
    std::vector<int> tmpVector;
    for(int i = 0; i < lg.VerticesCount(); ++i) {
        tmpVector.clear();
        lg.GetNextVertices(i, tmpVector);
        if (!tmpVector.empty()){
            os << i << "---";
            for (auto &el: tmpVector) {
                os << el << " ";
            }
            os << std::endl;
        }
    }

}
