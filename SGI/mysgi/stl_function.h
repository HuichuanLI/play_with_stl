#pragma once

template <class Pair>
struct select1st
{
	const typename Pair::first_type& operator()(const Pair& x) const
	{
		return x.first;
	}
};