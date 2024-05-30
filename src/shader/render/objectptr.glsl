// objectptr.glsl

struct ObjectPtr {
    uint index;
};

uniform uint objectNum;
uniform uint packPerObject;

ObjectPtr objectPtr(uint index) {
    ObjectPtr objPtr;
    objPtr.index = index;
    return objPtr;
}

bool objectPtrEOF(ObjectPtr objPtr) {
    return objPtr.index >= objectNum * packPerObject;
}

ObjectPtr objectPtrNext(ObjectPtr objPtr) {
    objPtr.index += packPerObject;
    return objPtr;
}
