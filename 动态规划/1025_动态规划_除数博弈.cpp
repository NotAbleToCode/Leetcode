// 爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

// 最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：

// 选出任一 x，满足 0 < x < N 且 N % x == 0 。
// 用 N - x 替换黑板上的数字 N 。
// 如果玩家无法执行这些操作，就会输掉游戏。

// 只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false。假设两个玩家都以最佳状态参与游戏。

#include<vector>
#include<iostream>
using namespace std;
// 动态规划来做
bool divisorGame(int N) {
    if(N==1){
        return false;
    }        
    if(N==2){
        return true;
    }
    vector<bool> f(N+1);
    f[1] = false;
    f[2] = true;
    for(int i=3;i<N+1;i++){
        bool temp = true;
        for(int j=1;j<=i/2;j++){
            if(i%j==0){
                temp = temp & f[i-j];
                if(temp==false){
                    break;
                }
            }
        }
        f[i] = !temp;
    }
    return f[N];
}
// 其实，return (N%2==0)?true:false;即可
// 因为，奇数肯定没有偶数因子的，只有奇数因子。偶数有1这么一个奇数因子。
// 因此，若自己一开始拿到的是偶数，可以选择1将其变为奇数。那么对方只能选择一个奇数因子将其变为偶数，我们再选择1将其变为奇数。那么每次对手做操作时，面对的都是奇数。
// 由于操作数严格递减的，那么对手肯定会面对到1这个奇数，从而输掉比赛。
// 若自己一开始拿到的是奇数。那么自己只能将其变为偶数。相当于对方偶数先手，必输。
int main(){
    cout<<divisorGame(3)<<endl;
}