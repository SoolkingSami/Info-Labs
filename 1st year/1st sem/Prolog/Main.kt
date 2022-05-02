infix fun String.revAppend(s: String) = s + this

fun main() {
    println("World!" revAppend "Hello, ")
}