import json
import networkx as nx
import matplotlib.pyplot as plt
from cache_wiki import WIKI_FILE


def render_graph():
    with open(WIKI_FILE) as json_file:
        json_value = json.load(json_file)
        graph_value = nx.Graph()
        graph_value.add_nodes_from([(node['page_name']
                                    for node in json_value['nodes'])])
        graph_value.add_edges_from([(edge['source'], edge['target'])
                                    for edge in json_value['edges']])
        degree_value = dict(graph_value.degree)
        plt.figure(figsize=(80, 80), dpi=80)
        setting_render = {
            'with_labels': True,
            'node_size': [
                v * 100 for v in degree_value.values()],
            'font_size': 20,
            'linewidths': 0.5,
            'width': 0.9,
            'node_color': '#ff0000'}
        nx.draw(graph_value, **setting_render)
        plt.savefig('wiki.png')


def main():
    render_graph()


if __name__ == '__main__':
    main()
