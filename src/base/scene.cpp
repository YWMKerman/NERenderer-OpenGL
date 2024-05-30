// scene.cpp

#include "include/scene.hpp"

#include "include/object.hpp"

#include <vector>

using namespace std;

Scene::Scene() {
    objectList = new vector<ObjectData>();
}

Scene::~Scene() {
    delete objectList;
}

Scene & Scene::AddObject(const Object &object) {
    objectList->push_back(object.GetObjectData());
    return *this;
}

ObjectData * Scene::GetObjectList(unsigned int *length) const {
    *length = (unsigned int) objectList->size();
    return objectList->data();
}
