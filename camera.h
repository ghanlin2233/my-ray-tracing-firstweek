#pragma once
#include "rtweekend.h"

class camera {
public:
	camera(const point3& lookfrom, const point3& lookat, const vec3& vup, const float& vfov, const float& aspect_ratio, const float& aperture, const float& focus_dist){
		auto theta = degrees_to_radians(vfov);
		auto h = tan(theta / 2);
		auto viewport_height = 2.0 * h;
		auto viewport_width = aspect_ratio * viewport_height;

		this->w = unit_vector(lookfrom - lookat);//�����Լ�
		this->u = unit_vector(cross(vup, w));//���ֱ�
		this->v = cross(w, u);//�Ϸ�

		this->origin = lookfrom;
		this->horizontal = focus_dist * viewport_width * u;
		this->vertical = focus_dist * viewport_height * v;
		//�ӿ����½ǵ�����
		this->lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;
		this->lens_radius = aperture / 2;
	}

	ray get_ray(float s, float t) {
		vec3 rd = lens_radius * random_in_unit_disk();
		//std::cout << rd << std::endl;
		vec3 offset = u * rd.x() + v * rd.y();
		return ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset);
	}
private:
	point3 origin;
	point3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 u, v, w;
	float lens_radius;//
};