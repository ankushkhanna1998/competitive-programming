import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

fun main(args: Array<String>) {
    repeat(console.readInt()) {
        // TODO
    }
    console.close()
}

private val console = IOConsole()

private class IOConsole {

    private val input = BufferedReader(InputStreamReader(System.`in`))
    private val output = PrintWriter(System.out)

    fun readLine(): String = input.readLine()
    fun readInt() = readLine().toInt()
    fun readLong() = readLine().toLong()
    fun readDouble() = readLine().toDouble()
    fun readStrings() = readLine().split(' ')
    fun readInts() = readStrings().map { it.toInt() }
    fun readLongs() = readStrings().map { it.toLong() }
    fun readDoubles() = readStrings().map { it.toDouble() }

    fun println() = output.println()

    fun println(token: Any?) {
        output.println(token ?: "null")
    }

    fun print(token: Any?) {
        output.print(token ?: "null")
    }

    fun debug(token: Any?) {
        System.err.println("Debug: $token")
        System.err.flush()
    }

    fun assertion(expression: Boolean) {
        if (!expression) {
            throw AssertionError()
        }
    }

    fun flush() {
        output.flush()
    }

    fun close() {
        flush()
        output.close()
        input.close()
    }
}
