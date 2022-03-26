//
// Created by kvitadmin on 24.03.2022.
//

#include "MatrixGraph.h"
#include <algorithm>
#include <iostream>

MatrixGraph::MatrixGraph() {
    graph = new std::vector<std::vector<int>>;
}

MatrixGraph::MatrixGraph(const MatrixGraph &mg) {
    graph = new std::vector<std::vector<int>>;
    *graph = *(mg.graph);
}

MatrixGraph::~MatrixGraph() noexcept {
    delete graph;
}

MatrixGraph& MatrixGraph::operator=(const MatrixGraph &mg) {
    if(this == &mg){
        return  *this;
    }
    delete graph;
    graph = new std::vector<std::vector<int>>;
    *graph = *(mg.graph);
    return *this;
}

MatrixGraph::MatrixGraph(const IGraph &igraph) {
    std::vector<int> tmpVector;
    graph = new std::vector<std::vector<int>>;
    for(int i = 0; i < igraph.VerticesCount(); ++i){
        graph->emplace_back(std::vector<int>(igraph.VerticesCount(), 0));
    }
    for(int i = 0; i < igraph.VerticesCount(); ++i)
    {
        tmpVector.clear();
        igraph.GetNextVertices(i,tmpVector);
        for(int j = 0; j < igraph.VerticesCount(); ++j){
            if(i == j){
                graph->at(i).at(j) = 0;
            }
            else{
                if(std::find(tmpVector.begin(), tmpVector.end(), j) != tmpVector.end()){
                    graph->at(i).at(j) = 1;
                }
                else{
                    graph->at(i).at(j) = 0;
                }
            }
        }
    }
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(graph->size());
}

void MatrixGraph::AddEdge(int from, int to) {
    if(from > graph->size() || to > graph->size()){
        std::cout << "Error!. Vertex number(from) too long!" << std::endl;
        return;
    }
    else if(from == to){
        std::cout << "Error! from = to!" << std::endl;
        return;
    }
    else if(from == graph->size() || to == graph->size()){
        std::vector<int> tmpVector(graph->size() + 1, 0);
        graph->emplace_back(tmpVector);
        graph->at(from).at(to) = 1;
    }
    else{
        graph->at(from).at(to) = 1;
    }
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    for(int i = 0; i < graph->size(); ++i){
        if(graph->at(vertex).at(i) == 1){
            vertices.emplace_back(i);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    for(int i = 0; i < graph->size(); ++i){
        if(graph->at(i).at(vertex) == 1){
            vertices.emplace_back(i);
        }
    }
}

void operator<< (std::ostream& os, MatrixGraph& mg){

    for(auto& vc : *(mg.graph)){
        for(auto& el : vc ){
            os << el << " ";
        }
        os << std::endl;
    }

}