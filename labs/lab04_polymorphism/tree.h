#ifndef TREE_H_
#define TREE_H_

#include<vector>
#include "entity.h"

// Represents a Tree in a physical system
class Tree : public Entity {
public:
    // Trees are on the ground, so do not have a z component
    Tree(const std::string& name, double x, double y) : name(name) {
        pos.push_back(x);
        pos.push_back(y);
    }
    // Gets the tree name
    const std::string& GetName() { return name; }
    // Gets the tree position
    std::vector<double> GetPosition() { return pos; }

private:
    std::vector<double> pos;
    std::string name;
};

#endif
