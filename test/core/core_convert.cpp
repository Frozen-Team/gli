//////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2015 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/core/core_convert.cpp
/// @date 2015-10-05 / 2015-10-05
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <gli/sampler2d.hpp>
#include <glm/gtc/epsilon.hpp>

namespace rgba8_int
{
	int test()
	{
		int Error = 0;

		{
			gli::u8vec4 const Color(255, 127, 0, 255);
			gli::texture2D Texture(gli::FORMAT_R8_UINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, gli::u32, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_CAST, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::u8vec4 Texel = gli::detail::convertFunc<gli::texture2D, glm::u8, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_CAST, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel.x == Color.x ? 0 : 1;
		}

		{
			gli::i8vec4 const Color(127, 63, 0,-128);
			gli::texture2D Texture(gli::FORMAT_R8_SINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, glm::i32, glm::i8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_CAST, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::i8vec4 Texel = gli::detail::convertFunc<gli::texture2D, glm::i8, glm::i8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_CAST, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel.x == Color.x ? 0 : 1;
		}

		{
			gli::u8vec4 const Color(255, 127, 0, 255);
			gli::texture2D Texture(gli::FORMAT_RG8_UINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, glm::u8, glm::u8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_CAST, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::u8vec4 Texel = gli::detail::convertFunc<gli::texture2D, glm::u8, glm::u8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_CAST, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel.x == Color.x ? 0 : 1;
			Error += Texel.y == Color.y ? 0 : 1;
		}

		{
			gli::i8vec4 const Color(127, 63, 0,-128);
			gli::texture2D Texture(gli::FORMAT_RG8_SINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, glm::i8, glm::i8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_CAST, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::i8vec4 Texel = gli::detail::convertFunc<gli::texture2D, glm::i8, glm::i8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_CAST, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel.x == Color.x ? 0 : 1;
			Error += Texel.y == Color.y ? 0 : 1;
		}

		{
			gli::u8vec4 const Color(255, 127, 0, 255);
			gli::texture2D Texture(gli::FORMAT_RGB8_UINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, glm::u8, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_CAST, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::u8vec4 Texel = gli::detail::convertFunc<gli::texture2D, glm::u8, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_CAST, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel.x == Color.x ? 0 : 1;
			Error += Texel.y == Color.y ? 0 : 1;
			Error += Texel.z == Color.z ? 0 : 1;
		}

		{
			gli::i8vec4 const Color(127, 63, 0,-128);
			gli::texture2D Texture(gli::FORMAT_RGB8_SINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, glm::i8, glm::i8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_CAST, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::i8vec4 Texel = gli::detail::convertFunc<gli::texture2D, glm::i8, glm::i8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_CAST, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel.x == Color.x ? 0 : 1;
			Error += Texel.y == Color.y ? 0 : 1;
			Error += Texel.z == Color.z ? 0 : 1;
		}

		{
			gli::u8vec4 const Color(255, 127, 0, 255);
			gli::texture2D Texture(gli::FORMAT_RGBA8_UINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, glm::u8, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_CAST, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::u8vec4 Texel = gli::detail::convertFunc<gli::texture2D, glm::u8, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_CAST, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel.x == Color.x ? 0 : 1;
			Error += Texel.y == Color.y ? 0 : 1;
			Error += Texel.z == Color.z ? 0 : 1;
			Error += Texel.w == Color.w ? 0 : 1;
		}

		{
			gli::i8vec4 const Color(127, 63, 0,-128);
			gli::texture2D Texture(gli::FORMAT_RGBA8_SINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, glm::i8, glm::i8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_CAST, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::i8vec4 Texel = gli::detail::convertFunc<gli::texture2D, glm::i8, glm::i8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_CAST, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel.x == Color.x ? 0 : 1;
			Error += Texel.y == Color.y ? 0 : 1;
			Error += Texel.z == Color.z ? 0 : 1;
			Error += Texel.w == Color.w ? 0 : 1;
		}

		return Error;
	}
}//namespace rgba8_int

namespace rgba8_norm
{
	int test()
	{
		int Error = 0;

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_R8_UNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
		}

		{
			gli::dvec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_R8_UNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::dvec4 Texel = gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_R8_SNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
		}

		{
			gli::dvec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_R8_SNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, double, glm::i8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::dvec4 Texel = gli::detail::convertFunc<gli::texture2D, double, glm::i8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RG8_UNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RG8_SNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGB8_UNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01f) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGB8_SNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01f) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGBA8_UNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.w, Color.w, 0.01f) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGBA8_SNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_NORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			gli::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_NORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.w, Color.w, 0.01f) ? 0 : 1;
		}

		return Error;
	}
}//namespace rgba8_norm

namespace rgba8_srgb
{
	int test()
	{
		int Error = 0;

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_R8_SRGB, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_SRGB, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_SRGB, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
		}

		{
			gli::dvec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_R8_SRGB, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_SRGB, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::dvec4 Texel = gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec1, gli::detail::CONVERT_MODE_SRGB, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RG8_SRGB, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_SRGB, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_SRGB, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
		}

		{
			gli::dvec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RG8_SRGB, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_SRGB, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::dvec4 Texel = gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec2, gli::detail::CONVERT_MODE_SRGB, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGB8_SRGB, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_SRGB, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_SRGB, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01f) ? 0 : 1;
		}

		{
			gli::dvec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGB8_SRGB, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_SRGB, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::dvec4 Texel = gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_SRGB, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01) ? 0 : 1;
		}

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGBA8_SRGB, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_SRGB, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_SRGB, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.w, Color.w, 0.01f) ? 0 : 1;
		}

		{
			gli::dvec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGBA8_SRGB, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_SRGB, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::dvec4 Texel = gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_SRGB, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.w, Color.w, 0.01) ? 0 : 1;
		}

		return Error;
	}
}//namespace rgba8_srgb

namespace rgb9e5
{
	int test()
	{
		int Error = 0;

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGB9E5_UFLOAT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_RGB9E5, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_RGB9E5, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01f) ? 0 : 1;
		}

		{
			gli::dvec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RGB9E5_UFLOAT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_RGB9E5, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::dvec4 Texel = gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_RGB9E5, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01) ? 0 : 1;
		}

		return Error;
	}
}//namespace rgb9e5

namespace rg11b10f
{
	int test()
	{
		int Error = 0;

		{
			gli::vec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RG11B10_UFLOAT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_RG11B10F, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_RG11B10F, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01f) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01f) ? 0 : 1;
		}

		{
			gli::dvec4 const Color(1.0f, 0.5f, 0.0f, 1.0f);
			gli::texture2D Texture(gli::FORMAT_RG11B10_UFLOAT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_RG11B10F, true>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::dvec4 Texel = gli::detail::convertFunc<gli::texture2D, double, glm::u8, gli::defaultp, gli::tvec3, gli::detail::CONVERT_MODE_RG11B10F, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::epsilonEqual(Texel.x, Color.x, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.y, Color.y, 0.01) ? 0 : 1;
			Error += gli::epsilonEqual(Texel.z, Color.z, 0.01) ? 0 : 1;
		}

		return Error;
	}
}//namespace rg11b10f

namespace rgb10a2norm
{
	int test()
	{
		int Error = 0;

		{
			gli::texture2D Texture(gli::FORMAT_RGB10A2_UNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_RGB10A2UNORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, gli::vec4(1.0f, 0.5f, 0.0f, 1.0f));
			glm::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_RGB10A2UNORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::all(gli::epsilonEqual(Texel, gli::vec4(1.0f, 0.5f, 0.0f, 1.0f), 0.01f)) ? 0 : 1;
		}

		{
			gli::texture2D Texture(gli::FORMAT_RGB10A2_SNORM, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_RGB10A2SNORM, true>::write(Texture, gli::texture2D::dim_type(0), 0, gli::vec4(1.0f, 0.5f, 0.0f, 1.0f));
			glm::vec4 Texel = gli::detail::convertFunc<gli::texture2D, float, glm::i8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_RGB10A2SNORM, true>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += gli::all(gli::epsilonEqual(Texel, gli::vec4(1.0f, 0.5f, 0.0f, 1.0f), 0.01f)) ? 0 : 1;
		}

		return Error;
	}
}//namespace rgb10a2norm

namespace rgb10a2int
{
	int test()
	{
		int Error = 0;

		{
			gli::uvec4 const Color(255, 127, 0, 3);
			gli::texture2D Texture(gli::FORMAT_RGB10A2_UINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, gli::uint, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_RGB10A2UINT, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::uvec4 Texel = gli::detail::convertFunc<gli::texture2D, gli::uint, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_RGB10A2UINT, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel == Color ? 0 : 1;
		}

		{
			gli::ivec4 const Color(127, 63, 0, 1);
			gli::texture2D Texture(gli::FORMAT_RGB10A2_SINT, gli::texture2D::dim_type(1), 1);
			gli::detail::convertFunc<gli::texture2D, gli::sint, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_RGB10A2SINT, false>::write(Texture, gli::texture2D::dim_type(0), 0, Color);
			glm::ivec4 Texel = gli::detail::convertFunc<gli::texture2D, gli::sint, glm::u8, gli::defaultp, gli::tvec4, gli::detail::CONVERT_MODE_RGB10A2SINT, false>::fetch(Texture, gli::texture2D::dim_type(0), 0);

			Error += Texel == Color ? 0 : 1;
		}

		return Error;
	}
}//namespace rgb10a2int

int main()
{
	int Error = 0;

	Error += rgba8_int::test();
	Error += rgba8_norm::test();
	Error += rgba8_srgb::test();
	Error += rgb9e5::test();
	Error += rg11b10f::test();
	Error += rgb10a2norm::test();
	Error += rgb10a2int::test();

	return Error;
}

