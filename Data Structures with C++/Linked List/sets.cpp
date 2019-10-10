//Операции над множества, представени чрез линейни списъци

//Дали даден елемент е част от свързан списък(множество)
template<typename T>
bool member(const T& x, LList<T>& L)
{
	L.iterStart();
	elem_link1<T>* p = L.iter();
	while (p)
	{
		if (p->inf == x) return true;
		p = p->link;
	}
	return false;
}

//Обединение на множества
template<typename T>
LList<T>unionSets(LList<T> p, LList<T> q)
{
	LList<T> result;
	elem_link1<T> *pp,
				  *qq;
	p.iterStart();
	q.iterStart();
	pp = p.iter();
	qq = q.iter();

	while (pp)
	{
		if (!member(pp->inf, result))
			result.toEnd(p->inf);
		pp = pp->link;
	}
	while (qq)
	{
		if (!member(qq->inf, result))
			result.toEnd(qq->inf);
		qq = qq->link;
	}
	return result;
}

//Сечение на множества
template<typename T>
LList<T>inresectionSets(LList<T> p, LList<T>q)
{
	LList<T> result;
	p.iterStart();
	elem_link1<T> *pp = p.iter();

	while (pp)
	{
		if (!member(pp->inf, result) && member(pp->inf, q))
			result.toEnd(pp->inf);
		pp = pp->link;
	}
	return result;
}

//Разлика на множества
template<typename T>
LList<T>differenceSet(LList<T> p, LList<T> q)
{
	LList<T> result;
	p.iterStart();
	elem_link1<T>* pp = p.iter();
	while (pp)
	{
		if (!member(pp->inf, q), !member(pp->inf, result))
			result.toEnd(pp->inf);
		pp = pp->link;
	}
	return result;
}
