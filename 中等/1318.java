class Solution {
    public int minFlips(int a, int b, int c) {
        int count=0;

        String s1=Integer.toBinaryString(a);
        String s2=Integer.toBinaryString(b);
        String s=Integer.toBinaryString(c);

        int n = Math.max(s1.length(),Math.max(s2.length(),s.length()));
        // 对其位数
        int diff = n - s1.length();
        for(int i = 0; i < diff; i++){
            s1 = "0" + s1;
        }
        diff = n-s2.length();
        for(int i = 0; i < diff; i++){
            s2 = "0" + s2;
        }
        diff = n-s.length();
        for(int i = 0; i < diff; i++){
            s= "0" + s;
        }
        // 反转
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            char ch1 = s1.charAt(i);
            char ch2 = s2.charAt(i);
            if(ch == '0'){
                if(ch1 != '0'){
                    count++;
                }
                if(ch2 != '0'){
                    count++;
                }
            } else if(ch1 == '0' && ch2 == '0'){
                count++;
            }
        }
        return count;   
    }
}