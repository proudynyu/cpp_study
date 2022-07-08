#include "pointWell.h"

PointWell::PointWell()
{
	CurrentPw = (pwtype)1u;
	MaxPw = (pwtype)1u;
}

PointWell::PointWell(pwtype cPw, pwtype mPw)
{
	CurrentPw = cPw;
	MaxPw = mPw;

	if (cPw > mPw)
	{
		CurrentPw, MaxPw = mPw;
	}
}

bool PointWell::setMax(pwtype new_max_hp)
{
	if (new_max_hp < 1)
	{
		return false;
	}

	MaxPw = new_max_hp;

	if (CurrentPw > MaxPw)
	{
		CurrentPw = MaxPw;
	}

	return true;
}

void PointWell::reduce(pwtype damage)
{
	if (damage > CurrentPw)
	{
		CurrentPw = 0;
		return;
	}
	CurrentPw -= damage;
}

void PointWell::increase(pwtype amount)
{
	if (amount + CurrentPw > MaxPw)
	{
		CurrentPw = MaxPw;
		return;
	}
	CurrentPw += amount;
}

pwtype PointWell::getMax()
{
	return MaxPw;
}

pwtype PointWell::getCurrent()
{
	return CurrentPw;
}