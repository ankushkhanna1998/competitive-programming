import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.stream.Stream;

public final class Main {

    public static void main(final String[] args) throws IOException {
        int testCases = console.nextInt();
        while (testCases-- > 0) {
            // TODO
        }
        console.close();
    }

    private static final IOConsole console = new IOConsole();
}

final class IOConsole {

    private final BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
    private final PrintWriter output = new PrintWriter(System.out);

    private StringTokenizer tokenizer = null;

    private void ensureTokens() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(input.readLine());
        }
    }

    public String nextLine() throws IOException {
        assertion(tokenizer == null || !tokenizer.hasMoreTokens());
        return input.readLine();
    }

    public String next() throws IOException {
        ensureTokens();
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public String[] nextStrings() throws IOException {
        ensureTokens();
        final String[] tokens = new String[tokenizer.countTokens()];
        for (int i = 0; i < tokens.length; i++) {
            tokens[i] = tokenizer.nextToken();
        }
        return tokens;
    }

    public Stream<String> nextStream() throws IOException {
        return Arrays.stream(nextStrings());
    }

    public IntStream nextIntStream() throws IOException {
        return nextStream().mapToInt(Integer::parseInt);
    }

    public LongStream nextLongStream() throws IOException {
        return nextStream().mapToLong(Long::parseLong);
    }

    public DoubleStream nextDoubleStream() throws IOException {
        return nextStream().mapToDouble(Double::parseDouble);
    }

    public int[] nextInts() throws IOException {
        return nextIntStream().toArray();
    }

    public long[] nextLongs() throws IOException {
        return nextLongStream().toArray();
    }

    public double[] nextDoubles() throws IOException {
        return nextDoubleStream().toArray();
    }

    public void println() {
        output.println();
    }

    public void println(final Object object) {
        output.println(object);
    }

    public void print(final Object object) {
        output.print(object);
    }

    public void debug(final Object object) {
        System.err.println("Debug: " + object);
        System.err.flush();
    }

    public void assertion(final boolean expression) {
        if (!expression) {
            throw new AssertionError();
        }
    }

    public void flush() {
        output.flush();
    }

    public void close() throws IOException {
        flush();
        output.close();
        input.close();
    }
}
