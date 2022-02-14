/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:45:07 by pcunha            #+#    #+#             */
/*   Updated: 2022/02/14 17:03:28 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define	TYPE_TRAITS_HPP

namespace ft {

	// Integral constant definition, to be used to define the true and false objects
	// It has a type (bool) and a value of this type (v) that can be True or False
	// The operator () returns v
	template <class T, T v>
	struct integral_constant
	{
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T,v>	type;
		operator T() const				{return v; };
	};


	// True / False_type definitions, to be used in the is_integral and enable_if constructs
	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	// Is_integral definition:
	// By default, is_integral inherits from false_type() so it's false unless
	// there is a match in the specializations below
	template <class T> 
	struct is_integral: public false_type{};

	// specializations:
	template <>
	struct is_integral<bool> : public true_type{};
	template <>
	struct is_integral<char> : public true_type{};
	template <>
	struct is_integral<short> : public true_type{};
	template <>
	struct is_integral<int> : public true_type{};
	template <>
	struct is_integral<long> : public true_type{};
	template <>
	struct is_integral<long long> : public true_type{};
	template <>
	struct is_integral<unsigned char> : public true_type{};
	template <>
	struct is_integral<unsigned short> : public true_type{};
	template <>
	struct is_integral<unsigned int> : public true_type{};
	template <>
	struct is_integral<unsigned long> : public true_type{};
	template <>
	struct is_integral<unsigned long long> : public true_type{};

	// Enable_if definition (starts empty)
	template <bool Cond, class T = void>
	struct enable_if {};
	// Eneble_if will be the type according to the match in the previous lines
	template <class T> struct enable_if<true, T> {typedef T type; };
};
#endif
