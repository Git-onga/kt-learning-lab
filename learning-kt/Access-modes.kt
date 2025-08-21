// File: AccessModifiersDemo.kt

// Public class - accessible from anywhere
public open class PublicClass {
    public val publicProperty: String = "I'm public"
    internal val internalProperty: String = "I'm internal"
    protected val protectedProperty: String = "I'm protected"
    private val privateProperty: String = "I'm private"
    
    public fun publicMethod() = println("Public method called")
    internal fun internalMethod() = println("Internal method called")
    protected fun protectedMethod() = println("Protected method called")
    private fun privateMethod() = println("Private method called")
    
    fun demonstrateAccess() {
        println("\n=== Inside PublicClass ===")
        println(publicProperty)      // ✅ Accessible
        println(internalProperty)    // ✅ Accessible
        println(protectedProperty)   // ✅ Accessible
        println(privateProperty)     // ✅ Accessible
        
        publicMethod()      // ✅ Accessible
        internalMethod()    // ✅ Accessible
        protectedMethod()   // ✅ Accessible
        privateMethod()     // ✅ Accessible
    }
}

// Internal class - accessible within same module
internal class InternalClass {
    public val publicProperty: String = "I'm public in internal class"
    private val privateProperty: String = "I'm private in internal class"
    
    fun showAccess() {
        println("\n=== Inside InternalClass ===")
        println(publicProperty)    // ✅ Accessible
        println(privateProperty)   // ✅ Accessible
    }
}

// Private class - only accessible within same file
private class PrivateClass {
    public val publicProperty: String = "I'm public in private class"
    
    fun showAccess() {
        println("\n=== Inside PrivateClass ===")
        println(publicProperty)    // ✅ Accessible
    }
}

// Subclass demonstrating protected access
class SubClass : PublicClass() {
    fun demonstrateProtectedAccess() {
        println("\n=== Inside SubClass ===")
        println(publicProperty)      // ✅ Accessible (inherited)
        println(internalProperty)    // ✅ Accessible (inherited)
        println(protectedProperty)   // ✅ Accessible (inherited)
        // println(privateProperty)   // ❌ NOT accessible - private
        
        publicMethod()      // ✅ Accessible
        internalMethod()    // ✅ Accessible
        protectedMethod()   // ✅ Accessible
        // privateMethod()   // ❌ NOT accessible - private
    }
}

// Different class in same file
class AnotherClass {
    fun demonstrateAccess() {
        println("\n=== Inside AnotherClass ===")
        
        val publicClass = PublicClass()
        println(publicClass.publicProperty)      // ✅ Accessible
        println(publicClass.internalProperty)    // ✅ Accessible (same module)
        // println(publicClass.protectedProperty) // ❌ NOT accessible - protected
        // println(publicClass.privateProperty)   // ❌ NOT accessible - private
        
        publicClass.publicMethod()      // ✅ Accessible
        publicClass.internalMethod()    // ✅ Accessible
        // publicClass.protectedMethod() // ❌ NOT accessible - protected
        // publicClass.privateMethod()   // ❌ NOT accessible - private
        
        val internalClass = InternalClass()
        println(internalClass.publicProperty)    // ✅ Accessible
        // println(internalClass.privateProperty) // ❌ NOT accessible - private
        
        val privateClass = PrivateClass()
        println(privateClass.publicProperty)     // ✅ Accessible (same file)
    }
}

// Main function to demonstrate all access modifiers
fun main() {
    println("🔐 Kotlin Access Modifiers Demonstration")
    println("=".repeat(50))
    
    // Demonstration from main function
    println("\n=== From Main Function ===")
    
    val publicClass = PublicClass()
    println(publicClass.publicProperty)      // ✅ Accessible
    println(publicClass.internalProperty)    // ✅ Accessible (same module)
    // println(publicClass.protectedProperty) // ❌ NOT accessible - protected
    // println(publicClass.privateProperty)   // ❌ NOT accessible - private
    
    publicClass.publicMethod()      // ✅ Accessible
    publicClass.internalMethod()    // ✅ Accessible
    // publicClass.protectedMethod() // ❌ NOT accessible - protected
    // publicClass.privateMethod()   // ❌ NOT accessible - private
    
    val internalClass = InternalClass()
    println(internalClass.publicProperty)    // ✅ Accessible
    // println(internalClass.privateProperty) // ❌ NOT accessible - private
    
    val privateClass = PrivateClass()
    println(privateClass.publicProperty)     // ✅ Accessible (same file)
    
    // Demonstrate access from within classes
    publicClass.demonstrateAccess()
    
    val subClass = SubClass()
    subClass.demonstrateProtectedAccess()
    
    val anotherClass = AnotherClass()
    anotherClass.demonstrateAccess()
    
    val internalClassDemo = InternalClass()
    internalClassDemo.showAccess()
    
    val privateClassDemo = PrivateClass()
    privateClassDemo.showAccess()
    
    // Show summary table
    printAccessSummary()
}

fun printAccessSummary() {
    println("\n" + "=".repeat(60))
    println("📊 ACCESS MODIFIERS SUMMARY")
    println("=".repeat(60))
    println("""
    | Modifier    | Class | Subclass | Same Module | Other Module | Same File |
    |-------------|-------|----------|-------------|--------------|-----------|
    | public      |   ✅   |    ✅     |      ✅      |       ✅      |     ✅     |
    | internal    |   ✅   |    ✅     |      ✅      |       ❌      |     ✅     |
    | protected   |   ✅   |    ✅     |      ❌      |       ❌      |     ✅     |
    | private     |   ✅   |    ❌     |      ❌      |       ❌      |     ✅     |
    """.trimMargin())
    
    println("\n💡 KEY POINTS:")
    println("• public: Accessible from anywhere")
    println("• internal: Accessible within same module")
    println("• protected: Accessible in class and subclasses")
    println("• private: Accessible only within declaring scope")
    println("• Default visibility is public in Kotlin")
}

// File: DifferentModule.kt (Conceptual - would be in different module)
/*
// This would be in a different module
class ExternalClass {
    fun testAccess() {
        val publicClass = PublicClass()
        println(publicClass.publicProperty)      // ✅ Accessible
        // println(publicClass.internalProperty)  // ❌ NOT accessible - different module
        // println(publicClass.protectedProperty) // ❌ NOT accessible - protected
        // println(publicClass.privateProperty)   // ❌ NOT accessible - private
        
        // val internalClass = InternalClass()    // ❌ NOT accessible - different module
        // val privateClass = PrivateClass()      // ❌ NOT accessible - different file
    }
}
*/

// File: Test.kt (Demonstrating file-private access)
private class FilePrivateClass {
    fun show() = println("I'm only accessible in this file")
}

fun testFilePrivate() {
    val filePrivate = FilePrivateClass()
    filePrivate.show()  // ✅ Accessible - same file
}
