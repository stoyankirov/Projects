// hist (списък), която по даден списък отпечатва на екрана двойки с честотата на 
// срещанията на всеки негов елемент
// Пример: hist [1, 2, 3, 1, 5, 3] ~> 1, 2 \ 2, 1 \ 3, 2 \ 5,1

template<typename T>
void hist(LList<T>& l)
{
	LList<T> copy = l;
	copy.iterStart();
	elem_link1<T> *p = NULL;
	elem_link1<T> *q = NULL;
	elem_link1<T> *t = copy.iter();

	while (t)
	{
		T x;
		p = t->link;
		int counter = 1;
		while (p)
		{
			if (p->inf == t->inf)
			{
				counter++;
				q = p->link;
				copy.deleteElement(p, x);
				p = q;			
			}
			else
			{
				p = p->link;
			}
		}
		cout << t->inf << " , " << counter << endl;
		q = t->link;
		copy.deleteElement(t, x);
		t = q;
	}
}
