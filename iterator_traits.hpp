/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:45:14 by pcunha            #+#    #+#             */
/*   Updated: 2022/04/14 01:45:16 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft{
	template <class I>
	struct iterator_traits
	{
		typedef typename I::difference_type		difference_type;
		typedef typename I::value_type			value_type;
		typedef typename I::pointer				pointer;
		typedef typename I::reference			reference;
		typedef typename I::iterator_category	iterator_category;
	};
}

#endif
