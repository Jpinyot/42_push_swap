
#include "libswap.h"

static t_stack	*ft_push(t_stack *a, t_stack *b)
{
	t_num	*tmp;

	tmp = a->bgn->next;
	b->bgn->prev = a->bgn;
	a->bgn->next = b->bgn;
	b->bgn = a->bgn;
	a->bgn = tmp;
	a->bgn->prev = NULL;
	return (a);
}

static t_stack  *ft_push_null(t_stack *a, t_stack *b)
{
	t_num	*tmp;

	tmp = a->bgn->next;
	b->bgn = a->bgn;
	b->end = a->bgn;
	b->bgn->next = NULL;
	b->bgn->prev = NULL;
	a->bgn = tmp;
	a->bgn->prev = NULL;
	return (a);
}


static t_stack  *ft_push_nn(t_stack *a, t_stack *b)
{

	b->bgn->prev = a->bgn;
	a->bgn->next = b->bgn;
	b->bgn = a->bgn;
	a->bgn = NULL;
	a->end = NULL;
	

	return (a);
}


t_stack *ft_pb(t_stack *a, t_stack *b, t_ret *ret)
{
	char	*del;

	if (a->bgn->next == NULL)
		ft_push_nn(a, b);
	else if (b->bgn != NULL)
		ft_push(a, b);
	else
		ft_push_null(a, b);
	del = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " pb");
	ret->mov += 1;
//	ft_strdel(&del);
	return (a);
}

t_stack	*ft_pa(t_stack *a, t_stack *b, t_ret *ret)
{
	char	*del;

	if (b->bgn->next == NULL)
		ft_push_nn(b, a);
	else if (a->bgn != NULL)
		ft_push(b, a);
	else
		ft_push_null(b, a);
	del = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " pa");
	ret->mov += 1;
//	ft_strdel(&del);
	
	return (a);
}


