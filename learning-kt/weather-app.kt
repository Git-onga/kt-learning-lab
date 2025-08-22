import kotlin.random.Random

// Weather data model
data class Weather(
    val location: String,
    val temperature: Double,
    val condition: String
)

// Weather service simulator
class WeatherService {
    private val conditions = listOf("Sunny", "Cloudy", "Rainy", "Stormy", "Windy", "Snowy")

    fun fetchWeather(location: String): Weather {
        println("Fetching weather data for $location...")

        // Simulate API delay
        Thread.sleep(1000)

        // Generate random weather data
        val temp = Random.nextDouble(15.0, 35.0)
        val condition = conditions.random()

        return Weather(location, temp, condition)
    }
}

// Main program
fun main() {
    val service = WeatherService()

    println("Enter a city name:")
    val city = readLine() ?: "Unknown City"

    val weather = service.fetchWeather(city)

    println("---- Weather Report ----")
    println("Location: ${weather.location}")
    println("Temperature: ${weather.temperature} °C")
    println("Condition: ${weather.condition}")
}
