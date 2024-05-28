// scene.hpp

#pragma once

#include "object.hpp"

#include <vector>

using namespace std;

class Scene {
    public:
        Scene();
        ~Scene();

        Scene & AddObject(Object object);
        ObjectData * GetObjectList() const;

    private:
        vector<ObjectData> *objectList;
};
