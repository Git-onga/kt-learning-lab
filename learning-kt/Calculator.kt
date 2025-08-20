fun main() {
    println("🧮 Simple Kotlin Calculator")
    println("==========================")
    
    while (true) {
        println("\nChoose an operation:")
        println("1. Addition (+)")
        println("2. Subtraction (-)")
        println("3. Exit")
        print("Enter your choice (1-3): ")
        
        when (readlnOrNull()?.toIntOrNull()) {
            1 -> performOperation("addition")
            2 -> performOperation("subtraction")
            3 -> {
                println("Goodbye! 👋")
                return
            }
            else -> println("❌ Invalid choice! Please enter 1, 2, or 3.")
        }
    }
}

fun performOperation(operation: String) {
    println("\n--- ${operation.replaceFirstChar { it.uppercase() }} ---")
    
    val num1 = getValidNumber("Enter first number: ")
    val num2 = getValidNumber("Enter second number: ")
    
    when (operation) {
        "addition" -> {
            val result = add(num1, num2)
            println("✅ Result: $num1 + $num2 = $result")
        }
        "subtraction" -> {
            val result = subtract(num1, num2)
            println("✅ Result: $num1 - $num2 = $result")
        }
    }
}

fun getValidNumber(prompt: String): Double {
    while (true) {
        print(prompt)
        val input = readlnOrNull()
        
        if (input.isNullOrBlank()) {
            println("❌ Please enter a number!")
            continue
        }
        
        val number = input.toDoubleOrNull()
        if (number != null) {
            return number
        } else {
            println("❌ Invalid number! Please try again.")
        }
    }
}

fun add(a: Double, b: Double): Double {
    return a + b
}

fun subtract(a: Double, b: Double): Double {
    return a - b
}
