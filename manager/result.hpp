// A rust-like structure that indicates either a valid value 
// or some other(mostly referring to an error) message.

#ifndef RESULT_HPP
#define RESULT_HPP

#include <variant>
#include <string>
#include <cstdlib>
#include "error.h"

namespace oj 
{
	template<typename T, typename E>
	class result 
	{
	private:
		using Self = result;
		result(T&& value);
		result(E&& value);
	public:
		/* construct a result using T */
		static Self ok(T&& value);
		
		/* construct a result using E */
		static Self err(E&& error);

		/* examine if the 'result' holds a valid value */
		bool is_ok() const { return std::holds_alternative<T>(this->dm_value); }
		
		/* equivalent to !is_ok(). Examine if the 'result' holds an error */
		bool is_err() const { return std::holds_alternative<E>(this->dm_value); }

		/* get the 'T' value. */
		const T& get_value() const { return std::get<0>(this->dm_value); }
		
		/* rust-style alias */
		const T& unwrap() const { return this->get_value(); }
		
		/* return the 'T' value if it does own one, or invoke 'f'. The 'f' must
		   terminate the process via exit() with an integer value indicating the error */
		template<typename Closure> 
		const T& unwrap_or_report(Closure f);
		
		/* get the 'E' value. */
		const E& get_error() const { return std::get<1>(this->dm_value); }
	private:
		std::variant<T, E> dm_value;
	};

	template<typename T, typename E>
	result<T, E>::result(T&& value) :dm_value{ std::move(value) }
	{
	}

	template<typename T, typename E>
	result<T, E>::result(E&& error) : dm_value{ std::move(error) }
	{
	}


	template<typename T, typename E>
	result<T, E> result<T, E>::ok(T&& value)
	{
		return { std::move(value) };
	}

	template<typename T, typename E>
	result<T, E> result<T, E>::err(E&& value)
	{
		return { std::move(value) };
	}

	template<typename T, typename E>
	template<typename Closure>
	const T& result<T, E>::unwrap_or_report(Closure f)
	{
		if (this->is_ok())
			return this->get_value();
		f();  // <- make sure this method finally terminates the process
		report_and_exit(error_type::NOT_EXIT_IN_UNWRAP_OR_REPORT); // The program should never run this statement;
	}

	// type alias
	template<typename Value>
	using Result = result<Value, std::string>;
}

#endif