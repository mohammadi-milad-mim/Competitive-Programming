private fun readInts() = readLine()!!.split(' ').map { it.toInt() }

fun main() {
    val (n, k) = readInts()
    val (a, s) = readInts()
    val res = (n*a-k*s).toDouble()/(n-k)
    println(if (res < 0 || res > 100) "impossible" else res)
}
