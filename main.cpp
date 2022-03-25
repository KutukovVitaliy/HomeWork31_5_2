#include <iostream>
#include "ListGraph.h"

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
   list.AddEdge(1,1);
   list.AddEdge(2,7);
   list.AddEdge(2,0);
   std::cout << list;
   list.GetPrevVertices(5, vec);
   std::cout << vec;
   vec.clear();
   list.GetPrevVertices(7, vec);
   std::cout << vec;
    return 0;
}
