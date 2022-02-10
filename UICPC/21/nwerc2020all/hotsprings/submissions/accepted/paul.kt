fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }.sorted()
    val b = a.subList(n/2,n).zip(a.subList(0,n/2).reversed()) { x, y -> listOf(x,y) }.flatten()
    println((if (n%2 == 0) b else b + listOf(a[n-1])).joinToString(" ") { it.toString() })
}
