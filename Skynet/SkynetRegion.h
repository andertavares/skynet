#pragma once

#include "Region.h"

class SkynetTerrainAnalyser;
class SkynetRegion : public RegionInterface
{
public:
	SkynetRegion( SkynetTerrainAnalyser & terrain_analyser, WalkPosition center, int clearance );

	const WalkPosition &getCenter() const override { return m_center; }
	int getClearance() const override { return m_clearance; }
	int getSize() const override { return m_size; }

	const VectorUnique<Chokepoint> &getChokepoints() const override { return m_chokepoints; }
	const VectorUnique<TilePosition> &getChokepointTiles() const override { return m_choke_point_tiles; }
	const VectorUnique<Base> &getBases() const override { return m_bases; }

	bool isConnected( Region other ) const override;

	void draw( Color color ) const override;

protected:
	friend SkynetTerrainAnalyser;

	void addChokepoint( Chokepoint chokepoint ) { m_chokepoints.insert( chokepoint ); }
	void removeChokepoint( Chokepoint chokepoint ) { m_chokepoints.remove( chokepoint ); }

	void addBase( Base base ) { m_bases.insert( base ); }

	void setSize( int size ) { m_size = size; }

private:
	SkynetTerrainAnalyser & m_terrain_analyser;
	WalkPosition m_center;
	int m_clearance;
	int m_size;

	VectorUnique<Chokepoint> m_chokepoints;
	VectorUnique<TilePosition> m_choke_point_tiles;
	VectorUnique<Base> m_bases;
};