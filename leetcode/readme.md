# leetcode题集

- 辅助工具 run.sh 使用g++快速编译并运行  
    bash run.sh {file_name}.cpp  
    run.sh {file_name}.cpp


## 简单

代码 | 题目 | 思路
:-: | :-: | :-:
[master-mind-lcci.cpp](master-mind-lcci.cpp) | [面试题 16.15. 珠玑妙算](https://leetcode-cn.com/problems/master-mind-lcci/) | 正常思路, 把正确答案出现的次数聚合下, 先比较正确 "猜中的", 在比较 "未猜中"
[count-primes.cpp](count-primes.cpp) | [204. 计数质数](https://leetcode-cn.com/problems/count-primes/) | 打表
[reverse-linked-list.cpp](reverse-linked-list.cpp) <br/> [fan-zhuan-lian-biao-lcof.cpp](fan-zhuan-lian-biao-lcof.cpp) | [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) <br/> [剑指 Offer 24. 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/) | 遍历一次就能出结果, 要注意替换指针的顺序, 不能断链了. 使用头节点的方式, 最后返回 头节点->next
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
[shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof.cpp](shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof.cpp) <br/> [majority-element.cpp](majority-element.cpp) | [剑指 Offer 39. 数组中出现次数超过一半的数字](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/) <br/> [169. 多数元素](https://leetcode-cn.com/problems/majority-element/) | 使用快排的思想, 右边界小于mid, 左边界大于mid, 就不排序了(节省时间), 直到中间值为mid.
[zui-xiao-de-kge-shu-lcof.cpp](zui-xiao-de-kge-shu-lcof.cpp) | [剑指 Offer 40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/) | 使用快排的思想, 右边界小于k, 左边界大于k的时候, 就不排序, 直到中间值为k.
[di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof.cpp](di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof.cpp) | [剑指 Offer 50. 第一个只出现一次的字符](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/) | 暴力 二维数组 0-出现次序, 1-次数
[zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof.cpp](zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof.cpp) <br/> [find-first-and-last-position-of-element-in-sorted-array.cpp](find-first-and-last-position-of-element-in-sorted-array.cpp) | [剑指 Offer 53 - I. 在排序数组中查找数字 I](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/) <br/> [34.在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | 二分查找. 好久没写过了, 要注意 区间只有一个值的情况. 目前是一直找的情况, 应该是可以优化的, 找到一处就停止, 然后在这个点前后遍历.
[que-shi-de-shu-zi-lcof.cpp](que-shi-de-shu-zi-lcof.cpp) | [剑指 Offer 53 - II. 0～n-1中缺失的数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/) | 暴力, 直接遍历.
[fan-zhuan-dan-ci-shun-xu-lcof.cpp](fan-zhuan-dan-ci-shun-xu-lcof.cpp) <br/> [reverse-words-in-a-string.cpp](reverse-words-in-a-string.cpp)| [剑指 Offer 58 - I. 翻转单词顺序](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/) <br> [151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/) | 反转整串, 在反转单词, 最后去掉空格. (应该有什么更快的方法吧)
[zuo-xuan-zhuan-zi-fu-chuan-lcof.cpp](zuo-xuan-zhuan-zi-fu-chuan-lcof.cpp) | [剑指 Offer 58 - II. 左旋转字符串](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/) | 偷懒的做法 创建strlen(s)+n的长度, 最后返回s+n


## 中等

代码 | 题目 | 思路
:-: | :-: | :-:
[sum-of-square-numbers.cpp](sum-of-square-numbers.cpp) | [633. 平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/) | 暴力, 减少循环次数 `a <= sqrt(c/2)`, 再看b能不能被整开方
[reverse-linked-list-ii.cpp](reverse-linked-list-ii.cpp) | [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/) | 正序链表+倒叙链表+正序链表
