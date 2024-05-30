// scene.hpp

#pragma once

#include "object.hpp"

#include <vector>

using namespace std;

class Scene {
    public:
        Scene();
        ~Scene();

        Scene & AddObject(const Object &object);
        ObjectData * GetObjectList(unsigned int *length) const;

    private:
        vector<ObjectData> *objectList;
};
