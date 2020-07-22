//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//

#ifndef __MY_GRAPH_BASICS_H_
#define __MY_GRAPH_BASICS_H_
#include "../headers.h"
#include <string>
#include "../primitives/vector3d.h"
#include <vector>
using std::vector;

/*
GRAPH_NODE:
radius
position
its_id
its_edges'_ID
dynamicID->active arr -> index
*/
class GRAPH_NODE {
public:
    GRAPH_NODE( ) {
        r = 1.0;
        /********** Keep y zero **********/
        p = vector3(0.0, 0.0, 0.0);//(X,Y,Z)
    }
    vector3 p;  //position
    double r;   //radius    

    int id;     //unique ID
    int dynamicID; // in the active index array

    vector<int> edgeID;
    //
};

/*
GRAPH_EDGE:
its_id
dynamicID->active arr -> index
its connected node's id
*/
class GRAPH_EDGE {
public:
    int id;
    int dynamicID; 
    int nodeID[2];
};

#endif