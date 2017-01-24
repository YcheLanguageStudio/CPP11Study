//
// Created by cheyulin on 12/20/16.
//

#include <iostream>

#include <boost/graph/adjacency_list.hpp>

#include "../../Utilities/pretty_print.h"

using namespace std;
using namespace boost;

#define BOOST_DEF_PROPERTY(KIND, NAME) \
  enum KIND##_##NAME##_t { KIND##_##NAME }; \
  BOOST_INSTALL_PROPERTY(KIND, NAME)

namespace boost {
    BOOST_DEF_PROPERTY(vertex, location);
    BOOST_DEF_PROPERTY(edge, length);
    BOOST_DEF_PROPERTY(graph, note);
}
#undef BOOST_DEF_PROPERTY


using VertexProperties=property<vertex_name_t, string, property<vertex_location_t, array<int, 2>, property<vertex_index_t, int>>>;
using EdgeProperties=property<edge_length_t, double>;
using GraphProperties=property<graph_name_t, string, property<graph_note_t, string>>;

void DemoComplexGraph() {
    cout << "Demo Complex Graph Property:" << endl;
    using Graph=adjacency_list<setS, vecS, undirectedS, VertexProperties, EdgeProperties, GraphProperties>;
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

void DemoGraphWithOnlyEdgeProperty() {
    cout << "\nDemo Edge Property:" << endl;
    using GraphWithEdgeProperty=adjacency_list<setS, vecS, undirectedS, no_property, EdgeProperties>;
    GraphWithEdgeProperty graph;
    property_map<GraphWithEdgeProperty, vertex_index_t>::type vertex_index_map = boost::get(vertex_index, graph);
    property_map<GraphWithEdgeProperty, edge_length_t>::type edge_length_map = boost::get(edge_length, graph);
    graph_traits<GraphWithEdgeProperty>::vertex_descriptor a, b;
    graph_traits<GraphWithEdgeProperty>::edge_descriptor ed2;

    a = add_vertex(graph);
    b = add_vertex(graph);
    add_vertex(graph);

    bool inserted_flag;
    std::tie(ed2, inserted_flag) = add_edge(a, b, graph);
    edge_length_map[ed2] = 1.55;

    for (auto vp = vertices(graph); vp.first != vp.second; ++vp.first) {
        cout << "vertex index:" << vertex_index_map[*vp.first] << endl;
    }

    for (auto ep = edges(graph); ep.first != ep.second; ++ep.first) {
        cout << "edge length:" << edge_length_map[*ep.first] << endl;
    }
}

int main() {
    DemoComplexGraph();
    DemoGraphWithOnlyEdgeProperty();
}