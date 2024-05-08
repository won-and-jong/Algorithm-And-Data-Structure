package week_4;

import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;

public class BOJ5430 {
    static Deque<Integer> queue = new ArrayDeque<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            String f = br.readLine();
            int n = Integer.parseInt(br.readLine());
//            split으로 여러 구분자 사용하는 법
//            String[] arr = br.readLine().split("[\\[\\],]");
            StringBuilder arr = new StringBuilder(br.readLine());
            arr.deleteCharAt(0);
            arr.deleteCharAt(arr.length() - 1);

            boolean r = false;
            if (!arr.isEmpty()) {
                addQ(arr);
            }
            try {
                for (int j = 0; j < f.length(); j++) {
                    if (f.charAt(j) == 'R') {
                        r = !r;
                    } else {
                        if (r) {
                            queue.removeLast();
                        } else {
                            queue.remove();
                        }
                    }
                }
                bw.write(makeStr(r) + "\n");
            } catch (Exception e) {
                bw.write("error\n");
            }
        }
        br.close();
        bw.close();
    }

    private static StringBuilder makeStr(boolean r) {
        StringBuilder arr = new StringBuilder();
        arr.append("[");
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                arr.append(queue.remove());
                break;
            }
            if (r) {
                arr.append(queue.removeLast() + ",");
            } else {
                arr.append(queue.remove() + ",");
            }
        }
        arr.append("]");
        return arr;
    }

    private static void addQ(StringBuilder split) {
        String[] s = split.toString().split(",");
        for (String string : s) {
            queue.offer(Integer.parseInt(string));
        }
    }
}
