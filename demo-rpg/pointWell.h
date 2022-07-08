#pragma once

#ifndef POINTWELL_CLASS_H
#define POINTWELL_CLASS_H

#include <cstdint>

typedef std::uint16_t pwtype;

class PointWell
{
public:
	PointWell();
	explicit PointWell(pwtype cPw, pwtype mPw);

	bool setMax(pwtype new_max_pw);
	void reduce(pwtype damage);
	void increase(pwtype amount);
	pwtype getMax();
	pwtype getCurrent();

private:
	pwtype CurrentPw;
	pwtype MaxPw;
};

#endif