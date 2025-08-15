// Syntax
fun functionName(parameter1: Type, parameter2: Type): ReturnType {
    // Function body
    return result
}

// simple function
fun greet(name: String): String {
    return "Hello, $name!"
}

// Usage
val message = greet("Alice")  // Returns "Hello, Alice!"

// Function with default parameters
fun calculateArea(
    length: Double, 
    width: Double = 10.0  // Default value
): Double {
    return length * width
}

// single expression function
fun isEven(number: Int): Boolean = number % 2 == 0

// Extension function
fun String.addExclamation(): String {
    return "$this!"
}

// Usage
println("Hello".addExclamation())  // Prints "Hello!"
