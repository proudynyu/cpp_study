#pragma once

#include "statblock.h"

StatBlock::StatBlock()
{
	Strength = (stattype)1;
	Intellect = (stattype)1;
};

StatBlock::StatBlock(stattype strValue, stattype intValue)
{
	Strength = strValue;
	Intellect = intValue;
}

stattype StatBlock::getStrength()
{
	return Strength;
}

stattype StatBlock::getIntellect()
{
	return Intellect;
}

void StatBlock::increaseStatus(stattype str_scalar, stattype int_scalar)
{
	Strength += str_scalar;
	Intellect += int_scalar;
}