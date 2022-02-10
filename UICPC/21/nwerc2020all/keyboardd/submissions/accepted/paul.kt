import java.util.*

fun main() {
    val a = readLine()!!.toList()
    val b = readLine()!!.toList()
    println(" abcdefghijklmnopqrstuvwxyz".filter { Collections.frequency(b,it) > Collections.frequency(a,it) })
}
