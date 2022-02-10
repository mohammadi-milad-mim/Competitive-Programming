import kotlin.math.roundToInt
import kotlin.math.sqrt
import kotlin.random.Random

val X = 1000000L
var n = -1

fun query(x: Long, y: Long): Long {
    if (x < 0 || x > X || y < 0 || y > X || n == 0) return 0
    println("%d %d".format(x,y))
    System.out.flush()
    val ans = readLine()!!.toLong()
    if (ans == 0L) --n
    return ans
}

fun main() {
    n = readLine()!!.toInt()
    while (n > 0) {
        val x = Random.nextLong(0,X)
        val y = Random.nextLong(0,X)
        val r = query(x,y)
        val s = query(x+1,y)
        val dx = (1+r-s) / 2
        val dy = sqrt((r - dx*dx).toDouble()).toLong()
        query(x+dx,y+dy)
        query(x+dx,y-dy)
    }
}