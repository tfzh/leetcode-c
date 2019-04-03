#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target);

int main() {
    int a[7] = {20,7,11,13,18,45,36};
    int tag = 24;
    int *num = twoSum(a,7,tag);
    printf("%d-%d\n",num[0],num[1]);
    return 0;
}

int* twoSum(int* nums, int numsSize, int target) {
    int min = 2147483647;
    int i = 0;
    //找出数组最小值
    for (i = 0; i < numsSize; i++) {
      if (nums[i] < min) {
          min = nums[i];
      }
    }
    //显然，只需考虑小于(target - min)的项
    int max = target - min;
    //hash的长度，即最大值减去最小值+1，因为是纯数字，使用数组即可 value和索引交换位置储存
    int len = max - min + 1;
    int *table = (int*)malloc(len*sizeof(int));
    int *indice = (int*)malloc(2*sizeof(int));
    for (i = 0; i < len; i++) {
        table[i] = -1;         //hash初值
    }
    for (i = 0; i < numsSize; i++) {
        //只需小于等于max的项
        if (nums[i] <= max) {
            //满足相加为target
            if (table[target-nums[i]-min] != -1) {
                indice[0] = table[target-nums[i] - min];
                indice[1] = i;
                return indice;
            }
            table[nums[i]-min] = i;
        }
    }
    free(table);
    return indice;
}
