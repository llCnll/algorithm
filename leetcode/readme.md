# leetcode题集

- 辅助工具 run.sh 使用g++快速编译并运行  
    bash run.sh {file_name}.cpp  
    run.sh {file_name}.cpp


## 简单

代码 | 题目 | 思路
:-: | :-: | :-:
[master-mind-lcci.cpp](master-mind-lcci.cpp) | [面试题 16.15. 珠玑妙算](https://leetcode-cn.com/problems/master-mind-lcci/) | 正常思路, 把正确答案出现的次数聚合下, 先比较正确 "猜中的", 在比较 "未猜中"
[count-primes.cpp](count-primes.cpp) | [204. 计数质数](https://leetcode-cn.com/problems/count-primes/) | 打表
[kth-missing-positive-number.cpp](kth-missing-positive-number.cpp) | [1539. 第 k 个缺失的正整数](https://leetcode-cn.com/problems/kth-missing-positive-number/) | 暴力 (应该可以优化)
[shu-zu-zhong-zhong-fu-de-shu-zi-lcof.cpp](shu-zu-zhong-zhong-fu-de-shu-zi-lcof.cpp) | [剑指 Offer 03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/) | 暴力(应该可以优化)
[ti-huan-kong-ge-lcof.cpp](ti-huan-kong-ge-lcof.cpp) | [剑指 Offer 05. 替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/) | 暴力(应该可以优化), 新创建一个数组, 注意新数组的长度为 3*size+1.
[cong-wei-dao-tou-da-yin-lian-biao-lcof.cpp](cong-wei-dao-tou-da-yin-lian-biao-lcof.cpp) | [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/) | 第一次遍历数量, 第二次遍历倒叙插入到数组
[fei-bo-na-qi-shu-lie-lcof.cpp](fei-bo-na-qi-shu-lie-lcof.cpp) | [剑指 Offer 10- I. 斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/) | a,b,c
[qing-wa-tiao-tai-jie-wen-ti-lcof.cpp](qing-wa-tiao-tai-jie-wen-ti-lcof.cpp) <br/> [climbing-stairs.cpp](climbing-stairs.cpp) | [剑指 Offer 10- II. 青蛙跳台阶问题](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/) <br/> [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) | 同上
[xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.cpp](xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.cpp) <br/> [find-minimum-in-rotated-sorted-array-ii.cpp](find-minimum-in-rotated-sorted-array-ii.cpp) | [剑指 Offer 11. 旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/) <br/> [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/) | 两两比较非递增则返回, 注意这个数组是递增的情况.
[da-yin-cong-1dao-zui-da-de-nwei-shu-lcof.cpp](da-yin-cong-1dao-zui-da-de-nwei-shu-lcof.cpp) | [剑指 Offer 17. 打印从1到最大的n位数](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/) | 直接遍历不就好了..
[shan-chu-lian-biao-de-jie-dian-lcof.cpp](shan-chu-lian-biao-de-jie-dian-lcof.cpp) | [剑指 Offer 18. 删除链表的节点](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/) | 题目中要求删除一个, 我这个全删了. 应该也没啥问题.
[diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof.cpp](diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof.cpp) | [剑指 Offer 21. 调整数组顺序使奇数位于偶数前面](https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/) | 头尾指针.
[lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.cpp](lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.cpp) | [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/) | 双指针.
[he-bing-liang-ge-pai-xu-de-lian-biao-lcof.cpp](he-bing-liang-ge-pai-xu-de-lian-biao-lcof.cpp) <br/> [merge-two-sorted-lists.cpp](merge-two-sorted-lists.cpp) | [剑指 Offer 25. 合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/) <br/> [合并两个有序链表](合并两个有序链表) | 多弄一个头节点, 最后返回的时候是头节点->next, 按顺序合并就行了.


## 中等

代码 | 题目 | 思路
:-: | :-: | :-:
[sum-of-square-numbers.cpp](sum-of-square-numbers.cpp) | [633. 平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/) | 暴力, 减少循环次数 a <= sqrt(c/2), 再看b能不能被整开方
[reverse-linked-list.cpp](reverse-linked-list.cpp) | [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) | 遍历一次就能出结果, 要注意替换指针的顺序, 不能断链了. 使用头节点的方式, 最后返回 头节点->next
[reverse-linked-list-ii.cpp](reverse-linked-list-ii.cpp) | [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/) | 正序链表+倒叙链表+正序链表
