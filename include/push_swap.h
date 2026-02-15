#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ================= STRUCTS ================= */

typedef struct s_simple_ops
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_simple_ops;

typedef struct s_chunk
{
	int		n;
	int		chunks;
	int		chunk_size;
}	t_chunk;

typedef struct s_cost
{
	int		ra;
	int		rb;
	int		total;
}	t_cost;

/* ================= FLAGS / VALIDATION ================= */

int			is_bench_mode(char *s);
int			is_strategy_selector(char *s);
int			is_numeric_string(char *s);
long long	ft_strtoll(const char *s, int *overflow);
int			check_flags(char **args, char **strategy,
				int *bench_mode, int *start);
int			validate_args(char **args, char **strategy,
				int *bench, int *start);
int			validate_numbers(char **args, int i);
int			contains_duplicates(int *nums, int size);

/* ================= UTILS ================= */

void		ft_putdouble_fd(double num, int fd);
int			ft_sqrt(int n);
int			*fill_array(char **args, int start, int size);

void		ft_sort_int_tab(int *tab, int size);
int			*build_array(t_list *s, int n);

void		print_stack(t_list *stack);
double		round_to_two_decimals(double num);
double		compute_disorder(t_list *stack);

int			find_min(t_list *s);
int			calculate_distance_from_top(t_list *s, int val);

/* ================= INDEXING / ARRAY HELPERS ================= */

int			*to_array(t_list **s);
int			*sort(int *arr, int size);
t_list		*push_values(int *a, int size);
t_list		*indexing(t_list **s);

/* ================= STACK OPERATIONS ================= */

void		swap(t_list **s);
void		push(t_list **take, t_list **put);
void		rotate(t_list **s);
void		reverse_rotate(t_list **s);

void		sa(t_list **s, t_simple_ops *ops);

void 		ra(t_list **a, t_simple_ops *ops, int nb);
void 		rra(t_list **a, t_simple_ops *ops, int nb);

/* ================= SIMPLE SORT ================= */

void		sort_two(t_list **a, int bench_mode);
void		sort_three(t_list **s, int bench_mode);
void		simple_sort(t_list **s, int bench_mode);

/* ================= MEDIUM SORT ================= */

t_chunk		*init_chunk(int n);
int			has_index_in_range(t_list *a, int low, int high);
void		rotate_to_range_top(t_list **a, int low, int high,
				t_simple_ops *ops);
void		push_current(t_list **a, t_list **b,
				int mid_index, t_simple_ops *ops);
void		push_chunks(t_list **a, t_list **b,
				t_chunk c, t_simple_ops *ops);
int			get_pos(t_list *s, t_list *node);
int			compute_rotations_to_top(t_list *s, t_list *node);
int			compute_rotations_a_for_index(t_list *a, int index);
t_cost		compute_cost(t_list *a, t_list *b, t_list *node);
t_list		*find_best_node_in_b(t_list *a,
				t_list *b, t_cost *best_cost);
void		apply_rotations(t_list **a, t_list **b,
				t_cost cost, t_simple_ops *ops);
void		reinsert_all_from_b(t_list **a,
				t_list **b, t_simple_ops *ops);
void		rotate_a_min_to_top(t_list **a,
				t_simple_ops *ops);
int			has_in_range(t_list *s, int min, int max);
int			find_max(t_list *s);
void		push_all_chunks(t_chunk *ch);
void		rotate_max_to_top_b(t_list **b,
				int max, t_simple_ops *ops);
void		push_back_max(t_list **a,
				t_list **b, t_simple_ops *ops);
void		rotate_range_to_top(t_list **a,
				int min, int max, t_simple_ops *ops);
void		medium_sort(t_list **s, int bench_mode);

/* ================= COMPLEX SORT ================= */

int			binary_digit_count(int n);
void		to_indices(t_list *s);
void		complex_sort(t_list **s, int bench_mode);

/* ================= BENCH ================= */

void		init_ops(t_simple_ops *ops);
void		worst_order_sort(t_list **s, t_simple_ops *ops);
void		bench_report(double disorder,
				char *strategy, t_simple_ops ops);
void		adaptive_sort(t_list **s, int bench_mode);

#endif
