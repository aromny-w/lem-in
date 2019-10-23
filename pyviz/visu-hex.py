
import re
import numpy as numpy
import networkx as nx
from Classes.Farm import Farm, make_farm
from Classes.Ant import Ant, create_ants
from Classes.Visualize import Visualize

farm = make_farm()
ants = create_ants(farm)

G = nx.Graph()
G.add_nodes_from(farm.rooms)
G.add_edges_from(farm.links)
pos = nx.spring_layout(G)

vis = Visualize(farm, ants, G, pos)
vis.init()
