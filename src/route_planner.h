#ifndef __ROUTE_PLANNER_H__
#define __ROUTE_PLANNER_H__

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    float GetDistance() { return distance; };
    void AStarSearch();

private:
    RouteModel &m_Model;
    RouteModel::Node *start_node;
    RouteModel::Node *end_node;
    std::vector<RouteModel::Node*>open_list;
    float distance;
    
    std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *current_node);
    float CalculateHValue(const RouteModel::Node *node);
    RouteModel::Node *NextNode(void);
    void AddNeighbors(RouteModel::Node *node);
};

#endif /* __ROUTE_PLANNER_H__ */

