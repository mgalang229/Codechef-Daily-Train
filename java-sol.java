
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        FastReader in = new FastReader();
        int x = in.nextInt();
        int n = in.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.next();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int last = 53;
            int cnt = 0;
            int ways = 0;
            for (int j = 0; j < 36; j++) {
                if ((j + 1) % 4 == 0) {
                    for (int k = 3; k >= 0; k--) {
                        if (s[i].charAt(j - k) == '0') {
                            cnt++;
                        }
                    }
                    if (s[i].charAt(last) == '0') {
                        cnt++;
                    }
                    if (s[i].charAt(last - 1) == '0') {
                        cnt++;
                    }
                    if (cnt >= x) {
                        ways += (Factorial(cnt) / (Factorial(x) * Factorial(cnt - x)));
                    }
                    cnt = 0;
                    last -= 2;
                }
            }
            ans += ways;
        }
        System.out.println(ans);
    }
    
    static int Factorial(int a) {
        if (a == 0) {
            return 1;
        }
        return a * Factorial(a - 1);
    }
    
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        
        int nextInt() {
            return Integer.parseInt(next());
        }
        
        long nextLong() {
            return Long.parseLong(next());
        }
        
        double nextDouble() {
            return Double.parseDouble(next());
        }
        
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch(IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
