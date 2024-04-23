import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1874 {

  public static class MyStack<T> {

    private Object[] arr;
    private int size;

    public MyStack() {
      this.arr = new Object[100001];
      size = 0;
    }

    public void push(T item) {
      arr[size++] = (T) item;
    }

    public T pop() {
      if (size == 0) {
        return null;
      }
      size--;
      T save = (T) arr[size];
      arr[size] = null;
      return save;
    }

    public T peek() {
      if (size == 0) {
        return null;
      }
      return (T) arr[size - 1];
    }

    public boolean isEmpty() {
      return size == 0;
    }

    public int size() {
      return size;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    MyStack<Integer> stack = new MyStack<>();

    int N = Integer.parseInt(br.readLine());

    int x = 1;
    StringBuilder sb = new StringBuilder();
    while (N-- > 0) {
      int num = Integer.parseInt(br.readLine());
      while (x <= num) {
        stack.push(x++);
        //bw.write("+\n");
        sb.append("+\n");
      }
      if (x > N && !stack.peek().equals(num)) {
        sb = new StringBuilder();
        sb.append("NO\n");
        // br = new BufferedWriter(new OutputStreamWriter(System.out));
        // br.write("NO\n");
        break;
      }
      stack.pop();
      // bw.write("-\n");
      sb.append("-\n");
    }
    bw.write(sb + "");
    br.close();
    bw.close();
  }
}
/* 처음 제출할 때 StringBuilder를 쓰지 않고 BufferedWriter만을 사용했더니 출력초과가 났다.
   그 이유에 대해 찾아보니 BufferedWriter는 버퍼를 이용하는 출력 함수이다. 
   버퍼가 가득차거나 flush를 호출 했을 때 출력하게 되는데
   n이 크고 불가능한 수열의 경우 NO를 출력하는 조건에 들어가기 전에 +-로 버퍼가 가득차
   +-를 출력해버리는 문제가 있었다. BufferedWriter의 기본 버퍼는 16384byte라고 하니 이 부분을 유의해서 풀자.
 */
