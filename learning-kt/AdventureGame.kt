import kotlin.random.Random
import kotlin.system.exitProcess

data class Player(val name: String, var health: Int = 100, var gold: Int = 0)

fun main() {
    println("🌲 Welcome to the Enchanted Forest Adventure! 🌲")
    print("Enter your name, brave adventurer: ")
    val playerName = readLine() ?: "Anonymous Hero"
    val player = Player(playerName)
    
    println("\nGreetings, ${player.name}! Your quest begins now...")
    
    // Game loop
    while (player.health > 0) {
        displayStatus(player)
        when (promptForAction()) {
            1 -> exploreForest(player)
            2 -> rest(player)
            3 -> searchForTreasure(player)
            4 -> {
                println("Thanks for playing!")
                exitProcess(0)
            }
        }
        
        // Random event chance
        if (Random.nextInt(10) < 3) {
            randomEvent(player)
        }
    }
    
    println("\n💀 Game Over! ${player.name} has been defeated...")
    println("You collected ${player.gold} gold pieces during your adventure!")
}

fun displayStatus(player: Player) {
    println("\n=== ${player.name}'s Status ===")
    println("❤️  Health: ${player.health}")
    println("💰 Gold: ${player.gold}")
    println("========================")
}

fun promptForAction(): Int {
    println("\nWhat would you like to do?")
    println("1. 🌳 Explore the forest")
    println("2. 🏕️  Rest at camp")
    println("3. 💎 Search for treasure")
    println("4. 🚪 Quit game")
    
    return readLine()?.toIntOrNull() ?: 0
}

fun exploreForest(player: Player) {
    println("\nYou venture deeper into the forest...")
    
    when (Random.nextInt(5)) {
        0 -> {
            println("You encounter a friendly fairy who restores your health!")
            player.health = minOf(100, player.health + 20)
        }
        1 -> {
            println("A mischievous gnome steals some gold!")
            player.gold = maxOf(0, player.gold - 10)
        }
        2 -> {
            println("You battle a fearsome forest creature!")
            player.health -= 25
            println("You take 25 damage!")
        }
        3 -> {
            println("You discover a hidden path leading to ancient ruins!")
            player.gold += 15
            println("You find 15 gold pieces!")
        }
        else -> {
            println("You enjoy a peaceful walk through the beautiful forest.")
        }
    }
}

fun rest(player: Player) {
    println("\nYou set up camp and rest for a while...")
    player.health = minOf(100, player.health + 10)
    println("You recover 10 health points!")
}

fun searchForTreasure(player: Player) {
    println("\nYou search for hidden treasure...")
    
    if (Random.nextBoolean()) {
        val treasure = Random.nextInt(5, 30)
        player.gold += treasure
        println("You found $treasure gold pieces!")
    } else {
        println("Your search yields nothing but forest debris.")
    }
}

fun randomEvent(player: Player) {
    println("\n*** Something unexpected happens! ***")
    
    when (Random.nextInt(4)) {
        0 -> {
            println("A sudden rainstorm soaks you to the bone!")
            player.health -= 5
        }
        1 -> {
            println("You stumble upon a forgotten cache of coins!")
            player.gold += 8
        }
        2 -> println("A rainbow appears overhead, filling you with hope.")
        else -> println("The wind whispers secrets of the ancient forest.")
    }
}
