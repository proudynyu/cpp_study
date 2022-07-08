#pragma once

#ifndef STATBLOCK_CLASS_H
#define STATBLOCK_CLASS_H

#include <cstdint>

typedef std::uint16_t stattype;

class StatBlock
{
public:
	StatBlock();
	explicit StatBlock(stattype strValue, stattype intValue);

	stattype getStrength();
	stattype getIntellect();

protected:
	void increaseStatus(stattype str_scalar, stattype int_scalar);

private:
	stattype Strength;
	stattype Intellect;
};

#endif