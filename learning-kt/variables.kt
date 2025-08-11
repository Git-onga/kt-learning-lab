fun main() {
    // Immutable variable
    val languageName: String = "Kotlin"
    
    // Mutable variable with type inference
    var score = 95
    
    // Nullable variable
    var nullableInt: Int? = null
    
    // Late initialization
    lateinit var userName: String
    
    // Using the lazy initialized value
    val databaseConnection by lazy { 
        createDatabaseConnection() 
    }
    
    println("Language: $languageName")
    println("Score: ${score + 5}")
}