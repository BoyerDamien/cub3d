#include "./includes/libft.h"

void print(t_element *element){
    ft_printf("element %d = %s\n", element->index, (char *)element->content);
}

int main(void){

    t_list test = ft_list();
    test.append(&test, "ok1");
    test.append(&test, "ok2");
    test.append(&test, "ok3");
    test.append(&test, "ok4");
    test.append(&test, "ok5");
    test.append(&test, "ok6");
    test.remove(&test, test.get(&test, 2));
    test.iter(test.first, print);
    ft_printf("\n\n");
    test.remove(&test, test.first);
    test.iter(test.first, print);
    test.clear(&test);
    return(0);
}