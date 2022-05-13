#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>

class GameObject {
protected:
	std::string desc;
public:
	GameObject(std::string desc);
	std::string getDesc();
	virtual ~GameObject() = 0;
};

#endif
