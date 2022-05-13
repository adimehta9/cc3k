#ifndef RH_H
#define RH_H
#include "effects.h"
#include <memory>



class RH : public Effects {
	public:
		RH();
		int calcAtk() const override;
		int calcDef() const override;
		int calcHp() const override;
};

#endif
