#include <iostream>
#include <vector>
#include <string>
#include "Destination.h"
#include "Destination.cpp"

using namespace std;


int main(int argc, char *argv[]) {
    string file1In, file2In, file3In;
    file1In=argv[1];
    file2In=argv[2];
    file3In=argv[3];
    string filesIn[3];
    filesIn[0]=file1In;
    filesIn[1]=file2In;
    filesIn[2]=file3In;
    char const * starChar = "\u2605";
    CityNetwork g(filesIn);
    if(filesIn==nullptr) return -1;
    g.displayEdges();
    return 0;
}




/* g.addCity("Boulder");
    g.addCity("Denver");
    g.addCity("New Mexico");
    g.addCity("Texas");
    g.addCity("New Orleans");
    //edge written to be undirected
    g.addEdge("Boulder", "Denver", 30);
    g.addEdge("Boulder", "New Mexico", 200);
    g.addEdge("Boulder", "Texas", 500);
    g.addEdge("Denver", "Texas", 300);
    g.addEdge("Texas", "New Orleans", 500);
*/