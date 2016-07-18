/* Copyright (c) 2016, Pollard Banknote Limited
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.

   3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef PBL_CPP_UNORDERED_MAP_H
#define PBL_CPP_UNORDERED_MAP_H

#include "version.h"

#ifdef CPP11
#include <unordered_map>
#else
#include <stdexcept>
#include <tr1/unordered_map>

namespace cpp11
{
template< class Key, class T, class Hash = std::tr1::hash< Key >, class KeyEqual = std::equal_to< Key >, class Allocator = std::allocator< std::pair< const Key, T > > >
class unordered_map
{
	typedef typename std::tr1::unordered_map< Key, T, Hash, KeyEqual, Allocator > container_type;
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef std::pair< const Key, T > value_type;
	typedef typename container_type::size_type size_type;
	typedef typename container_type::difference_type difference_type;
	typedef Hash hasher;
	typedef KeyEqual key_equal;
	typedef Allocator allocator_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef typename container_type::iterator iterator;
	typedef typename container_type::const_iterator const_iterator;

	allocator_type get_allocator() const
	{
		return inner.get_allocator();
	}

	iterator begin()
	{
		return inner.begin();
	}

	const_iterator begin() const
	{
		return inner.begin();
	}

	const_iterator cbegin() const
	{
		return inner.begin();
	}

	iterator end()
	{
		return inner.end();
	}

	const_iterator end() const
	{
		return inner.end();
	}

	const_iterator cend() const
	{
		return inner.end();
	}

	bool empty() const
	{
		return inner.empty();
	}

	size_type size() const
	{
		return inner.size();
	}

	size_type max_size() const
	{
		return inner.max_size();
	}

	void clear()
	{
		inner.clear();
	}

	std::pair< iterator, bool > insert(const value_type& value)
	{
		return inner.insert(value);
	}

	iterator insert(
		const_iterator    hint,
		const value_type& value
	)
	{
		return inner.insert(hint, value);
	}

	template< typename InputIterator >
	void insert(
		InputIterator first,
		InputIterator last
	)
	{
		inner.insert(first, last);
	}

	iterator erase(const_iterator pos)
	{
		return inner.erase(pos);
	}

	iterator erase(
		const_iterator first,
		const_iterator last
	)
	{
		return inner.erase(first, last);
	}

	size_type erase(const key_type& key)
	{
		return inner.erase(key);
	}

	void swap(unordered_map& o)
	{
		inner.swap(o.inner);
	}

	T& at(const Key& key)
	{
		iterator it = inner.find(key);

		if ( it == inner.end())
		{
			throw std::out_of_range("Map element not found");
		}

		return it->second;
	}

	const T& at(const Key& key) const
	{
		const_iterator it = inner.find(key);

		if ( it == inner.end())
		{
			throw std::out_of_range("Map element not found");
		}

		return it->second;
	}

	T& operator[](const Key& key)
	{
		return inner[key];
	}

	size_type count(const Key& key) const
	{
		return inner.count(key);
	}

	iterator find(const Key& key)
	{
		return inner.find(key);
	}

	const_iterator find(const Key& key) const
	{
		return inner.find(key);
	}

	std::pair< iterator, iterator > equal_range(const Key& key)
	{
		return inner.equal_range(key);
	}

	std::pair< const_iterator, const_iterator > equal_range(const Key& key) const
	{
		return inner.equal_range(key);
	}

private:
	container_type inner;
};
}
#endif // ifdef CPP11

#endif // PBL_CPP_UNORDERED_MAP_H
