import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        int[] colours = new int[N+1];
        List<Integer>[] idxs = new ArrayList[C + 1];
        for (int i = 0; i <= C; i++) {
            idxs[i] = new ArrayList<>();
            idxs[i].add(-1);
        }

        st = new StringTokenizer(br.readLine());

        for (int i = 1, c; i <= N; i++) {
            c = Integer.parseInt(st.nextToken());
            idxs[c].add(i);
            colours[i] = c;
        }

        st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());

        for (int i = 0, a, b; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            int ans = -1;
            for (int j = 0; j < 100; j++) {
                int x = ((int) (Math.random() * (b-a+1))) + a;
                x = colours[x];
                int lower = Collections.binarySearch(idxs[x], a);
                int upper = Collections.binarySearch(idxs[x], b);
                if (lower < 0)
                    lower = -lower - 1;
                if (upper < 0)
                    upper = -upper - 1;
                else
                    upper++;
                if (upper - lower > (b - a + 1) / 2) {
                    ans = x;
                    break;
                }
            }
            if (ans < 0) {
                sb.append("no\n");
            } else {
                sb.append("yes ");
                sb.append(ans);
                sb.append("\n");
            }
        }
        bw.write(sb.toString());
        bw.flush();
    }
}