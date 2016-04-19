//
// Created by cheyulin on 4/19/16.
//

// (C) Copyright Andrew Sutton 2007
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0 (See accompanying file
// LICENSE_1_0.txt or http://www.boost.org/LICENSE_1_0.txt)

//[code_bron_kerbosch_print_cliques
#include <iostream>

#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/bron_kerbosch_all_cliques.hpp>


using namespace std;
using namespace boost;

// The clique_printer is a visitor that will print the vertices that comprise
// a clique. Note that the vertices are not given in any specific order.
template<typename OutputStream, typename SizeType>
struct clique_printer {
    clique_printer(OutputStream &stream, SizeType size)
            : os(stream), size_(size) { }


    template<typename Clique, typename Graph>
    void clique(const Clique &c, const Graph &g) {
        // Iterate over the clique and print each vertex within it.
        cout <<c.size() <<","<<size_<<endl;
        if (c.size() < size_) {
            return;
        }
        typename Clique::const_iterator i, end = c.end();
        for (i = c.begin(); i != end; ++i) {
            os << g[*i].name << " ";
        }
        os << endl;


    }

    SizeType size_;
    OutputStream &os;
};

// The Actor type stores the name of each vertex in the graph.
struct Actor {
    string name;
};

// Declare the graph type and its vertex and edge types.
typedef undirected_graph<Actor> Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;

// The name map provides an abstract accessor for the names of
// each vertex. This is used during graph creation.
typedef property_map<Graph, string Actor::*>::type NameMap;

int main(int argc, char *argv[]) {
    // Create the graph and and its name map accessor.
    Graph g;
    NameMap nm(get(&Actor::name, g));

    //Construct Graph
    Vertex vertex_a = add_vertex(g);
    nm[vertex_a] = "a";
    Vertex vertex_b = add_vertex(g);
    nm[vertex_b] = "b";
    Vertex vertex_c = add_vertex(g);
    nm[vertex_c] = "c";
    Vertex vertex_d = add_vertex(g);
    nm[vertex_d] = "d";

    add_edge(vertex_a, vertex_b, g);
    add_edge(vertex_b, vertex_c, g);
    add_edge(vertex_a, vertex_c, g);
    add_edge(vertex_a, vertex_d, g);
    // Instantiate the visitor for printing cliques
    clique_printer<ostream, int> vis(cout, 3);

    // Use the Bron-Kerbosch algorithm to find all cliques, printing them
    // as they are found.
    bron_kerbosch_all_cliques(g, vis);

    cout <<endl<<endl;
    clique_printer<ostream, int> vis2(cout, 2);
    bron_kerbosch_all_cliques(g, vis2);

    getchar();
    return 0;
}
//]