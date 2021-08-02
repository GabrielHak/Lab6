//#include <stdlib.h>
#include "string.h"

int main() {
    char *str1 = "Hello World!";
    char *str2 = "Bye Bye World!";

    string s_str1 = string_create(str1);
    string s_str2 = string_create(str2);

    if(string_less(s_str1, s_str2)){
        printf("%s < %s\n", string_ref(s_str1), string_ref(s_str2));
    }else if(string_eq(s_str1, s_str2)){
        printf("%s == %s\n", string_ref(s_str1), string_ref(s_str2));
    }else{
        printf("%s > %s\n", string_ref(s_str1), string_ref(s_str2));
    }

    s_str1 = string_destroy(s_str1);
    s_str2 = string_destroy(s_str2);

    return 0;
}