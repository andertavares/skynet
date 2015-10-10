#pragma once

#include "Chokepoint.h"

class SkynetTerrainAnalyser;
class SkynetChokepoint : public ChokepointInterface
{
public:
	SkynetChokepoint( WalkPosition center, WalkPosition side1, WalkPosition side2, int clearance );

	WalkPosition getCenter() const override { return m_center; }
	std::pair<WalkPosition, WalkPosition> getSides() const override { return m_sides; }
	int getClearance() const override { return m_clearance; }

	const std::pair<Region, Region> &getRegions() const override { return m_regions; }

	void draw( Color color ) const override;

protected:
	friend SkynetTerrainAnalyser;

	void setRegion1( Region region ) { m_regions.first = region; }
	void setRegion2( Region region ) { m_regions.second = region; }

private:
	WalkPosition m_center;
	std::pair<WalkPosition, WalkPosition> m_sides;
	int m_clearance;

	std::pair<Region, Region> m_regions;
};