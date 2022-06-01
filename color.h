#pragma once

#include "vec3.h"
#include <iostream>
#include <fstream>

void write_color(std::ofstream& out, color pixel_color, int samples_per_pixel) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// Replace NaN components with zero. See explanation in Ray Tracing: The Rest of Your Life.
	//if (r != r) r = 0.0;
	//if (g != g) g = 0.0;
	//if (b != b) b = 0.0;

	// Divide the color by the number of samples and gamma-correct for gamma=2.0.
	auto scale = 1.0 / samples_per_pixel;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);
	//r = scale * r;
	//g = scale * g;
	//b = scale * b;

	out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
	//out << static_cast<int>(255.999 * pixel_color.x()) << ' '
	//	<< static_cast<int>(255.999 * pixel_color.y()) << ' '
	//	<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

