#include "./includes/ft_list.h"

void print(t_element *element)
{
	printf("Index = %d -- %s\n", element->index, (char *)element->content);
}

/*int search(t_element *element, void *content)
{
	return (element->index == *(int *)content);
}*/


int main(void)
{
	t_list list = ft_list();
	list.append(&list, "test");
	list.append(&list, "ok");
	list.insert_before(&list, list.first, "insertion");
	list.iter(list.first, print);
	printf("last = %d -- %s\n", list.first->index, (char *)list.first->content);
	//int test = 3;
	//t_element *element = list.search(list.first, &test, search);
	//printf("result = %d -- %s\n", element->index, (char *)element->content);
	list.clear(&list);
	return (0);
}