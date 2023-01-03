import sys
import json
import argparse


class Graph(object):
    def __init__(self, nodes, init_graph):
        self.nodes = nodes
        self.graph = self.construct_graph(nodes, init_graph)

    def construct_graph(self, nodes, init_graph):
        graph = dict()
        for node in nodes:
            graph[node] = dict()
        graph.update(init_graph)
        for node, edges in graph.items():
            for adjacent_node, value in edges.items():
                if graph[adjacent_node].get(node, False) is False:
                    graph[adjacent_node][node] = value
        return graph

    def get_nodes(self):
        return self.nodes

    def get_outgoing_edges(self, node):
        connections = list()
        for out_node in self.nodes:
            if self.graph[node].get(out_node, False):
                connections.append(out_node)
        return connections

    def value(self, node1, node2):
        return self.graph[node1][node2]


def algorithm_find(start_node, graph):
    unvisited_nodes = list(graph.get_nodes())
    shortest_path = dict()
    previous_nodes = dict()
    max_value = sys.maxsize
    for node in unvisited_nodes:
        shortest_path[node] = max_value
    shortest_path[start_node] = 0
    while unvisited_nodes:
        current_min_node = None
        for node in unvisited_nodes:
            if current_min_node is None:
                current_min_node = node
            elif shortest_path[node] < shortest_path[current_min_node]:
                current_min_node = node
        neighbors = graph.get_outgoing_edges(current_min_node)
        for neighbor in neighbors:
            tentative_value = shortest_path[
                current_min_node] + graph.value(current_min_node, neighbor)
            if tentative_value < shortest_path[neighbor]:
                shortest_path[neighbor] = tentative_value
                previous_nodes[neighbor] = current_min_node
        unvisited_nodes.remove(current_min_node)
    return previous_nodes, shortest_path


def print_result(
        previous_nodes,
        shortest_path,
        verbose_value,
        start_node,
        target_node):
    path = list()
    node = target_node
    while node != start_node:
        path.append(node)
        node = previous_nodes[node]
    path.append(start_node)
    print(shortest_path[target_node])
    if verbose_value:
        print(" -> ".join(reversed(path)))


def shortest_path(start_node, target_node, verbose_value=False):
    with open('wiki.json') as json_file:
        json_value = json.load(json_file)
        nodes = [node['page_name'] for node in json_value['nodes']]
        egdes = list([(edge['source'], edge['target'])
                      for edge in json_value['edges']])
        init_graph = {}
        for node in nodes:
            init_graph[node] = {}
        for tmp_value in egdes:
            init_graph[tmp_value[0]][tmp_value[1]] = 1
        graph = Graph(nodes, init_graph)
        try:
            previous_nodes, shortest_path = algorithm_find(
                start_node, graph=graph)
            print_result(previous_nodes, shortest_path,
                         verbose_value, start_node, target_node)
        except BaseException:
            print('The key does not exist')


def main():
    parser = argparse.ArgumentParser(description="find short path")
    parser.add_argument('-f', '--from', type=str, help='source web page')
    parser.add_argument('-t', '--to', type=str, help='destination web page')
    parser.add_argument('-v', '--verbose', action='store_true')
    parser.add_argument('--non-directed', action='store_true')
    args = dict(parser.parse_args()._get_kwargs())
    if args['verbose']:
        shortest_path(args['from'], args['to'], args['verbose'])
    else:
        shortest_path(args['from'], args['to'])


if __name__ == '__main__':
    main()
