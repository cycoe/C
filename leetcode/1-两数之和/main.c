/* 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 */

/* 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。 */

/* 示例: */

/* 给定 nums = [2, 7, 11, 15], target = 9 */

/* 因为 nums[0] + nums[1] = 2 + 7 = 9 */
/* 所以返回 [0, 1] */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/two-sum */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <malloc.h>
#include <memory.h>
#include <stdlib.h>

// hash map node
struct hash_data {
    int key;
    int data;
    struct hash_data * next;
};

struct hash_table {
    struct hash_data ** head;
    int hash_width;
};

// 初始化
int hash_init(struct hash_table * table, int width) {
    if (width <= 0)
        return -1;
    struct hash_data ** tmp = malloc(sizeof(struct hash_data *) * width);
    table->head = tmp;
    memset(table->head, 0, sizeof(struct hash_data *) * width);
    if (table->head == NULL)
        return -1;
    table->hash_width = width;
    return 0;
}

// 釋放内存
void hash_free(struct hash_table table) {
    if (table.head != NULL) {
        for (int i = 0; i < table.hash_width; i++) {
            struct hash_data * element_head = table.head[i];
            while (element_head != NULL) {
                struct hash_data * temp = element_head;
                element_head = element_head->next;
                free(temp);
            }
        }
        free(table.head);
        table.head = NULL;
    }
    table.hash_width = 0;
}

int hash_addr(struct hash_table table, int key) {
    int addr = abs(key) % table.hash_width;
    return addr;
}

// 增加节点
int hash_insert(struct hash_table table, int key, int value) {
    struct hash_data * tmp = malloc(sizeof(struct hash_data));
    if (tmp == NULL)
        return -1;
    tmp->key = key;
    tmp->data = value;
    int k = hash_addr(table, key);
    tmp->next = table.head[k];
    table.head[k] = tmp;
    return 0;
}

// 查找
struct hash_data * hash_find(struct hash_table table, int key) {
    int k = hash_addr(table, key);
    struct hash_data * element_head = table.head[k];
    while (element_head != NULL) {
        if (element_head->key == key) {
            return element_head;
        }
        element_head = element_head->next;
    }
    return NULL;
}

int * twoSum(int * nums, int numsSize, int target, int * returnSize) {
    int * ret = (int *) malloc(sizeof(int) * 2);
    * returnSize = 0;
    struct hash_table table;
    hash_init(&table, 100);
    for (int i = 0; i < numsSize; i++) {
        int key = target - nums[i];
        struct hash_data * data = hash_find(table, key);
        if (data != NULL && data->data != i) {
            ret[1] = i;
            ret[0] = data->data;
            *returnSize = 2;
            break;
        }
        hash_insert(table, nums[i], i);
    }
    hash_free(table);
    return ret;
}

int main(int argc, char *argv[])
{
    int a[] = {1, 3, 5, 6, 7, 8};
    int target = 6;
    int returnSize;
    int * index = twoSum(a, 6, target, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d: %d\n", i, index[i]);
    }
    return 0;
}
