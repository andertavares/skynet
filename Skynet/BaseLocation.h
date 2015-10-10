#pragma once

#include "Types.h"

#include "UnitGroup.h"

class BaseLocationInterface
{
public:
	virtual Position getCenterPosition() const = 0;
	virtual TilePosition getBuildLocation() const = 0;

	virtual Region getRegion() const = 0;

	virtual const UnitGroup &getMinerals() const = 0;
	virtual const UnitGroup &getGeysers() const = 0;

	virtual void draw( Color color ) const = 0;
};