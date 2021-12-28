// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *args[])
// {
//     int count = 0;
//     int task_size = 0;
//     int *task;
//     scanf("%d", &count);
//     scanf("%d", &task_size);
//     task = (int *)malloc(sizeof(int) * task_size);
//     for (size_t i = 0; i < task_size; i++)
//     {
//         scanf("%d", &task[i]);
//     }
//     int wait_task = 0;
//     int time = 0;
//     for (size_t j = 0; j < task_size; j++)
//     {

//         wait_task += task[j];
//         wait_task = wait_task - count;
//         time++;
//         if (wait_task < 0)
//         {
//             wait_task = 0;
//         }
//     }
//     time += wait_task / 3;
//     if (wait_task % 3 != 0)
//     {
//         time++;
//     }
//     printf("%d", time);
//     return 0;
// }

/*
#include <stdlib.h>

#include <stdio.h>

#include <string.h>



int check_char(char *str1, int length1, char *str2, int length2)

{

    for (int i = 0; i < length1; i++)

    {

        for (int j = 0; j < length2; j++)

        {

            if (str1[i] == str2[j])

            {

                return -1;

            }

        }

    }



    return 0;

}



int main(int argc, char *args[])

{



    char str_array[100][50] = {0};

    char str[5000 + 101];

    fgets(str, sizeof(str), stdin);

    int count = 0;

    int last_index = 0;

    for (int i = 0; i < strlen(str); i++)

    {

        if (str[i] == ',' || str[i] == '\n')

        {

            memcpy(str_array[count], str + last_index, i - last_index);

            count++;

            last_index = i + 1;

        }

    }

    int max = 0;

    for (int j = 0; j < count; j++)

    {

        for (size_t k = j + 1; k < count; k++)

        {

            if (0 == check_char(str_array[j], strlen(str_array[j]), str_array[k], strlen(str_array[k])))

            {

                int tmp = strlen(str_array[j]) * strlen(str_array[k]);

                if (tmp > max)

                {

                    max = tmp;

                }

            }

        }

    }

    printf("%d",max);



    return 0;

}



**/

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// typedef struct b_tree
// {
//     b_tree *l_child;
//     b_tree *r_child;
//     char node;
// } B_TREE;

// int gen_child_str(char *parent_str, int parent_length, char *l_child_str, int *l_length, char *r_child_str, int *r_length)
// {
//     char tmp[parent_length];
//     for (size_t i = 0; i < parent_length; i++)
//     {
//         if (parent_str[i] == '{')
//         {
//             memcpy(tmp, parent_str + i + 1, parent_length - 3);
//             break;
//         }
//     }
//     int flag = 0;
//     for (size_t j = 0; j < strlen(tmp); j++)
//     {
//         if (tmp[j] == '{')
//         {
//             flag++;
//         }
//         if (tmp[j] == '}')
//         {
//             flag--;
//             if (flag == 0)
//             {
//                 *l_length = j + 1;
//                 memcpy(l_child_str, tmp, *l_length);
//                 *r_length = strlen(tmp) - j - 3;
//                 memcpy(r_child_str, tmp + j + 2, *r_length);
//                 if (*r_length < 0)
//                 {
//                     *r_length = 0;
//                 }

//                 break;
//             }
//         }
//     }

//     return 0;
// }

// int build_tree(char *node_str, int length, B_TREE *root)
// {
//     if (length == 0)
//     {
//         return 0;
//     }
//     // if (root == nullptr)
//     // {
//     //     root = (B_TREE *)malloc(sizeof(B_TREE));
//     //     memset(root, 0, sizeof(B_TREE));
//     // }

//     root->node = node_str[0];
//     char *l_child_str = (char *)malloc(length);
//     int l_length = 0;
//     char *r_child_str = (char *)malloc(length);
//     int r_length = 0;
//     gen_child_str(node_str, length, l_child_str, &l_length, r_child_str, &r_length);
//     if (l_length != 0)
//     {
//         root->l_child = (B_TREE *)malloc(sizeof(B_TREE));
//     }
//     if (r_child_str != 0)
//     {
//         root->r_child = (B_TREE *)malloc(sizeof(B_TREE));
//     }

//     build_tree(l_child_str, l_length, root->l_child);
//     build_tree(r_child_str, r_length, root->r_child);
//     return 0;
// }
// int show_tree(B_TREE *root)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }
//     show_tree(root->l_child);
//     printf("%c", root->node);
//     show_tree(root->r_child);
//     return 0;
// }

// int main(int argc, char *args[])
// {
//     char node_str[100 * 4];
//     scanf("%s", node_str);
//     B_TREE *root = (B_TREE *)malloc(sizeof(B_TREE));
//     build_tree(node_str, strlen(node_str), root);
//     show_tree(root);
//     return 0;
// }

#include <stdio.h>

int main(int argc, char *args[])
{
    int n;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 2 * n - 1; j++)
        {
            if (i < n - j - 1)
            {
                printf(" ");
            }
            else if (j > n)
            {
                printf("%d", i + (n - j) + 1);
            }
            else
            {
                printf("%d", i - n + j + 1);
            }
        }
        printf("\n");
    }
}