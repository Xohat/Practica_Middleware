/**
@file HeightBuffer.h
@brief Archivo encargado de crear un buffer de datos para las imagenes y ser el objetivo de las modificaciones a las mismas
@author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / arturovilarc@gmail.com
// 2023.5 - 2023.06

#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace esne
{
	//.myimagenisverygod
	class HeightBuffer
	{
		unsigned width;
		unsigned depth;

		string file_path = "";
		string file_name = "";
		vector<float> buffer;

	public:

		HeightBuffer(unsigned int width, unsigned int depth) :
			width(width),
			depth(depth),
			buffer(width* depth)
		{
		}

		float get_width() const
		{
			return width;
		}

		float get_height(int x, int z) const
		{
			if (x >= 0 && z >= 0 && x < width && z < depth)
			{
				return buffer[x * depth + z];
			}
			else
			{
				return 1.f; // Devuelve 1.f si el indice es invalido
			}
		}

		float get_depth() const
		{
			return depth;
		}

		void set_height(int x, int z, int new_height)
		{
			if (x >= 0 && z >= 0 && x < width && z < depth)
			{
				buffer[x * depth + z] = new_height;
			}
		}

		void set_path(string new_path)
		{
			file_path = new_path;
		}
		string get_path() const 
		{
			return file_path;
		}

		void set_name(string new_name)
		{
			file_name = new_name;
		}
		string get_name() const
		{
			return file_name;
		}

		void set_width(int given_width) 
		{
			width = given_width;
		}

		void set_depth(int given_depth) 
		{
			depth = given_depth;
		}

		void set_buffer(int given_width, int given_height) 		
		{
			buffer.resize(given_width * given_height);
		}
	};
}