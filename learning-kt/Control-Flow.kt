val x = 10
val y = 20

// if-else
val max = if (x > y) x else y
println(max) // 20

// if with blocks
val result = if (x % 2 == 0) {
    "Even"
} else {
    "Odd"
}
println(result) // "Even"


// If-else (as expression)
val max = if (a > b) a else b

// When expression (like switch)
val description = when (x) {
    1 -> "One"
    2 -> "Two"
    in 3..10 -> "Between 3 and 10"
    else -> "Other number"
}

// For loop
for (i in 1..5) print(i)  // 12345
for (i in 1 until 5) print(i)  // 1234
for (i in 5 downTo 1) print(i)  // 54321
for (i in 1..10 step 2) print(i)  // 13579
for (i in 1..5) {
    println(i) // 1,2,3,4,5
}

for (i in 10 downTo 1 step 2) {
    println(i) // 10, 8, 6, ...
}

val fruits = listOf("Apple", "Banana", "Cherry")
for (fruit in fruits) {
    println(fruit)
}

// While loop
var x = 5
while (x > 0) {
    println(x)
    x--
}

var i = 1
while (i <= 5) {
    println(i)
    i++
}

//Do While loop
var j = 5
do {
    println(j)
    j--
} while (j > 0)


val day = 3
val nameOfDay = when (day) {
    1 -> "Monday"
    2 -> "Tuesday"
    3 -> "Wednesday"
    4 -> "Thursday"
    5 -> "Friday"
    6, 7 -> "Weekend"  // multiple matches
    else -> "Invalid day"
}
println(nameOfDay) // Wednesday

//break and continue
for (i in 1..5) {
    if (i == 3) break   // stops loop
    println(i)          // prints 1, 2
}

for (i in 1..5) {
    if (i == 3) continue // skips 3
    println(i)           // prints 1,2,4,5
}
