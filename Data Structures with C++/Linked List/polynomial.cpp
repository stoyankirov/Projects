//Представяне на полином чрез линеен списък.Работа с полиноми.
//anxn + an-1xn-1 +... + a1x + a0

struct monomial
{
	double coef;
	int power;
};

typedef LList<monomial> polynomial;

void create(polynomial& p)
{
	char flag;
	do
	{
		monomial mono;
		cout << "Enter coefficient: "; cin >> mono.coef;
		cout << "Enter power: "; cin >> mono.power;
		p.toEnd(mono);
		cout << "Input y/n: "; cin >> flag;


	} while (flag == 'y');
}

void LList<monomial>::print() const
{
	elem_link1<monomial> * p = start;
	while (p)
	{
		if(p->inf.coef > 0) cout << "+";
		else cout << "";
		cout << p->inf.coef << "x^" << p->inf.power;
		p = p->link;
	}
	cout << endl;
}

//събиране на полиноми
void addPolynomials(polynomial p, polynomial q, polynomial& result)
{
	p.iterStart();
	q.iterStart();
	elem_link1<monomial> *pp = p.iter(),
						 *qq = q.iter();
	while (pp&&qq)
	{
		if (pp->inf.power > qq->inf.power)
		{
			result.toEnd(pp->inf);
			pp = pp->link;
		}
		else if (pp->inf.power < qq->inf.power)
		{
			result.toEnd(qq->inf);
			qq = qq->link;
		}
		else
		{
			monomial mono;
			mono.power = pp->inf.power;
			mono.coef = pp->inf.coef + qq->inf.coef;
			qq = qq->link;
			pp = pp->link;
			if (mono.coef != 0) result.toEnd(mono);
		}
	}
	while (qq)
	{
		result.toEnd(qq->inf);
		qq = qq->link;
	}
	while (pp)
	{
		result.toEnd(pp->inf);
		pp = pp->link;
	}
}

//умножаване на полином с едночлен
void multPolynomialMono(polynomial p, monomial q, polynomial& result)
{
	p.iterStart();
	elem_link1<monomial> * pp = p.iter();
	while (pp)
	{
		monomial mono;
		mono.power = q.power + pp->inf.power;
		mono.coef = q.coef*pp->inf.coef;
		pp = pp->link;
		if (mono.coef != 0) result.toEnd(mono);
	}
}
