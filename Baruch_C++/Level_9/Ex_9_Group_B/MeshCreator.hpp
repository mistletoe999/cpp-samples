// MeshCreator.hpp
// Defines the MeshCreator function to be used to create 
// vector of evenly separated values

#ifndef MESH_CREATOR_HPP_
#define MESH_CREATOR_HPP_

#include <iostream>
#include <vector>

std::vector<double> CreateMesh(double startValue, double endValue, double diff);

#endif