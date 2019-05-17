#ifndef __ROUTE_MODEL_H__
#define __ROUTE_MODEL_H__

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

class RouteModel : public Model {
public:    
    class Node : public Model::Node {
    public:
        Node *parent = nullptr;
        float h_value = std::numeric_limits<float>::max();
        float g_value = 0.0;
        bool visited = false;
        std::vector<Node*> neighbors;

        Node(){}
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {};
        float distance(Node other) const;
        void FindNeighbors();
    private:
        int index;
        RouteModel * parent_model = nullptr;
        Node *FindNeighbor(std::vector<int> node_indices);
    };
    
    RouteModel(const std::vector<std::byte> &xml);  
    auto &SNodes() { return m_Nodes; };
    auto &GetNodeToRoadMap() { return node_to_road; };
    Node &FindClosestNode(float x, float y);
    std::vector<Node> path;

private:
    std::vector<Node> m_Nodes;
    std::unordered_map<int, std::vector<const Model::Road*>> node_to_road;

    void CreateNodeToRoadHashmap();
};

#endif /* __ROUTE_MODEL_H__ */

