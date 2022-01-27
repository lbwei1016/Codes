/*
***fast and slow pointer***
    Description:
        n = 19 -> 1^2 + 9^2 = 82 -> 8^2 + 2^2 ->...
        If the process goes to the cycle: 1->1->1... => happy
        If the process is in otherwise cycle => not happy
    Solution:
        可以發現，不論最終是 happy or not，都將進入某個 cycle。
        以 linked list 的角度來想，我們可以確保該 linked list 必定包含環，
        我們只需要確認在該環的值是否為 1。
    fast and slow pointer:
        快速判斷是否有環的方法。
        宣告兩指標: slow and fast: "slow" advances 1 node once; "fast" advances 2 nodes once
        若 list 無環，則 slow 不可能追上 fast；
        反之，slow and fast 終將同時指向環中某節點，或說 fast 會反向追上 slow (GCD)。

        以這題而言，只要判斷 slow and fast 指到的同一數字是否為 1 即可！
*/
class Solution {
public:
    int squ(int n) {
        int sum = 0;
        while(n > 0) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    bool fast_slow_pointer(int n) {
        int slow = n, fast = n;
        do {
            slow = squ(slow);
            fast = squ(fast);
            fast = squ(fast);
        } while(slow != fast);
        return slow == 1;
    }
    bool isHappy(int n) {
        return fast_slow_pointer(n);
    }
};