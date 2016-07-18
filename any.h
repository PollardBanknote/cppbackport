/// @todo GCC has <experimental/any> which may be preferable
#ifndef PBL_ANY_ANY_H
#define PBL_ANY_ANY_H

#include "version.h"

#ifdef CPP17
#include <any>
#else

#include <typeinfo>
#include <stdexcept>
#include <memory>

namespace cpp17
{
/** Thrown by any_cast if the type of object does not match the indicated type
 *
 * @todo Get better type name via abi::__cxa_demangle. Might want to add such
 * functionality to core
 */
class bad_any_cast
	: public std::bad_cast
{
public:
	explicit bad_any_cast(const std::type_info& ti)
		: info(ti)
	{
	}

	const char* what() const throw ( )
	{
		return info.name();
	}

private:
	const std::type_info& info;
};

/** An object that can hold any (CopyConstructible) type
 *
 * Values are constructed using the constructor, or by copy assignment. They
 * are retreived with any_cast<T>
 *
 * This object stores a pointer to a wrapper around the object. The wrapper
 * provides copying, destruction, and RTTI.
 *
 * @todo safe bool
 * @todo small types (no bigger than a pointer) should be stored directly
 */
class any
{
public:
	/** An any that does not contain anything
	 */
	any()
		: value(0)
	{
	}

	/** Copy constructor
	 */
	any(const any& a)
		: value(a.value ? a.value->clone() : 0)
	{
	}

	/** Fill an any with a T
	 *
	 * T must be CopyConstructible
	 */
	template< typename T >
	any(const T& x)
		: value(new actual< T >(x))
	{
	}

	/** Destroys the stored object
	 */
	~any()
	{
		clear();
	}

	/** Copy assignment
	 */
	any& operator=(const any& a)
	{
		any t(a);

		t.swap(*this);

		return *this;
	}

	/** Swap stored values
	 */
	void swap(any& a)
	{
		base* t = value;

		value   = a.value;
		a.value = t;
	}

	/** Check if this any currently stores an object
	 */
	bool empty() const
	{
		return !value;
	}

	/** Destroys the stored object
	 */
	void clear()
	{
		delete value;
		value = 0;
	}

	/** Get the type info of the stored object
	 *
	 * If there is no stored object, the type_info for "void" is returned
	 */
	const std::type_info& type() const
	{
		if ( value )
		{
			return value->type();
		}

		return typeid( void );
	}

private:
	struct base
	{
		virtual ~base()
		{
		}

		virtual base* clone() const                = 0;
		virtual const std::type_info& type() const = 0;
	};

	template< typename T >
	struct actual
		: base
	{
		explicit actual(const T& y)
			: x(y)
		{
		}

		actual* clone() const
		{
			return new actual(*this);
		}

		const std::type_info& type() const
		{
			return typeid( T );
		}

		T x;
	};

	template< typename T >
	friend T any_cast(const any&);

	template< typename T >
	friend const T* any_cast(const any*);

	template< typename T >
	friend T* any_cast(any*);

	base* value;
};

/** Get the value out of an any
 */
template< typename T >
T any_cast(const any& a)
{
	const std::type_info& ti = typeid( T );

	if ( a.type() != ti )
	{
		throw bad_any_cast(ti);
	}

	return static_cast< any::actual< T >* >( a.value )->x;
}

template< typename T >
const T* any_cast(const any* a)
{
	if ( a )
	{
		const std::type_info& ti = typeid( T );

		if ( a->type() == ti )
		{
			return &( static_cast< any::actual< T >* >( a->value )->x );
		}
	}

	return 0;
}

template< typename T >
T* any_cast(any* a)
{
	if ( a )
	{
		const std::type_info& ti = typeid( T );

		if ( a->type() == ti )
		{
			return &( static_cast< any::actual< T >* >( a->value )->x );
		}
	}

	return 0;
}

}
#endif
#endif // PBL_ANY_ANY_H
