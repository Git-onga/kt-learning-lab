fun main() {
    val tasks = mutableListOf<String>()  // List to hold tasks

    while (true) {
        println("\n--- To-Do List ---")
        println("1. Add Task")
        println("2. View Tasks")
        println("3. Exit")
        print("Choose an option: ")

        when (readLine()) {
            "1" -> {
                print("Enter task: ")
                val task = readLine()
                if (!task.isNullOrBlank()) {
                    tasks.add(task)
                    println("Task added!")
                } else {
                    println("Task cannot be empty.")
                }
            }
            "2" -> {
                if (tasks.isEmpty()) {
                    println("No tasks yet.")
                } else {
                    println("Your Tasks:")
                    tasks.forEachIndexed { index, task ->
                        println("${index + 1}. $task")
                    }
                }
            }
            "3" -> {
                println("Goodbye!")
                break
            }
            else -> println("Invalid option. Try again.")
        }
    }
}
