/**
@file Brush.h
@brief Archivo encargado de definir la brocha y sus variables
@author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / arturovilarc@gmail.com
// 2023.5 - 2023.06

#pragma once

#include "HeightBuffer.h"
#include "API.h"

namespace esne 
{
	class API Brush
	{

	protected:

		HeightBuffer heightBuffer;
		bool is_active = false;
		float current_color = -1;
		int width = 0;
		int height = 0;

	public:

		//Constructor por defecto
		Brush(unsigned given_width, unsigned given_depth) : heightBuffer(given_width, given_depth)
		{

		}

		// Getters
		int get_width()
		{
			return width;
		}
		int get_height()
		{
			return height;
		}
		float get_color()
		{
			return current_color;
		}

		/// <summary>
		/// Getter de estado activo
		/// </summary>
		/// <returns></returns>
		bool get_active() 
		{
			return is_active;
		}

		/// <summary>
		/// Setter de estado activo
		/// </summary>
		void set_active() 
		{
			is_active = true;
		}

		/// <summary>
		/// Setter de estado inactivo
		/// </summary>
		void set_inactive()
		{
			is_active = false;
		}

		// Setters
		void set_color(float given_color) 
		{
			current_color = given_color;
		}
		void set_width(int new_width) 
		{
			width = new_width;
		}
		void set_height(int new_height)
		{
			height = new_height;
		}

	};
}