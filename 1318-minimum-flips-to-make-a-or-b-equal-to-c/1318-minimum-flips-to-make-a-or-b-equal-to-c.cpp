class Solution {
public:
  int minFlips(int a, int b, int c)
{
    int count = 0;
    int checker=(a|b)^c;
    int bits=(a&b)&checker;
    while(checker!=0 || bits!=0)
    {
        if(checker&1==1) count++;
        if(bits&1==1) count++;
        checker>>=1;
        bits>>=1;
    }
    return count;
}
};