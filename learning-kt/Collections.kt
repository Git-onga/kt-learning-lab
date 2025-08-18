fun list() {
    // Immutable list
    val fruits = listOf("Apple", "Banana", "Orange")
    println(fruits[0]) // Apple

    // Mutable list
    val numbers = mutableListOf(1, 2, 3)
    numbers.add(4)
    println(numbers) // [1, 2, 3, 4]
}

fun sets() {
    val uniqueNums = setOf(1, 2, 2, 3, 4)
    println(uniqueNums) // [1, 2, 3, 4]

    val mutableSet = mutableSetOf("Kotlin", "Java")
    mutableSet.add("Python")
    println(mutableSet) // [Kotlin, Java, Python]
}

fun mapof() {
    val studentAges = mapOf("Alice" to 20, "Bob" to 22)
    println(studentAges["Alice"]) // 20

    val mutableMap = mutableMapOf("Kenya" to "Nairobi")
    mutableMap["Tanzania"] = "Dodoma"
    println(mutableMap) // {Kenya=Nairobi, Tanzania=Dodoma}
}

fun nullable() {
    var name: String = "Bildad"
    // name = null // ❌ ERROR

    var nullableName: String? = "Gitonga"
    nullableName = null // ✅ Allowed
}

fun safe() {
    val text: String? = null
    println(text?.length) // null, safe
}

fun elvisoperator() {
    val name: String? = null
    val displayName = name ?: "Guest"
    println(displayName) // Guest
}

fun nonnullassition() {
    val message: String? = "Hello"
    println(message!!.length) // Works, but crashes if message = null
}


