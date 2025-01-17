///////////////////////////////////////////////////////////////////////////////////
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
/// @file gli/core/texture1d_array.inl
/// @date 2012-06-27 / 2013-01-12
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include "../levels.hpp"

namespace gli
{
	inline texture1DArray::texture1DArray()
	{}

	inline texture1DArray::texture1DArray(format_type Format, dim_type const & Dimensions, size_type Layers)
		: texture(gli::TARGET_1D_ARRAY, Format, texture::dim_type(Dimensions.x, 1, 1), Layers, 1, gli::levels(Dimensions))
	{
		this->build_cache();
	}

	inline texture1DArray::texture1DArray(format_type Format, dim_type const & Dimensions, size_type Layers, size_type Levels)
		: texture(gli::TARGET_1D_ARRAY, Format, texture::dim_type(Dimensions.x, 1, 1), Layers, 1, Levels)
	{
		this->build_cache();
	}

	inline texture1DArray::texture1DArray(texture const & Texture)
		: texture(Texture, gli::TARGET_1D_ARRAY, Texture.format())
	{
		this->build_cache();
	}

	inline texture1DArray::texture1DArray
	(
		texture const & Texture,
		format_type Format,
		size_type BaseLayer, size_type MaxLayer,
		size_type BaseFace, size_type MaxFace,
		size_type BaseLevel, size_type MaxLevel
	)
		: texture(
			Texture, gli::TARGET_1D_ARRAY,
			Format,
			BaseLayer, MaxLayer,
			BaseFace, MaxFace,
			BaseLevel, MaxLevel)
	{
		this->build_cache();
	}

	inline texture1DArray::texture1DArray
	(
		texture1DArray const & Texture,
		size_type BaseLayer, size_type MaxLayer,
		size_type BaseLevel, size_type MaxLevel
	)
		: texture(
			Texture, gli::TARGET_1D_ARRAY,
			Texture.format(),
			Texture.base_layer() + BaseLayer, Texture.base_layer() + MaxLayer,
			Texture.base_face(), Texture.max_face(),
			Texture.base_level() + BaseLevel, Texture.base_level() + MaxLevel)
	{
		this->build_cache();
	}

	inline texture1D texture1DArray::operator[](size_type Layer) const
	{
		assert(!this->empty());
		assert(Layer < this->layers());

		return texture1D(
			*this, this->format(),
			this->base_layer() + Layer, this->base_layer() + Layer,
			this->base_face(), 	this->max_face(),
			this->base_level(), this->max_level());
	}

	inline texture1DArray::dim_type texture1DArray::dimensions(size_type Level) const
	{
		assert(!this->empty());

		return this->Caches[this->index_cache(0, Level)].Dim;
	}

	template <typename genType>
	inline genType texture1DArray::load(texture1DArray::dim_type const & TexelCoord, texture1DArray::size_type Layer, texture1DArray::size_type Level) const
	{
		assert(!this->empty());
		assert(!is_compressed(this->format()));
		assert(block_size(this->format()) == sizeof(genType));

		cache const & Cache = this->Caches[this->index_cache(Layer, Level)];

		std::size_t const Index = linear_index(TexelCoord, Cache.Dim);
		assert(Index < Cache.Size / sizeof(genType));

		return reinterpret_cast<genType const * const>(Cache.Data)[Index];
	}

	template <typename genType>
	inline void texture1DArray::store(texture1DArray::dim_type const & TexelCoord, texture1DArray::size_type Layer, texture1DArray::size_type Level, genType const & Texel)
	{
		assert(!this->empty());
		assert(!is_compressed(this->format()));
		assert(block_size(this->format()) == sizeof(genType));

		cache& Cache = this->Caches[this->index_cache(Layer, Level)];
		assert(glm::all(glm::lessThan(TexelCoord, Cache.Dim)));

		std::size_t const Index = linear_index(TexelCoord, Cache.Dim);
		assert(Index < Cache.Size / sizeof(genType));

		reinterpret_cast<genType*>(Cache.Data)[Index] = Texel;
	}

	inline texture1DArray::size_type texture1DArray::index_cache(size_type Layer, size_type Level) const
	{
		return Layer * this->levels() + Level;
	}

	inline void texture1DArray::build_cache()
	{
		this->Caches.resize(this->layers() * this->levels());

		for (size_type Layer = 0; Layer < this->layers(); ++Layer)
		for (size_type Level = 0; Level < this->levels(); ++Level)
		{
			cache& Cache = this->Caches[this->index_cache(Layer, Level)];
			Cache.Data = this->data<std::uint8_t>(Layer, 0, Level);
			Cache.Size = this->size(Level);
			Cache.Dim = glm::max(texture1D::dim_type(this->texture::dimensions(Level)), texture1D::dim_type(1));
		}
	}
}//namespace gli


