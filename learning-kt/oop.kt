// Simple class
class Person {
    // Properties
    var name: String = ""
    var age: Int = 0
    
    // Method
    fun speak() {
        println("Hello, my name is $name and I'm $age years old.")
    }
}

// objects declaration
val person = Person()
person.name = "Alice"
person.age = 25
person.speak()

// Class with a constructor
class Person(val name: String, var age: Int) {
    init {
        println("Person created: $name, $age")
    }
    
    fun speak() {
        println("Hello, I'm $name")
    }
}

// Usage
val person = Person("Bob", 30)
person.speak()

// Inheritace
// Base class (must be declared 'open' to be inherited)
open class Animal(val name: String) {
    open fun makeSound() {
        println("Some generic animal sound")
    }
}

// Derived class
class Dog(name: String, val breed: String) : Animal(name) {
    override fun makeSound() {
        println("Woof! Woof!")
    }
    
    fun fetch() {
        println("$name is fetching!")
    }
}

// Usage
val dog = Dog("Rex", "German Shepherd")
dog.makeSound()  // Output: Woof! Woof!
dog.fetch()      // Output: Rex is fetching!

//Acces Modifeirs
open class Base {
    public val publicProperty = "Public"      // Accessible everywhere
    protected val protectedProperty = "Protected" // Accessible in subclasses
    internal val internalProperty = "Internal" // Accessible in same module
    private val privateProperty = "Private"   // Accessible only in this class
}

class Derived : Base() {
    fun test() {
        println(publicProperty)    // OK
        println(protectedProperty) // OK
        println(internalProperty)  // OK
        // println(privateProperty) // Error: private
    }
}

//Abstract Class
abstract class Shape {
    abstract fun area(): Double
    abstract fun perimeter(): Double
    
    fun description() {
        println("This shape has area ${area()} and perimeter ${perimeter()}")
    }
}

class Circle(val radius: Double) : Shape() {
    override fun area(): Double = Math.PI * radius * radius
    override fun perimeter(): Double = 2 * Math.PI * radius
}

// Usage
val circle = Circle(5.0)
circle.description()

//Extension Functions
// Extension function for String class
fun String.addExcitement(): String = "$this!"

// Extension property for List<Int>
val List<Int>.sum: Int
    get() = this.fold(0) { acc, value -> acc + value }

// Usage
val excited = "Hello".addExcitement() // "Hello!"
val numbers = listOf(1, 2, 3, 4, 5)
println(numbers.sum) // 15
