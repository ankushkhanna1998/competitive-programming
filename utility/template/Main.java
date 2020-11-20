import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) throws IOException {
        IOConsole console = new IOConsole();
        int tt = console.nextInt();
        while (tt-- > 0) {
            // TODO
        }
        console.close();
    }

    private static final class IOConsole {
        private final BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        private final PrintWriter output = new PrintWriter(System.out);

        private StringTokenizer tokenizer = null;

        private void ensureTokens() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(input.readLine());
            }
        }

        public final String nextLine() throws IOException {
            assertion(tokenizer == null || !tokenizer.hasMoreTokens());
            return input.readLine();
        }

        public final String next() throws IOException {
            ensureTokens();
            return tokenizer.nextToken();
        }

        public final int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public final long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public final double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public final String[] nextStrings() throws IOException {
            ensureTokens();
            String[] tokens = new String[tokenizer.countTokens()];
            for (int i = 0; i < tokens.length; i++) {
                tokens[i] = tokenizer.nextToken();
            }
            return tokens;
        }

        public final Stream<String> nextStream() throws IOException {
            return Arrays.stream(nextStrings());
        }

        public final int[] nextInts() throws IOException {
            return nextStream().mapToInt(Integer::parseInt).toArray();
        }

        public final long[] nextLongs() throws IOException {
            return nextStream().mapToLong(Long::parseLong).toArray();
        }

        public final double[] nextDoubles() throws IOException {
            return nextStream().mapToDouble(Double::parseDouble).toArray();
        }

        public final void println() {
            output.println();
        }

        public final void println(Object object) {
            output.println(object);
        }

        public final void print(Object object) {
            output.print(object);
        }

        public final void flush() {
            output.flush();
        }

        public final void assertion(boolean expression) {
            if (!expression) {
                throw new AssertionError();
            }
        }

        public final void close() throws IOException {
            flush();
            output.close();
            input.close();
        }
    }

}
