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
#ifndef PBL_CPP_ALGORITHM_H
#define PBL_CPP_ALGORITHM_H

#include <algorithm>

#include "version.h"

#ifndef CPP11
#include <functional>

namespace cpp11
{

template< class InputIt, class UnaryPredicate >
InputIt find_if_not(
	InputIt        first,
	InputIt        last,
	UnaryPredicate q
)
{
	for (; first != last; ++first )
	{
		if ( !q(*first))
		{
			return first;
		}
	}

	return last;
}

template< class InputIt, class UnaryPredicate >
bool all_of(
	InputIt        first,
	InputIt        last,
	UnaryPredicate p
)
{
	return ::cpp11::find_if_not(first, last, p) == last;
}

template< class InputIt, class UnaryPredicate >
bool any_of(
	InputIt        first,
	InputIt        last,
	UnaryPredicate p
)
{
	return std::find_if(first, last, p) != last;
}

template< class InputIt, class UnaryPredicate >
bool none_of(
	InputIt        first,
	InputIt        last,
	UnaryPredicate p
)
{
	return std::find_if(first, last, p) == last;
}

template< class InputIt, class OutputIt, class UnaryPredicate >
OutputIt copy_if(
	InputIt        first,
	InputIt        last,
	OutputIt       d_first,
	UnaryPredicate pred
)
{
	while ( first != last )
	{
		if ( pred(*first))
		{
			*d_first++ = *first;
		}

		first++;
	}

	return d_first;
}

template< class InputIt, class Size, class OutputIt >
OutputIt copy_n(
	InputIt  first,
	Size     count,
	OutputIt result
)
{
	if ( count > 0 )
	{
		*result++ = *first;

		for ( Size i = 1; i < count; ++i )
		{
			*result++ = *++first;
		}
	}

	return result;
}

template< class InputIt, class UnaryPredicate >
bool is_partitioned(
	InputIt        first,
	InputIt        last,
	UnaryPredicate p
)
{
	for (; first != last; ++first )
	{
		if ( !p(*first))
		{
			break;
		}
	}

	for (; first != last; ++first )
	{
		if ( p(*first))
		{
			return false;
		}
	}

	return true;
}

template< class InputIt, class OutputIt1,
          class OutputIt2, class UnaryPredicate >
std::pair< OutputIt1, OutputIt2 > partition_copy(
	InputIt        first,
	InputIt        last,
	OutputIt1      d_first_true,
	OutputIt2      d_first_false,
	UnaryPredicate p
)
{
	while ( first != last )
	{
		if ( p(*first))
		{
			*d_first_true = *first;
			++d_first_true;
		}
		else
		{
			*d_first_false = *first;
			++d_first_false;
		}

		++first;
	}

	return std::pair< OutputIt1, OutputIt2 >(d_first_true, d_first_false);
}

template< class ForwardIt, class Compare >
ForwardIt is_sorted_until(
	ForwardIt first,
	ForwardIt last,
	Compare   comp
)
{
	if ( first != last )
	{
		ForwardIt next = first;

		while ( ++next != last )
		{
			if ( comp(*next, *first))
			{
				return next;
			}

			first = next;
		}
	}

	return last;
}

template< class ForwardIt >
ForwardIt is_sorted_until(
	ForwardIt first,
	ForwardIt last
)
{
	return ::cpp11::is_sorted_until(first, last, std::less< typename std::iterator_traits< ForwardIt >::value_type >());
}

template< class ForwardIt >
bool is_sorted(
	ForwardIt first,
	ForwardIt last
)
{
	return ::cpp11::is_sorted_until(first, last) == last;
}

template< class ForwardIt, class Compare >
bool is_sorted(
	ForwardIt first,
	ForwardIt last,
	Compare   comp
)
{
	return ::cpp11::is_sorted_until(first, last, comp) == last;
}

template< class T >
std::pair< const T&, const T& > minmax(
	const T& a,
	const T& b
)
{
	return ( b < a ) ? std::pair< const T&, const T& >(b, a)
		   : std::pair< const T&, const T& >(a, b);
}

template< class T, class Compare >
std::pair< const T&, const T& > minmax(
	const T& a,
	const T& b,
	Compare  comp
)
{
	return comp(b, a) ? std::pair< const T&, const T& >(b, a)
		   : std::pair< const T&, const T& >(a, b);
}

template< class ForwardIt, class Compare >
std::pair< ForwardIt, ForwardIt > minmax_element(
	ForwardIt first,
	ForwardIt last,
	Compare   comp
)
{
	std::pair< ForwardIt, ForwardIt > result(first, first);

	if ( first == last )
	{
		return result;
	}

	if ( ++first == last )
	{
		return result;
	}

	if ( comp(*first, *result.first))
	{
		result.first = first;
	}
	else
	{
		result.second = first;
	}

	while ( ++first != last )
	{
		ForwardIt i = first;

		if ( ++first == last )
		{
			if ( comp(*i, *result.first))
			{
				result.first = i;
			}
			else if ( !( comp(*i, *result.second)))
			{
				result.second = i;
			}

			break;
		}
		else
		{
			if ( comp(*first, *i))
			{
				if ( comp(*first, *result.first))
				{
					result.first = first;
				}

				if ( !( comp(*i, *result.second)))
				{
					result.second = i;
				}
			}
			else
			{
				if ( comp(*i, *result.first))
				{
					result.first = i;
				}

				if ( !( comp(*first, *result.second)))
				{
					result.second = first;
				}
			}
		}
	}

	return result;
}

template< class ForwardIt >
std::pair< ForwardIt, ForwardIt > minmax_element(
	ForwardIt first,
	ForwardIt last
)
{
	return ::cpp11::minmax_element(first, last, std::less< typename std::iterator_traits< ForwardIt >::value_type >());
}

template< class ForwardIterator, class T >
void iota(
	ForwardIterator first,
	ForwardIterator last,
	T               value
)
{
	while ( first != last )
	{
		*first++ = value;
		++value;
	}
}

template< class InputIt, class OutputIt >
OutputIt move(
	InputIt  first,
	InputIt  last,
	OutputIt dest
)
{
	while ( first != last )
	{
		*dest++ = *first++;
	}

	return dest;
}

}
#endif // ifndef CPP11

#ifndef CPP14
namespace cpp14
{
}
#endif // ifndef CPP14


#endif // PBL_CPP_ALGORITHM_H
