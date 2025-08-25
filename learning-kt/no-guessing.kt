import kotlin.random.Random

class NumberGuessingGame {
    private var totalScore = 0
    private var roundsPlayed = 0
    
    fun playGame() {
        println("🎯 Welcome to the Advanced Number Guessing Game!")
        println("================================================")
        
        var playAgain = true
        
        while (playAgain) {
            playRound()
            print("\nWould you like to play again? (yes/no): ")
            val response = readLine()?.lowercase()
            playAgain = response == "yes" || response == "y"
        }
        
        showFinalStats()
    }
    
    private fun playRound() {
        val randomNumber = Random.nextInt(1, 101)
        var attempts = 0
        val maxAttempts = 10
        var guess: Int?
        
        println("\n🌟 Round ${++roundsPlayed}")
        println("I'm thinking of a number between 1 and 100.")
        println("You have $maxAttempts attempts to guess it!")
        println("----------------------------------------")
        
        while (attempts < maxAttempts) {
            val remainingAttempts = maxAttempts - attempts
            print("Attempt ${attempts + 1}/$maxAttempts ($remainingAttempts left): ")
            
            guess = readLine()?.toIntOrNull()
            
            if (guess == null) {
                println("❌ Please enter a valid number!")
                continue
            }
            
            attempts++
            
            when {
                guess < 1 || guess > 100 -> {
                    println("⚠️  Please enter a number between 1 and 100!")
                    attempts-- // Don't count invalid attempts
                }
                guess < randomNumber -> {
                    println("📈 Too low!")
                    if (randomNumber - guess <= 5) {
                        println("   🔥 You're very close!")
                    }
                }
                guess > randomNumber -> {
                    println("📉 Too high!")
                    if (guess - randomNumber <= 5) {
                        println("   🔥 You're very close!")
                    }
                }
                else -> {
                    val roundScore = maxAttempts - attempts + 1
                    totalScore += roundScore
                    
                    println("🎉 Congratulations! You guessed it in $attempts attempts!")
                    println("💰 Round score: $roundScore points")
                    println("🏆 Total score: $totalScore points")
                    return
                }
            }
            
            if (attempts == maxAttempts / 2) {
                giveHint(randomNumber)
            }
        }
        
        println("😔 Game over! You ran out of attempts.")
        println("💡 The number was: $randomNumber")
    }
    
    private fun giveHint(number: Int) {
        val hint = when {
            number < 33 -> "Hint: The number is in the lower third (1-33)"
            number < 66 -> "Hint: The number is in the middle third (34-65)"
            else -> "Hint: The number is in the upper third (66-100)"
        }
        println("💡 $hint")
    }
    
    private fun showFinalStats() {
        println("\n📊 Game Statistics:")
        println("==================")
        println("Rounds played: $roundsPlayed")
        println("Total score: $totalScore points")
        println("Average score per round: ${if (roundsPlayed > 0) totalScore / roundsPlayed else 0}")
        
        when (totalScore) {
            in 0..10 -> println("🏅 Rating: Beginner")
            in 11..30 -> println("🏅 Rating: Intermediate")
            in 31..50 -> println("🏅 Rating: Advanced")
            else -> println("🏅 Rating: Number Wizard!")
        }
    }
}

fun main() {
    val game = NumberGuessingGame()
    game.playGame()
}
