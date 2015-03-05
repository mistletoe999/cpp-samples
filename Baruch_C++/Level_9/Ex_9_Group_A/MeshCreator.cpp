// MeshCreator.cpp
// Implements the functions in MeshCreator.hpp

#include "MeshCreator.hpp"

std::vector<double> CreateMesh(double startValue, double endValue, double diff)
{
	std::vector<double> mesh;
	for (double val = startValue; val <= endValue; val += diff)
	{
		mesh.push_back(val);
	}
	return mesh;
}