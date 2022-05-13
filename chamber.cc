#include "chamber.h"
#include <memory>
#include <functional>

using namespace std;

Chamber::Chamber(int x) {
	shared_ptr<GameObject> null(nullptr);
	if(x==0){
		size = 104;
		objects = vector<vector<reference_wrapper<shared_ptr<GameObject>>>>(4);
		for(int i=0; i< 4; i++){
			objects[i] = vector<reference_wrapper<shared_ptr<GameObject>>>(26, null);
		}
	} else if(x==1){
		size = 201;
		objects = vector<vector<reference_wrapper<shared_ptr<GameObject>>>>(10);
		int columns[] = { 23, 23, 31, 34, 15, 15, 15, 15, 15, 15 };

		for(int i=0; i< 10; i++){
			objects[i] = vector<reference_wrapper<shared_ptr<GameObject>>>(columns[i], null);
		}
	} else if(x==2){
		size = 36;
		objects = vector<vector<reference_wrapper<shared_ptr<GameObject>>>>(3);
		for(int i=0; i< 3; i++){
			objects[i] = vector<reference_wrapper<shared_ptr<GameObject>>>(12, null);
		}
	} else if (x==3){
		size = 147;
		objects = vector<vector<reference_wrapper<shared_ptr<GameObject>>>>(7);
		for(int i=0; i<7; i++){
			objects[i] = vector<reference_wrapper<shared_ptr<GameObject>>>(21, null);
		}
	} else if (x==4){
		size = 147;
		objects = vector<vector<reference_wrapper<shared_ptr<GameObject>>>>(6);
		for(int i=0; i<3; i++){
			objects[i] = vector<reference_wrapper<shared_ptr<GameObject>>>(11, null);
		}
		for(int i=3; i<6; i++){
			objects[i] = vector<reference_wrapper<shared_ptr<GameObject>>>(39, null);
		}
	}
}

shared_ptr<GameObject>& Chamber::getObject(int x, int y) const {
	return objects[x][y].get();
}

void Chamber::setObject(int x, int y, shared_ptr<GameObject> obj) {
	objects[x][y].get() = obj;
}

int Chamber::getSize() const {
	return size;
}
