//
// Created by cheyulin on 12/20/16.
//

#include <boost/graph/adjacency_list.hpp>
#include <iostream>

#include "../../Utilities/pretty_print.h"

using namespace std;
using namespace boost;

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

using VertexProperties=property<vertex_name_t, string, property<vertex_location_t,
        array<int, 2>, property<vertex_index_t, int>>>;
using EdgeProperties=property<edge_length_t, double>;
using GraphProperties=property<graph_name_t, string, property<graph_notes_t, string>>;
using Graph=adjacency_list<setS, vecS, undirectedS, VertexProperties, EdgeProperties, GraphProperties>;
using GraphWithEdgeProperty=adjacency_list<setS, vecS, undirectedS, no_property, EdgeProperties>;

void DemoSimpleGraph() {
    cout << "Demo Simple Graph Property:" << endl;

    Graph g;
    property_map<Graph, vertex_location_t>::type vertex_location_map = boost::get(vertex_location, g);
    property_map<Graph, vertex_index_t>::type vertex_index_map = boost::get(vertex_index, g);
    property_map<Graph, edge_length_t>::type edge_length_map = boost::get(edge_length, g);

    graph_traits<Graph>::vertex_descriptor a, b, c;
    graph_traits<Graph>::edge_descriptor ed;

    a = add_vertex(g);
    b = add_vertex(g);
    c = add_vertex(g);
    vertex_location_map[b][0] = 1;
    vertex_location_map[b][1] = 1;
    vertex_location_map[c][0] = 3;
    vertex_location_map[c][1] = 3;

    bool inserted_flag;
    std::tie(ed, inserted_flag) = add_edge(a, b, g);
    edge_length_map[ed] = 1.2;
    std::tie(ed, inserted_flag) = add_edge(a, c, g);
    edge_length_map[ed] = 1.3;
    std::tie(ed, inserted_flag) = add_edge(b, c, g);
    edge_length_map[ed] = 1.4;

    cout << "degree of a:" << degree(a, g) << endl;
    for (auto vp = vertices(g); vp.first != vp.second; ++vp.first) {
        cout << "vertex index:" << vertex_index_map[*vp.first] << endl;
        cout << "vertex location :" << vertex_location_map[*vp.first] << endl;
    }

    for (auto ep = edges(g); ep.first != ep.second; ++ep.first) {
        cout << "edge length:" << edge_length_map[*ep.first] << endl;
    }
}

void DemoGraphWithEdgeProperty() {
    cout << "\nDemo Edge Property:" << endl;
    bool inserted_flag;
    graph_traits<GraphWithEdgeProperty>::vertex_descriptor aa, bb, cc;
    GraphWithEdgeProperty graph;
    aa = add_vertex(graph);
    bb = add_vertex(graph);
    add_vertex(graph);
    property_map<GraphWithEdgeProperty, edge_length_t>::type edge_length_map2 = boost::get(edge_length, graph);
    graph_traits<GraphWithEdgeProperty>::edge_descriptor ed2;

    std::tie(ed2, inserted_flag) = add_edge(aa, bb, graph);
    property_map<Graph, edge_length_t>::type edge_length_map = boost::get(edge_length, graph);
    edge_length_map[ed2] = 1.55;
    cout << edge_length_map[ed2] << endl;
}

int main() {
    DemoSimpleGraph();
    DemoGraphWithEdgeProperty();
}