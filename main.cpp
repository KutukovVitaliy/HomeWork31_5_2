#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"

void operator<< (std::ostream& os, std::vector<int> vec){
    for(auto &el:vec){
        os << el << " ";
    }
    os << std::endl;
}

int main() {
   ListGraph list;
   std::vector<int> vec;
   list.AddEdge(0,5);
   list.AddEdge(0,7);
   list.AddEdge(1,5);
   list.AddEdge(1,3);
   list.AddEdge(2,7);
   list.AddEdge(2,0);
   list.AddEdge(7,1);
   list.AddEdge(7,4);
   std::cout << "ListGraph:" << std::endl;
   std::cout << list;
   std::cout << "GetPrev (5):" << std::endl;
   list.GetPrevVertices(5, vec);
   std::cout << vec;
   vec.clear();
    std::cout << "GetPrev (7):" << std::endl;
   list.GetPrevVertices(7, vec);
   std::cout << vec;
   std::cout << "Matrix Graph :" << std::endl;
   MatrixGraph mgraph(list);
   mgraph.AddEdge(0, 3);
   std::cout << mgraph;
   std::cout << "GetNext (0):" << std::endl;
   vec.clear();
   mgraph.GetNextVertices(0, vec);
   std::cout << vec;
   vec.clear();
   std::cout << "GetPrev (3):" << std::endl;
   mgraph.GetPrevVertices(3, vec);
    std::cout << vec;
    vec.clear();
    std::cout << "GetPrev (5):" << std::endl;
    mgraph.GetPrevVertices(5, vec);
    std::cout << vec;
    vec.clear();
    std::cout << "GetPrev (7):" << std::endl;
    mgraph.GetPrevVertices(7, vec);
    std::cout << vec;
    return 0;
}
