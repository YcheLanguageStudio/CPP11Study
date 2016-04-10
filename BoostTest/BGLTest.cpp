//
// Created by cheyulin on 4/9/16.
//

//Below is code I used to attach some properties to vertices, edges, and graphs.
// Note that vertex name and graph name are predefined properties
// (see boost/properties.hpp for a complete list) so that vertex_name_t and graph_name_t are already defined.
// However, vertex_location_t, edge_length_t, and graph_notes_t are my own properties and hence need definition.
// I cobbled together this code from various examples and documentation, and I'm not sure exactly what BOOST_INSTALL_PROPERTY does, but the code seems to work fine.
#include <boost/graph/adjacency_list.hpp>
#include <iostream>

using namespace boost;
using namespace std;
// Define custom properties
enum vertex_location_t {
    vertex_location
};
enum edge_length_t {
    edge_length
};
enum graph_notes_t {
    graph_notes
};


namespace boost {
    BOOST_INSTALL_PROPERTY(vertex, location);
    BOOST_INSTALL_PROPERTY(edge, length);
    BOOST_INSTALL_PROPERTY(graph, notes);
}

// Define vertex properties:  vertex name and location
typedef property<vertex_name_t, string,
        property<vertex_location_t, int,property<vertex_index_t, int>>>
        VertexProperties;

// Define edge properties:  length
typedef property<edge_length_t, double> EdgeProperties;

// Define graph properties:  graph name and notes
typedef property<graph_name_t, string,
        property<graph_notes_t, string> >
        GraphProperties;

// Define a graph type
typedef adjacency_list
        <
                vecS,       // edge container type
                vecS,       // vertex container type
                undirectedS,
                VertexProperties,
                EdgeProperties,
                GraphProperties
        > Graph;

int main() {
    Graph g;

    typename property_map<Graph, vertex_location_t>::type vertex_location_map = boost::get(vertex_location, g);
    typename property_map<Graph, vertex_index_t>::type vertex_index_map = boost::get(vertex_index,g);

    typename graph_traits<Graph>::vertex_descriptor a, b, c;
    a = add_vertex(g);
    b = add_vertex(g);
    c = add_vertex(g);
    typename graph_traits<Graph>::vertex_descriptor  d;
    d=a;
    vertex_location_map[d] =111;
    cout << "vertex_location a:"<<vertex_location_map[a] << endl;
    vertex_location_map[b] = 2;
    vertex_location_map[c] = 3;

    cout << "a:"<<vertex_index_map[a] << endl;
    cout << "b:"<<vertex_index_map[b] << endl;
    cout << "c:"<<vertex_index_map[c] << endl;
//    typedef property_map<Graph,graph_name_t>::type graph_note_map_t;
//    graph_note_map_t graph_note_map = boost::get(graph_notes, g);
//    boost::put(graph_note_map, g, "dd");
////    std::cout <<"Graph_Name:" << boost::get(graph_note_map, g);

    typename property_map<Graph, edge_length_t>::type edge_length_map = boost::get(edge_length, g);

    typename graph_traits<Graph>::edge_descriptor ed;
    bool inserted_flag;

    tie(ed, inserted_flag) = add_edge(a, b, g);
    boost::put(edge_length_map, ed, 1.2);
    tie(ed, inserted_flag) = add_edge(a, c, g);
    boost::put(edge_length_map, ed, 1.3);
    tie(ed, inserted_flag) = add_edge(b, c, g);
    boost::put(edge_length_map, ed, 1.4);

    for (auto vp = vertices(g); vp.first != vp.second; ++vp.first) {
        std::cout << "vertex_location_internal_property:" << vertex_location_map[*vp.first] << std::endl;
    }

    for (auto ep = edges(g); ep.first != ep.second; ++ep.first) {
        std::cout << "dege_length:" << boost::get(edge_length_map, *ep.first) << std::endl;
    }
}



