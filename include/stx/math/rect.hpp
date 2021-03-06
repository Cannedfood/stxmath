#pragma once

#include "vec2.hpp"
#include "vec3.hpp"

namespace stx {

/// A axis aligned rectangle defined by maximum and minimum @ingroup stxmath
struct quad {
	vec2 min;
	vec2 max;

	constexpr
	quad() : quad(0, 0, 0, 0) {}

	constexpr
	quad(vec2 const& mn, vec2 const& mx) : min(mn), max(mx) {}

	constexpr
	quad(float mnx, float mny, float mxx, float mxy) : min(mnx, mny), max(mxx, mxy) {}

	constexpr
	vec2 size() const noexcept { return max - min; }

	constexpr
	float width() const noexcept { return max.x - min.x; }

	constexpr
	float height() const noexcept { return max.y - min.y; }

	constexpr
	bool empty() const noexcept { return min.x == max.x && min.y == max.y; }
};

/// A axis aligned rectangle defined by minumum and size @ingroup stxmath
struct rect {
	vec2 position;
	vec2 size;

	constexpr
	rect() : rect(0, 0, 0, 0) {}

	constexpr
	rect(vec2 const& pos, vec2 const& sz) : position(pos), size(sz) {}

	constexpr
	rect(float x, float y, float w, float h) : position(x, y), size(w, h) {}

	constexpr
	vec2 max() const noexcept { return position + size; }

	rect clamp(rect const& other) const noexcept {
		rect r;
		r.position = other.position.max(position);
		r.size     = other.max().min(max()) - r.position;
		return r;
	}

	constexpr
	bool contains(vec2 const& v) const noexcept {
		vec2 diff = v - position;
		return diff.x > 0 && diff.x < size.x && diff.y > 0 && diff.y < size.y;
	}

	constexpr
	bool empty() const noexcept { return size.x == 0 && size.y == 0; }
};

} // namespace stx
