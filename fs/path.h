/* Copyright (c) 2015, Pollard Banknote Limited
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
#ifndef PBL_CPP_FS_PATH_H
#define PBL_CPP_FS_PATH_H
#include <string>
#include <iosfwd>

namespace cpp17
{
namespace filesystem
{
/** A file path
 *
 * A partial implementation of std::experimental::filesystem::path
 * @todo Construct from the other basic_string types and pointer-to-char16_t, etc.
 */
class path
{
public:
	typedef char value_type;
	typedef std::basic_string< value_type > string_type;

	static const value_type preferred_separator = '/';

	/// An empty path
	path();

	/// Construct a path form the given string
	path(const string_type&);

	path(const char*);

	/// Copy constructor
	path(const path&);

	/// Copy assignment
	path& operator=(const path&);

	path& operator=(const string_type&);

	/// Clear the path
	void clear();

	/// Swap the two paths
	void swap(path&);

	std::string string() const;
	const char* c_str() const;
	path& operator/=(const path&);
	path& append(const path&);

	/// Is the path empty (i.e., "")
	bool empty() const;
	const std::string& native() const;

	path filename() const;
	path parent_path() const;

	operator string_type() const;

	bool is_absolute() const;

	path lexically_relative(const path&) const;
private:
	std::pair< std::size_t, std::size_t > first_path_component() const;
	bool next_path_component(std::pair< std::size_t, std::size_t >&) const;

	std::string s;
};

path operator/(const path& lhs, const path& rhs);

std::ostream& operator<<(std::ostream&, const path&);
}
}

#endif // PBL_FS_PATH_H
