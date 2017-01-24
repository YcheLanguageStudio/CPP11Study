// Copyright 2005 The Trustees of Indiana University.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor
//           Andrew Lumsdaine
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <boost/graph/compressed_sparse_row_graph.hpp>
#include <boost/graph/iteration_macros.hpp>
#include <boost/graph/graphviz.hpp>

using namespace boost;

class WebPage {
public:
    std::string url;
};

int main() {
    typedef std::pair<int, int> E;
    const char *urls[6] = {
            "http://www.boost.org/libs/graph/doc/index.html",
            "http://www.boost.org/libs/graph/doc/table_of_contents.html",
            "http://www.boost.org/libs/graph/doc/adjacency_list.html",
            "http://www.boost.org/libs/graph/doc/history.html",
            "http://www.boost.org/libs/graph/doc/bundles.html",
            "http://www.boost.org/libs/graph/doc/using_adjacency_list.html",
    };

    E the_edges[] = {E(0, 1), E(0, 2), E(0, 3), E(1, 0), E(1, 3), E(1, 5),
                     E(2, 0), E(2, 5), E(3, 1), E(3, 4), E(4, 1), E(5, 0),
                     E(5, 2)};

    std::vector<size_t> sources;
    std::vector<size_t> destinations;
    std::transform(std::begin(the_edges), std::end(the_edges), std::back_inserter(sources),
                   [](auto &&ele) { return ele.first; });
    std::transform(std::begin(the_edges), std::end(the_edges), std::back_inserter(destinations),
                   [](auto &&ele) { return ele.second; });

    using WebGraph=compressed_sparse_row_graph<directedS, WebPage>;
    WebGraph g(construct_inplace_from_sources_and_targets, sources, destinations, 6u);

    // Set the URLs of each vertex
    int index = 0;
    BGL_FORALL_VERTICES(v, g, WebGraph) {
            g[v].url = urls[index++];
        }

    // Output each of the links
    std::cout << "The web graph:" << std::endl;
    BGL_FORALL_EDGES(e, g, WebGraph) {
            std::cout << "  " << g[source(e, g)].url << " -> " << g[target(e, g)].url << std::endl;
        }

    return 0;
}