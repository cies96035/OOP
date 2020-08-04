//********************************************
// Student Name			:�B�ú�
// Student ID			:109511015
// Student Email Address:cies96035.eed09@nctu.edu.tw
//********************************************
//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/04/09
//
#include <iostream>
#include <fstream>
#include "mySystem_GraphSystem.h"
#include <time.h>

using namespace std;

#define GRAPH_FILE_NAME "graph.txt"


//pdf p.4 MAX=1000,1000
int Param::GRAPH_MAX_NUM_NODES = 1000;
int Param::GRAPH_MAX_NUM_EDGES = 1000;
int Param::Export_Count_DrawingFX = 300;

GRAPH_SYSTEM::GRAPH_SYSTEM( )
{
    mFlgAutoNodeDeletion = false;
    mExport_Count_DrawingFX = 0;

    initMemoryPool();
    createDefaultGraph();
}

void GRAPH_SYSTEM::initMemoryPool( )
{
    mMaxNumNodes = Param::GRAPH_MAX_NUM_NODES;
    mMaxNumEdges = Param::GRAPH_MAX_NUM_EDGES;

    mNodeArr_Pool = new GRAPH_NODE[mMaxNumNodes];
    mEdgeArr_Pool = new GRAPH_EDGE[mMaxNumEdges];

    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;
    mActiveNodeArr = new int[mMaxNumNodes];
    mActiveEdgeArr = new int[mMaxNumEdges];

    mFreeNodeArr = new int[mMaxNumNodes];
    mFreeEdgeArr = new int[mMaxNumEdges];
    //
    for ( int i = 0; i < mMaxNumNodes; ++i ) {
        mNodeArr_Pool[ i ].id = i;
    }
    for ( int i = 0; i < mMaxNumEdges; ++i ) {
        mEdgeArr_Pool[ i ].id = i;
    }
    //
    reset( );
}

void GRAPH_SYSTEM::reset( )
{
	/*ignore
    /****************************unknow****************************/
    stopAutoNodeDeletion();
    /****************************unknow****************************/

    //mNumPoints_DoubleCircles = 0;

    //How many Nodes/Edges used
    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;

    //How many Nodes/Edges left
    mCurNumOfFreeNodes = mMaxNumNodes;
    mCurNumOfFreeEdges = mMaxNumEdges;

	//set index unique id which isnt used
    for ( int i = 0; i < mCurNumOfFreeNodes; ++i ) {
        mFreeNodeArr[ i ] = i;
    }
    for ( int i = 0; i < mCurNumOfFreeEdges; ++i ) {
        mFreeEdgeArr[ i ] = i;
    }

    /****************************unknow****************************/
    mPassiveSelectedNode = 0;
    mSelectedNode = 0;
    /****************************unknow****************************/
}


/*
<-----get free node from pool----->
get pool's id
return NODE = pool+id
give a dynamic id to NODE
connected edge id(vector) .clear()
pos=0,0,0
r=1
*/
GRAPH_NODE *GRAPH_SYSTEM::getFreeNode( ) 
{
    //isnt any nodes left
    if ( mCurNumOfFreeNodes == 0 ) return NULL;// --> addNOde return -1

    //else
    --mCurNumOfFreeNodes;//use one

    //get unique id
    int id = mFreeNodeArr[ mCurNumOfFreeNodes];

	//use id to get a DRAPH_NODE
    GRAPH_NODE *n = &mNodeArr_Pool[ id ];

	//a NODE is active
	mActiveNodeArr[ mCurNumOfActiveNodes ] = id;

	//get dynamic id
    n->dynamicID = mCurNumOfActiveNodes;
	
	//add Active
    ++mCurNumOfActiveNodes;
    return n;
}
//^
//| similar
//V
GRAPH_EDGE *GRAPH_SYSTEM::getFreeEdge( )
{
    //isnt any nodes left
    if ( mCurNumOfFreeEdges == 0 ) return 0;

    //else
    --mCurNumOfFreeEdges;//use one

    int id = mFreeEdgeArr[ mCurNumOfFreeEdges ];
	
	//get GRAPH_NODE with POOL
    GRAPH_EDGE *e = &mEdgeArr_Pool[ id ];

	//get dynamic id
    e->dynamicID = mCurNumOfActiveEdges;

	//add Active
    ++mCurNumOfActiveEdges;
    return e;
}


//Default Graph (option 1)
void GRAPH_SYSTEM::createDefaultGraph( )
{
    cout << "here"<< endl;
    reset( );

    int n_0 = addNode( 0.0, 0.0, 0.0 );
    cout << "n_0:"<< n_0 << endl;

    int n_1 = addNode( 5.0, 0.0, 0.0 );
    cout << "n_1:"<< n_1 << endl;

    int n_2 = addNode( 0.0, 0.0, 5.0 );
    cout << "n_2:"<< n_2 << endl;

    addEdge( n_0, n_2 );
    addEdge( n_1, n_2 );
}

void GRAPH_SYSTEM::createNet_Horizontal( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    vector<int> id;
}

void GRAPH_SYSTEM::createNet_Vertical( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    vector<int> id;
}

void GRAPH_SYSTEM::createRandomGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;

}

void GRAPH_SYSTEM::createRadialGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;

}

void GRAPH_SYSTEM::createRandomGraph_DoubleCircles(int n)
{
    reset( );

    //n = 36;
    float dx = 5.0;
    float dz = 5.0;
    float r = 15; // radius
    float d = 10; // layer distance
    float offset_x = 15.;
    float offset_z = 15.;

    vector<int> id;
}

void GRAPH_SYSTEM::createNet_Circular( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 15.;
    float offset_z = 15.;
    vector<int> id;
    id.resize( n*(num_layers+1) );
}
void GRAPH_SYSTEM::createNet_Square( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 5.;
    float offset_z = 5.;
}
void GRAPH_SYSTEM::createNet_RadialCircular( int n ) {

    reset( );

    float offset_x = 15.0;
    float offset_z = 15.0;

    float r = 15; // radius
}


/****Add a node and return the id of the node****/
//int GRAPH_SYSTEM::addNode( float x, float y, float z, float r )
int GRAPH_SYSTEM::addNode( float x, float y, float z, float r )
{
    GRAPH_NODE *g = getFreeNode();
	if( g==NULL ) return -1;
	g->p = vector3(x,y,z);
	g->r = r;
	g->edgeID.clear();//initial
	return g->id;
}

/****Add an edge and return the id of an edge****/
int GRAPH_SYSTEM::addEdge( int nodeID_0, int nodeID_1 )//pass by unique id
{
    GRAPH_EDGE *h = getFreeEdge();
	if( h==NULL ) return -1;
	h->nodeID[0]=nodeID_0;
	h->nodeID[1]=nodeID_1;
	//each node add a new Edge
	mNodeArr_Pool[ nodeID_0 ].edgeID.emplace_back( h->id );
	mNodeArr_Pool[ nodeID_1 ].edgeID.emplace_back( h->id );
	return h->id;
}

void GRAPH_SYSTEM::askForInput( )
{
    cout << "GRAPH_SYSTEM" << endl;
    cout << "Key usage:" << endl;
    cout << "1: create a default graph" << endl;
    cout << "2: create a graph with 10x10 nodes. Connect the consecutive nodes horizontally" << endl;
    cout << "3: create a graph with 10x10 nodes. Connect the consecutive nodes vertically" << endl;
    cout << "4: create a graph with 10x10 nodes. Create 10 randomly generated edges" << endl;
    cout << "5: create a graph with 10x10 nodes. Create 10 randomly generated edges attached at a random node" << endl;
    cout << "Delete: delete a node and all the edges attached at it" << endl;
    cout << "Spacebar: unselect the selected node" << endl;
    cout << " " << endl;
    cout << "Use the mouse to select nodes and add edges" << endl;
    cout << "Click the left button to select/unselect or create an edge" << endl;
    cout << " " << endl;
    cout << "A selected node is highlighted as red." << endl;

}

GRAPH_NODE *GRAPH_SYSTEM::findNearestNode( double x, double z, double &cur_distance2 ) const
{
    GRAPH_NODE *n = 0;
    cur_distance2 = 2e18;//INF
    for ( int i = 0; i < mCurNumOfActiveNodes; ++i ) {
        //double detx=this->x-x;
        //double detz=this->z-z;
        //if( detx*detx + detz*detz < cur_distance2)
        //{/*update n*/}
    }
    return n;
}

void GRAPH_SYSTEM::clickAt(double x, double z)
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) {
        mSelectedNode = 0;
        return;
    }
    if ( cur_d2 > n->r*n->r ) {
        mSelectedNode = 0;
        return;

    }
    if ( mSelectedNode == n ) {
        mSelectedNode = 0;
        return;
    }
    if ( mSelectedNode != 0 ) {
        addEdge( mSelectedNode->id, n->id );
        mSelectedNode = 0;
        return;
    }
    mSelectedNode = n;
}

void GRAPH_SYSTEM::deleteEdge( int edgeID )
{
    GRAPH_EDGE *e = &mEdgeArr_Pool[ edgeID ];
    int dynamicID = e->dynamicID; 
	
	//update Active
	mCurNumOfActiveEdges--;
	swap(mActiveEdgeArr[edgeID],mActiveEdgeArr[ mCurNumOfActiveEdges]);

	//update Pool
	mEdgeArr_Pool[ mCurNumOfActiveEdges ].dynamicID = dynamicID;
	
	//update Free
	swap(mFreeEdgeArr[ e->id ],mFreeEdgeArr[ mCurNumOfFreeEdges ]);
	mCurNumOfFreeEdges++;

}

void GRAPH_SYSTEM::removeEdgeFromNode( const GRAPH_EDGE *e, int nodeID )
{
    GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
    int j = 0;
}
void GRAPH_SYSTEM::deleteEdgesOfNode( int nodeID )
{
    GRAPH_NODE *n  = &mNodeArr_Pool[ nodeID ];
}

void GRAPH_SYSTEM::deleteNode( int nodeID ) {
    if ( mCurNumOfActiveNodes <= 0 ) return;//no node can delete
    GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
    int dynamicID = n->dynamicID;

}

void GRAPH_SYSTEM::deleteSelectedNode(  ) {
    if ( mSelectedNode == 0 ) return;
    deleteNode( mSelectedNode->id );
    deleteEdgesOfNode( mSelectedNode->id );
    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

bool GRAPH_SYSTEM::isSelectedNode( ) const
{
    return mSelectedNode != 0;
}

void GRAPH_SYSTEM::getInfoOfSelectedPoint( double &r, vector3 &p ) const
{
    if ( isSelectedNode( ) == false ) return;
    r = mSelectedNode->r;
    p = mSelectedNode->p;

}



void GRAPH_SYSTEM::handleKeyPressedEvent( unsigned char key )
{
    
    switch( key ) {
    case 127: // delete
        mFlgAutoNodeDeletion = false;
        deleteSelectedNode( );
        break;
    case '1':
        mFlgAutoNodeDeletion = false;
        createDefaultGraph( );
        mSelectedNode = 0;
        break;
    case '2':
        mFlgAutoNodeDeletion = false;
        createNet_Circular(12, 3);
        mSelectedNode = 0;

        break;
    case '3':
        mFlgAutoNodeDeletion = false;
        createNet_Square(15, 4);
        mSelectedNode = 0;

        break;
    case '4':
        mFlgAutoNodeDeletion = false;
        createNet_RadialCircular(24);
        mSelectedNode = 0;

        break;
    case '5':
        mNumPoints_DoubleCircles = 24;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case '<':
        mNumPoints_DoubleCircles--;
        if (mNumPoints_DoubleCircles<3) 
            mNumPoints_DoubleCircles = 3;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case '>':
        mNumPoints_DoubleCircles++;
        if (mNumPoints_DoubleCircles> 36) 
            mNumPoints_DoubleCircles = 36;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;

    case ' ':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        break;
    case 'd':
        mFlgAutoNodeDeletion = !mFlgAutoNodeDeletion;
        break;
    case 'e':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        exportGraph( GRAPH_FILE_NAME );
        break;
    }
}

void GRAPH_SYSTEM::handlePassiveMouseEvent( double x, double z )
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) return;
    if ( cur_d2 > n->r*n->r ) {
        mPassiveSelectedNode = 0;
        return;
    }
    mPassiveSelectedNode = n;
}

///////////////////mCurNumOfActiveNodes/////////////////////////
int GRAPH_SYSTEM::getNumOfNodes( ) const
{
    return mCurNumOfActiveNodes;
}

int GRAPH_SYSTEM::getNodeID( int nodeIndex ) const
{
    int nodeID = mActiveNodeArr[ nodeIndex ];
    return nodeID;
}


//ERROR
int GRAPH_SYSTEM::getNodeInfo( int nodeIndex, double &r, vector3 &p ) const
{
    int nodeID = mActiveNodeArr[ nodeIndex ];
    GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
    r = n->r;
    p = n->p;
    return nodeID;
}

///////////////////mCurNumOfActiveEdges/////////////////////////
int GRAPH_SYSTEM::getNumOfEdges( ) const
{
    return mCurNumOfActiveEdges;
}

int GRAPH_SYSTEM::getEdgeID( int edgeIndex ) const
{
    int edgeID = mActiveEdgeArr[ edgeIndex ];
    return edgeID;
}

int GRAPH_SYSTEM::getNodeIDOfEdge( int edgeIndex, int nodeIndex ) const
{
    int edgeID = mActiveEdgeArr[ edgeIndex ];
    GRAPH_EDGE *e = &mEdgeArr_Pool[ edgeID ];
    return e->nodeID[ nodeIndex ];
}

///ＣＯＮＦＵＳＥ///
vector3 GRAPH_SYSTEM::getNodePositionOfEdge( int edgeIndex, int nodeIndex ) const
{
    vector3 p;
    return p;
}


//Delete Flag?
void GRAPH_SYSTEM::stopAutoNodeDeletion()
{
    mFlgAutoNodeDeletion = false;
}

//
// For every frame, update( ) function is called.
//
// 
void GRAPH_SYSTEM::update( )
{
    if (!mFlgAutoNodeDeletion) {
     
        return;
    }
    if (mCurNumOfActiveNodes<=0) {
     mFlgAutoNodeDeletion = false;
        return;
    }
    Sleep(250);


    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

//
// Export each node to the file steam fObj
// node_ID x y z
// The work flow
//
// Get the number of nodes
// For each node do
//    Get the node ID of the node
//    Get the radius and position of the node
//    Save the node information to the file stream
//
// Return
//
void GRAPH_SYSTEM::emitNodes( std::fstream *fObj ) const
{
    vector3 p;
    double r;
    int num = getNumOfNodes( );
}

//
// Export each edge to the file stream fObj
// edge_ID node0_ID node1_ID
//
// The work flow
//
// Get the number of edges
// For each edge do
//    Get the edge ID of the edge
//    Get the node ID of the first node of the edge
//    Get the node ID of the second node of the edge
//    Save the edge information to the file stream
//
// Return
//
void GRAPH_SYSTEM::emitEdges( std::fstream *fObj ) const
{
    int num = getNumOfEdges( );
}

//
// The work flow
// Create a file stream object or pointer, fObj
// Use fObj to open a file for text output
// Check if the file is opened successfully
// If the file cannot be opened, show an error message and return
// Otherwise, go on to process the following steps.
// Get the number of nodes, n
// Get the number of edges, m
// Save n to fObj
// Save m to fObj
// Call emitNodes
// Call emitEdges
// Close the file
// Delete the object fObj if necessary
// Show a message
//
void GRAPH_SYSTEM::exportGraph(const std::string &fileName) const
{
    cout << "BEGIN GRAPH_SYSTEM::exportGraph" << endl;

    //////////////////////////////////////
    // DO NOT DELETE THE FOLLOWING LINE
    mExport_Count_DrawingFX = Param::Export_Count_DrawingFX;
    //////////////////////////////////////

    cout << "Filename:" << fileName << endl;
    fstream *fObj = new fstream;


    cout << "END GRAPH_SYSTEM::exportGraph" << endl;

}

