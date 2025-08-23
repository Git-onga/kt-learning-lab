fun main() {
    val day = 3
    
    when (day) {
        1 -> println("Monday")
        2 -> println("Tuesday")
        3 -> println("Wednesday")
        4 -> println("Thursday")
        5 -> println("Friday")
        6 -> println("Saturday")
        7 -> println("Sunday")
        else -> println("Invalid day")
    }
}

// mutliple cases
fun main() {
    val grade = 'B'
    
    when (grade) {
        'A', 'B' -> println("Excellent")
        'C' -> println("Good")
        'D' -> println("Pass")
        'F' -> println("Fail")
        else -> println("Invalid grade")
    }
}

// using range
fun main() {
    val score = 85
    
    when (score) {
        in 90..100 -> println("A")
        in 80..89 -> println("B")
        in 70..79 -> println("C")
        in 60..69 -> println("D")
        else -> println("F")
    }
}
