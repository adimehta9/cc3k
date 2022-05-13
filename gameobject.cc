#include "gameobject.h"

using namespace std;

GameObject::GameObject(string desc)
	: desc{ desc }
{}

string GameObject::getDesc() {
	return desc;
}

GameObject::~GameObject() {

}
