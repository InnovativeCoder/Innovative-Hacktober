fun main(args: Array<String>) {
    val noOfTestCases = readLine()!!.toInt()
    var listOfFactorials = mutableListOf<String>()
    var factorial = Factorial()

    for(n in 1..noOfTestCases)
    {
        listOfFactorials.add(factorial.factorial(readLine()!!.toInt()).toString())
    }

    listOfFactorials.forEach { println(it.last()) }
}

class Factorial
{
    fun factorial(number : Int) : Int
    {
        if(number == 1 || number == 0)
            return 1
        else
        return factorial(number-1) * number
    }
}