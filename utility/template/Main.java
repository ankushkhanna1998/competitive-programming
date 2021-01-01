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
        final IOConsole console = new IOConsole();
        int tt = console.nextInt();
        while (tt-- > 0) {
            // TODO
        }
        console.close();
    }
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
        final String[] tokens = new String[tokenizer.countTokens()];
        for (int i = 0; i < tokens.length; i++) {
            tokens[i] = tokenizer.nextToken();
        }
        return tokens;
    }

    public final Stream<String> nextStream() throws IOException {
        return Arrays.stream(nextStrings());
    }

    public final IntStream nextIntStream() throws IOException {
        return nextStream().mapToInt(Integer::parseInt);
    }

    public final LongStream nextLongStream() throws IOException {
        return nextStream().mapToLong(Long::parseLong);
    }

    public final DoubleStream nextDoubleStream() throws IOException {
        return nextStream().mapToDouble(Double::parseDouble);
    }

    public final int[] nextInts() throws IOException {
        return nextIntStream().toArray();
    }

    public final long[] nextLongs() throws IOException {
        return nextLongStream().toArray();
    }

    public final double[] nextDoubles() throws IOException {
        return nextDoubleStream().toArray();
    }

    public final void println() {
        output.println();
    }

    public final void println(final Object object) {
        output.println(object);
    }

    public final void print(final Object object) {
        output.print(object);
    }

    public final void flush() {
        output.flush();
    }

    public final void assertion(final boolean expression) {
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
