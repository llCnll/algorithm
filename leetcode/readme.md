# leetcode题集

- 辅助工具 run.sh 使用g++快速编译并运行  
    bash run.sh {file_name}.cpp  
    run.sh {file_name}.cpp


## 简单

耗时 | 代码 | 题目 | 思路
:-: | :-: | :-: | :-:
^ | [master-mind-lcci.cpp](master-mind-lcci.cpp) | [面试题 16.15. 珠玑妙算](https://leetcode-cn.com/problems/master-mind-lcci/) | 正常思路, 把正确答案出现的次数聚合下, 先比较正确 "猜中的", 在比较 "未猜中"
^ | [count-primes.cpp](count-primes.cpp) | [204. 计数质数](https://leetcode-cn.com/problems/count-primes/) | 打表
^ | [reverse-linked-list.cpp](reverse-linked-list.cpp) <br/> [fan-zhuan-lian-biao-lcof.cpp](fan-zhuan-lian-biao-lcof.cpp) | [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) <br/> [剑指 Offer 24. 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/) | 遍历一次就能出结果, 要注意替换指针的顺序, 不能断链了. 使用头节点的方式, 最后返回 头节点->next
^ | [kth-missing-positive-number.cpp](kth-missing-positive-number.cpp) | [1539. 第 k 个缺失的正整数](https://leetcode-cn.com/problems/kth-missing-positive-number/) | 暴力 (应该可以优化)
^ | [shu-zu-zhong-zhong-fu-de-shu-zi-lcof.cpp](shu-zu-zhong-zhong-fu-de-shu-zi-lcof.cpp) | | [剑指 Offer 03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/) | 暴力(应该可以优化)
^ | [ti-huan-kong-ge-lcof.cpp](ti-huan-kong-ge-lcof.cpp) | | [剑指 Offer 05. 替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/) | 暴力(应该可以优化), 新创建一个数组, 注意新数组的长度为 3*size+1.
^ | [cong-wei-dao-tou-da-yin-lian-biao-lcof.cpp](cong-wei-dao-tou-da-yin-lian-biao-lcof.cpp) | [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/) | 第一次遍历数量, 第二次遍历倒叙插入到数组
^ | [fei-bo-na-qi-shu-lie-lcof.cpp](fei-bo-na-qi-shu-lie-lcof.cpp) | [剑指 Offer 10- I. 斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/) | a,b,c
^ | [qing-wa-tiao-tai-jie-wen-ti-lcof.cpp](qing-wa-tiao-tai-jie-wen-ti-lcof.cpp) <br/> [climbing-stairs.cpp](climbing-stairs.cpp) | [剑指 Offer 10- II. 青蛙跳台阶问题](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/) <br/> [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) | 同上
^ | [xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.cpp](xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.cpp) <br/> [find-minimum-in-rotated-sorted-array-ii.cpp](find-minimum-in-rotated-sorted-array-ii.cpp) | [剑指 Offer 11. 旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/) <br/> [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/) | 两两比较非递增则返回, 注意这个数组是递增的情况.
^ | [da-yin-cong-1dao-zui-da-de-nwei-shu-lcof.cpp](da-yin-cong-1dao-zui-da-de-nwei-shu-lcof.cpp) | [剑指 Offer 17. 打印从1到最大的n位数](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/) | 直接遍历不就好了..
^ | [shan-chu-lian-biao-de-jie-dian-lcof.cpp](shan-chu-lian-biao-de-jie-dian-lcof.cpp) | [剑指 Offer 18. 删除链表的节点](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/) | 题目中要求删除一个, 我这个全删了. 应该也没啥问题.
^ | [diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof.cpp](diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof.cpp) | [剑指 Offer 21. 调整数组顺序使奇数位于偶数前面](https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/) | 头尾指针.
^ | [lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.cpp](lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.cpp) | [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/) | 双指针.
^ | [he-bing-liang-ge-pai-xu-de-lian-biao-lcof.cpp](he-bing-liang-ge-pai-xu-de-lian-biao-lcof.cpp) <br/> [merge-two-sorted-lists.cpp](merge-two-sorted-lists.cpp) | [剑指 Offer 25. 合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/) <br/> [合并两个有序链表](合并两个有序链表) | 多弄一个头节点, 最后返回的时候是头节点->next, 按顺序合并就行了.
^ | [shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof.cpp](shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof.cpp) <br/> [majority-element.cpp](majority-element.cpp) | [剑指 Offer 39. 数组中出现次数超过一半的数字](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/) <br/> [169. 多数元素](https://leetcode-cn.com/problems/majority-element/) | 使用快排的思想, 右边界小于mid, 左边界大于mid, 就不排序了(节省时间), 直到中间值为mid.
^ | [zui-xiao-de-kge-shu-lcof.cpp](zui-xiao-de-kge-shu-lcof.cpp) | [剑指 Offer 40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/) | 使用快排的思想, 右边界小于k, 左边界大于k的时候, 就不排序, 直到中间值为k.
^ | [di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof.cpp](di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof.cpp) | [剑指 Offer 50. 第一个只出现一次的字符](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/) | 暴力 二维数组 0-出现次序, 1-次数
^ | [zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof.cpp](zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof.cpp) <br/> [find-first-and-last-position-of-element-in-sorted-array.cpp](find-first-and-last-position-of-element-in-sorted-array.cpp) | [剑指 Offer 53 - I. 在排序数组中查找数字 I](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/) <br/> [34.在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | 二分查找. 好久没写过了, 要注意 区间只有一个值的情况. 目前是一直找的情况, 应该是可以优化的, 找到一处就停止, 然后在这个点前后遍历.
^ | [que-shi-de-shu-zi-lcof.cpp](que-shi-de-shu-zi-lcof.cpp) | [剑指 Offer 53 - II. 0～n-1中缺失的数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/) | 暴力, 直接遍历.
^ | [fan-zhuan-dan-ci-shun-xu-lcof.cpp](fan-zhuan-dan-ci-shun-xu-lcof.cpp) <br/> [reverse-words-in-a-string.cpp](reverse-words-in-a-string.cpp)| [剑指 Offer 58 - I. 翻转单词顺序](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/) <br> [151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/) | 反转整串, 在反转单词, 最后去掉空格. (应该有什么更快的方法吧)
^ | [zuo-xuan-zhuan-zi-fu-chuan-lcof.cpp](zuo-xuan-zhuan-zi-fu-chuan-lcof.cpp) | [剑指 Offer 58 - II. 左旋转字符串](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/) | 偷懒的做法 创建strlen(s)+n的长度, 最后返回s+n
^ | [er-cha-shu-de-jing-xiang-lcof.cpp](er-cha-shu-de-jing-xiang-lcof.cpp) <br/> [invert-binary-tree.cpp](invert-binary-tree.cpp)| [剑指 Offer 27. 二叉树的镜像](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/) <br> [226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/) | 先序递归, 每次交换两孩子.
^ | [dui-cheng-de-er-cha-shu-lcof.cpp](dui-cheng-de-er-cha-shu-lcof.cpp) <br/> [symmetric-tree.cpp](symmetric-tree.cpp)| [剑指 Offer 28. 对称的二叉树](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/) <br> [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) | 有点绕, 要传两个根节点做比较.
^ | [cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof.cpp](cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof.cpp) <br/> [binary-tree-level-order-traversal.cpp](binary-tree-level-order-traversal.cpp)| [剑指 Offer 32 - II. 从上到下打印二叉树 II](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/) <br> [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) | [借鉴了下](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/comments/246551) 主要再想c有什么动态扩容的东西.. 发现直接1000*1000就好了. 原来也想二维数组实际上也是一维线性的, 中间差几个指针就好了. 借鉴的这个人方法很巧妙, 可能是因为题目吧, 用的dfs, 而不是bfs. 省去了队列.
^ | [er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof.cpp](er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof.cpp) | [剑指 Offer 54. 二叉搜索树的第k大节点](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/) | 二查搜索树左小右大, 又是取TopK所以有后序遍历.
^ | [er-cha-shu-de-shen-du-lcof.cpp](er-cha-shu-de-shen-du-lcof.cpp) <br/> [maximum-depth-of-binary-tree.cpp](maximum-depth-of-binary-tree.cpp)| [剑指 Offer 55 - I. 二叉树的深度](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/) <br> [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) | 深度遍历就好了.
^ | [ping-heng-er-cha-shu-lcof.cpp](ping-heng-er-cha-shu-lcof.cpp) <br/> [balanced-binary-tree.cpp](balanced-binary-tree.cpp)| [剑指 Offer 55 - II. 平衡二叉树](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/) <br> [110. 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/) | 求树高.
^ | [er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof.cpp](er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof.cpp) <br/> [lowest-common-ancestor-of-a-binary-tree.cpp](lowest-common-ancestor-of-a-binary-tree.cpp)| [剑指 Offer 68 - II. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/) <br> [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) | 自己想的方法, 不知道靠谱不, 给每个节点设置val值, 符合第一个值为1,符合第二个值为2, 两个值都符合为3(加法), 那条链上的值都为此值, 最后返回第一个值为3的节点. 使用 LRD 后序遍历
^ | [er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof.cpp](er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof.cpp) <br/> [lowest-common-ancestor-of-a-binary-search-tree.cpp](lowest-common-ancestor-of-a-binary-search-tree.cpp)| [剑指 Offer 68 - I. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/) <br> [235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | 直接用上一题的代码了, 就通过了, 仔细看这个二查搜索树的, 应该是有简单方法吧.
^ | [shun-shi-zhen-da-yin-ju-zhen-lcof.cpp](shun-shi-zhen-da-yin-ju-zhen-lcof.cpp) <br/> [spiral-matrix.cpp](spiral-matrix.cpp)| [剑指 Offer 29. 顺时针打印矩阵](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/) <br> [54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/) | 边界值没处理好, 直接开2倍空间解决...
^ | [lian-xu-zi-shu-zu-de-zui-da-he-lcof.cpp](lian-xu-zi-shu-zu-de-zui-da-he-lcof.cpp) <br/> [maximum-subarray.cpp](maximum-subarray.cpp)| [剑指 Offer 42. 连续子数组的最大和](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/) <br> [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) | 动态规划, 加上当前值比之前的值小, 则重置
^ | [he-wei-sde-liang-ge-shu-zi-lcof.cpp](he-wei-sde-liang-ge-shu-zi-lcof.cpp) | [剑指 Offer 57. 和为s的两个数字](https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/) | 二分查找. 并设置了提前终止的标志, `num[i]<=target/2`
^ | [yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof.cpp](yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof.cpp) | [剑指 Offer 62. 圆圈中最后剩下的数字](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/) | 约瑟夫环 f(n) = (f(n-1) + m) % n
^ | [bu-ke-pai-zhong-de-shun-zi-lcof.cpp](bu-ke-pai-zhong-de-shun-zi-lcof.cpp) | [剑指 Offer 61. 扑克牌中的顺子](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/) | 桶排序, 暴力破解
^ | [bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof.cpp](bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof.cpp) | [剑指 Offer 65. 不用加减乘除做加法](https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/) | 进位&, 值相加^.
^ | [he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof.cpp](he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof.cpp) | [剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) | 滑动窗口
^ | [liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof.cpp](liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof.cpp) <br/> [intersection-of-two-linked-lists.cpp](intersection-of-two-linked-lists.cpp) | [剑指 Offer 52. 两个链表的第一个公共节点](https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/) <br/> [剑指 Offer 52. 两个链表的第一个公共节点](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) | 有点意思, 之前想的是快慢指针, 没想到还有这么巧的方法. (变成我，走过我走过的路。我变成你，走过你走过的路。然后我们便相遇了.)
^ | [is-unique-lcci.cpp](is-unique-lcci.cpp) | [面试题 01.01. 判定字符是否唯一](https://leetcode-cn.com/problems/is-unique-lcci/) | 有个评论写得很好 [https://leetcode-cn.com/problems/is-unique-lcci/comments/562374](https://leetcode-cn.com/problems/is-unique-lcci/comments/562374), 位运算/set/排序. 针对不同情况选择.
^ | [check-permutation-lcci.cpp](check-permutation-lcci.cpp) | [面试题 01.02. 判定是否互为字符重排](https://leetcode-cn.com/problems/check-permutation-lcci/) | 桶(26)set(假定26个字母), 一个串加一个串减, 最后为0.
^ | [string-to-url-lcci.cpp](string-to-url-lcci.cpp) | [面试题 01.03. URL化](https://leetcode-cn.com/problems/string-to-url-lcci/) | 常规操作, 使用strcat会超时.
^ | [palindrome-permutation-lcci.cpp](palindrome-permutation-lcci.cpp) | [面试题 01.04. 回文排列](https://leetcode-cn.com/problems/palindrome-permutation-lcci/) | 统计出现次数, 偶数:出现次数都为偶数, 奇数:仅允许一个字符是奇数, 其他是偶数.
^ | [compress-string-lcci.cpp](compress-string-lcci.cpp) | [面试题 01.06. 字符串压缩](https://leetcode-cn.com/problems/compress-string-lcci/) | 常规操作吧.
^ | [string-rotation-lcci.cpp](string-rotation-lcci.cpp) | [面试题 01.09. 字符串轮转](https://leetcode-cn.com/problems/string-rotation-lcci/) | s2+s2 包含s1, 则为旋转.
^ | [remove-duplicate-node-lcci.cpp](remove-duplicate-node-lcci.cpp) | [面试题 02.01. 移除重复节点](https://leetcode-cn.com/problems/remove-duplicate-node-lcci/) | set集合判断.
^ | [kth-node-from-end-of-list-lcci.cpp](kth-node-from-end-of-list-lcci.cpp) | [面试题 02.02. 返回倒数第 k 个节点](https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/) | 中规中矩.
^ | [delete-middle-node-lcci.cpp](delete-middle-node-lcci.cpp) | [面试题 02.03. 删除中间节点](https://leetcode-cn.com/problems/delete-middle-node-lcci/) | 审题, 只穿要删除的节点. 所以做替换就好了.
^ | [running-sum-of-1d-array.cpp](running-sum-of-1d-array.cpp) | [1480. 一维数组的动态和](https://leetcode-cn.com/problems/running-sum-of-1d-array/) | https://github.com/azl397985856/leetcode/blob/master/thinkings/prefix.md 母题0 前缀和 试试手
^ | [linked-list-cycle.cpp](linked-list-cycle.cpp) | [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) | 快慢指针
^ | [palindrome-number.cpp](palindrome-number.cpp) | [9. 回文数](https://leetcode-cn.com/problems/palindrome-number/) | 用空间换时间.
^ | [valid-parentheses.cpp](valid-parentheses.cpp) | [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/) | 栈, 可能写的不够优雅...
^ | [swap-nodes-in-pairs.cpp](swap-nodes-in-pairs.cpp) | [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/) | 借助头节点, 进行交换.
^ | [remove-element.cpp](remove-element.cpp) | [27. 移除元素](https://leetcode-cn.com/problems/remove-element/) | 前后遍历, 当前值为val, 从后面扔一个值过来.
^ | [search-insert-position.cpp](search-insert-position.cpp) | [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/) | 二分查找.
^ | [longest-common-prefix.cpp](longest-common-prefix.cpp) | [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/) | 暴力... 可优化
^ | [remove-duplicates-from-sorted-list.cpp](remove-duplicates-from-sorted-list.cpp) | [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/) | 先做的82.. 把82题跳过的相关代码删掉就好了, 在额外判断下最后一个节点是否是我们想要的.
^ | [length-of-last-word.cpp](length-of-last-word.cpp) | [58. 最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/) | 倒序, 注意结尾的空格.
^ | [remove-nth-node-from-end-of-list.cpp](remove-nth-node-from-end-of-list.cpp) | [19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/) | 快慢指针, 注意什么时候跳过元素就可以了.
^ | [sorted-merge-lcci.cpp](sorted-merge-lcci.cpp) | [面试题 10.01. 合并排序的数组](https://leetcode-cn.com/problems/sorted-merge-lcci/) | 从队尾倒序遍历, 省很多事情.
^ | [is-subsequence.cpp](is-subsequence.cpp) | [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/) | 双指针, 但是进阶的没想好怎么弄(待优化)
^ | [minimum-depth-of-binary-tree.cpp](minimum-depth-of-binary-tree.cpp) | [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/) | 递归遍历. 当前深度 与 记录的深度 进行比较, 可提前返回(剪枝)
^ | [excel-sheet-column-title.cpp](excel-sheet-column-title.cpp) | [168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/) | 简单的模25,除26.
^ | [excel-sheet-column-number.cpp](excel-sheet-column-number.cpp) | [168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/) | 26进制, 注意结果用 uint.
^ | [valid-anagram.cpp](valid-anagram.cpp) | [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/) | 桶计数.
^ | [maximum-depth-of-binary-tree.cpp](maximum-depth-of-binary-tree.cpp) | [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) | 递归遍历.
^ | [binary-tree-paths.cpp](binary-tree-paths.cpp) | [257. 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/) | 深度优先遍历.
^ | [sum-of-left-leaves.cpp](sum-of-left-leaves.cpp) | [404. 左叶子之和](https://leetcode-cn.com/problems/sum-of-left-leaves/) | 递归遍历, 标记子节点状态.
^ | [happy-number.cpp](happy-number.cpp) | [202. 快乐数](https://leetcode-cn.com/problems/happy-number/) | 当小于10, 并且不等于7的时候, 返回false.
^ | [squares-of-a-sorted-array.cpp](squares-of-a-sorted-array.cpp) | [977. 有序数组的平方](https://leetcode-cn.com/problems/squares-of-a-sorted-array/) | 双指针, 通过绝对值进行比较.
^ | [middle-of-the-linked-list.cpp](middle-of-the-linked-list.cpp) | [876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/) | 快慢指针,快指针指向NULL, 慢指针的位置即所得.
^ | [find-all-numbers-disappeared-in-an-array.cpp](find-all-numbers-disappeared-in-an-array.cpp) | [448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/) | 当前值移动到对应索引位置.
^ | [find-the-duplicate-number.cpp](find-the-duplicate-number.cpp) | [287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/) | 偷个懒, 沿用448的方法, 进阶: 转化成 环链表找入口点问题.
8ms 8mb | [path-sum.cpp](path-sum.cpp) | [112. 路径总和](https://leetcode-cn.com/problems/path-sum/) | 深度递归遍历.
32ms 7mb | [binary-search.cpp](binary-search.cpp) | [704. 二分查找](https://leetcode-cn.com/problems/binary-search/) | 二分查找.
8ms 6.2mb | [find-smallest-letter-greater-than-target.cpp](find-smallest-letter-greater-than-target.cpp) | [744. 寻找比目标字母大的最小字母](https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/) | 二分查找.
96ms 16.1mb | [minimum-absolute-difference.cpp](minimum-absolute-difference.cpp) | [1200. 最小绝对差](https://leetcode-cn.com/problems/minimum-absolute-difference/) | 先排序, 在记录最小差值.
28ms 7.2mb | [assign-cookies.cpp](assign-cookies.cpp) | [455. 分发饼干](https://leetcode.cn/problems/assign-cookies/) | 先排序, 在一次比较即可.
4ms 6.1mb | [merge-sorted-array.cpp](merge-sorted-array.cpp) | [88. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/) | 从后遍历即可.
4ms 5.6mb | [longest-palind.cpp](longest-palindrome.cpp) | [409. 最长回文串](https://leetcode.cn/problems/longest-palindrome/) | 记录每个字母出现的个数,如果是偶数直接加,如果是奇数看情况加,大于1的奇数加-1的值.
56ms 8.4mb | [array-partition-i.cpp](array-partition-i.cpp) | [561. 数组拆分 I](https://leetcode.cn/problems/array-partition/) | 排序,然后选偶数位置.
8ms 6mb | [richest-customer-wealth.cpp](richest-customer-wealth.cpp) | [1672. 最富有客户的资产总量](https://leetcode.cn/problems/richest-customer-wealth/) | 遍历.
0ms 5.8mb | [binary-tree-preorder-traversal.cpp](binary-tree-preorder-traversal.cpp) | [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorde) | 先序遍历.
0ms 5.8mb | [binary-tree-inorder-traversal.cpp](binary-tree-inorder-traversal.cpp) | [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/) | 中序遍历.
0ms 5.7mb | [add-binary.cpp](add-binary.cpp) | [7. 二进制求和](https://leetcode.cn/problems/add-binary/) | 竖式计算.
0ms 5.6mb | [same-tree.cpp](same-tree.cpp) | [100. 相同的树](https://leetcode.cn/problems/same-tree/) | 递归.
4ms 6.1mb | [pascals-triangle.cpp](pascals-triangle.cpp) | [118. 杨辉三角](https://leetcode.cn/problems/pascals-triangle/) | 常规做法.
0ms 5.8mb | [pascals-triangle-ii.cpp](pascals-triangle-ii.cpp) | [119. 杨辉三角 II](https://leetcode.cn/problems/pascals-triangle-ii/) | 常规做法.
204ms 78.5mb | [contains-duplicate-ii.cpp](contains-duplicate-ii.cpp) | [219. 存在重复元素 II](https://leetcode.cn/problems/contains-duplicate-ii/) | 滑动窗口.
4ms 5.1mb | [power-of-two.cpp](power-of-two.cpp) | [231. 2 的幂](https://leetcode.cn/problems/power-of-two/) | 位运算, 按位与.

## 中等

耗时 | 代码 | 题目 | 思路
:-: | :-: | :-: | :-:
^ | [sum-of-square-numbers.cpp](sum-of-square-numbers.cpp) | [633. 平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/) | 暴力, 减少循环次数 `a <= sqrt(c/2)`, 再看b能不能被整开方
^ | [er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof.cpp](er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof.cpp) | [剑指 Offer 54. 二叉搜索树的第k大节点](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/) | 二查搜索树左小右大, 又是取TopK所以有后序遍历.
^ | [reverse-linked-list-ii.cpp](reverse-linked-list-ii.cpp) | [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/) | 正序链表+倒叙链表+正序链表
^ | [er-wei-shu-zu-zhong-de-cha-zhao-lcof.cpp](er-wei-shu-zu-zhong-de-cha-zhao-lcof.cpp) <br/> [search-a-2d-matrix-ii.cpp](search-a-2d-matrix-ii.cpp)| [剑指 Offer 04. 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/) <br> [240. 搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/) | 原来想二份查找的, 后来借鉴了下, 发现变成二查搜索树就简单了很多!
^ | [jian-sheng-zi-lcof.cpp](jian-sheng-zi-lcof.cpp) <br/> [integer-break.cpp](integer-break.cpp)| [剑指 Offer 14- I. 剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/) <br> [343. 整数拆分](https://leetcode-cn.com/problems/integer-break/) | 找规律(数学方法), `1*3<2*2`, 尽可能都是长度都是3. 应该还可以是用动态规划.
^ | [shu-zhi-de-zheng-shu-ci-fang-lcof.cpp](shu-zhi-de-zheng-shu-ci-fang-lcof.cpp) <br/> [powx-n.cpp](powx-n.cpp)| [剑指 Offer 16. 数值的整数次方](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/) <br> [50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/) | 原来是暴力, 但是超时了, 后来就两两相乘那么做降为logn(快速幂)
^ | [zi-fu-chuan-de-pai-lie-lcof.cpp](zi-fu-chuan-de-pai-lie-lcof.cpp) | [剑指 Offer 38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/) | 回溯+剪枝(剪枝条件很关键, 前一个节点相同且选择过)
^ | [shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof.cpp](shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof.cpp) <br/> [nth-digit.cpp](nth-digit.cpp)| [剑指 Offer 44. 数字序列中某一位的数字](https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/) <br> [400. 第 N 位数字](https://leetcode-cn.com/problems/nth-digit/) | 找规律, 区分当前数字的位数 --> 返回第几位.
^ | [ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof.cpp](ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof.cpp) | [剑指 Offer 45. 把数组排成最小的数](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/) | 想复杂了... 见__QsortComp2, 后来想了下局部最小, 最后推出全最小.
^ | [ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof.cpp](ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof.cpp) | [剑指 Offer 46. 把数字翻译成字符串](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/) | 回溯+剪枝.
^ | [li-wu-de-zui-da-jie-zhi-lcof.cpp](li-wu-de-zui-da-jie-zhi-lcof.cpp) | [剑指 Offer 47. 礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/) | 动态规划, 取左和上的最大值.
^ | [zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof.cpp](zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof.cpp) <br/> [longest-substring-without-repeating-characters.cpp](longest-substring-without-repeating-characters.cpp)| [剑指 Offer 48. 最长不含重复字符的子字符串](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/) <br> [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) | 滑动窗口 +桶标记是否存在. 看到更好的方案是这个桶可以记录出现的下标.
^ | [chou-shu-lcof.cpp](chou-shu-lcof.cpp) <br/> [ugly-number-ii.cpp](ugly-number-ii.cpp)| [剑指 Offer 49. 丑数](https://leetcode-cn.com/problems/chou-shu-lcof/) <br> [264. 丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/) | 打表.
^ | [shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof.cpp](shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof.cpp) | [剑指 Offer 56 - I. 数组中数字出现的次数](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/) | 异或+分组(注意操作符的优先以级!)
^ | [shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof.cpp](shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof.cpp) | [剑指 Offer 56 - II. 数组中数字出现的次数 II](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/) | 32位分别遍历数组取次数, 模3不为0表示是多出来的数字的. (进阶 数字电路: [K：剑指offer-56 题解 谁说数字电路的知识不能用到算法中？从次数统计到逻辑表达式的推导，一文包你全懂](https://www.cnblogs.com/MyStringIsNotNull/p/12585218.html))
^ | [nge-tou-zi-de-dian-shu-lcof.cpp](nge-tou-zi-de-dian-shu-lcof.cpp) | [剑指 Offer 60. n个骰子的点数](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/) | 递推f(n)建立在f(n-1)之上, 概率又相互独立, /6即可, 然后在累加.
^ | [gu-piao-de-zui-da-li-run-lcof.cpp](gu-piao-de-zui-da-li-run-lcof.cpp) <br/> [best-time-to-buy-and-sell-stock.cpp](best-time-to-buy-and-sell-stock.cpp)| [剑指 Offer 63. 股票的最大利润](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/) <br/> [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) | 动态规划(常规思路) result = max(result, cur_price - min_price).
^ | [qiu-12n-lcof.cpp](qiu-12n-lcof.cpp) | [剑指 Offer 64. 求1+2+…+n](https://leetcode-cn.com/problems/qiu-12n-lcof/) | 移位运算, (阴差阳错的发现这是快速乘, 但是还是有点差距)
^ | [gou-jian-cheng-ji-shu-zu-lcof.cpp](gou-jian-cheng-ji-shu-zu-lcof.cpp) | [剑指 Offer 66. 构建乘积数组](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/) | 维护两个数组一个正向的乘积, 一个逆向的乘积, 最终结果为 正*逆.
^ | [ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof.cpp](ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof.cpp) <br/> [string-to-integer-atoi.cpp](string-to-integer-atoi.cpp)| [剑指 Offer 67. 把字符串转换成整数](https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/) <br/> [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/) | 暴力, 使用longlong类型, 最后判断下有没有越界.
^ | [zhong-jian-er-cha-shu-lcof.cpp](zhong-jian-er-cha-shu-lcof.cpp) <br/> [construct-binary-tree-from-preorder-and-inorder-traversal.cpp](construct-binary-tree-from-preorder-and-inorder-traversal.cpp)| [剑指 Offer 07. 重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/) <br/> [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | 写了100行...感觉有点蠢, 额外维护inorder长度的数组, 标记按照中序遍历的节点是否已添加到走过了, 之后就是递归构建左右子树(递归左右子树还是两个方法...应该可以优化合并). 官方思路还有个迭代.
^ | [cong-shang-dao-xia-da-yin-er-cha-shu-lcof.cpp](cong-shang-dao-xia-da-yin-er-cha-shu-lcof.cpp) | [剑指 Offer 32 - I. 从上到下打印二叉树](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/) | 层次遍历, 注意边界就好了.
^ | [cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof.cpp](cong-shang-dao-xia-da-yin-er-cha-shu--iii-lcof.cpp) | [剑指 Offer 32 - III. 从上到下打印二叉树 III](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/) | 继2之后, 在偶数层倒序下就好了.
^ | [er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof.cpp](er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof.cpp) | [剑指 Offer 33. 二叉搜索树的后序遍历序列](剑指 Offer 33. 二叉搜索树的后序遍历序列) | 递归, 将区间分为 左子树-右子树-根, 在临界值上花了点功夫...
^ | [er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof.cpp](er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof.cpp) <br/> [path-sum-ii.cpp](path-sum-ii.cpp)| [剑指 Offer 34. 二叉树中和为某一值的路径](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/) <br/> [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/) | 一直超时... 原因就是一开始就初始化二维数组的行, 后来变成要赋值的时候初始化行就好了, 以及复制数组的时候用memcpy能快很多, 而且简短.值可以为负数, 所以不能提前终止. dfs算法.
^ | [er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof.cpp](er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof.cpp) | [剑指 Offer 36. 二叉搜索树与双向链表](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/) | 递归, 左子树的最右节点 -- 根 -- 右子树最左节点.
^ | [ju-zhen-zhong-de-lu-jing-lcof.cpp](ju-zhen-zhong-de-lu-jing-lcof.cpp) <br/> [word-search.cpp](word-search.cpp)| [剑指 Offer 12. 矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/) <br/> [79. 单词搜索](https://leetcode-cn.com/problems/word-search/) | 暴力 + dfs.
^ | [ji-qi-ren-de-yun-dong-fan-wei-lcof.cpp](ji-qi-ren-de-yun-dong-fan-wei-lcof.cpp) | [剑指 Offer 13. 机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/) | 暴力 + dfs.
^ | [one-away-lcci.cpp](one-away-lcci.cpp) | [面试题 01.05. 一次编辑](https://leetcode-cn.com/problems/one-away-lcci/) | 比较长度, 当对位不同的时候, 分别三种操作, 看是否满足(先看长度, 再看对位).
^ | [fu-za-lian-biao-de-fu-zhi-lcof.cpp](fu-za-lian-biao-de-fu-zhi-lcof.cpp) <br/> [copy-list-with-random-pointer.cpp](copy-list-with-random-pointer.cpp)| [剑指 Offer 35. 复杂链表的复制](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/) <br/> [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/) | 要保留原链表的格式. 遍历三次. 1.复制节点 2.更新random 3.复原.
^ | [ZVAVXX.cpp](ZVAVXX.cpp) <br/> [subarray-product-less-than-k.cpp](subarray-product-less-than-k.cpp)| [剑指 Offer II 009. 乘积小于 K 的子数组](https://leetcode-cn.com/problems/ZVAVXX/) <br/> [713. 乘积小于K的子数组](https://leetcode-cn.com/problems/subarray-product-less-than-k/) | 滑动窗口+找规律(每次窗口长度加一, count就加上窗口大小 比如窗口是 (10, 5) 下一窗口是 (10, 5, 1), 新增[(10, 5, 1), (5, 1), (1)] 一共3个, 即滑动窗口大小)
^ | [add-two-numbers.cpp](add-two-numbers.cpp) | [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/) | 注意进位就好了.
^ | [longest-palindromic-substring.cpp](longest-palindromic-substring.cpp) | [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/) | 反转 + 公共字串(最后一项那啥可能需要注意下, 公共字串不一定是回文序列, 要额外判断), 参考: https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/
^ | [longest-increasing-subsequence.cpp](longest-increasing-subsequence.cpp) | [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/) | 动态规划, n^2复杂度, 可以优化为nlogn...
^ | [remove-duplicates-from-sorted-array-ii.cpp](remove-duplicates-from-sorted-array-ii.cpp) | [80. 删除有序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/) | 遍历一遍出结果.
^ | [remove-duplicates-from-sorted-list-ii.cpp](remove-duplicates-from-sorted-list-ii.cpp) | [82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/) | 快慢指针, 当有重复的时候慢指针不着急移动, 可能下一组还是重复的.
^ | [permutations.cpp](permutations.cpp) | [46. 全排列](https://leetcode-cn.com/problems/permutations/) | 递归+回溯
^ | [permutations-ii.cpp](permutations-ii.cpp) | [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/) | 递归+回溯+剪枝, 剪枝使用的是set判断该轮是否使用过. 应该还可以优化, 才超过10%...
^ | [flatten-binary-tree-to-linked-list.cpp](flatten-binary-tree-to-linked-list.cpp) | [114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/) | 判断是否有左子树, 有的话插入到当前节点与右节点中间. 递归.
^ | [find-peak-element.cpp](find-peak-element.cpp) | [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/) | 二分查找. 处理好边界值.
^ | [linked-list-cycle-ii.cpp](linked-list-cycle-ii.cpp) | [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/) | [参考评论](https://leetcode-cn.com/problems/linked-list-cycle-ii/comments/52525) 快慢指针相遇后, 相遇点与起点在一起走, 相遇即为入口点.
^ | [house-robber.cpp](house-robber.cpp) | [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/) | 动态规划, (i)+(i-2)的值 与 (i-1)比较大小.
^ | [generate-parentheses.cpp](generate-parentheses.cpp) | [generate-parentheses](https://leetcode-cn.com/problems/generate-parentheses/) | 递归, 由于用的全局变量, 每次估计没初始化, 导致还保留上次的值, 坑死我了.
^ | [kth-largest-element-in-an-array.cpp](kth-largest-element-in-an-array.cpp) | [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/) | 快排.
^ | [jump-game.cpp](jump-game.cpp) | [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/) | 遍历当前节点+跳跃值 >= 数组长度.
^ | [coin-change.cpp](coin-change.cpp) | [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) | 动态规划, 去当前值-当前硬币的值 + 1, 即为当前最合适的值. 遍历取最小的值.
^ | [minimum-size-subarray-sum.cpp](minimum-size-subarray-sum.cpp) | [209. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/) | 滑动窗口, 注意边界值... 待优化: nlogn
^ | [fruit-into-baskets.cpp](fruit-into-baskets.cpp) | [904. 水果成篮](https://leetcode-cn.com/problems/fruit-into-baskets/) | 滑动窗口, 使用变量记录当前种类, 使用桶记录数量.
^ | [merge-intervals.cpp](merge-intervals.cpp) | [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/) | 先排序, 在进行合并, 之前使用描点的方式,有问题, 比如 (1,4) (5,6) 会被合并成(1,6)
92ms 17.2mb | [find-all-duplicates-in-an-array.cpp](find-all-duplicates-in-an-array.cpp) | [442. 数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/) | 同448, 循环交换, 最后在进行遍历.
56ms 732.6mb <br/> 8ms 188.7mb| [binary-tree-level-order-traversal-ii.cpp](binary-tree-level-order-traversal-ii.cpp) | [107. 二叉树的层序遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/) | 包装一层, 记录深度, 层次遍历, 最后翻转. <br/> 使用深度遍历, 取巧的方式, 使用返回列作为当前行的总数.
20ms 182.7mb | [binary-tree-zigzag-level-order-traversal.cpp](binary-tree-zigzag-level-order-traversal.cpp) | [103. 二叉树的锯齿形层序遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/) | 同107第二种方案,使用深度遍历, 取巧的方式, 使用返回列作为当前行的总数. 对奇数行进行反转排序.
12ms 9.8mb | [average-of-levels-in-binary-tree.cpp](average-of-levels-in-binary-tree.cpp) | [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/) | 深度遍历, 记录每行数据和数量.
12ms 8.8mb | [populating-next-right-pointers-in-each-node.cpp](populating-next-right-point.cpp) | [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/) | 包装一层, 记录深度, 层次遍历, 如果当前深度与队列一个的深度一样则拼接, 否则为NULL. 可能会有优化方案吧, 毕竟时间复杂度不是 常量级别.
0ms 6mb | [sum-root-to-leaf-numbers.cpp](sum-root-to-leaf-numbers.cpp) | [129. 求根节点到叶节点数字之和](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/) | 深度递归遍历.
4ms 6.6mb | [subsets.cpp](subsets.cpp) | [78. 子集](https://leetcode-cn.com/problems/subsets/) | 在原结果的基础上, 复制一份添加当前值.
8ms 6.9mb | [subsets-ii.cpp](subsets-ii.cpp) | [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/) | 在78的基础上(在原结果的基础上, 复制一份添加当前值.), 增一些操作. 1) 现将原数组排序, 2) 如果当前值与前一个值相同, 则只追加上次那个数添加的部分, 不相同则将结果全部遍历添加一份出来.
4ms 17.6mb | [letter-case-permutation/submissions.cpp](letter-case-permutation/submissions.cpp) | [784. 字母大小写全排列](https://leetcode-cn.com/problems/letter-case-permutation/) | 递归回溯,先全部转成小写,判断的时候就容易多了, 是字母, 就把大小写两个分支加上, 数字就不动.
20ms 10.2mb | [single-element-in-a-sorted-array.cpp](single-element-in-a-sorted-array.cpp) | [540. 有序数组中的单一元素](https://leetcode-cn.com/problems/single-element-in-a-sorted-array/) | 二分查找,n为偶数且n+1 相等, 则找右区间. 反之左区间.相邻元素不相等, 则返回当前下标.
8ms 11.9mb | [longest-common-subsequence.cpp](longest-common-subsequence.cpp) | [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/) | 动态转移方程, 相等:dp[i-1][j-1]+1, 不相等max(dp[i-1][j],dp[i][j-1]).
40ms 13.5mb | [smallest-k-lcc.cpp](smallest-k-lcc.cpp) | [面试题 17.14. 最小K个数](https://leetcode) | 快速排序.
8ms 10.1mb | [kth-smallest-element-in-a-bst.cpp](kth-smallest-element-in-a-bst.cpp) | [230. 二叉搜索树中第K小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/) | 二叉搜索树左小右大, 左根右遍历.
92ms 19.3mb | [product-of-array-except-self.cpp](product-of-array-except-self.cpp) | [238. 除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/) | 左乘积 * 右乘积, 边界用1表示.
76ms 11.3mb | [container-with-most-water.cpp](container-with-most-water.cpp) | [11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) | 1.暴力超时, 2.双指针,每次只移动短指针.
1300ms 7.7mb | [partitioning-into-minimum-number-of-deci-binary-numbers.cpp](partitioning-into-minimum-number-of-deci-binary-numbers.cpp) | [1689. 十-二进制数的最少数目](https://leetcode.cn/problems/partitioning-into-minimum-number-of-deci-binary-numbers/) | 实际上就是看字符串的最大值是多少.
0ms 9.3mb | [get-kth-magic-n.cpp](get-kth-magic-number-lcci.cpp) | [面试题 17.09. 第](面试题 17.09. 第 k 个数) | 三指针.


## 困难

耗时 | 代码 | 题目 | 思路
:-: | :-: | :-: | :-:
^ | [hua-dong-chuang-kou-de-zui-da-zhi-lcof.cpp](hua-dong-chuang-kou-de-zui-da-zhi-lcof.cpp) <br/> [sliding-window-maximum.cpp](sliding-window-maximum.cpp)| [剑指 Offer 59 - I. 滑动窗口的最大值](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/) <br/> [239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/) |这人说的很好[从哨兵到数据结构的思维推进](https://leetcode-cn.com/problems/sliding-window-maximum/solution/cong-shao-bing-dao-shu-ju-jie-gou-de-si-kuti2/), 做剑指offer的时候用的 二审此题 的方法, 如果遇到单调的话, 就会超时(看一年前别人的提交是通过的, 估计更新了测试用例). 更新后的方法: 维护一个单调队列, 队尾的值小于要进来的值则出队.
^ | [xu-lie-hua-er-cha-shu-lcof.cpp](xu-lie-hua-er-cha-shu-lcof.cpp) <br/> [aserialize-and-deserialize-binary-tree.cpp](serialize-and-deserialize-binary-tree.cpp)| [剑指 Offer 37. 序列化二叉树](https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/) <br/> [297. 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/) | 正常做就好了, (buffer overflow detected, ans数组开小了).
^ | [shu-zu-zhong-de-ni-xu-dui-lcof.cpp](shu-zu-zhong-de-ni-xu-dui-lcof.cpp) | [剑指 Offer 51. 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/) | 归并排序.
8ms 6.8mb | [reverse-nodes-in-k-group.cpp](reverse-nodes-in-k-group.cpp) | [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/) | 添加头节点方便操作, 根据头节点往下判断, 是否有k个, 有k个就进行头插法, 返回最后一个节点作为下一次的头节点.
