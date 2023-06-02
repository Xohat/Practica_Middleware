
// Distributed under MIT License
// @arturovilarc@gmail.com
// 2023

#pragma once

// For Visual Studio

#if defined HeightMapEditorLib

#define API __declspec(dllexport)

#else

#define API __declspec(dllimport)

#endif
