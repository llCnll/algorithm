# leetcode题集

- 辅助工具 run.sh 使用g++快速编译并运行  
    bash run.sh {file_name}.cpp  
    run.sh {file_name}.cpp


## 简单

题目 | 思路
:-: | :-:
[面试题 16.15. 珠玑妙算](https://leetcode-cn.com/problems/master-mind-lcci/) | 正常思路, 把正确答案出现的次数聚合下, 先比较正确 "猜中的", 在比较 "未猜中"
[204. 计数质数](https://leetcode-cn.com/problems/count-primes/) | 打表
[第 k 个缺失的正整数](https://leetcode-cn.com/problems/kth-missing-positive-number/) | 暴力 (应该可以优化)
[数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/) | 暴力(应该可以优化)
[替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/) | 暴力(应该可以优化), 新创建一个数组, 注意新数组的长度为 3*size+1.
[从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/) | 第一次遍历数量, 第二次遍历倒叙插入到数组
[斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/) | a,b,c
[青蛙跳台阶问题](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)
[爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) | 同上
[旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)
[寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/) | 两两比较非递增则返回, 注意这个数组是递增的情况.
[二进制中1的个数](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/) 
[1的个数](https://leetcode-cn.com/problems/number-of-1-bits/) | 位与运算求个数


## 中等

题目 | 思路
:-: | :-:
[633. 平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/) | 暴力, 减少循环次数 a <= sqrt(c/2), 再看b能不能被整开方
[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) | 遍历一次就能出结果, 要注意替换指针的顺序, 不能断链了. 使用头节点的方式, 最后返回 头节点->next
[92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/) | 正序链表+倒叙链表+正序链表
