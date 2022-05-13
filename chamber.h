#ifndef CHAMBER_H
#define CHAMBER_H
#include <memory>
#include <vector>
#include <functional>
#include "gameobject.h"

using namespace std;

class Chamber {
    private:
    int size;

    public:
    vector<vector<reference_wrapper<shared_ptr<GameObject>>>> objects;
    Chamber(int x);
    shared_ptr<GameObject>& getObject(int x, int y) const;
    void setObject(int x, int y, shared_ptr<GameObject> obj);
    int getSize() const;
};


#endif
